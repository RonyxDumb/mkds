/* Decompiled C draft; module arm9; ROM address 02142a30. No matching claim. */
#include "types.h"
#include "deps/02142a30_func_02142a30.h"

int func_02142a30(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = Wm_CheckInitialized();
  if (iVar2 == 0) {
    uVar3 = (*(uint *)(uRam02142a88 & 0xfffffffc) >> (uRam02142a88 & 3) * 8 |
            *(uint *)(uRam02142a88 & 0xfffffffc) << (uRam02142a88 & 3) * -8 + 0x20) + 4;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    DC_InvalidateRangeNoClean(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,2);
    uVar3 = (*(uint *)(uRam02142a88 & 0xfffffffc) >> (uRam02142a88 & 3) * 8 |
            *(uint *)(uRam02142a88 & 0xfffffffc) << (uRam02142a88 & 3) * -8 + 0x20) + 4;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if (*(ushort *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) < 2) {
      iVar2 = 3;
    }
    else {
      iVar2 = 0;
    }
    return iVar2;
  }
  return iVar2;
}

