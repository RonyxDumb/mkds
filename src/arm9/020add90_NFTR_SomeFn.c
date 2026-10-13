/* Decompiled C draft; module arm9; ROM address 020add90. No matching claim. */
#include "types.h"
#include "deps/020add90_NFTR_SomeFn.h"

uint NFTR_SomeFn(uint param_1)

{
  uint uVar1;
  
  uVar1 = NFTR_GetTileIndexForCharacter();
  if (uVar1 == uRam020addb4) {
    uVar1 = (uint)*(ushort *)
                   ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 2);
  }
  return uVar1;
}

