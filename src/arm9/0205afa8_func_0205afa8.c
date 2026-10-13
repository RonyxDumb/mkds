/* Decompiled C draft; module arm9; ROM address 0205afa8. No matching claim. */
#include "types.h"
#include "deps/0205afa8_func_0205afa8.h"

uint func_0205afa8(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = func_0x0219bb50();
  uVar6 = (int)*(char *)((*(uint *)(uRam0205b0a4 & 0xfffffffc) >> (uRam0205b0a4 & 3) * 8 |
                         *(uint *)(uRam0205b0a4 & 0xfffffffc) << (uRam0205b0a4 & 3) * -8 + 0x20) +
                         iVar2 + 6) & 0xffff;
  iVar2 = func_0205d27c(uVar6);
  uVar3 = Maybe_helper_03c240(uVar6);
  uVar3 = uVar3 & uRam0205b0a8;
  iVar4 = IsRacerFinishedRace(uVar6);
  if (((iVar4 != 0) &&
      (uVar5 = uVar6 * 0x8c +
               (*(uint *)(uRam0205b0ac & 0xfffffffc) >> (uRam0205b0ac & 3) * 8 |
               *(uint *)(uRam0205b0ac & 0xfffffffc) << (uRam0205b0ac & 3) * -8 + 0x20) + 0x14,
      uVar1 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
      (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) != 1)) &&
     (uVar5 = (*(uint *)(uRam0205b0b0 & 0xfffffffc) >> (uRam0205b0b0 & 3) * 8 |
              *(uint *)(uRam0205b0b0 & 0xfffffffc) << (uRam0205b0b0 & 3) * -8 + 0x20) + 0x72c,
     uVar1 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
     uVar5 >> uVar1 * 8 == 0 && uVar5 << uVar1 * -8 + 0x20 == 0)) {
    uVar3 = uRam0205b0a8;
  }
  uVar5 = uVar6 * 0x8c +
          (*(uint *)(uRam0205b0ac & 0xfffffffc) >> (uRam0205b0ac & 3) * 8 |
          *(uint *)(uRam0205b0ac & 0xfffffffc) << (uRam0205b0ac & 3) * -8 + 0x20) + 0x14;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (uVar3 == 0) {
    uVar3 = iVar2 - 1;
  }
  if ((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) == 1) {
    uVar5 = 0;
  }
  else {
    iVar2 = func_0203c8c0(uVar6);
    uVar5 = 6 - iVar2;
  }
  iVar2 = IsRacerFinishedRace(uVar6);
  if ((iVar2 == 0) &&
     (uVar6 = (*(uint *)(uRam0205b0b0 & 0xfffffffc) >> (uRam0205b0b0 & 3) * 8 |
              *(uint *)(uRam0205b0b0 & 0xfffffffc) << (uRam0205b0b0 & 3) * -8 + 0x20) + 0x72c,
     uVar1 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
     uVar6 >> uVar1 * 8 == 0 && uVar6 << uVar1 * -8 + 0x20 == 0)) {
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  return uVar3 | iVar2 << 0x16 | (uVar5 & 7) << 0x13;
}

