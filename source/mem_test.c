#include "mem_tests.h"
/* Walking 0 memory test */
bool mem_test_walking0(MEM_TEST_SETUP_T *pMemSetup)
{
  int i = 0;
  uint32_t fbytes = pMemSetup->bytes, *addr = pMemSetup->start_addr;

  /* Must be 32-bit algined */
  if ((((uint32_t)addr & 0x3) != 0) || ((fbytes & 0x3) != 0))
  {
    return false;
  }

  /* Write walking 0 pattern */
  while (fbytes > 0)
  {
    *addr = ~(1 << i);

    addr++;
    fbytes -= 4;
    i++;
    if (i >= 32)
    {
      i = 0;
    }
  }

  /* Verify walking 0 pattern */
  i = 0;
  fbytes = pMemSetup->bytes;
  addr = pMemSetup->start_addr;
  while (fbytes > 0)
  {
    if (*addr != ~(1 << i))
    {
      pMemSetup->fail_addr = addr;
      pMemSetup->is_val = *addr;
      pMemSetup->ex_val = ~(1 << i);
      return false;
    }

    addr++;
    fbytes -= 4;
    i++;
    if (i >= 32)
    {
      i = 0;
    }
  }

  return true;
}

/* Walking 1 memory test */
bool mem_test_walking1(MEM_TEST_SETUP_T *pMemSetup)
{
  int i = 0;
  uint32_t fbytes = pMemSetup->bytes, *addr = pMemSetup->start_addr;

  /* Must be 32-bit algined */
  if ((((uint32_t)addr & 0x3) != 0) || ((fbytes & 0x3) != 0))
  {
    return false;
  }

  /* Write walking 1 pattern */
  while (fbytes > 0)
  {
    *addr = (1 << i);

    addr++;
    fbytes -= 4;
    i++;
    if (i >= 32)
    {
      i = 0;
    }
  }

  /* Verify walking 1 pattern */
  i = 0;
  fbytes = pMemSetup->bytes;
  addr = pMemSetup->start_addr;
  while (fbytes > 0)
  {
    if (*addr != (1 << i))
    {
      pMemSetup->fail_addr = addr;
      pMemSetup->is_val = *addr;
      pMemSetup->ex_val = (1 << i);
      return false;
    }

    addr++;
    fbytes -= 4;
    i++;
    if (i >= 32)
    {
      i = 0;
    }
  }

  return true;
}

/* Address memory test */
bool mem_test_address(MEM_TEST_SETUP_T *pMemSetup)
{
  uint32_t fbytes = pMemSetup->bytes, *addr = pMemSetup->start_addr;

  /* Must be 32-bit algined */
  if ((((uint32_t)addr & 0x3) != 0) || ((fbytes & 0x3) != 0))
  {
    return false;
  }

  /* Write address for memory location */
  while (fbytes > 0)
  {
    *addr = (uint32_t)addr;

    addr++;
    fbytes -= 4;
  }

  /* Verify address for memory location */
  fbytes = pMemSetup->bytes;
  addr = pMemSetup->start_addr;
  while (fbytes > 0)
  {
    if (*addr != (uint32_t)addr)
    {
      pMemSetup->fail_addr = addr;
      pMemSetup->is_val = *addr;
      pMemSetup->ex_val = (uint32_t)addr;
      return false;
    }

    addr++;
    fbytes -= 4;
  }

  return true;
}

/* Inverse address memory test */
bool mem_test_invaddress(MEM_TEST_SETUP_T *pMemSetup)
{
  uint32_t fbytes = pMemSetup->bytes, *addr = pMemSetup->start_addr;

  /* Must be 32-bit algined */
  if ((((uint32_t)addr & 0x3) != 0) || ((fbytes & 0x3) != 0))
  {
    return false;
  }

  /* Write inverse address for memory location */
  while (fbytes > 0)
  {
    *addr = ~(uint32_t)addr;

    addr++;
    fbytes -= 4;
  }

  /* Verify inverse address for memory location */
  fbytes = pMemSetup->bytes;
  addr = pMemSetup->start_addr;
  while (fbytes > 0)
  {
    if (*addr != ~(uint32_t)addr)
    {
      pMemSetup->fail_addr = addr;
      pMemSetup->is_val = *addr;
      pMemSetup->ex_val = ~(uint32_t)addr;
      return false;
    }

    addr++;
    fbytes -= 4;
  }

  return true;
}

/* Pattern memory test */
bool mem_test_pattern(MEM_TEST_SETUP_T *pMemSetup)
{
  uint32_t fbytes = pMemSetup->bytes, *addr = pMemSetup->start_addr;
  uint32_t pattern = 0x55AA55AA;

  /* Must be 32-bit algined */
  if ((((uint32_t)addr & 0x3) != 0) || ((fbytes & 0x3) != 0))
  {
    return false;
  }

  /* Write pattern for memory location */
  while (fbytes > 0)
  {
    *addr = pattern;

    pattern = ~pattern;
    addr++;
    fbytes -= 4;
  }

  /* Verify pattern for memory location */
  pattern = 0x55AA55AA;
  fbytes = pMemSetup->bytes;
  addr = pMemSetup->start_addr;
  while (fbytes > 0)
  {
    if (*addr != pattern)
    {
      pMemSetup->fail_addr = addr;
      pMemSetup->is_val = *addr;
      pMemSetup->ex_val = pattern;
      return false;
    }

    pattern = ~pattern;
    addr++;
    fbytes -= 4;
  }

  return true;
}

/* Pattern memory test with seed and increment value */
bool mem_test_pattern_seed(MEM_TEST_SETUP_T *pMemSetup, uint32_t seed, uint32_t incr)
{
  uint32_t fbytes = pMemSetup->bytes, *addr = pMemSetup->start_addr;
  uint32_t pattern = seed;

  /* Must be 32-bit algined */
  if ((((uint32_t)addr & 0x3) != 0) || ((fbytes & 0x3) != 0))
  {
    return false;
  }

  /* Write pattern for memory location */
  while (fbytes > 0)
  {
    *addr = pattern;

    pattern += incr;
    addr++;
    fbytes -= 4;
  }

  /* Verify pattern for memory location */
  pattern = seed;
  fbytes = pMemSetup->bytes;
  addr = pMemSetup->start_addr;
  while (fbytes > 0)
  {
    if (*addr != pattern)
    {
      pMemSetup->fail_addr = addr;
      pMemSetup->is_val = *addr;
      pMemSetup->ex_val = pattern;
      return false;
    }

    pattern += incr;
    addr++;
    fbytes -= 4;
  }

  return true;
}