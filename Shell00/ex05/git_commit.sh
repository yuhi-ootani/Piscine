#!/bin/bash

#ｰn　5　で直近5個目
#--format="　"はコミットログのどの要素かを指定している
#%H はコミットIDを指定している
git log -n 5 --format="%H"