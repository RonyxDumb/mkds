/* Decompiled C draft; module arm9; ROM address 020dd8b0. No matching claim. */
#include "types.h"
#include "deps/020dd8b0_func_020dd8b0.h"

void func_020dd8b0(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  uint local_20;
  uint local_1c;
  uint local_18;
  
  VecFx32_Subtract(param_3,(uint)(uintptr_t)(param_2),&local_20);
  iVar5 = *(int *)(param_1 + 0x24);
  iVar4 = iVar5 >> 0x1f;
  uVar6 = Multiply64(local_20,(int)local_20 >> 0x1f,iVar5,iVar4);
  local_20 = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
  uVar6 = Multiply64(local_1c,(int)local_1c >> 0x1f,iVar5,iVar4);
  local_1c = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
  uVar6 = Multiply64(local_18,(int)local_18 >> 0x1f,iVar5,iVar4);
  local_18 = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
  puVar3 = *(undefined4 **)(param_1 + 0x44);
  uVar2 = param_2[1];
  *puVar3 = *param_2;
  puVar3[1] = uVar2;
  puVar3[2] = param_2[2];
  puVar3 = *(undefined4 **)(param_1 + 0x48);
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  iVar4 = 1;
  if (1 < *(int *)(param_1 + 0x20)) {
    iVar5 = 0xc;
    do {
      VecFx32_Add(*(int *)(param_1 + 0x44) + (iVar4 + -1) * 0xc,(uint)(uintptr_t)(&local_20),
                  (int *)(uintptr_t)(*(int *)(param_1 + 0x44) + iVar5));
      iVar1 = *(int *)(param_1 + 0x48) + iVar5;
      *(undefined4 *)(*(int *)(param_1 + 0x48) + iVar5) = 0;
      *(undefined4 *)(iVar1 + 4) = 0;
      *(undefined4 *)(iVar1 + 8) = 0;
      iVar5 = iVar5 + 0xc;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x20));
  }
  return;
}

