/* Decompiled C draft; module arm9_ov001; ROM address 0218b034. No matching claim. */
#include "types.h"
#include "deps/0218b034_FUN_0218b034.h"

void FUN_0218b034(int param_1)

{
  longlong *plVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  undefined8 uVar9;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  plVar1 = (longlong *)func_0x020d22d0();
  lVar8 = func_0x02133048((int)plVar1[1],*(undefined4 *)((int)plVar1 + 0xc),(int)*plVar1,
                          *(undefined4 *)((int)plVar1 + 4));
  *plVar1 = lVar8 + plVar1[2];
  iVar7 = 0;
  uVar2 = *(uint *)((int)plVar1 + 4) >> 0x10;
  do {
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    uVar2 = uVar2 + DAT_0218b1a8;
    iVar3 = FUN_02188220(param_1);
    if (iVar3 == 0) {
      iVar3 = (int)(uVar2 & 0xffff) >> 4;
      iVar4 = *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218b1ac);
      iVar6 = (int)*(short *)(DAT_0218b1b0 + iVar3 * 4);
      uVar9 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar6,iVar6 >> 0x1f);
      local_2c = *(int *)(param_1 + 4) +
                 ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
      local_28 = *(int *)(param_1 + 8) + *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218b1b4);
      iVar4 = *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218b1ac);
      iVar3 = (int)*(short *)(DAT_0218b1b0 + (iVar3 * 2 + 1) * 2);
      uVar9 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar3,iVar3 >> 0x1f);
      local_24 = *(int *)(param_1 + 0xc) +
                 ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
    }
    else {
      iVar3 = (int)(uVar2 & 0xffff) >> 4;
      iVar4 = *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218b1b8);
      iVar6 = (int)*(short *)(DAT_0218b1b0 + iVar3 * 4);
      uVar9 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar6,iVar6 >> 0x1f);
      local_2c = *(int *)(param_1 + 4) +
                 ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
      local_28 = *(int *)(param_1 + 8) + *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218b1bc);
      iVar4 = *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218b1b8);
      iVar3 = (int)*(short *)(DAT_0218b1b0 + (iVar3 * 2 + 1) * 2);
      uVar9 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar3,iVar3 >> 0x1f);
      local_24 = *(int *)(param_1 + 0xc) +
                 ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
    }
    if (iVar7 == 0) {
      uVar5 = func_0x020fd428();
      FUN_02187b94(uVar5,&local_2c,&local_20,
                   *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218b1c0));
    }
    else {
      uVar5 = FUN_02187e00(9);
      FUN_02187b94(uVar5,&local_2c,&local_20,
                   *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218b1c4));
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 3);
  FUN_02187518(param_1,DAT_0218b1cc,0,DAT_0218b1d0,DAT_0218b1c8,0);
  func_0x020d2774(param_1,DAT_0218b1d4);
  return;
}

