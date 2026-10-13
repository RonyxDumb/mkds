/* Decompiled C draft; module arm9_ov001; ROM address 02188f04. No matching claim. */
#include "types.h"
#include "deps/02188f04_FUN_02188f04.h"

undefined4 FUN_02188f04(int param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined4 local_30;
  undefined4 local_28;
  undefined1 auStack_20 [12];
  
  if (param_2 == (int *)0x0) {
    return 0;
  }
  func_0x021484d0((uint)(uintptr_t)(param_2),param_1 + 4,(int *)(void *)(auStack_20));
  iVar3 = *(int *)(param_1 + 4) - *param_2;
  iVar1 = *(int *)(param_1 + 0xc) - param_2[2];
  if (param_3 < 1) {
    uVar2 = func_0x02132440(param_3 * 0x1000);
    local_28 = func_0x021329f8(uVar2,DAT_02188fd8);
  }
  else {
    uVar2 = func_0x02132440(param_3 * 0x1000);
    local_28 = func_0x02131234(DAT_02188fd8,uVar2);
  }
  if (param_3 < 1) {
    uVar2 = func_0x02132440(param_3 * 0x1000);
    local_30 = func_0x021329f8(uVar2,DAT_02188fd8);
  }
  else {
    uVar2 = func_0x02132440(param_3 * 0x1000);
    local_30 = func_0x02131234(DAT_02188fd8,uVar2);
  }
  lVar5 = func_0x02133048(iVar3,iVar3 >> 0x1f,iVar3,iVar3 >> 0x1f);
  lVar6 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar1,iVar1 >> 0x1f);
  iVar1 = func_0x021322c8(local_30);
  iVar3 = func_0x021322c8(local_28);
  uVar7 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar3,iVar3 >> 0x1f);
  iVar1 = (int)((ulonglong)uVar7 >> 0x20);
  iVar3 = (int)((ulonglong)(lVar5 + lVar6) >> 0x20);
  bVar4 = (uint)(lVar5 + lVar6) < (uint)uVar7;
  if ((int)((iVar3 - iVar1) - (uint)bVar4) < 0 !=
      (SBORROW4(iVar3,iVar1) != SBORROW4(iVar3 - iVar1,(uint)bVar4))) {
    return 1;
  }
  return 0;
}

