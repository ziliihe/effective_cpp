#!/bin/bash
set -e

if [ ! -d "out" ]; then
  mkdir out
fi

echo "------------------- [ item 02 result ] ---------------------------"
g++ -E main.cpp -o out/item02.pre

cat -n out/item02.pre | grep -E "1.1413|AspectRatio" 

echo "------------------------------------------------------------------"
g++ effective.cpp main.cpp -o out/item02

out/item02
