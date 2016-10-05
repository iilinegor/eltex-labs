#!/bin/bash

if ! [ -z "$1" ]; then
echo "target directory:"$1
if ! [ -d $1 ]; then
mkdir $1
fi
cd $1
fi


for ((i = 1; i <= 5; i++))
do
        mkdir "folder"$i
        cd "folder"$i
        for ((j = 1; j <= 10; j++))
        do
                mkdir "subfolder"$j
                cd "subfolder"$j
                for ((k = 1; k <= 20; k++))
                do
                        touch "file"$k
                done
                cd ../
        done
        cd ../
done
echo "done!"
exit 0

