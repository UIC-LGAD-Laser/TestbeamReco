gcc_config_version=4.9.3
LCGPLAT=x86_64-slc6-gcc49-opt
LCG_lib_name=lib64
LCG_arch=x86_64


THIS_BASH=$BASH
if [[ $THIS_BASH == "" ]]; then
    THIS_HERE=$(dirname $0)
else
    THIS_HERE=$(dirname ${BASH_SOURCE[0]})
fi


#if [ -z $1 ] 
#then LCG_contdir=/afs/cern.ch/sw/lcg/contrib
#else LCG_contdir=$1 
#fi
#LCG_gcc_home=${LCG_contdir}/gcc/${gcc_config_version}/${LCGPLAT}
LCG_gcc_home=$THIS_HERE

export PATH=${LCG_gcc_home}/bin:${PATH}
export COMPILER_PATH=${LCG_gcc_home}/lib/gcc/${LCG_arch}-unknown-linux-gnu/${gcc_config_version}


if [ ${LD_LIBRARY_PATH} ]
then
export LD_LIBRARY_PATH=${LCG_gcc_home}/${LCG_lib_name}:${LD_LIBRARY_PATH}
else
export LD_LIBRARY_PATH=${LCG_gcc_home}/${LCG_lib_name}
fi

export FC=`which gfortran`
export CXX=`which g++`
export CC=`which gcc`