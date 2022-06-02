#!/bin/sh

mkfifo mypipe-$$

cat mypipe | nc -l mypipe-$$ | /home/jae/cs3157-pub/bin/mdb-lookup-cs3157 > mypipe-$$

rm -f mypipe-$$
