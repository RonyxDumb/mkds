/* Decompiled C draft; module arm9; ROM address 020eaa14. No matching claim. */
#include "types.h"
#include "deps/020eaa14_func_020eaa14.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020eaa14(uint *param_1,uint *param_2,int param_3,int param_4,uint param_5,uint *param_6)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  uint local_38;
  uint local_34;
  uint local_30;
  uint uStack_2c;
  uint uStack_28;
  uint uStack_24;
  
  local_38 = *param_2;
  local_34 = param_2[1];
  local_30 = param_2[2];
  if (0 < (int)local_34) {
    iVar2 = 0;
    lVar1 = (longlong)(int)local_30 * (longlong)(int)local_30 +
            (longlong)(int)local_38 * (longlong)(int)local_38;
    local_34 = 0;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      iVar2 = Vector3_MaybeNormalize((uint)(uintptr_t)(&local_38),&local_38);
    }
    if (iVar2 == 0) {
      uVar3 = param_1[1];
      uVar4 = param_1[2];
      *param_6 = *param_1;
      param_6[1] = uVar3;
      param_6[2] = uVar4;
      return;
    }
  }
  iVar2 = Vector3_DotProduct((uint)(uintptr_t)(&local_38),(uint)(uintptr_t)(param_1));
  uVar9 = (uint)((longlong)(int)local_34 * (longlong)iVar2) >> 0xc |
          (int)((ulonglong)((longlong)(int)local_34 * (longlong)iVar2) >> 0x20) << 0x14;
  uVar4 = (uint)((longlong)(int)local_38 * (longlong)iVar2) >> 0xc |
          (int)((ulonglong)((longlong)(int)local_38 * (longlong)iVar2) >> 0x20) << 0x14;
  uVar5 = (uint)((longlong)(int)local_30 * (longlong)iVar2) >> 0xc |
          (int)((ulonglong)((longlong)(int)local_30 * (longlong)iVar2) >> 0x20) << 0x14;
  *param_6 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) - uVar4;
  uVar3 = (uint)(param_1 + 1) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  param_4 = -param_4;
  param_6[1] = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) - uVar9;
  uVar3 = (uint)(param_1 + 2) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  iVar7 = (int)((ulonglong)((longlong)(int)param_5 * (longlong)(int)param_5) >> 0x20);
  param_6[2] = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) - uVar5;
  iVar2 = (int)param_5 >> 0x1f;
  lVar1 = (longlong)
          (int)(*(uint *)((uint)param_6 & 0xfffffffc) >> ((uint)param_6 & 3) * 8 |
               *(uint *)((uint)param_6 & 0xfffffffc) << ((uint)param_6 & 3) * -8 + 0x20) *
          (longlong)param_3;
  *param_6 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar3 = (uint)(param_6 + 1) & 3;
  uVar6 = *(uint *)((uint)(param_6 + 1) & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) * (longlong)param_3;
  param_6[1] = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar3 = (uint)(param_6 + 2) & 3;
  uVar6 = *(uint *)((uint)(param_6 + 2) & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) * (longlong)param_3;
  param_6[2] = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  lVar1 = (longlong)(int)uVar5 * (longlong)param_4;
  uStack_24 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  lVar1 = (longlong)(int)uVar4 * (longlong)param_4;
  uStack_2c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  lVar1 = (longlong)(int)uStack_2c * (longlong)(int)uStack_2c +
          (longlong)(int)uStack_24 * (longlong)(int)uStack_24;
  iVar8 = (int)((ulonglong)lVar1 >> 0x20);
  bVar10 = (uint)lVar1 < (uint)((longlong)(int)param_5 * (longlong)(int)param_5);
  lVar1 = (longlong)(int)uVar9 * (longlong)param_4;
  uStack_28 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  if ((int)(iVar8 - (iVar7 + (uint)bVar10)) < 0 !=
      (SBORROW4(iVar8,iVar7) != SBORROW4(iVar8 - iVar7,(uint)bVar10))) {
    uStack_2c = (uint)((ulonglong)param_5 * (ulonglong)local_38) >> 0xc |
                (((int)local_38 >> 0x1f) * param_5 +
                local_38 * iVar2 + (int)((ulonglong)param_5 * (ulonglong)local_38 >> 0x20)) *
                0x100000;
    uStack_28 = (uint)((ulonglong)param_5 * (ulonglong)local_34) >> 0xc |
                (((int)local_34 >> 0x1f) * param_5 +
                local_34 * iVar2 + (int)((ulonglong)param_5 * (ulonglong)local_34 >> 0x20)) *
                0x100000;
    uStack_24 = (uint)((ulonglong)param_5 * (ulonglong)local_30) >> 0xc |
                (((int)local_30 >> 0x1f) * param_5 +
                local_30 * iVar2 + (int)((ulonglong)param_5 * (ulonglong)local_30 >> 0x20)) *
                0x100000;
  }
  VecFx32_Add((uint)(uintptr_t)(&uStack_2c),(uint)(uintptr_t)(param_6),param_6);
  return;
}

