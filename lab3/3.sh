#!/bin/bash
# Текст меню #
target="Выберите цель:\n\n[0] Удалённый сервер\n[1] Репозиторий\n[2] Ветка\n[3] Файл\n[4] Коммит\n"
server="Что сделать?\n\n[1] Добавить\n[2] Удалить\n[3] Назад\n"
repo="Что сделать?\n\n[1] Создать\n[2] Удалить\n[3] Клонировать\n[4] Назад\n"
branch="Что сделать?\n\n[1] Создать\n[2] Удалить\n[3] Перейти\n[4] Показать все\n[5] Назад\n"
files="Что сделать?\n\n[1] Добавить\n[2] Удалить\n[3] Назад\n"
commit="Что сделать?\n\n[1] Создать\n[2] Редактировать\n[3] Назад\n"
A=0;

clear

echo -e $target

while ( [ 3 -eq 3 ] ) do
read -n 1 B 
clear
echo -e $target

# Считываем команду # 
case "$B" in 

  "0"   )  
			clear
			echo -e $server

			while ( [ 0 -eq 0 ] ) do
				read -n 1 C 
				clear
				echo -e $server
				case "$C" in 
				  "1"   )
							echo "Какой адрес у удалённого репозитория?"
							read line
							git remote add $line
						;;

				  "2"   )
							echo "Какой адрес у удалённого репозитория?"
							read line
							git remote rm $line
						;;

				  "3"   )							
							break
						;;
				esac
			done
			clear
			echo -e $target
			;; 

  "1"   )  
			clear
			echo -e $repo

			while ( [ 0 -eq 0 ] ) do
				read -n 1 C 
				clear
				echo -e $repo
				case "$C" in 
				  "1"   )
							git init
						;;

				  "2"   )
							echo "Репозиторий удалён"
							rm -rf .git
						;;

				  "3"   )
							echo "Введите адрес репозитория"
							read line
							git clone $line
						;;

				  "4"   )
							break
						;;
				esac
			done
			clear
			echo -e $target
			;;
			
  "2"   )   
			clear
			echo -e $branch

			while ( [ 0 -eq 0 ] ) do
				read -n 1 C 
				clear
				echo -e $branch
				case "$C" in 
				  "1"   )
							echo "Как будет называться ветка?"
							read line
							git branch -l $line
						;;

				  "2"   )
							git branch -a
							echo "Какую ветку удалить?"
							read line
							git branch -D $line
						;;

				  "3"   )
							git branch -a
							echo "К какой ветке перейти?"
							read line
							git branch -M $line
						;;

				  "4"   )
							git branch -a
						;;

				  "5"   )
							break
						;;
				esac
			done
			clear
			echo -e $target
			;;
			
  "3"   )   
			clear
			echo -e $files

			while ( [ 0 -eq 0 ] ) do
				read -n 1 C 
				clear
				echo -e $files
				case "$C" in 
				  "1"   )
							echo "Укажите файл для добавления"
							read line
							git add $line
						;;

				  "2"   )
							echo "Укажите файл для удаления"
							read line
							git rm -rf $line
						;;

				  "3"   )
							break
						;;
				esac
			done
			clear
			echo -e $target
			;;
			
  "4"   )   
			clear
			echo -e $commit

			while ( [ 0 -eq 0 ] ) do
				read -n 1 C 
				clear
				echo -e $commit
				case "$C" in 
				  "1"   )
							echo "Введите комментарий"
							read line
							git commit -m "${line}"
						;;

				  "2"   )
							echo "Введите новый комментарий"
							read line
							git commit -m "${line}"
						;;

				  "3"   )
							break
						;;
				esac
			done
			clear
			echo -e $target
			;;
esac
done