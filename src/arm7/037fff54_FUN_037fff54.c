/* Decompiled C draft; module arm7; ROM address 037fff54. No matching claim. */
#include "types.h"
#include "deps/037fff54_FUN_037fff54.h"

void FUN_037fff54(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_038005c8();
  if (iVar2 != 0) {
    FUN_038003fc();
    uVar3 = (*(uint *)(DAT_037fffa8 & 0xfffffffc) >> (DAT_037fffa8 & 3) * 8 |
            *(uint *)(DAT_037fffa8 & 0xfffffffc) << (DAT_037fffa8 & 3) * -8 + 0x20) + 0x24;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    FUN_038006f0((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 1);
    FUN_03800350(param_1,0xd8);
    uVar3 = (*(uint *)(DAT_037fffa8 & 0xfffffffc) >> (DAT_037fffa8 & 3) * 8 |
            *(uint *)(DAT_037fffa8 & 0xfffffffc) << (DAT_037fffa8 & 3) * -8 + 0x20) + 0x38;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    FUN_03800610(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,0);
  }
  return;
}

