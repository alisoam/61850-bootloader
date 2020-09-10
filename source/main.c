#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "FreeRTOS.h"
#include "task.h"

#include "board.h"
#include "clock_config.h"
#include "fsl_device_registers.h"
#include "fsl_iomuxc.h"
#include "fsl_ocotp.h"
#include "peripherals.h"
#include "pin_mux.h"


#define BT_FUSE_SEL_OCOTP_ADDRESS 0x06
#define BT_FUSE_SEL_OCOTP_MASK    SRC_SBMR2_BT_FUSE_SEL_MASK

__attribute__((constructor(101))) static void setupHardware() {
  BOARD_ConfigMPU();
  BOARD_InitPins();
  BOARD_BootClockRUN();
  BOARD_InitBootPeripherals();

  CLOCK_EnableClock(kCLOCK_Trace);
  extern void SWO_Init();
  SWO_Init();
}

void USBTask(void* arg) {
  while (true) {
    vTaskDelay(5 * configTICK_RATE_HZ);
    printf("Still Alive.\n");
  }
}

int main()
{
  puts("Programm Started...");
  printf("System clock is %lu\n", SystemCoreClock);

  OCOTP_Init(OCOTP, CLOCK_GetFreq(kCLOCK_IpgClk));
  uint32_t version = OCOTP_GetVersion(OCOTP);
  printf("OCOTP controller version: 0x%08lx\n\n", version);
  uint32_t ocotpBtFuseSel = OCOTP_ReadFuseShadowRegister(OCOTP, BT_FUSE_SEL_OCOTP_ADDRESS);
    printf("The origin value of fuse address 0x%02x is 0x%08lx\n", BT_FUSE_SEL_OCOTP_ADDRESS, ocotpBtFuseSel);
/*  if (0x00U == (ocotpBtFuseSel & BT_FUSE_SEL_OCOTP_MASK)) {
    status_t status  = OCOTP_WriteFuseShadowRegister(OCOTP,
                                                     BT_FUSE_SEL_OCOTP_ADDRESS,
                                                     ocotpBtFuseSel | BT_FUSE_SEL_OCOTP_MASK);
    if (status == kStatus_Success) {
      printf("OCOTP Write operation success!\n");
      printf("The new value is 0x%08lx\n", OCOTP_ReadFuseShadowRegister(OCOTP, BT_FUSE_SEL_OCOTP_ADDRESS));
    } else {
      printf("OCOTP write operation failed. Access deny!\n");
    }
  }*/


  for (unsigned int i = 0; i < 3; i++) {
    boardLedSet(BOARD_LED1 + i, 1);
    for (volatile unsigned int j = 0; j < 10000000; j++)
      ;
    boardLedSet(BOARD_LED1 + i, 0);
  }

 // xTaskCreate(USBTask, "enet", 2*configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);

  vTaskStartScheduler();
  return 1;
}
