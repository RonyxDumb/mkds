/* Decompiled C draft; module arm9; ROM address 021466d8. No matching claim. */
#include "types.h"
#include "deps/021466d8_MaybeGamecardTransferSY.h"

void MaybeGamecardTransferSY(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  uint uVar4;
  
  iVar1 = iRam02146720;
  uVar4 = iRam02146720 + 0x28U & 3;
  uVar2 = *(uint *)(iRam02146720 + 0x28U & 0xfffffffc);
  uVar3 = iRam02146720 + 0x20U & 3;
  uVar5 = *(uint *)(iRam02146720 + 0x20U & 0xfffffffc);
  MIi_CardDmaCopy32(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20,uRam02146724,
                    uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20,0x200);
  uVar4 = iVar1 + 0x1cU & 3;
  uVar3 = *(uint *)(iVar1 + 0x1cU & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  Card_WriteRomOperation(uVar4 >> 8 | 0xb7000000,uVar4 << 0x18);
  uVar4 = iRam02146728 + 4U & 3;
  uVar3 = *(uint *)(iRam02146728 + 4U & 0xfffffffc);
  *puRam0214672c = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  return;
}

