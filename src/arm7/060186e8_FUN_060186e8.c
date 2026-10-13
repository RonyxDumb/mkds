/* Decompiled C draft; module arm7; ROM address 060186e8. No matching claim. */
#include "types.h"
#include "deps/060186e8_FUN_060186e8.h"

undefined4 FUN_060186e8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint local_8 [2];
  
  uVar3 = (*(uint *)(DAT_060187d4 & 0xfffffffc) >> (DAT_060187d4 & 3) * 8 |
          *(uint *)(DAT_060187d4 & 0xfffffffc) << (DAT_060187d4 & 3) * -8 + 0x20) + 0x314;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  thunk_FUN_038015ac(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  FUN_060188a4();
  local_8[0] = 0;
  thunk_FUN_03804bbc(0x2c,2,local_8);
  uVar3 = (*(uint *)(DAT_060187d4 & 0xfffffffc) >> (DAT_060187d4 & 3) * 8 |
          *(uint *)(DAT_060187d4 & 0xfffffffc) << (DAT_060187d4 & 3) * -8 + 0x20) + 0x314;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  thunk_FUN_03801540(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  if ((local_8[0] < 0xa4) || (DAT_060187d8 < local_8[0])) {
    uVar4 = 0;
  }
  else {
    local_8[0] = local_8[0] + 2;
    uVar4 = FUN_06009138((*(uint *)(DAT_060187d4 & 0xfffffffc) >> (DAT_060187d4 & 3) * 8 |
                         *(uint *)(DAT_060187d4 & 0xfffffffc) << (DAT_060187d4 & 3) * -8 + 0x20) +
                         0x188);
    uVar2 = DAT_060187d4;
    *(undefined4 *)
     ((*(uint *)(DAT_060187d4 & 0xfffffffc) >> (DAT_060187d4 & 3) * 8 |
      *(uint *)(DAT_060187d4 & 0xfffffffc) << (DAT_060187d4 & 3) * -8 + 0x20) + 0x318) = uVar4;
    uVar5 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
    uVar3 = uVar5 + 0x318;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    if (uVar3 == 0) {
      uVar4 = 0;
    }
    else {
      *(uint *)(uVar5 + 0x318) = uVar3 + 0xc;
      uVar3 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x314;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      thunk_FUN_038015ac(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
      FUN_060188a4();
      uVar3 = (*(uint *)(DAT_060187d4 & 0xfffffffc) >> (DAT_060187d4 & 3) * 8 |
              *(uint *)(DAT_060187d4 & 0xfffffffc) << (DAT_060187d4 & 3) * -8 + 0x20) + 0x318;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      thunk_FUN_03804bbc(0x2a,local_8[0],uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
      uVar3 = (*(uint *)(DAT_060187d4 & 0xfffffffc) >> (DAT_060187d4 & 3) * 8 |
              *(uint *)(DAT_060187d4 & 0xfffffffc) << (DAT_060187d4 & 3) * -8 + 0x20) + 0x314;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      thunk_FUN_03801540(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
      uVar4 = 1;
    }
  }
  return uVar4;
}

