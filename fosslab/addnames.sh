#!/bin/bash
if [ $# -ge 2 ]
then
 if test -f $1
  then
   if grep $2 $1
    then
     echo "user name exist"
    else
     echo "$2" >>$1
   fi
  else
   echo "file does not exist"
 fi 
else
echo "not correct number of arguments"
fi

