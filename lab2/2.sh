#!/bin/bash
# Текст меню #
actions="Выберите действие:\n[1] Добавить будильник\n[2] Удалить будильник&\n[3] Посмотреть существующие будильники\n"
clear

echo -e $actions

while ( [ 3 -eq 3 ] ) do
read -n 1 B 
clear
echo -e $actions

# Считываем команду # 
case "$B" in 
# Добавление нового будильника #  
  "1"   )  
			h=99
			m=99
			# Валидируем ввод # 
			while (( $h > 24 || $h < 0));
			do
				echo "Введите час сигнала будильника"
				read h
				if [ -z $h ]; then
					h=7
				fi
				# приводим к формату 00 # 
				if [ ${#h} -eq 1 ]; then
					h=0$h
				fi
			done
			while (( $m > 59 || $m < 0));
			do
				echo "Введите минуты сигнала будильника (по умолчанию 00)"
				read m
				if [ -z $m ]; then
					m=0
				fi

				if [ ${#m} -eq 1 ]; then
					m=0$m
				fi
			done
			echo "Введите файл сигнала будильника (по умолчанию ~/1.mp4)"
			read song
				if [ -z $song ]; then
					song="~/1.mp4"
				fi
			echo "Будильник добавлен на $h:$m"
			crontab -u $USER -l > ./tmp
			echo "$m $h * * * mplayer $song #as" >> ./tmp
			crontab -u $USER ./tmp

			;; 
# Удаление будильника #
  "2"   )  
			i=0 # счётчик
			# выводим нумерованный список будильников #
			crontab -u $USER -l | grep -v "# " | grep "#as" > ./list.tmp
			while read line
			do
			echo "[$i] Будильник на ${line:3:2}:${line:0:2}"
			((i++))
			done < ./list.tmp

			# получаем номер будильника
			echo "Введите номер будильника"
			read C

			clear

			i=0
			# удаляем из crontab выбранный будильник
			echo -n > ./tmp
			while read line
			do
			if ! [ $i -eq $C ]
			then
				echo "[$i] Будильник на ${line:3:2}:${line:0:2}"
				echo "$line" >> ./tmp
			else
				echo "[*] Будильник на ${line:3:2}:${line:0:2}"
			fi
				((i++))
			done < ./list.tmp
			crontab -u $USER -l | grep -v "#as" | grep -v "# "> ./list.tmp
			cat ./tmp >> ./list.tmp
			crontab -u $USER ./list.tmp
			;;
  "3"   )   crontab -u $USER -l | grep -v "# " | grep "#as" > ./tmp
			while read line
			do
				echo "Будильник на ${line:3:2}:${line:0:2}"
			done < ./tmp
			;;
esac
	# чистим временные файлы 
	rm -rf ./tmp ./list.tmp ./count	
done
