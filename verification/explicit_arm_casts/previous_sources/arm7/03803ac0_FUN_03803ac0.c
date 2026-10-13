/* Decompiled C draft; module arm7; ROM address 03803ac0. No matching claim. */
#include "types.h"
#include "deps/03803ac0_FUN_03803ac0.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_03803ac0(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 auStack_18 [8];
  undefined1 auStack_10 [8];
  
  uVar3 = 1;
  if (*DAT_03803bbc == DAT_03803bc0) {
    uVar3 = 0;
  }
  else if ((int)((uint)*(byte *)((int)DAT_03803bbc + 5) << 0x1e) < 0) {
    uVar3 = 0;
  }
  else {
    FUN_038039d4(*(undefined2 *)(DAT_03803bc4 + 2),auStack_18);
    FUN_03803a78(auStack_10);
    if ((((DAT_080000b2 == -0x6a) && (*DAT_03803bbc != _DAT_080000be)) ||
        ((DAT_080000b2 != -0x6a && (*DAT_03803bbc != *DAT_03803bc8)))) ||
       ((uVar1 = (uint)(DAT_03803bbc + 4) & 3,
        uVar2 = *(uint *)((uint)(DAT_03803bbc + 4) & 0xfffffffc),
        (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != _DAT_080000ac &&
        ((int)((uint)*(byte *)((int)DAT_03803bbc + 5) << 0x1f) < 0)))) {
      *(byte *)((int)DAT_03803bbc + 5) = *(byte *)((int)DAT_03803bbc + 5) | 2;
      uVar3 = 0;
    }
    FUN_03803a44(auStack_10);
    FUN_038039ac(*(undefined2 *)(DAT_03803bc4 + 2),auStack_18);
  }
  return uVar3;
}

