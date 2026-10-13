/* Decompiled C draft; module arm9; ROM address 020ead80. No matching claim. */
#include "types.h"
#include "deps/020ead80_func_020ead80.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4
func_020ead80(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,int param_5,int param_6
             ,int param_7,uint *param_8)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 auStack_40 [12];
  int local_34;
  int local_30;
  int local_2c;
  int iStack_28;
  undefined4 uStack_24;
  int iStack_20;
  
  uVar8 = param_3 + 0xc;
  uVar7 = param_3 + 0x18;
  VecFx32_Subtract(param_1,param_2,auStack_40);
  local_30 = VecFx32_CrossProduct_0(auStack_40,uVar8);
  if ((param_5 + param_7 <= local_30) ||
     (param_6 = param_6 + param_7,
     local_30 == -param_6 || local_30 + param_6 < 0 != SBORROW4(local_30,-param_6))) {
    return 0;
  }
  if (local_30 < 1) {
    param_6 = local_30 + param_6;
  }
  else {
    param_6 = (param_5 + param_7) - local_30;
  }
  local_34 = VecFx32_CrossProduct_0(auStack_40,param_3);
  local_30 = 0;
  local_2c = VecFx32_CrossProduct_0(auStack_40,uVar7);
  iVar3 = VecFx32_Norm(&local_34);
  if (iVar3 < param_4 + param_7) {
    iVar3 = (param_4 + param_7) - iVar3;
    if ((param_6 < iVar3) && (0 < local_30)) {
      if (param_8 != (uint *)0x0) {
        lVar1 = (longlong)
                (int)(*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                     *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) * (longlong)param_6;
        *param_8 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
        uVar7 = param_3 + 0x10 & 3;
        uVar8 = *(uint *)(param_3 + 0x10 & 0xfffffffc);
        lVar1 = (longlong)(int)(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) * (longlong)param_6
        ;
        param_8[1] = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
        uVar7 = param_3 + 0x14 & 3;
        uVar8 = *(uint *)(param_3 + 0x14 & 0xfffffffc);
        lVar1 = (longlong)(int)(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) * (longlong)param_6
        ;
        param_8[2] = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      }
      return 1;
    }
    if (param_8 != (uint *)0x0) {
      iStack_28 = 0;
      uStack_24 = 0;
      iStack_20 = 0;
      lVar1 = (longlong)local_2c * (longlong)local_2c +
              (longlong)local_34 * (longlong)local_34 + (longlong)local_30 * (longlong)local_30;
      if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
        Vector3_MaybeNormalize(&local_34);
      }
      uVar9 = (uint)((longlong)iStack_28 * (longlong)iVar3) >> 0xc |
              (int)((ulonglong)((longlong)iStack_28 * (longlong)iVar3) >> 0x20) << 0x14;
      uVar5 = (uint)((longlong)iStack_20 * (longlong)iVar3) >> 0xc |
              (int)((ulonglong)((longlong)iStack_20 * (longlong)iVar3) >> 0x20) << 0x14;
      lVar1 = (longlong)
              (int)(*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
                   *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20) *
              (longlong)(int)uVar9;
      lVar2 = (longlong)
              (int)(*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                   *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) * (longlong)(int)uVar5;
      *param_8 = ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) +
                 ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
      uVar7 = param_3 + 4 & 3;
      uVar6 = *(uint *)(param_3 + 4 & 0xfffffffc);
      uVar8 = param_3 + 0x1c & 3;
      uVar4 = *(uint *)(param_3 + 0x1c & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) *
              (longlong)(int)uVar9;
      lVar2 = (longlong)(int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) *
              (longlong)(int)uVar5;
      param_8[1] = ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) +
                   ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
      uVar7 = param_3 + 8 & 3;
      uVar6 = *(uint *)(param_3 + 8 & 0xfffffffc);
      uVar8 = param_3 + 0x20 & 3;
      uVar4 = *(uint *)(param_3 + 0x20 & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) *
              (longlong)(int)uVar9;
      lVar2 = (longlong)(int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) *
              (longlong)(int)uVar5;
      param_8[2] = ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) +
                   ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    }
    return 2;
  }
  return 0;
}

