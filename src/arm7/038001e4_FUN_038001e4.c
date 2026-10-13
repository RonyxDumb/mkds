/* Decompiled C draft; module arm7; ROM address 038001e4. No matching claim. */
#include "types.h"
#include "deps/038001e4_FUN_038001e4.h"

void FUN_038001e4(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_038005c8();
  if (iVar2 != 0) {
    uVar3 = (*(uint *)(DAT_0380024c & 0xfffffffc) >> (DAT_0380024c & 3) * 8 |
            *(uint *)(DAT_0380024c & 0xfffffffc) << (DAT_0380024c & 3) * -8 + 0x20) + 0x24;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    FUN_038006f0((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 1 + param_3);
    FUN_03800350(param_1,3);
    FUN_03800538(0,param_2,param_3,DAT_03800250);
    FUN_03800610(0,0);
  }
  return;
}

