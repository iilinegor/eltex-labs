#!bin/bash
cd /var/spool/cron/crontabs/
if [ -f ${HOME:6} ];
	then
	echo "Есть файл" ${HOME:6}
fi
if ! [ -f ${HOME:6} ];
	then
	echo "Нет файла" ${HOME:6}
fi