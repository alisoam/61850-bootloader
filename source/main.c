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

#define APPLICATION               0x60100000

__attribute__((constructor(101))) static void setupHardware() {
  BOARD_ConfigMPU();
  BOARD_InitPins();
  BOARD_BootClockRUN();
  BOARD_InitBootPeripherals();
}

void startApplication()
{
  uint32_t* stackPtrUA  = (uint32_t*)APPLICATION;
  uint32_t* startPtrVUA = (uint32_t*)APPLICATION;
  startPtrVUA += 1;
  uint32_t startVUA = *startPtrVUA;

  startVUA |= 1;
  void (*application)() = (void (*)())startVUA;
  __set_MSP( *stackPtrUA );
  __ISB();
  application();
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

  startApplication();

  vTaskStartScheduler();
  return 1;
}
