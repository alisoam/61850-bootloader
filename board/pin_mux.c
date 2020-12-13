/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v8.0
processor: MIMXRT1062xxxxA
package_id: MIMXRT1062DVL6A
mcu_data: ksdk2_0
processor_version: 8.0.3
pin_labels:
- {pin_num: K1, pin_signal: GPIO_SD_B0_03, label: LED3, identifier: LED3}
- {pin_num: J4, pin_signal: GPIO_SD_B0_00, label: LED2, identifier: LED2}
- {pin_num: H2, pin_signal: GPIO_SD_B0_04, label: LED1, identifier: LED1}
- {pin_num: B9, pin_signal: GPIO_B0_08, label: ENET2_RST, identifier: ENET2_RST}
- {pin_num: H10, pin_signal: GPIO_AD_B0_01, label: LED1, identifier: LED1}
- {pin_num: M11, pin_signal: GPIO_AD_B0_02, label: LED2, identifier: LED2}
- {pin_num: C14, pin_signal: GPIO_B1_14, label: LED3, identifier: LED3}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: G13, peripheral: ARM, signal: arm_trace_swo, pin_signal: GPIO_AD_B0_10}
  - {pin_num: H10, peripheral: GPIO1, signal: 'gpio_io, 01', pin_signal: GPIO_AD_B0_01, direction: OUTPUT}
  - {pin_num: M11, peripheral: GPIO1, signal: 'gpio_io, 02', pin_signal: GPIO_AD_B0_02, direction: OUTPUT}
  - {pin_num: C14, peripheral: GPIO2, signal: 'gpio_io, 30', pin_signal: GPIO_B1_14, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           /* iomuxc clock (iomuxc_clk_enable): 0x03U */

  /* GPIO configuration of LED1 on GPIO_AD_B0_01 (pin H10) */
  gpio_pin_config_t LED1_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_B0_01 (pin H10) */
  GPIO_PinInit(GPIO1, 1U, &LED1_config);

  /* GPIO configuration of LED2 on GPIO_AD_B0_02 (pin M11) */
  gpio_pin_config_t LED2_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_B0_02 (pin M11) */
  GPIO_PinInit(GPIO1, 2U, &LED2_config);

  /* GPIO configuration of LED3 on GPIO_B1_14 (pin C14) */
  gpio_pin_config_t LED3_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_B1_14 (pin C14) */
  GPIO_PinInit(GPIO2, 30U, &LED3_config);

  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_01_GPIO1_IO01,        /* GPIO_AD_B0_01 is configured as GPIO1_IO01 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_02_GPIO1_IO02,        /* GPIO_AD_B0_02 is configured as GPIO1_IO02 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_10_ARM_TRACE_SWO,     /* GPIO_AD_B0_10 is configured as ARM_TRACE_SWO */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_B1_14_GPIO2_IO30,           /* GPIO_B1_14 is configured as GPIO2_IO30 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_GPR->GPR26 = ((IOMUXC_GPR->GPR26 &
    (~(BOARD_INITPINS_IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL_MASK))) /* Mask bits to zero which are setting */
      | IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL(0x00U) /* GPIO1 and GPIO6 share same IO MUX function, GPIO_MUX1 selects one GPIO function: 0x00U */
    );
  IOMUXC_GPR->GPR27 = ((IOMUXC_GPR->GPR27 &
    (~(BOARD_INITPINS_IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL_MASK))) /* Mask bits to zero which are setting */
      | IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL(0x00U) /* GPIO2 and GPIO7 share same IO MUX function, GPIO_MUX2 selects one GPIO function: 0x00U */
    );
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
