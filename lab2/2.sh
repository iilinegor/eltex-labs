#!bin/bash
user=${HOME:6}
actions="Выберите действие:\n[1] Добавить будильник\n[2] Удалить будильник&\n[3] Посмотреть существующие будильники\n"
clear


if [ -d /var/spool/cron/crontabs/ ];
then
	cd /var/spool/cron/crontabs/
else
	echo "Проверьте наличие утилиты cron"
fi


if ! [ -f $user ];
then
	touch $user
	chown $user $user
	chgrp crontab $user
	chmod 600 $user
fi

echo -e $actions

while ( [ 3 -eq 3 ] ) do
read -n 1 B 
clear
echo -e $actions
case "$B" in 
  "1"   )  
			h=99
			m=99
			while (( $h > 24 || $h < 0));
			do
				echo "Введите час сигнала будильника"
				read h
			done
			while (( $m > 59 || $m < 0));
			do
				echo "Введите минуты сигнала будильника (по умолчанию 00)"
				read m
				if [ -z $m ]; then
					m=0
				fi
			done
			echo "Введите файл сигнала будильника (по умолчанию ~/1.mp4)"
			read song
				if [ -z $song ]; then
					song="~/1.mp4"
				fi

			echo "Будильник добавлен на $h:$m"
			d=1
			if (( ${#m} < 2)); then
				echo " $m $h * * * mplayer $song #as" >> $user
			else
				echo "$m $h * * * mplayer $song #as" >> $user
			fi

			cat $user | grep -v "# " > tmp
			echo -n > $user
			crontab -u $user tmp
			echo -n > tmp
			;; 
  "2"   )  
			i=0
			cat $user | grep -v "# " | grep "#as" > list.tmp
			while read line
			do
			echo "[$i] Будильник на ${line:2:2}:${line:0:2}"
			((i++))
			done < list.tmp

			echo "Введите номер будильника"
			read C

			clear

			i=0
			echo -n > tmp

			while read line
			do
			if ! [ $i -eq $C ]
			then
				echo "[$i] Будильник на ${line:2:2}:${line:0:2}"
				echo "$line" >> tmp
			else
				echo "[*] Будильник на ${line:2:2}:${line:0:2}"
			fi
				((i++))
			done < list.tmp
			cat $user | grep -v "#as" | grep -v "# "> list.tmp
			cat tmp >> list.tmp
			crontab -u $user list.tmp
			echo -n > tmp
			;;
  "3"   )  cat $user | grep -v "# " | grep "#as" > tmp
			while read line
			do
				echo "Будильник на ${line:2:2}:${line:0:2}"
			done < tmp
			;;
esac
	rm -rf tmp list.tmp count	
done
