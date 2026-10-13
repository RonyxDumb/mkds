/* Decompiled C draft; module arm7; ROM address 0600c460. No matching claim. */
#include "types.h"
#include "deps/0600c460_FUN_0600c460.h"

undefined4 FUN_0600c460(short *param_1)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  
  if (((*param_1 != 0) &&
      (uVar1 = (uint)(param_1 + 4) & 3, uVar2 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc),
      puVar3 = (ushort *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20), (*puVar3 & 1) != 0)) &&
     ((((uint)puVar3 & DAT_0600c4c0) >> 1 | 0x8000) != (uint)*DAT_0600c4c4)) {
    FUN_060149b0();
    return 1;
  }
  return 0;
}

