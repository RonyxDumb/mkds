/* Decompiled C draft; module arm7; ROM address 0600ca18. No matching claim. */
#include "types.h"
#include "deps/0600ca18_FUN_0600ca18.h"

void FUN_0600ca18(int param_1)

{
  short *psVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = DAT_0600cb10;
  iVar2 = (*(uint *)(DAT_0600cb10 & 0xfffffffc) >> (DAT_0600cb10 & 3) * 8 |
          *(uint *)(DAT_0600cb10 & 0xfffffffc) << (DAT_0600cb10 & 3) * -8 + 0x20) + DAT_0600cb14;
  *DAT_0600cb18 = 0x1000;
  if (*(short *)(iVar2 + 0x3c) != 0) {
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if (((*(ushort *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x690) & 0x10) != 0) &&
       (param_1 != 0)) {
      if (((*DAT_0600cb20 == 3) || (*DAT_0600cb20 == 5)) && (*DAT_0600cb1c == 0)) {
        uVar3 = iVar2 + 0x44;
        uVar4 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        iVar2 = 0;
        for (uVar3 = (uint)*(ushort *)(uVar4 + 2); uVar3 != 0; uVar3 = (uVar3 << 0xf) >> 0x10) {
          iVar2 = iVar2 + (uVar3 & 1);
        }
        FUN_06009860(iVar2 * (*(ushort *)(uVar4 + 0x24) + 10) + 0xc0 +
                     (uint)*(ushort *)(uVar4 + 10) * 4 & 0xffff,DAT_0600cb24);
        psVar1 = (short *)((*(uint *)(DAT_0600cb10 & 0xfffffffc) >> (DAT_0600cb10 & 3) * 8 |
                           *(uint *)(DAT_0600cb10 & 0xfffffffc) << (DAT_0600cb10 & 3) * -8 + 0x20) +
                          0x400);
        *psVar1 = *psVar1 + 1;
        return;
      }
    }
    FUN_06008a8c(0,0x10);
  }
  return;
}

