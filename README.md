####################################################################################
#
#	Nome Programa: happyNumber.c
#	Autor: João Arthur
#	Objetivo: Dado um numero inteiro de entrada verificar se ele eh feliz.
#			- Um numero feliz é aquele que a soma de seus digitos elevados ao quadrado repetidas vezes eh igual a 1.
#	Ex: 
#		Entrada: 7
#				7² = 49
#				4² + 9² = 97
#				9² + 7² = 130
#				1² + 3² + 0² = 10
#				1² + 0² = 1	
#		Saida: Eh Feliz.
#	Versionamento:
#	1.0: Criação. Resp.: João Arthur
#	
#	Parâmetros de execução
#	./happyNumber
#####################################################################################


####################################################################################
#
#	Requisitos: gcc versão 6.3.0.
#	Instalação: Compilar com gcc conforme abaixo.
# 				gcc -g -Wall -o happyNumber happyNumber.c
#				Obs: Se estiver no Linux, pode usar o shell compilar.sh 
#
#	Uso: executar o programa e esperar os retornos em tela para inserir os 
#		 valores necessarios.
####################################################################################

####################################################################################
#
#	Testes Automatizados: 
#	Requisitos: Rodar em Linux 
#	Instalação: Baixar o arquivo testeHappy.sh e deixar no mesmo diretório do binario.
#				Criar um arquvio de configuracao com um cenario por linha com o numero 
#				a ser testado e o resultado esperado separados por ";"
#				Ex: 7;O Numero 7, eh um Happy Number.
#					8;O Numero 8, nao eh um Happy Number.
#
#
#	Uso: executar o Shell passando o arquivo de configuração como parametro
#		Ex:./testeHappy.sh cenariosHappy.conf
#
#	Resultados: Ira imprimir o numero do cenario seguido de "Passou" caso sucesso 
#				ou "Falhou". Caso falha ainda imprime o resultado esperado 
#				e o resultado obitido.
####################################################################################