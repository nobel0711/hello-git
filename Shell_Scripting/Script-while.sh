#!/bin/sh
quit=n
while [ "$quit" != "y" ]; do
    read menu_choice
    case "$menu_choice" in
        a) ls;;
        b) ls -al;;
        q|Q) quit=y;;
        *) echo "Sorry, choice not recognized.";;
    esac
done

