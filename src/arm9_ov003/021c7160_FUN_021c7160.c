/* Decompiled C draft; module arm9_ov003; ROM address 021c7160. No matching claim. */
#include "types.h"
#include "deps/021c7160_FUN_021c7160.h"

void FUN_021c7160(void)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(*DAT_021c7190 + 0x14);
  if (3 < uVar2) {
    uVar2 = 3;
  }
  puVar1 = *(uint **)(*DAT_021c7190 + 4);
  *puVar1 = (*(byte *)(DAT_021c7194 + uVar2 * 3 + 2) & DAT_021c7198) << 0x10 |
            *puVar1 & DAT_021c719c | 0x28;
  return;
}

