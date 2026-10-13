/* Decompiled C draft; module arm7; ROM address 0600a5b4. No matching claim. */
#include "types.h"
#include "deps/0600a5b4_FUN_0600a5b4.h"

undefined4 FUN_0600a5b4(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  uVar1 = *(uint *)(DAT_0600a680 & 0xfffffffc) >> (DAT_0600a680 & 3) * 8 |
          *(uint *)(DAT_0600a680 & 0xfffffffc) << (DAT_0600a680 & 3) * -8 + 0x20;
  if (param_1 < 0x21) {
    uVar6 = (uint)*(ushort *)(uVar1 + 0x362);
    if (uVar6 == 0) {
      uVar2 = 1;
    }
    else {
      if (*(short *)(uVar1 + 0x404) == 0x13) {
        if (param_1 < uVar6) {
          return 0;
        }
      }
      else {
        bVar9 = param_1 != uVar6;
        uVar6 = param_1;
        if (bVar9) {
          return 0;
        }
      }
      iVar8 = uVar1 + 0x364;
      iVar7 = uVar1 + 900;
      for (uVar1 = 0; uVar1 < uVar6; uVar1 = uVar1 + 1) {
        uVar3 = FUN_060096c4((ushort *)(uintptr_t)(iVar7));
        iVar7 = iVar7 + 1;
        uVar4 = FUN_060096c4((ushort *)(uintptr_t)(param_2));
        param_2 = param_2 + 1;
        uVar5 = FUN_060096c4((ushort *)(uintptr_t)(iVar8));
        iVar8 = iVar8 + 1;
        if ((uVar4 | uVar3) != (uVar5 | uVar3)) {
          return 0;
        }
      }
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

