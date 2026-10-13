/* Decompiled C draft; module arm7; ROM address 03803a44. No matching claim. */
#include "types.h"
#include "deps/03803a44_FUN_03803a44.h"

void FUN_03803a44(uint param_1)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  
  puVar2 = DAT_03803a74;
  *DAT_03803a74 =
       *DAT_03803a74 & 0xfff3 |
       (ushort)((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) << 2);
  uVar1 = param_1 + 4 & 3;
  uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
  *puVar2 = *puVar2 & 0xffef | (ushort)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) << 4);
  return;
}

