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
	chmod U=6 g=0 o=0 $user
fi

echo -e $actions

while ( [ 3 -eq 3 ] ) do
read -n 1 B 
clear
echo -e $actions
case "$B" in 
  "1"   )  echo "Будильник добавлен"
			echo "*/1 * * * * mplayer ~/1.mp4 #as" >> $user
			crontab -u $user $user
			#cat $user | grep -v "# " >> $user
			#sed $user -e '/^# /d' $user
			#cat $user
			;; 
  "2"   )  echo "Будильник пока нельзя удалить";;
  "3"   )  cat $user | grep -v "# ";;
esac
done

#sed $user -e '/^#/d' > $user