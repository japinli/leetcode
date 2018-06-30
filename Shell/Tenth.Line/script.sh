#!/bin/bash

sed -n '10p' file.txt

awk 'NF == 10' file.txt

tail -n+10 file.txt | head -1

