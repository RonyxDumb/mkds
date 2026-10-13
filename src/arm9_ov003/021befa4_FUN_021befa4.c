/* Decompiled C draft; module arm9_ov003; ROM address 021befa4. No matching claim. */
#include "types.h"
#include "deps/021befa4_FUN_021befa4.h"

void FUN_021befa4(undefined4 param_1)

{
  undefined1 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  *(short *)(*DAT_021bf038 + 0x14) = *(short *)(*DAT_021bf038 + 0x14) + 1;
  if (0xf < *(ushort *)(*DAT_021bf038 + 0x14)) {
    uVar6 = (uint)*(byte *)(DAT_021bf03c + (uint)*(byte *)(*DAT_021bf038 + 0x17));
    iVar5 = 0;
    if (uVar6 != 0) {
      iVar4 = 0;
      do {
        uVar1 = *(undefined1 *)(iVar5 + DAT_021bf040 + (uint)*(byte *)(*DAT_021bf038 + 0x17) * 2);
        uVar3 = FUN_021d1974(*(undefined4 *)(*DAT_021bf038 + iVar4),0);
        FUN_021d1c3c(0,uVar1,uVar3);
        FUN_021d1790(*(undefined4 *)(*DAT_021bf038 + iVar4),0xffffffff,1);
        iVar4 = iVar4 + 4;
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar6);
    }
    FUN_021bf258(*(undefined2 *)(DAT_021bf044 + 2));
    piVar2 = DAT_021bf038;
    *(undefined2 *)(*DAT_021bf038 + 0x14) = 0;
    *(undefined1 *)(*piVar2 + 0x16) = 0xff;
    iVar5 = *piVar2;
    if (*(int *)(iVar5 + 0x10) != 0) {
      *(undefined4 *)(iVar5 + 0x10) = 0;
      FUN_021d34c8(0,param_1);
    }
  }
  return;
}

