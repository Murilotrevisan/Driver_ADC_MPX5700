/**
 *
 * Zenith EESC USP
 * MPX5700 Pressure sensor Driver
 * Author: Murilo Henrique Pasini Trevisan
 * 22/08/2021
 *
 */

/* INCLUDES */

#include "MPX5700_Driver.h"

/* FUNCTIONS */

error_t MPX5700_init(MPX5700_t mpx) {
	return adc_init(mpx.adc);
}

result16_t MPX5700_get_value(MPX5700_t mpx) {
	return adc_read(mpx.adc);
}

float MPX5700_get_pressure(MPX5700_t mpx) {
	result16_t Bit_Value = MPX5700_get_value(mpx);
	if (Bit_Value.hasError) {
		return -99.f ;
	}
	const int V_Sensor = 5; /* Tensão de alimentação do sensor */
	const float V_Source = 3.3; /* Tensão de alimentação do microcontrolador */

	/* Converte o valor do ADC em bits para tensão na entrada do microcontrolador */
	const float V_in = (4095/ (V_Source) ) * Bit_Value.value;

	/* Converte a tensão de entrada do microcontrolador para a tensão de saida do sensor */
	const float V_out = (V_Source / V_Sensor) * V_in;

	/* Converte tensão de saida do sensor para pressão medida (datasheet) */
	const float Pressure = (( Vout / Vs) - MPX_CONV_SUM) / MPX_CONV_MUL;

	return Pressure;
}
