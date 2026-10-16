/* Decompiled C draft; module arm9; ROM address 02122794. No matching claim. */
#include "types.h"
#include "deps/02122794_func_02122794.h"

uint func_02122794(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar1 = *(uint *)(uRam021227f4 & 0xfffffffc) >> (uRam021227f4 & 3) * 8 |
          *(uint *)(uRam021227f4 & 0xfffffffc) << (uRam021227f4 & 3) * -8 + 0x20;
  uVar2 = uVar1;
  do {
    if (param_1 == *(char *)(uVar2 + 0x1f4e)) goto LAB_021227d0;
    uVar3 = (int)((uVar3 + 1) * 0x1000000) >> 0x18;
    uVar2 = uVar2 + 1;
  } while ((int)uVar3 < 4);
  uVar3 = 0xffffffff;
LAB_021227d0:
  if (uVar3 == 0xffffffff) {
    uVar3 = 0;
  }
  else {
    uVar3 = (uint)*(byte *)(uVar1 + 0x1f55) & 1 << (uVar3 & 0xff);
  }
  return uVar3;
}

