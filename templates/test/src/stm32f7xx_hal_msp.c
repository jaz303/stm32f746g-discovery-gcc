#include "stm32f7xx_hal.h"

/**
  * @brief  Initializes the Global MSP.
  * @retval None
  */
void HAL_MspInit(void)
{
    GPIO_InitTypeDef gpioConfig;
    gpioConfig.Pin = GPIO_PIN_1;
    gpioConfig.Mode = GPIO_MODE_OUTPUT_PP;
    gpioConfig.Pull = GPIO_NOPULL;
    gpioConfig.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOI, &gpioConfig);
}

/**
  * @brief  DeInitializes the Global MSP.  
  * @retval None
  */
void HAL_MspDeInit(void)
{

}

/**
  * @brief  Initializes the PPP MSP.
  * @retval None
  */
void HAL_PPP_MspInit(void)
{
 
}

/**
  * @brief  DeInitializes the PPP MSP.  
  * @retval None
  */
void HAL_PPP_MspDeInit(void)
{

}
