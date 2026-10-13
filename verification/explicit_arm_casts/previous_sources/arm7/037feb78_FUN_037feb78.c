/* Decompiled C draft; module arm7; ROM address 037feb78. No matching claim. */
#include "types.h"
#include "deps/037feb78_FUN_037feb78.h"

void FUN_037feb78(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = param_1 * 0x24 + DAT_037fec3c;
  iVar6 = 0;
  do {
    iVar2 = FUN_037fe2e4(iVar5,iVar6);
    if (iVar2 != 0) {
      FUN_037fe40c(iVar2,iVar5,0x7f);
      FUN_037fe3d0(iVar2);
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x10);
  FUN_037fc2e4();
  uVar4 = 0;
  do {
    if (param_2 <= uVar4) {
LAB_037fec04:
      FUN_037fc2f8();
      uVar3 = *(uint *)(DAT_037fec40 & 0xfffffffc) >> (DAT_037fec40 & 3) * 8 |
              *(uint *)(DAT_037fec40 & 0xfffffffc) << (DAT_037fec40 & 3) * -8 + 0x20;
      if (uVar3 != 0) {
        iVar6 = uVar3 + 0x40;
        iVar5 = (uint)*(byte *)(iVar5 + 1) * 0x24;
        uVar3 = iVar6 + iVar5;
        uVar1 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        *(uint *)(iVar6 + iVar5) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + uVar4;
      }
      return;
    }
    iVar6 = FUN_037fd404(iVar5,0);
    if (iVar6 != 0) {
      FUN_037fe230(iVar5);
      goto LAB_037fec04;
    }
    uVar4 = uVar4 + 1;
  } while( true );
}

