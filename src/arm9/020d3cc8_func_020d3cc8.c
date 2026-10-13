/* Decompiled C draft; module arm9; ROM address 020d3cc8. No matching claim. */
#include "types.h"
#include "deps/020d3cc8_func_020d3cc8.h"

void func_020d3cc8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  uVar3 = *(uint *)(uRam020d3d0c & 0xfffffffc) >> (uRam020d3d0c & 3) * 8 |
          *(uint *)(uRam020d3d0c & 0xfffffffc) << (uRam020d3d0c & 3) * -8 + 0x20;
  uVar4 = (uint)*(ushort *)(uVar3 + 0x174);
  if (uVar4 != 0) {
    do {
      uVar2 = uVar3 + 0x134 + iVar5 * 4;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      func_020e6fd4(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)uVar4);
    return;
  }
  return;
}

