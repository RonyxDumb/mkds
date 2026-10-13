/* Decompiled C draft; module arm7; ROM address 060134b4. No matching claim. */
#include "types.h"
#include "deps/060134b4_FUN_060134b4.h"

int FUN_060134b4(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar2 = *(uint *)(DAT_06013524 & 0xfffffffc) >> (DAT_06013524 & 3) * 8 |
          *(uint *)(DAT_06013524 & 0xfffffffc) << (DAT_06013524 & 3) * -8 + 0x20;
  uVar4 = (uint)*(ushort *)(uVar2 + 0x362);
  FUN_060096e4(param_1,0);
  FUN_060096e4(param_1 + 1,uVar4 & 0xff);
  iVar5 = 2;
  for (uVar3 = 0; uVar3 < uVar4; uVar3 = uVar3 + 1) {
    uVar1 = FUN_060096c4(uVar2 + 0x364 + uVar3);
    FUN_060096e4(param_1 + iVar5,uVar1);
    iVar5 = iVar5 + 1;
  }
  return iVar5;
}

