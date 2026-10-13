/* Decompiled C draft; module arm9; ROM address 02089b4c. No matching claim. */
#include "types.h"
#include "deps/02089b4c_func_02089b4c.h"

void func_02089b4c(int param_1,int param_2,undefined4 param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  
  *(undefined4 *)(param_1 + 0x10) = param_3;
  uVar3 = param_2 + 0x70U & 3;
  uVar2 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((int)uVar3 < 0x5001) {
    return;
  }
  uVar3 = uVar3 - 0x5000;
  lVar1 = (ulonglong)uVar3 * 0x5b;
  uVar2 = (uint)lVar1;
  uVar3 = uVar2 + 0x800 >> 0xc |
          (((int)uVar3 >> 0x1f) * 0x5b + (int)((ulonglong)lVar1 >> 0x20) +
          (uint)(0xfffff7ff < uVar2)) * 0x100000;
  if (0x1000 < (int)uVar3) {
    uVar3 = 0x1000;
  }
  uVar2 = (uint)((ulonglong)uRam02089c34 * (ulonglong)uVar3);
  lVar1 = (ulonglong)
          (0x1000 - (uVar2 + 0x800 >> 0xc |
                    (((int)uVar3 >> 0x1f) * uRam02089c34 +
                     (int)((ulonglong)uRam02089c34 * (ulonglong)uVar3 >> 0x20) +
                    (uint)(0xfffff7ff < uVar2)) * 0x100000)) * 0x6000 + 0x800;
  *(uint *)(param_1 + 0x10) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  uVar3 = param_2 + 0xd0U & 3;
  uVar2 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) {
    uVar3 = param_2 + 0xd8U & 3;
    uVar2 = *(uint *)(param_2 + 0xd8U & 0xfffffffc);
    if (iRam02089c38 < (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
      uVar3 = param_1 + 0x10U & 3;
      uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      *(int *)(param_1 + 0x10) = (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) >> 1;
    }
    return;
  }
  return;
}

