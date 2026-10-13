/* Decompiled C draft; module arm7; ROM address 0600c514. No matching claim. */
#include "types.h"
#include "deps/0600c514_FUN_0600c514.h"

void FUN_0600c514(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  
  puVar4 = DAT_0600c578;
  uVar3 = DAT_0600c574;
  iVar5 = (*(uint *)(DAT_0600c56c & 0xfffffffc) >> (DAT_0600c56c & 3) * 8 |
          *(uint *)(DAT_0600c56c & 0xfffffffc) << (DAT_0600c56c & 3) * -8 + 0x20) + DAT_0600c570;
  uVar1 = *(ushort *)(iVar5 + 0xa4);
  if (uVar1 != DAT_0600c574) {
    uVar2 = *DAT_0600c578;
    *DAT_0600c578 = uVar1;
    *DAT_0600c57c = *DAT_0600c57c | 0x80;
    *puVar4 = uVar2;
    *(short *)(iVar5 + 0xa4) = (short)uVar3;
  }
  return;
}

