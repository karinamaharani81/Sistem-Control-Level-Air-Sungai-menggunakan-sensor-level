#include "Level.h"
#include "adc.h"

float baca_level_air() {
    HAL_ADC_Start(&hadc1);
    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK) {
        uint32_t adc_val = HAL_ADC_GetValue(&hadc1);
        float level_cm = ((float)adc_val) * 50.0f / 4095.0f;
        return level_cm;
    }
    return -1;
}
