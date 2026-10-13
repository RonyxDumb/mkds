/* Decompiled C draft; module arm9; ROM address 02096df0. No matching claim. */
#include "types.h"
#include "deps/02096df0_func_02096df0.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 func_02096df0(int param_1,undefined4 param_2,int param_3,uint *param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iStack_20;
  int local_1c;
  int iStack_18;
  
  VecFx32_Subtract(param_2,param_1 + 4,&iStack_20);
  uVar4 = param_1 + 0xa0U & 3;
  uVar2 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
  if ((int)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + param_3) <= local_1c) {
    return 0;
  }
  iVar3 = VecFx32_Norm((uint)(uintptr_t)(&iStack_20));
  uVar4 = param_1 + 0x58U & 3;
  uVar2 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  if ((int)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + param_3) <= iVar3) {
    return 0;
  }
  uVar4 = param_1 + 0xb0U & 3;
  uVar2 = *(uint *)(param_1 + 0xb0U & 0xfffffffc);
  uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  if (uVar4 == 1) {
    *param_4 = 0;
    param_4[1] = 0;
    param_4[2] = 0;
    return 1;
  }
  if ((uVar4 != 4) &&
     ((uVar4 != 5 ||
      (uVar4 = param_1 + 0xa0U & 3, uVar2 = *(uint *)(param_1 + 0xa0U & 0xfffffffc),
      (int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) < 0x7801)))) {
    *param_4 = 0;
    param_4[1] = 0;
    param_4[2] = 0;
    return 1;
  }
  lVar1 = (longlong)iStack_18 * (longlong)iStack_18 +
          (longlong)iStack_20 * (longlong)iStack_20 + (longlong)local_1c * (longlong)local_1c;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize((uint)(uintptr_t)(&iStack_20),&iStack_20);
  }
  uVar4 = param_1 + 0x58U & 3;
  uVar2 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  iVar3 = ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + param_3) - iVar3;
  *param_4 = (uint)((longlong)iStack_20 * (longlong)iVar3) >> 0xc |
             (int)((ulonglong)((longlong)iStack_20 * (longlong)iVar3) >> 0x20) << 0x14;
  param_4[1] = (uint)((longlong)local_1c * (longlong)iVar3) >> 0xc |
               (int)((ulonglong)((longlong)local_1c * (longlong)iVar3) >> 0x20) << 0x14;
  param_4[2] = (uint)((longlong)iStack_18 * (longlong)iVar3) >> 0xc |
               (int)((ulonglong)((longlong)iStack_18 * (longlong)iVar3) >> 0x20) << 0x14;
  return 1;
}

