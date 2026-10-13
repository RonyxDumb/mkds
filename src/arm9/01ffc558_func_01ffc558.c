/* Decompiled C draft; module arm9; ROM address 01ffc558. No matching claim. */
#include "types.h"
#include "deps/01ffc558_func_01ffc558.h"

void func_01ffc558(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(uRam01ffc594 & 0xfffffffc) >> (uRam01ffc594 & 3) * 8 |
          *(uint *)(uRam01ffc594 & 0xfffffffc) << (uRam01ffc594 & 3) * -8 + 0x20;
  uVar1 = uVar2 + 8;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) != 4) {
    return;
  }
  if ((*(ushort *)(uVar2 + 0x44) & 1) == 0) {
    return;
  }
  uVar1 = param_1 + 0x78U & 3;
  uVar3 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  *(short *)(iRam01ffc59c + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 0x5c) =
       (short)uRam01ffc598;
  return;
}

