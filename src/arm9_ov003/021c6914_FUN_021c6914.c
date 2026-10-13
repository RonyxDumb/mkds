/* Decompiled C draft; module arm9_ov003; ROM address 021c6914. No matching claim. */
#include "types.h"
#include "deps/021c6914_FUN_021c6914.h"

void FUN_021c6914(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (uint)*(byte *)(*DAT_021c6958 + 0x29);
  uVar4 = uVar3 & 0xf;
  iVar2 = (int)uVar3 >> 4;
  if (0x1f < uVar3) {
    uVar4 = 0xf;
    iVar2 = 1;
  }
  puVar1 = *(uint **)(*DAT_021c6958 + 4);
  *puVar1 = (*(byte *)(DAT_021c695c + uVar4) & DAT_021c6960) << 0x10 |
            *puVar1 & DAT_021c6964 | (uint)*(byte *)(DAT_021c6968 + iVar2);
  return;
}

