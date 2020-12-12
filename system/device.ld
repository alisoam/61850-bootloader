ENTRY(Reset_Handler)

HEAP_SIZE  = 0x4000;
STACK_SIZE = 0x800;
VECTOR_RAM_SIZE = 0x400;

MEMORY
{
  m_itcm_vectors        (RX)  : ORIGIN = 0x00000000, LENGTH = 0x00000400
  m_itcm                (RX)  : ORIGIN = 0x00000400, LENGTH = 0x0003FC00
  m_dtcm                (RW)  : ORIGIN = 0x20000000, LENGTH = 0x00040000
  m_ocram               (RW)  : ORIGIN = 0x20200000, LENGTH = 0x00000000
  m_ocram_ncache        (RW)  : ORIGIN = 0x20200000, LENGTH = 0x00080000

  m_flash_config        (RX)  : ORIGIN = 0x60000000, LENGTH = 0x00001000
  m_flash_ivt           (RX)  : ORIGIN = 0x60001000, LENGTH = 0x00001000
  m_flash_vectors       (RX)  : ORIGIN = 0x60002000, LENGTH = 0x00000400
  m_flash               (RX)  : ORIGIN = 0x60002400, LENGTH = 0x000FDC00
}

SECTIONS
{
  __NCACHE_REGION_START = ORIGIN(m_ocram_ncache);
  __NCACHE_REGION_SIZE  = LENGTH(m_ocram_ncache);

  .flash_config :
  {
    . = ALIGN(4);
    __FLASH_BASE = .;
    KEEP(* (.boot_hdr.conf))     /* flash config section */
    . = ALIGN(4);
  } > m_flash_config

  .ivt :
  {
    . = ALIGN(4);
       KEEP(* (.boot_hdr.ivt))           /* ivt section */
       KEEP(* (.boot_hdr.boot_data))     /* boot section */
       KEEP(* (.boot_hdr.dcd_data))      /* dcd section */
    . = ALIGN(4);
  } > m_flash_ivt


  __Vectors = LOADADDR(.vectors);
  __vectors_load_start__ = LOADADDR(.vectors);
  .vectors :
  {
    . = ALIGN(4);
    __VECTOR_TABLE = .;
    __vectors_start__ = .;

    KEEP(*(.isr_vector))

    . = ALIGN(4);
    __vectors_end__ = .;
  } > m_itcm_vectors AT> m_flash_vectors

  .text_flash :
  {
    . = ALIGN(4);

    *(.reset_handler)
    *(.text.Reset_Handler .text.SystemInit .text.SystemInitHook \
      .rodata.Reset_Handler .rodata.SystemInit .rodata.SystemInitHook)

    . = ALIGN(4);
  } > m_flash

  __text_load_start__ = LOADADDR(.text);
  .text :
  {
    . = ALIGN(4);
    __text_start__ = .;

    *(.text .text*)

    *(.glue_7)
    *(.glue_7t)
    *(.eh_frame)
    KEEP (*(.init))
    KEEP (*(.fini))

    . = ALIGN(4); 
    __text_itcm_end__ = .;
  } > m_itcm AT> m_flash

  .ctors :
  {
    __CTOR_LIST__ = .;
    /* gcc uses crtbegin.o to find the start of
       the constructors, so we make sure it is
       first.  Because this is a wildcard, it
       doesn't matter if the user does not
       actually link against crtbegin.o; the
       linker won't look for a file to match a
       wildcard.  The wildcard also means that it
       doesn't matter which directory crtbegin.o
       is in.  */
    KEEP (*crtbegin.o(.ctors))
    KEEP (*crtbegin?.o(.ctors))
    /* We don't want to include the .ctor section from
       from the crtend.o file until after the sorted ctors.
       The .ctor section from the crtend file contains the
       end of ctors marker and it must be last */
    KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*(.ctors))
    __CTOR_END__ = .;
  } > m_itcm AT> m_flash

  .dtors :
  {
    __DTOR_LIST__ = .;
    KEEP (*crtbegin.o(.dtors))
    KEEP (*crtbegin?.o(.dtors))
    KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*(.dtors))
    __DTOR_END__ = .;
  } > m_itcm AT> m_flash

  .preinit_array :
  {
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array*))
    PROVIDE_HIDDEN (__preinit_array_end = .);
  } > m_itcm AT> m_flash

  .init_array :
  {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array*))
    PROVIDE_HIDDEN (__init_array_end = .);
  } > m_itcm AT> m_flash

  .fini_array :
  {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array*))
    PROVIDE_HIDDEN (__fini_array_end = .);
  } > m_itcm AT> m_flash

  .ARM.extab :
  {
    *(.ARM.extab* .gnu.linkonce.armextab.*)
  } > m_itcm AT> m_flash

  .ARM :
  {
    __exidx_start = .;

    *(.ARM.exidx*)

    __exidx_end = .;
    __text_end__ = .;
  } > m_itcm AT> m_flash

  .ncache.init :
  {
    __noncachedata_start__ = .;
    *(NonCacheable.init)
    . = ALIGN(4);
    __noncachedata_init_end__ = .;
  } > m_ocram_ncache
  . = __noncachedata_init_end__;
  .bss_ncache (NOLOAD):
  {
    . = ALIGN(4);
    *(.ncache.bss ncache.bss*)
    *(.enet.bss .enet.bss*)
    *(NonCacheable)
    . = ALIGN(4);
    __noncachedata_end__ = .;
  } > m_ocram_ncache

  __data_load_start__ = LOADADDR(.data);
  .data :
  {
    . = ALIGN(4);
    __data_start__ = .;

    *(.data .data*)
    *(.rodata .rodata*)

    . = ALIGN(4);
    __data_end__ = .;
  } > m_dtcm AT> m_flash

  .bss (NOLOAD):
  {
    . = ALIGN(4);
    __bss_start__ = .;

    *(COMMON)

    *(.bss .bss*)

    . = ALIGN(4);
    __bss_end__ = .;
  } > m_dtcm

  .heap (NOLOAD):
  {
    . = ALIGN(8);
    __heap_base__ = .;
    . += HEAP_SIZE;
    __heap_limit__ = .;
  } > m_dtcm

  .stack (NOLOAD):
  {
    . = ALIGN(8);
    . += STACK_SIZE;
    . = ALIGN(8);
    __StackTop = .;
    _stack_top = .;
  } > m_dtcm

  PROVIDE(__stack = __StackTop);
}
