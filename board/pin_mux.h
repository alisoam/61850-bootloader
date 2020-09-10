/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/* GPIO_SD_B0_04 (coord H2), LED1 */
#define BOARD_INITPINS_LED1_GPIO                                           GPIO3   /*!< GPIO device name: GPIO3 */
#define BOARD_INITPINS_LED1_PORT                                           GPIO3   /*!< PORT device name: GPIO3 */
#define BOARD_INITPINS_LED1_PIN                                              16U   /*!< GPIO3 pin index: 16 */

/* GPIO_SD_B0_00 (coord J4), LED2 */
#define BOARD_INITPINS_LED2_GPIO                                           GPIO3   /*!< GPIO device name: GPIO3 */
#define BOARD_INITPINS_LED2_PORT                                           GPIO3   /*!< PORT device name: GPIO3 */
#define BOARD_INITPINS_LED2_PIN                                              12U   /*!< GPIO3 pin index: 12 */

/* GPIO_SD_B0_03 (coord K1), LED3 */
#define BOARD_INITPINS_LED3_GPIO                                           GPIO3   /*!< GPIO device name: GPIO3 */
#define BOARD_INITPINS_LED3_PORT                                           GPIO3   /*!< PORT device name: GPIO3 */
#define BOARD_INITPINS_LED3_PIN                                              15U   /*!< GPIO3 pin index: 15 */

/* GPIO_B0_08 (coord B9), ENET2_RST */
#define BOARD_INITPINS_ENET2_RST_GPIO                                      GPIO2   /*!< GPIO device name: GPIO2 */
#define BOARD_INITPINS_ENET2_RST_PORT                                      GPIO2   /*!< PORT device name: GPIO2 */
#define BOARD_INITPINS_ENET2_RST_PIN                                          8U   /*!< GPIO2 pin index: 8 */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/