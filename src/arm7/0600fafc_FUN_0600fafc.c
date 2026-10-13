/* Decompiled C draft; module arm7; ROM address 0600fafc. No matching claim. */
#include "types.h"
#include "deps/0600fafc_FUN_0600fafc.h"

void FUN_0600fafc(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(DAT_0600fb4c & 0xfffffffc) >> (DAT_0600fb4c & 3) * 8 |
          *(uint *)(DAT_0600fb4c & 0xfffffffc) << (DAT_0600fb4c & 3) * -8 + 0x20;
  *(ushort *)(uVar3 + DAT_0600fb50 + 4) = *(ushort *)(uVar3 + DAT_0600fb50 + 4) & 0xfffe;
  uVar1 = uVar3 + 0x424 & 3;
  uVar2 = *(uint *)(uVar3 + 0x424 & 0xfffffffc);
  FUN_0600f19c(uVar3 + 0x200,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  if (*(short *)(uVar3 + 0x208) != 0) {
    FUN_06008a8c(2,0xb);
  }
  return;
}

