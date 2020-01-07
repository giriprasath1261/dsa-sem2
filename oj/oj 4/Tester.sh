#!/bin/bash

i=$1
# at max 10000 iterations
if [[ $i -eq 10000 ]]
then
	exit 1
fi

echo $i
# rm "in.txt"

# Input generator oythin script belo
/usr/bin/python3 _InputGenerator.py_ > "in.txt"

# put the compiled programs' path below
echo $(_Path1_ < in.txt) > out1
echo $(_Path2_ < in.txt) > out2

if diff out1 out2 >/dev/null ; then
	# Put this files path below
	_Path3_ $(($i + 1))
	echo $i
	exit $?
else
	echo "Hello you are wrong!"
	# echo $i
	exit 0
fi
