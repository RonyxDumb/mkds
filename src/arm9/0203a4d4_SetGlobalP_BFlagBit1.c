/* Decompiled C draft; module arm9; ROM address 0203a4d4. No matching claim. */
#include "types.h"
#include "deps/0203a4d4_SetGlobalP_BFlagBit1.h"

void SetGlobalP_BFlagBit1(int param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    uVar1 = *(uint *)(uRam0203a508 & 0xfffffffc) >> (uRam0203a508 & 3) * 8 |
            *(uint *)(uRam0203a508 & 0xfffffffc) << (uRam0203a508 & 3) * -8 + 0x20;
    *(ushort *)(uVar1 + 0x50) = *(ushort *)(uVar1 + 0x50) | 1;
    return;
  }
  uVar1 = *(uint *)(uRam0203a508 & 0xfffffffc) >> (uRam0203a508 & 3) * 8 |
          *(uint *)(uRam0203a508 & 0xfffffffc) << (uRam0203a508 & 3) * -8 + 0x20;
  *(ushort *)(uVar1 + 0x50) = *(ushort *)(uVar1 + 0x50) & 0xfffe;
  return;
}

