/* Decompiled C draft; module arm7; ROM address 037fe968. No matching claim. */
#include "types.h"
#include "deps/037fe968_FUN_037fe968.h"

void FUN_037fe968(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = DAT_037fe9c4;
  iVar4 = 0;
  do {
    if ((((int)((uint)*(byte *)(iVar2 + iVar4 * 0x24) << 0x1f) < 0) &&
        (uVar3 = iVar2 + iVar4 * 0x24 + 0x20, uVar1 = uVar3 & 3,
        uVar3 = *(uint *)(uVar3 & 0xfffffffc),
        uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20, param_1 <= uVar3)) &&
       (uVar3 <= param_2)) {
      FUN_037fe230();
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x10);
  return;
}

