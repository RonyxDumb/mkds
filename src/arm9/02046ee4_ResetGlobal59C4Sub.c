/* Decompiled C draft; module arm9; ROM address 02046ee4. No matching claim. */
#include "types.h"
#include "deps/02046ee4_ResetGlobal59C4Sub.h"

void ResetGlobal59C4Sub(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *(uint *)(uRam02046f50 & 0xfffffffc) >> (uRam02046f50 & 3) * 8 |
          *(uint *)(uRam02046f50 & 0xfffffffc) << (uRam02046f50 & 3) * -8 + 0x20;
  uVar1 = uVar2 + 0x30;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((int)((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) << 0x1e) < 0) {
    uVar2 = uVar2 + 0x3c;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    Maybe_helper_10f0d8(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    uVar3 = uRam02046f50;
    *(undefined4 *)
     ((*(uint *)(uRam02046f50 & 0xfffffffc) >> (uRam02046f50 & 3) * 8 |
      *(uint *)(uRam02046f50 & 0xfffffffc) << (uRam02046f50 & 3) * -8 + 0x20) + 0x3c) = 0;
    uVar4 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    uVar1 = uVar4 + 0x30;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    *(uint *)(uVar4 + 0x30) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xfffffffd;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    uVar1 = uVar3 + 0x30;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    *(uint *)(uVar3 + 0x30) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xfffffffb;
    return;
  }
  return;
}

