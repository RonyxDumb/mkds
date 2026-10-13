/* Decompiled C draft; module arm9_ov001; ROM address 02185fb0. No matching claim. */
#include "types.h"
#include "deps/02185fb0_FUN_02185fb0.h"

undefined4 FUN_02185fb0(int param_1,int param_2,char *param_3,byte *param_4)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  int local_20;
  int local_1c;
  int local_18;
  
  cVar1 = *param_3;
  *(uint *)(param_1 + DAT_021860bc) = (uint)*param_4;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  if (cVar1 == '\x01') {
    iVar4 = *(int *)(param_1 + 4) - *(int *)(param_2 + 0x80);
    local_1c = 0;
    local_18 = *(int *)(param_1 + 0xc) - *(int *)(param_2 + 0x88);
    local_20 = iVar4;
    lVar5 = func_0x02133048(local_18,local_18 >> 0x1f,local_18,local_18 >> 0x1f);
    lVar6 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar4,iVar4 >> 0x1f);
    lVar7 = func_0x02133048(0,0,0,0);
    lVar5 = lVar5 + lVar6 + lVar7;
    if ((int)(uint)((uint)lVar5 < 0x10) <= (int)((ulonglong)lVar5 >> 0x20)) {
      func_0x02039860((uint)(uintptr_t)(&local_20),&local_20);
      iVar4 = -*(int *)(*(int *)(param_1 + 0xa0) + 0x24);
      iVar3 = iVar4 >> 0x1f;
      uVar8 = func_0x02133048(local_20,local_20 >> 0x1f,iVar4,iVar3);
      *(uint *)(param_1 + 0x10) = (uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14;
      uVar8 = func_0x02133048(local_1c,local_1c >> 0x1f,iVar4,iVar3);
      *(uint *)(param_1 + 0x14) = (uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14;
      uVar8 = func_0x02133048(local_18,local_18 >> 0x1f,iVar4,iVar3);
      *(uint *)(param_1 + 0x18) = (uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14;
      func_0x02147fd8(*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x28),(uint)(uintptr_t)(&local_20),
                      param_1 + DAT_021860c0,(int *)(uintptr_t)(param_1 + DAT_021860c0));
    }
    pcVar2 = *(code **)(param_1 + DAT_021860c4);
    *(undefined4 *)(param_1 + DAT_021860c4) = 0;
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(param_1,param_2);
    }
  }
  if (*(int *)(param_1 + DAT_021860c8) == 0) {
    *(int *)(param_1 + DAT_021860c8) = 0x1f;
  }
  return *(undefined4 *)(param_1 + DAT_021860bc);
}

