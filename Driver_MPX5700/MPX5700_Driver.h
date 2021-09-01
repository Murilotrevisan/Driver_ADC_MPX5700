/**
 *
 * Zenith EESC USP
 * MPX5700 Pressure sensor Driver
 * Author: Murilo Henrique Pasini Trevisan
 * 22/08/2021
 *
 */

/* DEFINES */

#ifndef MPX5700_ADC_DRIVER_H
#define MPX5700_ADC_DRIVER_H

/* INCLUDES */

#include "bsp.h"

/*SENSOR STRUCT*/

typedef struct {
	adc_t* adc;
} MPX5700_t;

/* FUNCTIONS */

error_t MPX5700_init(MPX5700_t mpx);
result16_t MPX5700_get_value(MPX5700_t mpx);
float MPX5700_get_pressure(MPX5700_t mpx);

/* CONVERSÂO AD -> PRESSURE */

#define MPX_CONV_SUM (float)(0.04);
#define MPX_CONV_MUL (float)(0.0012858);


#endif /* MPX5700_ADC_DRIVER_H */
