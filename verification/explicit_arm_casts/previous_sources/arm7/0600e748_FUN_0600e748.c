/* Decompiled C draft; module arm7; ROM address 0600e748. No matching claim. */
#include "types.h"
#include "deps/0600e748_FUN_0600e748.h"

void FUN_0600e748(uint param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = FUN_0600e918();
  if ((iVar2 == 0x40) &&
     (uVar5 = *(uint *)(DAT_0600e800 & 0xfffffffc) >> (DAT_0600e800 & 3) * 8 |
              *(uint *)(DAT_0600e800 & 0xfffffffc) << (DAT_0600e800 & 3) * -8 + 0x20,
     ((uint)*(ushort *)(uVar5 + 0x534) & 1 << (param_1 & 0xff)) == 0)) {
    iVar2 = (uint)*(ushort *)(uVar5 + 0x3d8) + DAT_0600e804;
    uVar3 = thunk_FUN_037f8850(0x1000000);
    if (param_1 == 0) {
      bVar1 = FUN_060096c4(iVar2 + 4);
      FUN_060096e4(iVar2 + 4,bVar1 | 1);
    }
    else {
      uVar5 = FUN_0600e840(param_1);
      iVar2 = iVar2 + 5 + (uVar5 >> 3);
      uVar4 = FUN_060096c4(iVar2);
      FUN_060096e4(iVar2,(uVar4 | 1 << (uVar5 & 7)) & 0xff);
    }
    thunk_FUN_037f888c(uVar3);
  }
  return;
}

