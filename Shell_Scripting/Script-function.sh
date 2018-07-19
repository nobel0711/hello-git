#!/bin/sh
quit=n

f1(){
ls
}

f2(){
ls -al
}

while [ "$quit" != "y" ]; do
    read menu_choice
    case "$menu_choice" in
        a) f1;;
        b) f2;;
        q|Q) quit=y;;
        *) echo "Sorry, choice not recognized.";;
    esac
done

