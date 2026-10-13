/* Decompiled C draft; module arm9_ov000; ROM address 021a6c90. No matching claim. */
#include "types.h"
#include "deps/021a6c90_FUN_021a6c90.h"

uint FUN_021a6c90(void)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  
  uVar1 = 0;
  uVar2 = (uint)*DAT_021a6cdc;
  if (uVar2 < 0x11) {
    if (uVar2 != 0) {
      iVar4 = 0;
      pbVar3 = DAT_021a6ce0;
      if (uVar2 != 0) {
        do {
          uVar1 = uVar1 + *pbVar3;
          iVar4 = iVar4 + 1;
          pbVar3 = pbVar3 + 1;
        } while (iVar4 < (int)uVar2);
      }
      uVar1 = func_0x02133068(uVar1);
    }
  }
  else {
    iVar4 = 0;
    pbVar3 = DAT_021a6ce0;
    do {
      uVar1 = uVar1 + *pbVar3;
      pbVar3 = pbVar3 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x10);
    uVar1 = func_0x02133068(uVar1,0x10);
  }
  return uVar1 & 0xff;
}

