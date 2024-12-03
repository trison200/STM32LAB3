/*
 * display.c
 *
 *  Created on: Nov 28, 2024
 *      Author: ADMIN
 */

#include "display.h"

const uint8_t Led7Seg[] = { 0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010,
		0b10000010, 0b11111000, 0b10000000, 0b10010000  };
const int MAX_LED = 4;
  int index_led = 0;

void display7SEG(int num){
	uint8_t led_id = Led7Seg[num];
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, (led_id & 0x01) );
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, ((led_id>>1) & 0x01) );
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, ((led_id>>2) & 0x01) );
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, ((led_id>>3) & 0x01) );
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, ((led_id>>4) & 0x01) );
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, ((led_id>>5) & 0x01) );
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, ((led_id>>6) & 0x01) );
}

void clearAll(){
	HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin |EN2_Pin | EN3_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, a_Pin | b_Pin | c_Pin | d_Pin | e_Pin | f_Pin | g_Pin, SET);
}

int en_pin[4]={ EN0_Pin, EN1_Pin,EN2_Pin,EN3_Pin};

void en_Pin(int number){
	HAL_GPIO_WritePin(GPIOA, en_pin[number] , RESET);
}
int led_buffer [4] = {0 , 0 , 0 , 0};
void update7SEG(int index){
	clearAll();
	switch (index){
	case 0:{
		display7SEG(led_buffer[0]);
		en_Pin(0);
		break;
	}
	case 1:{
			display7SEG(led_buffer[1]);
			en_Pin(1);
			break;
		}
	case 2:{
			display7SEG(led_buffer[2]);
			en_Pin(2);
			break;
		}
	case 3:{
			display7SEG(led_buffer[3]);
			en_Pin(3);
			break;
		}
	default:
		break;
	}
}

void updateLedBuffer(int num1, int num2){
		led_buffer[0] = num1/10;
		led_buffer[1] = num1%10;
		led_buffer[2] = num2/10;
		led_buffer[3] = num2%10;
}

void turnOn(enum LED led)
{
    switch (led)
    {
        case RED1:
        	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 0);
            HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 1);
            HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 1);
            break;
        case RED2:
        	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 0);
            HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 1);
            HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 1);
            break;
        case GREEN1:
        	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 0);
            HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
            HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 1);
            break;
        case GREEN2:
        	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 0);
            HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 1);
            HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 1);
            break;
        case YELLOW1:
        	 HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 0);
            HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
            HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 1);
            break;
        case YELLOW2:
        	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 0);
            HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 1);
            HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 1);
            break;
        default:
            break;
    }
}

void blinking(enum LED led){
	switch (led)
	    {
	        case RED1:
	        	HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
	            HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 1);
	            HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 1);
	            HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
	            HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 1);
	            HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 1);
	            break;
	        case GREEN1:
	        	HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
	            HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
	            HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 1);
	            HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
	            HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 1);
	            HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 1);
	            break;
	        case YELLOW1:
	        	HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
	            HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
	            HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 1);
	            HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
	            HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 1);
	            HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 1);
	            break;
	        default:
	            break;
	    }
}

