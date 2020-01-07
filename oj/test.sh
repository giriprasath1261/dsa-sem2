#!/bin/bash

i=$1
# at max 10000 iterations
if [[ $i -eq 10000 ]]
then
	exit 1
fi

#rm "in.txt"
/usr/bin/python3 gowtests.py > "in.txt"

# put the paths below
a=$( ./gowworking < in.txt)
b=$(./a.out < in.txt)
if [[ $a -eq $b ]]
then
    ./test.sh $(($i + 1))
     exit $?
else
	echo " you are wrong"
	exit 0
fi
