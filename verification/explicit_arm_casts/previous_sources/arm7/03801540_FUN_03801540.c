/* Decompiled C draft; module arm7; ROM address 03801540. No matching claim. */
#include "types.h"
#include "deps/03801540_FUN_03801540.h"

void FUN_03801540(uint param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if (((*(uint *)((uint)DAT_038015a4 & 0xfffffffc) >> ((uint)DAT_038015a4 & 3) * 8 != 0 ||
        *(uint *)((uint)DAT_038015a4 & 0xfffffffc) << ((uint)DAT_038015a4 & 3) * -8 + 0x20 != 0) &&
      (uVar1 = (uint)(DAT_038015a4 + 1) & 3,
      uVar3 = *(uint *)((uint)(DAT_038015a4 + 1) & 0xfffffffc),
      (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 4)) &&
     (uVar1 = (uint)(DAT_038015a4 + 0x126) & 3,
     uVar3 = *(uint *)((uint)(DAT_038015a4 + 0x126) & 0xfffffffc),
     (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == param_1)) {
    FUN_037faf70();
    puVar2 = DAT_038015a4;
    DAT_038015a4[1] = 5;
    *puVar2 = 0;
    puVar2[0x126] = 0;
    FUN_037faf84();
    FUN_037f9088(DAT_038015a8);
  }
  return;
}

