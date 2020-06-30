#!/usr/bin/env bash

while ((1)); do
	if [[ "$1" == "new" ]]
	then
		./generator --big-superposition > map
	fi
	./lem-in < map || exit 1
done
