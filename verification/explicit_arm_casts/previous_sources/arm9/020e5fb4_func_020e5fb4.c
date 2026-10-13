/* Decompiled C draft; module arm9; ROM address 020e5fb4. No matching claim. */
#include "types.h"
#include "deps/020e5fb4_func_020e5fb4.h"

undefined4 func_020e5fb4(int param_1,undefined4 param_2,int param_3,uint *param_4)

{
  uint uVar1;
  longlong lVar2;
  ushort *puVar3;
  longlong *plVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  int local_20;
  int local_1c;
  int local_18;
  
  VecFx32_Subtract(param_2,param_1 + 4,&local_20);
  iVar5 = VecFx32_CrossProduct_0(&local_20,param_1 + 0x40);
  plVar4 = plRam020e61a0;
  puVar3 = puRam020e619c;
  if (iVar5 < 1) {
    uVar1 = param_1 + 0x108U & 3;
    uVar6 = *(uint *)(param_1 + 0x108U & 0xfffffffc);
    iVar7 = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + param_3 + iVar5;
    iVar5 = -iVar7;
    if (iVar7 < 0) {
      return 0;
    }
  }
  else {
    uVar1 = param_1 + 0x108U & 3;
    uVar6 = *(uint *)(param_1 + 0x108U & 0xfffffffc);
    iVar5 = ((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + param_3) - iVar5;
    if (iVar5 < 0) {
      return 0;
    }
  }
  uVar1 = param_1 + 0x104U & 3;
  uVar6 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
  param_3 = param_3 + (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  iVar7 = (int)((ulonglong)((longlong)param_3 * (longlong)param_3) >> 0x20);
  lVar2 = (longlong)local_18 * (longlong)local_18 +
          (longlong)local_20 * (longlong)local_20 + (longlong)local_1c * (longlong)local_1c;
  iVar8 = (int)((ulonglong)lVar2 >> 0x20);
  bVar9 = (uint)lVar2 < (uint)((longlong)param_3 * (longlong)param_3);
  if ((int)(iVar8 - (iVar7 + (uint)bVar9)) < 0 !=
      (SBORROW4(iVar8,iVar7) != SBORROW4(iVar8 - iVar7,(uint)bVar9))) {
    *puRam020e619c = 1;
    *plVar4 = lVar2;
    do {
    } while ((*puVar3 & 0x8000) != 0);
    param_3 = param_3 - (*(uint *)(uRam020e61a4 & 0xfffffffc) >> (uRam020e61a4 & 3) * 8 |
                        *(uint *)(uRam020e61a4 & 0xfffffffc) << (uRam020e61a4 & 3) * -8 + 0x20);
    iVar7 = iVar5;
    if (iVar5 < 1) {
      iVar7 = -iVar5;
    }
    if (iVar7 < param_3) {
      uVar1 = param_1 + 0x40U & 3;
      uVar6 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
      lVar2 = (longlong)(int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) * (longlong)iVar5;
      *param_4 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      uVar1 = param_1 + 0x44U & 3;
      uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      lVar2 = (longlong)(int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) * (longlong)iVar5;
      param_4[1] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      uVar1 = param_1 + 0x48U & 3;
      uVar6 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      lVar2 = (longlong)(int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) * (longlong)iVar5;
      param_4[2] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      *(undefined4 *)(param_1 + 0x10c) = 0;
    }
    else {
      if (local_1c < 0) {
        local_1c = 0;
      }
      lVar2 = (longlong)local_18 * (longlong)local_18 +
              (longlong)local_20 * (longlong)local_20 + (longlong)local_1c * (longlong)local_1c;
      if ((int)(uint)((uint)lVar2 < 0x10) <= (int)((ulonglong)lVar2 >> 0x20)) {
        Vector3_MaybeNormalize(&local_20,&local_20);
      }
      *param_4 = (uint)((longlong)local_20 * (longlong)param_3) >> 0xc |
                 (int)((ulonglong)((longlong)local_20 * (longlong)param_3) >> 0x20) << 0x14;
      param_4[1] = (uint)((longlong)local_1c * (longlong)param_3) >> 0xc |
                   (int)((ulonglong)((longlong)local_1c * (longlong)param_3) >> 0x20) << 0x14;
      param_4[2] = (uint)((longlong)local_18 * (longlong)param_3) >> 0xc |
                   (int)((ulonglong)((longlong)local_18 * (longlong)param_3) >> 0x20) << 0x14;
      *(undefined4 *)(param_1 + 0x10c) = 1;
    }
    return 1;
  }
  return 0;
}

