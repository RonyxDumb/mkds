/* Decompiled C draft; module arm9; ROM address 020b3fb0. No matching claim. */
#include "types.h"
#include "deps/020b3fb0_Bmg_Load_from_thumb.h"

void Bmg_Load_from_thumb(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(param_1 + 0x20);
  for (uVar3 = 0; uVar3 < *(uint *)(param_1 + 0xc); uVar3 = uVar3 + 1) {
    iVar1 = puVar4[1];
    iVar2 = SwapEndianness32_from_thumb(*puVar4);
    if (iVar2 == iRam020b3ff0) {
      *puRam020b3ffc = puVar4;
    }
    else if (iVar2 == iRam020b3ff4) {
      *puRam020b3ff8 = puVar4;
    }
    puVar4 = (undefined4 *)((int)puVar4 + iVar1);
  }
  return;
}

