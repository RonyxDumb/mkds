/* Decompiled C draft; module arm9; ROM address 02089e68. No matching claim. */
#include "types.h"
#include "deps/02089e68_func_02089e68.h"

void func_02089e68(short *param_1)

{
  longlong lVar1;
  uint uVar2;
  
  lVar1 = (ulonglong)uRam02089ec8 * (ulonglong)(uint)(*param_1 * 0x1000);
  uVar2 = (uint)lVar1;
  param_1[1] = (short)((int)(uVar2 + 0x800 >> 0xc |
                            ((*param_1 * 0x1000 >> 0x1f) * uRam02089ec8 +
                             (int)((ulonglong)lVar1 >> 0x20) + (uint)(0xfffff7ff < uVar2)) *
                            0x100000) >> 0xc);
  *param_1 = *param_1 + -1;
  if (*param_1 < 1) {
    param_1[4] = 0;
    param_1[5] = 0;
  }
  return;
}

