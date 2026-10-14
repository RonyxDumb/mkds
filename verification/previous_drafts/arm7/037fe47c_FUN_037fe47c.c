/* Decompiled C draft; module arm7; ROM address 037fe47c. No matching claim. */
#include "types.h"
#include "deps/037fe47c_FUN_037fe47c.h"

void FUN_037fe47c(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  *param_1 = *param_1 & 0xfb;
  *(undefined4 *)(param_1 + 0x20) = param_2;
  param_1[0x18] = 0x78;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 1;
  param_1[0x1c] = 0xf0;
  param_1[0x1d] = 0;
  param_1[5] = 0x7f;
  iVar2 = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[4] = 0x40;
  do {
    param_1[iVar2 + 8] = 0xff;
    uVar1 = DAT_037fe528;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  uVar3 = *(uint *)(DAT_037fe528 & 0xfffffffc) >> (DAT_037fe528 & 3) * 8 |
          *(uint *)(DAT_037fe528 & 0xfffffffc) << (DAT_037fe528 & 3) * -8 + 0x20;
  if (uVar3 != 0) {
    iVar2 = 0;
    *(undefined4 *)((uint)param_1[1] * 0x24 + uVar3 + 0x40) = 0;
    do {
      uVar3 = uVar1 & 3;
      uVar4 = *(uint *)(uVar1 & 0xfffffffc);
      *(undefined2 *)
       ((uint)param_1[1] * 0x24 + (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + iVar2 * 2 +
       0x20) = 0xffff;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x10);
  }
  return;
}

