/* Decompiled C draft; module arm9_ov001; ROM address 021924cc. No matching claim. */
#include "types.h"
#include "deps/021924cc_FUN_021924cc.h"

/* WARNING: Removing unreachable block (ram,0x0219250a) */
/* WARNING: Removing unreachable block (ram,0x021924e4) */
/* WARNING: Removing unreachable block (ram,0x0219252e) */

void FUN_021924cc(void)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  int local_38;
  undefined4 local_34;
  uint local_30;
  uint local_2c;
  undefined4 local_28;
  int local_24;
  uint local_20;
  undefined4 local_1c;
  uint local_18;
  
  if (*(int *)(*DAT_02192680 + 8) == 4) {
    sVar1 = FUN_02181b54();
    iVar3 = FUN_02181b68(sVar1 + 2);
  }
  else {
    iVar3 = 0;
  }
  if (*(int *)(*DAT_02192680 + 8) == 4) {
    uVar2 = FUN_02181b54();
    uVar4 = FUN_02181b68(uVar2);
  }
  else {
    uVar4 = 0;
  }
  if (*(int *)(*DAT_02192680 + 8) == 4) {
    sVar1 = FUN_02181b54();
    uVar5 = FUN_02181b68(sVar1 + 1);
  }
  else {
    uVar5 = 0;
  }
  iVar6 = *(int *)(*(int *)(iVar3 + 0xa0) + DAT_02192684);
  iVar7 = (int)*(short *)(DAT_0219268c + ((int)(*(uint *)(iVar3 + DAT_02192688) & 0xffff) >> 4) * 4)
  ;
  uVar8 = func_0x02133048(iVar6,iVar6 >> 0x1f,iVar7,iVar7 >> 0x1f);
  local_20 = (uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14;
  local_1c = *(undefined4 *)(iVar3 + 8);
  iVar6 = *(int *)(*(int *)(iVar3 + 0xa0) + DAT_02192684);
  iVar7 = (int)*(short *)(DAT_0219268c +
                         (((int)(*(uint *)(iVar3 + DAT_02192688) & 0xffff) >> 4) * 2 + 1) * 2);
  uVar8 = func_0x02133048(iVar6,iVar6 >> 0x1f,iVar7,iVar7 >> 0x1f);
  local_18 = (uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14;
  iVar6 = *(int *)(*(int *)(iVar3 + 0xa0) + DAT_02192690);
  iVar7 = (int)*(short *)(DAT_0219268c +
                         (((int)(*(uint *)(iVar3 + DAT_02192688) & 0xffff) >> 4) * 2 + 1) * 2);
  uVar8 = func_0x02133048(iVar6,iVar6 >> 0x1f,iVar7,iVar7 >> 0x1f);
  local_38 = -((uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14);
  local_34 = *(undefined4 *)(iVar3 + 8);
  iVar6 = *(int *)(*(int *)(iVar3 + 0xa0) + DAT_02192690);
  iVar7 = (int)*(short *)(DAT_0219268c + ((int)(*(uint *)(iVar3 + DAT_02192688) & 0xffff) >> 4) * 4)
  ;
  uVar8 = func_0x02133048(iVar6,iVar6 >> 0x1f,iVar7,iVar7 >> 0x1f);
  local_30 = (uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14;
  iVar6 = *(int *)(*(int *)(iVar3 + 0xa0) + DAT_02192690);
  iVar7 = (int)*(short *)(DAT_0219268c +
                         (((int)(*(uint *)(iVar3 + DAT_02192688) & 0xffff) >> 4) * 2 + 1) * 2);
  uVar8 = func_0x02133048(iVar6,iVar6 >> 0x1f,iVar7,iVar7 >> 0x1f);
  local_2c = (uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14;
  local_28 = *(undefined4 *)(iVar3 + 8);
  iVar6 = *(int *)(*(int *)(iVar3 + 0xa0) + DAT_02192690);
  iVar3 = (int)*(short *)(DAT_0219268c + ((int)(*(uint *)(iVar3 + DAT_02192688) & 0xffff) >> 4) * 4)
  ;
  uVar8 = func_0x02133048(iVar6,iVar6 >> 0x1f,iVar3,iVar3 >> 0x1f);
  local_24 = -((uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14);
  FUN_02188968(uVar4,&local_20);
  FUN_02188968(uVar5,&local_20);
  FUN_02188980(uVar4,&local_38);
  FUN_02188980(uVar5,&local_2c);
  return;
}

