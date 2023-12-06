
#Setup env from cvmfs
source ${PWD}/setup_cern.sh

#Add scripts direcotry to path
SCRIPTSDIR=${PWD}/../scripts
if [[ $PATH != *"${SCRIPTSDIR}"* ]]
then
    export PATH=${SCRIPTSDIR}:${PATH}
    echo "adding ${SCRIPTSDIR} to the path"
fi

