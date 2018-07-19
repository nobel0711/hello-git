#!/bin/sh
i=0
echo $0 #script name
echo $# #number of argument
for arg in $@
do
	echo $i: $arg
	#i=$(($i+1))
	#i=$(expr $i + 1) # space required
	i='expr $i + 3' # space required
done

