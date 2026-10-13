/* Decompiled C draft; module arm9; ROM address 020203e4. No matching claim. */
#include "types.h"
#include "deps/020203e4_func_020203e4.h"

void func_020203e4(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = puRam02020418;
  puVar1 = puRam02020414;
  if (*(uint *)((uint)puRam02020410 & 0xfffffffc) >> ((uint)puRam02020410 & 3) * 8 == 0 &&
      *(uint *)((uint)puRam02020410 & 0xfffffffc) << ((uint)puRam02020410 & 3) * -8 + 0x20 == 0) {
    return;
  }
  *puRam02020410 = 0;
  *puVar1 = 0;
  *puVar2 = 0;
  return;
}

