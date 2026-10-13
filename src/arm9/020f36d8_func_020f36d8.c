/* Decompiled C draft; module arm9; ROM address 020f36d8. No matching claim. */
#include "types.h"
#include "deps/020f36d8_func_020f36d8.h"

uint func_020f36d8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar3 != 0) {
    uVar2 = (*(uint *)(uRam020f3714 & 0xfffffffc) >> (uRam020f3714 & 3) * 8 |
            *(uint *)(uRam020f3714 & 0xfffffffc) << (uRam020f3714 & 3) * -8 + 0x20) + 0xb0;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    iVar4 = uVar3 - (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    return (int)((longlong)iRam020f3718 * (longlong)iVar4 >> 0x24) - (iVar4 >> 0x1f) & 0xff;
  }
  return 0xff;
}

