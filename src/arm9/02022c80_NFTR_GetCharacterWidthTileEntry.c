/* Decompiled C draft; module arm9; ROM address 02022c80. No matching claim. */
#include "types.h"
#include "deps/02022c80_NFTR_GetCharacterWidthTileEntry.h"

int NFTR_GetCharacterWidthTileEntry(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  ushort *puVar3;
  
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar2 = uVar1 + 0xc;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  puVar3 = (ushort *)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20);
  while( true ) {
    if (puVar3 == (ushort *)0x0) {
      return uVar1 + 4;
    }
    if ((*puVar3 <= param_2) && (param_2 <= puVar3[1])) break;
    uVar2 = (uint)(puVar3 + 2) & 3;
    uVar4 = *(uint *)((uint)(puVar3 + 2) & 0xfffffffc);
    puVar3 = (ushort *)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
  }
  return (int)puVar3 + (uint)*(ushort *)(param_1 + 10) * (param_2 - *puVar3) + 8;
}

