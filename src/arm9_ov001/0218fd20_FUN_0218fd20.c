/* Decompiled C draft; module arm9_ov001; ROM address 0218fd20. No matching claim. */
#include "types.h"
#include "deps/0218fd20_FUN_0218fd20.h"

/* WARNING: Removing unreachable block (ram,0x0218fe16) */
/* WARNING: Removing unreachable block (ram,0x0218fdee) */
/* WARNING: Removing unreachable block (ram,0x0218fe68) */

void FUN_0218fd20(int param_1,int param_2)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined8 uVar7;
  uint local_18;
  undefined4 local_14;
  uint local_10;
  
  iVar3 = func_0x02148714(*(int *)(param_2 + 0x50) - *(int *)(param_1 + 4),
                          *(int *)(param_2 + 0x58) - *(int *)(param_1 + 0xc));
  uVar4 = iVar3 - *(int *)(param_1 + DAT_0218fea8) & 0xffff;
  if (DAT_0218feac < (int)uVar4) {
    uVar4 = uVar4 - DAT_0218feb0;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0xa0) + 0x88);
  if ((((int)uVar4 <= iVar3) && ((int)(uVar4 + iVar3) < 0 == SBORROW4(uVar4,-iVar3))) &&
     (iVar3 = FUN_021871f8(param_1,7), iVar3 != 0)) {
    iVar3 = -*(int *)(*(int *)(param_1 + 0xa0) + DAT_0218feb4);
    iVar6 = (int)*(short *)(DAT_0218feb8 +
                           ((int)(*(uint *)(param_1 + DAT_0218fea8) & 0xffff) >> 4) * 4);
    uVar7 = func_0x02133048(iVar3,iVar3 >> 0x1f,iVar6,iVar6 >> 0x1f);
    local_18 = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
    local_14 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218febc);
    iVar3 = -*(int *)(*(int *)(param_1 + 0xa0) + DAT_0218feb4);
    iVar6 = (int)*(short *)(DAT_0218feb8 +
                           (((int)(*(uint *)(param_1 + DAT_0218fea8) & 0xffff) >> 4) * 2 + 1) * 2);
    uVar7 = func_0x02133048(iVar3,iVar3 >> 0x1f,iVar6,iVar6 >> 0x1f);
    local_10 = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
    if (*(int *)(*DAT_0218fec0 + 8) == 4) {
      uVar1 = FUN_02181b54();
      uVar5 = FUN_02181b68(uVar1);
    }
    else {
      uVar5 = 0;
    }
    FUN_02188950(uVar5,&local_18);
    if (*(int *)(*DAT_0218fec0 + 8) == 4) {
      sVar2 = FUN_02181b54();
      uVar5 = FUN_02181b68(sVar2 + 1);
    }
    else {
      uVar5 = 0;
    }
    FUN_02188950(uVar5,&local_18);
    func_0x0208b7bc(DAT_0218fec4,param_2 + 0x50);
    func_0x0208b7bc(DAT_0218fec8,param_2 + 0x50);
    func_0x0208b7bc(DAT_0218fecc,param_2 + 0x50);
    *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | *DAT_0218fed0;
    if (*(int *)(*DAT_0218fec0 + 8) == 4) {
      sVar2 = FUN_02181b54();
      uVar5 = FUN_02181b68(sVar2 + 2);
    }
    else {
      uVar5 = 0;
    }
    FUN_0219006c(uVar5);
    FUN_021881f4(param_1,DAT_0218fed4);
    *(undefined4 *)(param_1 + DAT_0218fed8) = 2;
    return;
  }
  *(undefined4 *)(param_1 + DAT_0218fed8) = 2;
  FUN_021881f4(param_1,DAT_0218fedc);
  return;
}

