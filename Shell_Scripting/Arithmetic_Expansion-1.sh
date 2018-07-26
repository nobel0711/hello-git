
#!/bin/sh
echo -n "Enter your Score: "
read score
if [ $(($score>=60)) -eq 1 ]; then
#if [ $score -ge 60 ]; then
	echo passed
else
	echo failed
fi

