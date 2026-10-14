/* Decompiled C draft; module arm9; ROM address 0203c25c. No matching claim. */
#include "types.h"
#include "deps/0203c25c_UpdatePlayerLapCountIfNot123.h"

bool UpdatePlayerLapCountIfNot123(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  bVar4 = false;
  uVar2 = (*(uint *)(uRam0203c2e0 & 0xfffffffc) >> (uRam0203c2e0 & 3) * 8 |
          *(uint *)(uRam0203c2e0 & 0xfffffffc) << (uRam0203c2e0 & 3) * -8 + 0x20) + param_1 * 0x8c +
          0x14;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (((uVar2 == 1) || (uVar2 == 2)) || (uVar2 == 3)) {
    bVar4 = true;
  }
  bVar4 = !bVar4;
  if (bVar4) {
    uVar3 = GetCurrentLapCount();
    uVar2 = (*(uint *)(uRam0203c2e0 & 0xfffffffc) >> (uRam0203c2e0 & 3) * 8 |
            *(uint *)(uRam0203c2e0 & 0xfffffffc) << (uRam0203c2e0 & 3) * -8 + 0x20) + param_1 * 0x8c
            + 0x38;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == uVar3) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
  }
  return bVar4;
}

