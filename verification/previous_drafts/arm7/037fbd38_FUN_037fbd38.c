/* Decompiled C draft; module arm7; ROM address 037fbd38. No matching claim. */
#include "types.h"
#include "deps/037fbd38_FUN_037fbd38.h"

void FUN_037fbd38(uint param_1,uint param_2,int param_3,short param_4,uint param_5)

{
  uint uVar1;
  
  *(char *)(DAT_037fbdd4 + param_1) = (char)param_5;
  uVar1 = *(uint *)(DAT_037fbdd8 & 0xfffffffc) >> (DAT_037fbdd8 & 3) * 8 |
          *(uint *)(DAT_037fbdd8 & 0xfffffffc) << (DAT_037fbdd8 & 3) * -8 + 0x20;
  if (-1 < (int)uVar1) {
    param_5 = uVar1;
  }
  *(char *)(DAT_037fbddc + param_1) = (char)param_2;
  if ((0 < (int)(*(uint *)(DAT_037fbde0 & 0xfffffffc) >> (DAT_037fbde0 & 3) * 8 |
                *(uint *)(DAT_037fbde0 & 0xfffffffc) << (DAT_037fbde0 & 3) * -8 + 0x20)) &&
     ((1 << (param_1 & 0xff) & DAT_037fbde4) != 0)) {
    param_2 = FUN_037fba94(param_2,param_5);
  }
  *(uint *)(param_1 * 0x10 + 0x4000400) = param_2 | param_5 << 0x10 | 0x60000000 | param_3 << 8;
  *(short *)(param_1 * 0x10 + 0x4000408) = -param_4;
  return;
}

