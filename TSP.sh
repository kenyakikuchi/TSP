#! /usr/bin/bash

FILENAME="qa194"

: > ./results/${FILENAME}.csv
#for i in `seq 100`
#do
./bin/TSP.out ./datasets/${FILENAME}.tsp 0.00001 0.01 >> ./results/${FILENAME}.csv
#done
