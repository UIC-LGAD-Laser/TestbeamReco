#!/bin/bash

# LCG wrapper for lcgenv script

scriptdir="$(cd "$(dirname -- "${BASH_SOURCE:-$0}")" && pwd)"
BINFO_PLATFORM="$(basename $scriptdir)"

# where is lcgenv?
if which lcgenv &>/dev/null; then
  lcgenv=$(which lcgenv)
else
  lcgenv=""
  idx=1
  dir="$scriptdir"
  while [ -z "$lcgenv" ]; do
    if ! test -z "$(ls $dir/lcgenv/*/*/lcgenv 2>/dev/null)"; then
      lcgenv="$(ls $dir/lcgenv/*/*/lcgenv 2>/dev/null | head -1)"
      LCGDIR=$dir
    fi
    dir=$(dirname $dir)
    let "idx = $idx + 1"
    if [ $idx -ge 15 ]; then
      echo "# Cannot find lcgenv! Exiting ..."
      return 0
    fi
  done
fi

tmpenv=$(mktemp)

find $scriptdir -type 'f' -iname '.buildinfo*' -print0 | while IFS= read -r -d $'\0' buildinfo; do
  BINFO_NAME="$(cat $buildinfo | sed 's/, /\n/g' | awk -F ' ' '/^NAME/{print $2}')"
  BINFO_VERSION="$(cat $buildinfo | sed 's/, /\n/g' | awk -F ' ' '/^VERSION/{print $2}' | cut -d, -f 1)"

  (cd $LCGDIR; python $lcgenv $BINFO_NAME $BINFO_VERSION $BINFO_PLATFORM) >> $tmpenv
done

if [ ! -s $tmpenv ]; then
  # try to find package without .buildinfo
  BINFO_VERSION="$(basename $(dirname $scriptdir))"
  BINFO_NAME="$(basename $(dirname $(dirname $scriptdir)))"

  (cd $LCGDIR; python $lcgenv $BINFO_NAME $BINFO_VERSION $BINFO_PLATFORM) > $tmpenv
fi

source $tmpenv
rm -f $tmpenv

