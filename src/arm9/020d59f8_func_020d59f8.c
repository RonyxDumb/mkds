/* Decompiled C draft; module arm9; ROM address 020d59f8. No matching claim. */
#include "types.h"
#include "deps/020d59f8_func_020d59f8.h"

undefined2 func_020d59f8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint in_r12;
  int iVar5;
  
  iVar5 = -1;
  uVar3 = *(uint *)(uRam020d5a5c & 0xfffffffc) >> (uRam020d5a5c & 3) * 8 |
          *(uint *)(uRam020d5a5c & 0xfffffffc) << (uRam020d5a5c & 3) * -8 + 0x20;
  iVar4 = 0;
  if (0 < (int)uVar3) {
    do {
      uVar2 = iRam020d5a60 + iVar4 * 4;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar2 = param_1 & (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
      if ((uVar2 != 0) && ((iVar5 < 0 || (in_r12 < uVar2)))) {
        in_r12 = uVar2;
        iVar5 = iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)uVar3);
  }
  return *(undefined2 *)(iRam020d5a64 + iVar5 * 2);
}

