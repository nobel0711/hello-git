#!/bin/sh
echo "Is this morning? Please answer yes or no. "
read answer
if [ "$answer" = "yes" ]; then
    echo "Good morning"
elif [ "$answer" = "no" ]; then
    echo "Good afternoon"
else
    echo "Sorry, $answer not recognized. Enter yes or no."
    exit 1
fi
exit 0
