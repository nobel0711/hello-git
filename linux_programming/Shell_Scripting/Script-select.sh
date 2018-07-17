#!/bin/sh
clear
select item in Continue Finish Test
do
    case "$item" in
        Continue) ;;
        Finish) break ;;
	Test) ls;;
        *) echo "Wrong choice! Please select again!";;
    esac
done

