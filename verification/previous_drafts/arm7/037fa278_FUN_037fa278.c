/* Decompiled C draft; module arm7; ROM address 037fa278. No matching claim. */
#include "types.h"
#include "deps/037fa278_FUN_037fa278.h"

undefined8 FUN_037fa278(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  bool bVar4;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_037faf70();
  uVar2 = *DAT_037fa318;
  local_c = *(uint *)(DAT_037fa31c & 0xfffffffc) >> (DAT_037fa31c & 3) * 8 |
            *(uint *)(DAT_037fa31c & 0xfffffffc) << (DAT_037fa31c & 3) * -8 + 0x20;
  uVar1 = DAT_037fa31c + 4 & 3;
  uVar3 = *(uint *)(DAT_037fa31c + 4 & 0xfffffffc);
  local_8 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & DAT_037fa320;
  if ((((*(uint *)(DAT_037fa324 & 0xfffffffc) >> (DAT_037fa324 & 3) * 8 |
        *(uint *)(DAT_037fa324 & 0xfffffffc) << (DAT_037fa324 & 3) * -8 + 0x20) & 8) != 0) &&
     ((uVar2 & 0x8000) == 0)) {
    bVar4 = 0xfffffffe < local_c;
    local_c = local_c + 1;
    local_8 = local_8 + bVar4;
  }
  FUN_037faf84();
  return CONCAT44(local_8 << 0x10 | local_c >> 0x10,(uint)uVar2 | local_c << 0x10);
}

