/* Decompiled C draft; module arm7; ROM address 0600eadc. No matching claim. */
#include "types.h"
#include "deps/0600eadc_FUN_0600eadc.h"

void FUN_0600eadc(uint param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_0600eafc & 0xfffffffc) >> (DAT_0600eafc & 3) * 8 |
          *(uint *)(DAT_0600eafc & 0xfffffffc) << (DAT_0600eafc & 3) * -8 + 0x20;
  *(ushort *)(uVar1 + 0x530) = *(ushort *)(uVar1 + 0x530) | (ushort)(1 << (param_1 & 0xff));
  return;
}

