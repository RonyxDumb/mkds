/* Decompiled C draft; module arm7; ROM address 037f8000. No matching claim. */
#include "types.h"
#include "deps/037f8000_FUN_037f8000.h"

void FUN_037f8000(void)

{
  if (*(uint *)(DAT_037f8028 & 0xfffffffc) >> (DAT_037f8028 & 3) * 8 != 0 ||
      *(uint *)(DAT_037f8028 & 0xfffffffc) << (DAT_037f8028 & 3) * -8 + 0x20 != 0) {
    FUN_03802c90();
  }
  return;
}

