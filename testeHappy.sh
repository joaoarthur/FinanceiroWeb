#!/bin/bash

cenarios=$1

if [[ ! -f $cenarios ]] ; then
   echo "Arquivo de configuracao $1 nao existe."
   exit -1
fi

typeset -i numCenario=0
cat $cenarios | while read cen
do
	numCenario=$(($numCenario+1))
	cenario=`echo $cen | cut -d\; -f1`
	resultado=`echo $cen | cut -d\; -f2`
	echo $cenario | ./happyNumber | tail -1 | cut -d\: -f2 | while read result
	do
		if [[ $result == $resultado ]]
		then
			echo "Cenario $numCenario: Passou"
		else 
			echo "Cenario $numCenario: Falhou <----> Esperado |$resultado| <----> retornado |$result|"
		fi
	done
done
	