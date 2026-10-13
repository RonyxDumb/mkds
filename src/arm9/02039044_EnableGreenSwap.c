/* Decompiled C draft; module arm9; ROM address 02039044. No matching claim. */
#include "types.h"
#include "deps/02039044_EnableGreenSwap.h"

void EnableGreenSwap(void)

{
  WaitForIRQ(1,1);
  func_021489c4();
  *puRam02039078 =
       *(uint *)((uint)puRam02039078 & 0xfffffffc) >> ((uint)puRam02039078 & 3) * 8 |
       *(uint *)((uint)puRam02039078 & 0xfffffffc) << ((uint)puRam02039078 & 3) * -8 + 0x20 |
       0x10000;
  return;
}

