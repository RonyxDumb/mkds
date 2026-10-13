/* Decompiled C draft; module arm7; ROM address 06014554. No matching claim. */
#include "types.h"
#include "deps/06014554_FUN_06014554.h"

void FUN_06014554(ushort *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = DAT_060145f4;
  if ((*param_1 & 1) == 0) {
    uVar3 = FUN_0600ef30();
    if (uVar3 != 0xff) {
      FUN_060145f8();
    }
    if ((*(short *)((*(uint *)(DAT_060145f4 & 0xfffffffc) >> (DAT_060145f4 & 3) * 8 |
                    *(uint *)(DAT_060145f4 & 0xfffffffc) << (DAT_060145f4 & 3) * -8 + 0x20) + 0x32e)
         == 1) && (iVar4 = FUN_0600e918(uVar3), iVar4 == 0x40)) {
      FUN_0600ebbc(uVar3 & 0xffff,0x20);
      FUN_06014930();
    }
  }
  else {
    for (uVar5 = 1; uVar1 = uVar3 & 3, uVar2 = *(uint *)(uVar3 & 0xfffffffc),
        uVar5 < *(ushort *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x322);
        uVar5 = uVar5 + 1) {
      FUN_060145f8(uVar5);
    }
  }
  return;
}

