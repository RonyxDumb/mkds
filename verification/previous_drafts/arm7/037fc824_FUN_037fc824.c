/* Decompiled C draft; module arm7; ROM address 037fc824. No matching claim. */
#include "types.h"
#include "deps/037fc824_FUN_037fc824.h"

void FUN_037fc824(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar4;
  uint uVar5;
  uint uVar3;
  
  iVar1 = DAT_037fc8a8;
  uVar5 = 0;
  do {
    iVar4 = uVar5 * 0x54 + iVar1;
    if (((((int)((uint)*(byte *)(iVar4 + 3) << 0x1f) < 0) && (*(char *)(iVar4 + 1) == '\0')) &&
        (uVar3 = iVar4 + 0x44U & 3, uVar2 = *(uint *)(iVar4 + 0x44U & 0xfffffffc),
        uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20, param_1 <= uVar3)) &&
       (uVar3 <= param_2)) {
      *(byte *)(iVar4 + 3) = *(byte *)(iVar4 + 3) & 0xfd;
      FUN_037fbd0c(uVar5,0);
    }
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 0x10);
  return;
}

