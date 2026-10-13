/* Decompiled C draft; module arm7; ROM address 0600bbe8. No matching claim. */
#include "types.h"
#include "deps/0600bbe8_FUN_0600bbe8.h"

undefined4 FUN_0600bbe8(uint param_1)

{
  uint uVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = DAT_0600bc64;
  if (param_1 < 4) {
    uVar2 = (ushort)param_1;
    *(ushort *)
     ((*(uint *)(DAT_0600bc64 & 0xfffffffc) >> (DAT_0600bc64 & 3) * 8 |
      *(uint *)(DAT_0600bc64 & 0xfffffffc) << (DAT_0600bc64 & 3) * -8 + 0x20) + 0x32e) = uVar2;
    *(ushort *)
     ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
      *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x350) = uVar2;
    *DAT_0600bc68 = (ushort)DAT_0600bc6c & *DAT_0600bc68 | uVar2;
    FUN_0600ae2c(*(undefined2 *)
                  ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                   *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x352));
    uVar5 = *(uint *)(DAT_0600bc64 & 0xfffffffc) >> (DAT_0600bc64 & 3) * 8 |
            *(uint *)(DAT_0600bc64 & 0xfffffffc) << (DAT_0600bc64 & 3) * -8 + 0x20;
    uVar4 = uVar5 + 0x340;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(uVar5 + 0x340) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20 | 8;
    uVar3 = 0;
  }
  else {
    uVar3 = 5;
  }
  return uVar3;
}

