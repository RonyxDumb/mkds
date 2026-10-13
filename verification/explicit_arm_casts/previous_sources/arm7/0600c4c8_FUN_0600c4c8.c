/* Decompiled C draft; module arm7; ROM address 0600c4c8. No matching claim. */
#include "types.h"
#include "deps/0600c4c8_FUN_0600c4c8.h"

undefined4 FUN_0600c4c8(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = (*(uint *)(DAT_0600c50c & 0xfffffffc) >> (DAT_0600c50c & 3) * 8 |
          *(uint *)(DAT_0600c50c & 0xfffffffc) << (DAT_0600c50c & 3) * -8 + 0x20) + DAT_0600c510;
  iVar1 = FUN_0600c460(iVar3 + 0x50);
  if (iVar1 == 0) {
    iVar1 = FUN_0600c460(iVar3 + 100);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

