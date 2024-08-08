#!/bin/bash

who
echo

echo $SHELL
echo

echo $HOME
echo

uname -a
echo

pwd
echo

users | wc -w
echo

cat /etc/shells
echo

df -h
echo

lscpu
echo

free -h
echo

df -T
echo

ps -e
