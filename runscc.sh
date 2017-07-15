#!/bin/bash

CMDBASE="./build/master/optimized/scratch/"
OPTBASE=" --enableC3P --writeResult --writeFlowInfo "
DIRBASE="result/c3p/"
PROGRAM="c3p-clos"
PATHOUT="ds"
OPTIONS=" --enableDS --pathOut="${DIRBASE}${PATHOUT}
COMMAND=${CMDBASE}${PROGRAM}${OPTBASE}${OPTIONS}


while getopts "c:o:" arg #选项后面的冒号表示该选项需要参数
do
  case $arg in
  #b)
  #  NS3BRANCH=$OPTARG      #参数存在$OPTARG中
  #  ;;
  c)
    PROGRAM=$OPTARG
    ;;
  o)
    PATHOUT=$OPTARG
    ;;
  ?)  #当有不认识的选项的时候arg为?
    echo "unkonw argument"
    exit 1
    ;;
  esac
done
mkdir -p ${DIRBASE}${PATHOUT}
for i in {1..9}
do
  COMMAND=${CMDBASE}${PROGRAM}${OPTBASE}${OPTIONS}" --miceLoad=0."${i}
  $COMMAND &
done
