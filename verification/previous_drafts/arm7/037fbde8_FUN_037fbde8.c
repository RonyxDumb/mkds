/* Decompiled C draft; module arm7; ROM address 037fbde8. No matching claim. */
#include "types.h"
#include "deps/037fbde8_FUN_037fbde8.h"

void FUN_037fbde8(uint param_1,int param_2,uint param_3,int param_4,short param_5,uint param_6)

{
  uint uVar1;
  
  *(char *)(DAT_037fbe8c + param_1) = (char)param_6;
  uVar1 = *(uint *)(DAT_037fbe90 & 0xfffffffc) >> (DAT_037fbe90 & 3) * 8 |
          *(uint *)(DAT_037fbe90 & 0xfffffffc) << (DAT_037fbe90 & 3) * -8 + 0x20;
  if (-1 < (int)uVar1) {
    param_6 = uVar1;
  }
  *(char *)(DAT_037fbe94 + param_1) = (char)param_3;
  if ((0 < (int)(*(uint *)(DAT_037fbe98 & 0xfffffffc) >> (DAT_037fbe98 & 3) * 8 |
                *(uint *)(DAT_037fbe98 & 0xfffffffc) << (DAT_037fbe98 & 3) * -8 + 0x20)) &&
     ((1 << (param_1 & 0xff) & DAT_037fbe9c) != 0)) {
    param_3 = FUN_037fba94(param_3,param_6);
  }
  *(uint *)(param_1 * 0x10 + 0x4000400) =
       param_3 | param_2 << 0x18 | 0x60000000U | param_6 << 0x10 | param_4 << 8;
  *(short *)(param_1 * 0x10 + 0x4000408) = -param_5;
  return;
}

