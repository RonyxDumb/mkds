/* Decompiled C draft; module arm9; ROM address 020ea94c. No matching claim. */
#include "types.h"
#include "deps/020ea94c_func_020ea94c.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020ea94c(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 *param_6)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int local_20;
  int local_1c;
  int local_18;
  
  uVar1 = (uint)(param_2 + 1) & 3;
  uVar6 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  if (0 < (int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20)) {
    func_020eaa14();
    return;
  }
  local_20 = *param_2;
  local_1c = param_2[1];
  local_18 = param_2[2];
  lVar2 = (longlong)local_18 * (longlong)local_18 +
          (longlong)local_20 * (longlong)local_20 + (longlong)local_1c * (longlong)local_1c;
  iVar3 = 0;
  if ((int)(uint)((uint)lVar2 < 0x10) <= (int)((ulonglong)lVar2 >> 0x20)) {
    iVar3 = Vector3_MaybeNormalize((uint)(uintptr_t)(&local_20),&local_20);
  }
  if (iVar3 != 0) {
    func_020eaa14(param_1,&local_20,param_3,param_4);
    return;
  }
  uVar4 = param_1[1];
  uVar5 = param_1[2];
  *param_6 = *param_1;
  param_6[1] = uVar4;
  param_6[2] = uVar5;
  return;
}

