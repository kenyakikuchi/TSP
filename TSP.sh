#! /usr/bin/bash

: > log.csv
#for i in `seq 100`
#do
./TSP.out mona-lisa100K.tsp 0.001 0.01 >> log.csv
#done
