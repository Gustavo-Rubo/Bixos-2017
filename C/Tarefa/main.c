/**
 * Processo Seletivo 2017 - main.c
 *
 * Equipe ThundeRatz de Robótica
 * 03/2017
 */

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "sensors.h"
#include "motors.h"
#include <math.h> //precisamos fazer contas

int main() {
	sensors_init();
	motors_init();
	sei();
	wdt_reset();
	wdt_disable();
	
	/*
	  A seguinte estratégia toma inspiração na prova de cabo de guerra da naval.
	  Consiste em, conhecendo o tamanho da arena e conhecendo a posição inicial
	  do robô, que este fosse para o canto, esperasse o outro se aproximar, e então
	  saísse do caminho, deixando o oponente em uma posição vulnerável, com sua
	  traseira pronta para ser atacada, em um movimento que eu chamo de 'crau'.
	*/
	
	int raio_arena = 50; //assumindo um valor pro raio do campo
	int pos[] = [-20, 0]; //assumindo a posição inicial do robo (em coordenadas)
	//assume-se que o robô inicia a competição virado de frente para o adversário.
	
	int raio_pos = sqrt(pow(pos[0], 2) + pow(pos[1], 2));
	
	for (int i = raio_pos; i < raio_arena; i++) {
		//nota: assume-se aqui uma unidade de tempo e uma unidade de distancia,
		//as quais só podem ser obtidas experimentalmente.
		motors(-255, -255);
		_delay_ms(10);
	}
	
	
	
	for (;;) {
		
		

		_delay_ms(10);
	}
	
	/*
	  Comentários sobre a estratégia:
	  O grande ponto negativo é que precisamos assumir muita coisa, e faz muita falta
	  algum método de conhecer a posição do robô dentro da arena. É necessário também
	  saber qual é a duração de um 'passo' do robô, ou seja, qual a unidade de tempo
	  que ele leva para andar uma unidade de espaço, com os motores em operação total.
	  Seria conveniente também um meio de temporariamente desligar os eletroímãs que
	  prendem o robô à arena, de forma a tornar este mais rápido.
	  
	  Contra outras estratégias:
	  -muito eficiente contra um algoritmo que te segue em linha reta a todos os momentos,
	   salvo quando o oponente é muito mais rápido
	  -se o oponente não se aproximar o suficiente, nada acontecerá.
	*/

	return 0;
}
