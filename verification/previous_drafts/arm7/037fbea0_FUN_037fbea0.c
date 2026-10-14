/* Decompiled C draft; module arm7; ROM address 037fbea0. No matching claim. */
#include "types.h"
#include "deps/037fbea0_FUN_037fbea0.h"

void FUN_037fbea0(uint param_1,undefined4 param_2,int param_3,int param_4,undefined2 param_5,
                 undefined4 param_6,uint param_7,int param_8,short param_9,uint param_10)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_1 * 0x10;
  *(char *)(DAT_037fbf5c + param_1) = (char)param_10;
  uVar2 = *(uint *)(DAT_037fbf60 & 0xfffffffc) >> (DAT_037fbf60 & 3) * 8 |
          *(uint *)(DAT_037fbf60 & 0xfffffffc) << (DAT_037fbf60 & 3) * -8 + 0x20;
  if (-1 < (int)uVar2) {
    param_10 = uVar2;
  }
  *(char *)(DAT_037fbf64 + param_1) = (char)param_7;
  if ((0 < (int)(*(uint *)(DAT_037fbf68 & 0xfffffffc) >> (DAT_037fbf68 & 3) * 8 |
                *(uint *)(DAT_037fbf68 & 0xfffffffc) << (DAT_037fbf68 & 3) * -8 + 0x20)) &&
     ((1 << (param_1 & 0xff) & DAT_037fbf6c) != 0)) {
    param_7 = FUN_037fba94(param_7,param_10);
  }
  *(uint *)(iVar1 + 0x4000400) =
       param_7 | param_3 << 0x1d | param_4 << 0x1b | param_10 << 0x10 | param_8 << 8;
  *(short *)(iVar1 + 0x4000408) = -param_9;
  *(undefined2 *)(iVar1 + 0x400040a) = param_5;
  *(undefined4 *)(iVar1 + 0x400040c) = param_6;
  *(undefined4 *)(iVar1 + 0x4000404) = param_2;
  return;
}

