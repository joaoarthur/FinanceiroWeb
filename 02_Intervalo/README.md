####################################################################################
#
#	Nome Programa: intervalo.c
#	Autor: João Arthur
#	Objetivo: Coletar um conjunto de valores inteiros e imprimir ordenadamente 
#			separado por intervalos.
#	Ex: 
#		Entrada: 10,22,9,5,7,21,6,23,8,1,19,17,100,20	
#		Saida: [1],[5-10],[17],[19-23],[100]
#	Versionamento:
#	1.0: Criação. Resp.: João Arthur
#	
#	Parâmetros de execução
#	./intervalo
####################################################################################

####################################################################################
#
#	Requisitos: gcc versão 6.3.0.
#	Instalação: Compilar com gcc conforme abaixo.
# 				gcc -g -Wall -o intervalo intervalo.c
#				Obs: Se estiver no Linux, pode usar o shell compilar.sh 
#
#	Uso: executar o programa e esperar os retornos em tela para inserir os 
#		 valores necessarios.
####################################################################################

####################################################################################
#
#	Testes Automatizados: 
#	Requisitos: Rodar em Linux 
#	Instalação: Baixar o arquivo testeIntervalo.sh e deixar no mesmo diretório do binario.
#				Criar um arquvio de configuracao com um cenario por linha com os valores 
#				a serem testados e o resultado esperado separados por ";".
#				Os valores devem ser separados por "," e o Resultado deve estar no padrao
#				[d-d],[d] onde d é o numero.
#				Ex: 10,30,40,32,66,62,54,71,171;[10],[30],[32],[40],[54],[62],[66],[71],[171]
#
#
#	Uso: executar o Shell passando o arquivo de configuração como parametro
#		Ex:./testeIntervalo.sh cenariosIntervalo.conf
#
#	Resultados: Ira imprimir o numero do cenario seguido de "Passou" caso sucesso 
#				ou "Falhou". Caso falha ainda imprime o resultado esperado 
#				e o resultado obitido.
####################################################################################