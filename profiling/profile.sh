#!/bin/bash

[ -z "$1" ] && echo "give me a filename to write out to"

FILES=$(find . -iname '*.c')

for f in FILES
do
	echo $f >> $1
	../amacc $f >> $1
done
