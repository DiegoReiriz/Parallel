#!/bin/sh
#SBATCH -N 1 # solicitamos 1 nodos
#SBATCH -t 00:00:10 # solicitamos 10 segundos de ejecución (mandatory)
srun ./main.out

