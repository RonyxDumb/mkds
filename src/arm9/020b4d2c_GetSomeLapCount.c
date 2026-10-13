/* Decompiled C draft; module arm9; ROM address 020b4d2c. No matching claim. */
#include "types.h"
#include "deps/020b4d2c_GetSomeLapCount.h"

uint GetSomeLapCount(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = *(uint *)(uRam020b4d98 & 0xfffffffc) >> (uRam020b4d98 & 3) * 8 |
          *(uint *)(uRam020b4d98 & 0xfffffffc) << (uRam020b4d98 & 3) * -8 + 0x20;
  uVar3 = uVar5 + 0xc & 3;
  uVar2 = *(uint *)(uVar5 + 0xc & 0xfffffffc);
  if ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) == 1) {
    uVar1 = (ushort)*(byte *)(uVar5 + 99);
  }
  else {
    uVar1 = (ushort)*(char *)(uVar5 + 0x62);
  }
  uVar3 = func_0203c8c0(uVar1);
  uVar6 = *(uint *)(uRam020b4d98 & 0xfffffffc) >> (uRam020b4d98 & 3) * 8 |
          *(uint *)(uRam020b4d98 & 0xfffffffc) << (uRam020b4d98 & 3) * -8 + 0x20;
  uVar2 = uVar6 + 0xc & 3;
  uVar5 = *(uint *)(uVar6 + 0xc & 0xfffffffc);
  if ((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) == 1) {
    uVar1 = (ushort)*(byte *)(uVar6 + 99);
  }
  else {
    uVar1 = (ushort)*(char *)(uVar6 + 0x62);
  }
  iVar4 = IsRacerFinishedRace(uVar1);
  if (iVar4 == 0) {
    uVar3 = uVar3 - 1 & 0xffff;
  }
  return uVar3;
}

