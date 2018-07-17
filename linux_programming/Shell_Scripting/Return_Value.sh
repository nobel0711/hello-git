#!/bin/sh
if grep "abc" file
then
	echo file contains abc
else
	echo file doesn\'t contain abc
fi
grep abc file
echo return code is $?
exit 0

