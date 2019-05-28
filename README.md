# TSP
verify PAC learnability of TSP

# DIRECTORY STRUCTURE
TSP/  
+--includes/  
|  +--Fisher_Yates.h  
|  +--Nodes.h  
|  +--TSP.h  
|  +--resources.h  
+--sources/  
|  +--Fisher_Yates.cpp  
|  +--Nodes.cpp  
|  +--TSP.cpp  
|  +--main.cpp  
+--objects/  
|  +--*.o  
+--bin/  
|  +--TSP.out  
+--datasets/  
|  +--*.tsp  
+--results/  
|  +--*.csv  
+--README.md  
+--TSP.sh  
+--makefile

# SETUP
$ make

# HOW TO USE
1. modify "FILENAME" of TSP.sh
2. $ sh TSP.sh
3. $(FILENAME).csv is created on TSP/results/
