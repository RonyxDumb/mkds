/* Decompiled C draft; module arm9; ROM address 02043f28. No matching claim. */
#include "types.h"
#include "deps/02043f28_MaybeReloadRacersSfx.h"

void MaybeReloadRacersSfx(int param_1)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = 0;
  uVar3 = *(uint *)(uRam02043fa8 & 0xfffffffc) >> (uRam02043fa8 & 3) * 8 |
          *(uint *)(uRam02043fa8 & 0xfffffffc) << (uRam02043fa8 & 3) * -8 + 0x20;
  uVar6 = 0;
  if (*(char *)(uVar3 + 0x3d0) != '\0') {
    do {
      if (param_1 == 0) {
        uVar5 = uVar6 * 0x30 + uVar3 + 0x250;
        uVar1 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        uVar2 = *(ushort *)(iRam02043fac + (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) * 2);
      }
      else {
        uVar5 = uVar6 * 0x30 + uVar3 + 0x68;
        uVar1 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        uVar2 = *(ushort *)(iRam02043fac + (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) * 2);
      }
      uVar4 = uVar4 | uVar2;
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < *(byte *)(uVar3 + 0x3d0));
  }
  MaybeReloadRacerSbnksSwars(uVar4);
  return;
}

