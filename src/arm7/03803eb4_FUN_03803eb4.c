/* Decompiled C draft; module arm7; ROM address 03803eb4. No matching claim. */
#include "types.h"
#include "deps/03803eb4_FUN_03803eb4.h"

void FUN_03803eb4(void)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  byte bVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if ((*(uint *)((uint)DAT_03803f84 & 0xfffffffc) >> ((uint)DAT_03803f84 & 3) * 8 == 0 &&
       *(uint *)((uint)DAT_03803f84 & 0xfffffffc) << ((uint)DAT_03803f84 & 3) * -8 + 0x20 == 0) &&
     (*DAT_03803f84 = 1, (*DAT_03803f88 & 1) != 0)) {
    uVar5 = FUN_037f88c4(0x40000);
    uVar2 = *DAT_03803f8c;
    *DAT_03803f8c = 1;
    uVar3 = DAT_03803f90;
    while (uVar1 = uVar3 + 0x10 & 3, uVar6 = *(uint *)(uVar3 + 0x10 & 0xfffffffc),
          (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) != 1) {
      thunk_FUN_038011a4(0x100);
    }
    bVar4 = FUN_03803da4((((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                           *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & DAT_03803f94)
                         >> 6) * 0x20 + 0x2000004);
    *(byte *)(DAT_03803f98 + 5) = *(byte *)(DAT_03803f98 + 5) & 0xfe | bVar4 & 1;
    FUN_03803964(1);
    *DAT_03803f8c = uVar2;
    FUN_037f88c4(uVar5);
  }
  return;
}

