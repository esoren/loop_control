/*
 * motorcontrol.c
 *
 *  Created on: Jan 25, 2019
 *      Author: esoren
 */


#include "gpio.h"
#include "stm32f4xx_hal.h"
#include "main.h"
#include "motorcontrol.h"
#include "dwt_stm32_delay.h"

void enable_motor_driver(void) {
	HAL_GPIO_WritePin(MOTOR_EN_GPIO_Port, MOTOR_EN_Pin, GPIO_PIN_SET);
}

void disable_motor_driver(void) {
	HAL_GPIO_WritePin(MOTOR_EN_GPIO_Port, MOTOR_EN_Pin, GPIO_PIN_RESET);
}


void set_motor_dir(uint8_t motor_dir) {
	if(motor_dir == 0) {
		HAL_GPIO_WritePin(MOTOR_DIR_GPIO_Port, MOTOR_DIR_Pin, GPIO_PIN_RESET);
	} else {
		HAL_GPIO_WritePin(MOTOR_DIR_GPIO_Port, MOTOR_DIR_Pin, GPIO_PIN_SET);
	}
}

void send_motor_steps(uint32_t step_count, uint32_t delay_in_us) {

	for (uint32_t step = 0; step < step_count; step++) {
		HAL_GPIO_WritePin(MOTOR_STEP_GPIO_Port, MOTOR_STEP_Pin, GPIO_PIN_SET);
		DWT_Delay_us(delay_in_us);
		HAL_GPIO_WritePin(MOTOR_STEP_GPIO_Port, MOTOR_STEP_Pin, GPIO_PIN_RESET);
		DWT_Delay_us(delay_in_us);
	}
}
