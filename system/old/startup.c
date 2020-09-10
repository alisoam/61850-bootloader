void startup() {
  __asm volatile("cpsid i");

  /*unsigned int* loadAddr, * execAddr, * endAddr;

  extern unsigned int __vectors_flash_start__;
  extern unsigned int __vectors_end__;
  extern unsigned int __vectors_start__;
  loadAddr = (unsigned int*)__vectors_flash_start__;
  execAddr = (unsigned int*)__vectors_start__;
  endAddr = (unsigned int*)__vectors_end__;
  while (execAddr < endAddr) {
    *execAddr = *loadAddr;
    execAddr++;
    loadAddr++;
  }
  unsigned int* VTOR = (unsigned int*)(0xE000ED08);
  extern unsigned int __Vectors;
  *VTOR = (unsigned int)&__Vectors;

  extern unsigned int __text_flash_start__;
  extern unsigned int __text_end__;
  extern unsigned int __text_start__;
  loadAddr = &__text_flash_start__;
  execAddr = &__text_start__;
  endAddr = &__text_end__;
  while (execAddr < endAddr) {
    *execAddr = *loadAddr;
    execAddr++;
    loadAddr++;
  }

  extern void SystemInit();
  SystemInit();

  extern unsigned int __data_flash_start__;
  extern unsigned int __data_end__;
  extern unsigned int __data_start__;
  loadAddr = &__data_flash_start__;
  execAddr = &__data_start__;
  endAddr = &__data_end__;
  while (execAddr < endAddr) {
    *execAddr = *loadAddr;
    execAddr++;
    loadAddr++;
  }

  extern unsigned int __bss_start__;
  extern unsigned int __bss_end__;
  execAddr = &__bss_start__;
  endAddr = &__bss_end__;
  while (execAddr < endAddr) {
    *execAddr = 0;
    execAddr++;
  }*/

  extern void __libc_init_array();
  __libc_init_array();

  __asm volatile ("cpsie i");

  extern void _start();
  _start();

}
