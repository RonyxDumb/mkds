/* Decompiled C draft; module arm9; ROM address 02079bcc. No matching claim. */
#include "types.h"
#include "deps/02079bcc_GetCharacterKartModel.h"

uint GetCharacterKartModel(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam02079bec & 0xfffffffc) >> (uRam02079bec & 3) * 8 |
          *(uint *)(uRam02079bec & 0xfffffffc) << (uRam02079bec & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar1 = param_1 * 0xb4 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x14;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar1 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 4;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  return uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
}

