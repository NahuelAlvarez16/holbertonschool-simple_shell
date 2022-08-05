# C - Simple Shell
## Description
*Second Holberton School group project.
*This project consists in replicating how a Linux Shell works.

## Introduction
A Unix shell is a command line interpreter that provides a user interface for Unix-like operating systems. The shell is both an interactive command language and a scripting language, and is used by the operating system to control system execution through shell scripts.

## Environment of our Simple Shell
-   Language: C
-   Editor: VIM
-   Compile mode: gcc Wall -Werror -Wextra -pedantic -std=gnu89 -g
-   Style rules:  [Betty style](https://github.com/holbertonschool/Betty/wiki)

## What is the PATH
PATH is a list of directories that a computer searches to find a requested or built-in executable command.

## Test
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Our built-ins:

| Built-in | Description |
|--|--|
| env | Print system environment variables |
|exit | Exit 

## Test Valgrind
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --show-leak-kinds=all -s ./hsh

## Interactive mode
gets:
![enter image description here](https://i.imgur.com/9Tg3oBH.png)
ls: List information about the files

pwd: command writes to standard output the full path name of your current directory

exit: is used to exit from the current shell

Input: `$ ls`, `$ pwd`, `$ exit`  


## Examples of commands in non-interactive mode what they do

![enter image description here](https://i.imgur.com/FUSED3J.png)
![enter image description here](https://i.imgur.com/IJb0jwp.png)
ls -la: List long format including hidden files

env: print a list of the current environment variables or run another program in a custom environment without modifying the current one

Input:`$ echo "ls -la /var"`,  `$ echo "env" | ./hsh,`

## Flowchart

![enter image description here](https://i.imgur.com/g3l1VNH.png)

##  Contributors
[Nahuel Alvarez](https://github.com/NahuelAlvarez16) and [Santiago Rodriguez](https://github.com/santirodriguezzz) from the 18th cohort - Holberton School.
