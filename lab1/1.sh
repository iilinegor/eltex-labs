#!/bin/bash



echo "Введите имя начальной директории"
read A
echo "Введите шаблон имени дочерних директорий"
read B
echo "Введите количество дочерних директорий"
read C
echo "Введите шаблон имени вложенных директорий"
read D
echo "Введите количество вложенных директорий"
read E
echo "Введите шаблон имени файлов"
read F
echo "Введите количество файлов"
read G


if ! [ -z $A ]; then
A="./"
echo "Начало: "$A
if ! [ -d $A ]; then
mkdir $A
fi
cd $A
fi


for ((i = 1; i <= $C; i++))
do
        mkdir $B$i
        cd $B$i
        for ((j = 1; j <= $E; j++))
        do
                mkdir $D$j
                cd $D$j
                for ((k = 1; k <= $G; k++))
                do
                        touch $F$k
                done
                cd ../
        done
        cd ../
done
echo "done!"
exit 0

