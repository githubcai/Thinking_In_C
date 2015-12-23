#!/bin/bash

value=""

for args in $@
do
	value=${value}" "${args}
done

g++ ${value} -lZThread
