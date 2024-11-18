#!/bin/sh

#findコマンドは現在のディレクトリ（drwxr-xr-x 2 oyuhi 2024_tokyo 62  9月  3 16:39 .）もカウントするため、ファイルの数が通常ファイルより数が多くなる
#find . ：　現在のディレクトリから見つけるコマンド
#wc -l : wc = word countの略で文字数を数えるコマンド　-l = 行数をカウントするオプション


find . | wc -l | awk '{print $1}'
