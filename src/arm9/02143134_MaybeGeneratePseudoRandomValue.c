/* Decompiled C draft; module arm9; ROM address 02143134. No matching claim. */
#include "types.h"
#include "deps/02143134_MaybeGeneratePseudoRandomValue.h"

uint MaybeGeneratePseudoRandomValue(void)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  byte local_10 [16];
  
  pbVar1 = local_10;
  Os_GetMacAddress((undefined4)(uintptr_t)(local_10));
  iVar2 = 0;
  uVar3 = 0;
  do {
    iVar2 = iVar2 + 1;
    uVar3 = uVar3 + *pbVar1 & 0xffff;
    pbVar1 = pbVar1 + 1;
  } while (iVar2 < 6);
  uVar3 = (uVar3 + (*(uint *)(uRam021431cc & 0xfffffffc) >> (uRam021431cc & 3) * 8 |
                   *(uint *)(uRam021431cc & 0xfffffffc) << (uRam021431cc & 3) * -8 + 0x20) & 0xffff)
          * 0x70000 >> 0x10;
  return (uVar3 - iRam021431d4 * (int)((longlong)iRam021431d0 * (longlong)(int)uVar3 >> 0x23)) + 200
         & 0xffff;
}

