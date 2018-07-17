#!/bin/sh
echo "Is this morning? Please answer yes or no."
read answer
case "$answer" in
    yes | y | Yes | YES) echo "Good morning!";;
    no | n | No | NO) echo "Good afternoon!";;
    *) echo "Sorry, answer not recognized.";;
esac
exit 0

