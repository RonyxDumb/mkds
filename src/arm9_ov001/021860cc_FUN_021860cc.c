/* Decompiled C draft; module arm9_ov001; ROM address 021860cc. No matching claim. */
#include "types.h"
#include "deps/021860cc_FUN_021860cc.h"

undefined4 FUN_021860cc(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 uVar9;
  
  iVar1 = *(int *)(param_1 + DAT_021861dc);
  if (iVar1 == 0) {
    param_3 = param_3 + *(int *)(param_1 + DAT_021861e0);
    iVar1 = *param_2 - *(int *)(param_1 + DAT_021861e4);
    iVar2 = param_2[1] - *(int *)(param_1 + DAT_021861e8);
    iVar3 = param_2[2] - *(int *)(param_1 + DAT_021861ec);
    lVar6 = func_0x02133048(iVar3,iVar3 >> 0x1f,iVar3,iVar3 >> 0x1f);
    lVar7 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar1,iVar1 >> 0x1f);
    lVar8 = func_0x02133048(iVar2,iVar2 >> 0x1f,iVar2,iVar2 >> 0x1f);
    uVar9 = func_0x02133048(param_3,param_3 >> 0x1f,param_3,param_3 >> 0x1f);
    iVar1 = (int)((ulonglong)uVar9 >> 0x20);
    lVar6 = lVar6 + lVar7 + lVar8;
    iVar2 = (int)((ulonglong)lVar6 >> 0x20);
    bVar5 = (uint)lVar6 < (uint)uVar9;
    if ((int)((iVar2 - iVar1) - (uint)bVar5) < 0 !=
        (SBORROW4(iVar2,iVar1) != SBORROW4(iVar2 - iVar1,(uint)bVar5))) {
      func_0x020eb3f0((undefined4)(uintptr_t)(param_2),param_1 + DAT_021861e4,param_3,param_4);
      return 1;
    }
    return 0;
  }
  if (iVar1 != 1) {
    if (iVar1 != 2) {
      return 0;
    }
    uVar4 = func_0x020ead80((undefined4)(uintptr_t)(param_2),param_1 + DAT_021861e4,param_1 + 0x28,
                            *(undefined4 *)(param_1 + DAT_021861e0),
                            *(undefined4 *)(param_1 + DAT_021861f0),
                            *(undefined4 *)(param_1 + DAT_021861f0),param_3,(uint *)(uintptr_t)(param_4));
    return uVar4;
  }
  uVar4 = func_0x020eafc4((undefined4)(uintptr_t)(param_2),param_1 + DAT_021861e4,param_1 + 0x28,param_1 + DAT_021861e0,
                          param_1 + DAT_021861e0,param_3,(uint *)(uintptr_t)(param_4));
  return uVar4;
}

