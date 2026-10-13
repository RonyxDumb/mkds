/* Decompiled C draft; module arm9_ov001; ROM address 02192694. No matching claim. */
#include "types.h"
#include "deps/02192694_FUN_02192694.h"

/* WARNING: Removing unreachable block (ram,0x021926ac) */

void FUN_02192694(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  int local_20;
  undefined4 local_1c;
  int local_18;
  
  if (*(int *)(*DAT_02192784 + 8) == 4) {
    sVar1 = FUN_02181b54();
    iVar2 = FUN_02181b68(sVar1 + 2);
  }
  else {
    iVar2 = 0;
  }
  iVar3 = func_0x0207a974((short)*(char *)(*DAT_02192784 + 0x62));
  if (*(int *)(iVar2 + 0xa8) == 4) {
    iVar6 = *(int *)(iVar2 + 0xa0);
    iVar3 = func_0x02148714(*(int *)(iVar3 + 0x88) - *(int *)(iVar2 + 0xc),
                            *(int *)(iVar3 + 0x80) - *(int *)(iVar2 + 4));
    uVar4 = iVar3 - *(int *)(iVar6 + DAT_02192788);
  }
  else {
    iVar6 = *(int *)(iVar2 + 0xa0);
    iVar3 = func_0x02148714(*(int *)(iVar3 + 0x88) - *(int *)(iVar2 + 0xc),
                            *(int *)(iVar3 + 0x80) - *(int *)(iVar2 + 4));
    uVar4 = *(int *)(iVar6 + DAT_02192788) + iVar3;
  }
  iVar3 = (int)(uVar4 & 0xffff) >> 4;
  iVar5 = (int)*(short *)(DAT_02192790 + (iVar3 * 2 + 1) * 2);
  uVar7 = func_0x02133048(*(int *)(iVar6 + DAT_0219278c),*(int *)(iVar6 + DAT_0219278c) >> 0x1f,
                          iVar5,iVar5 >> 0x1f);
  local_20 = *(int *)(iVar2 + 4) + ((uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14);
  local_1c = *(undefined4 *)(iVar2 + 8);
  iVar6 = *(int *)(*(int *)(iVar2 + 0xa0) + DAT_0219278c);
  iVar3 = (int)*(short *)(DAT_02192790 + iVar3 * 4);
  uVar7 = func_0x02133048(iVar6,iVar6 >> 0x1f,iVar3,iVar3 >> 0x1f);
  local_18 = *(int *)(iVar2 + 0xc) + ((uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14);
  FUN_02188998(iVar2,&local_20);
  return;
}

