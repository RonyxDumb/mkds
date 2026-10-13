/* Decompiled C draft; module arm9; ROM address 0209d394. No matching claim. */
#include "types.h"
#include "deps/0209d394_func_0209d394.h"

void func_0209d394(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = uRam0209d3f8;
  if (param_1 == 0) {
    return;
  }
  iVar5 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iVar5) {
      return;
    }
    uVar4 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar5 * 4;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
    if (uVar4 == 0) break;
    uVar3 = uVar1 & 3;
    uVar2 = *(uint *)(uVar1 & 0xfffffffc);
    uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 8;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    if (uVar3 == 1) {
      uVar3 = uVar4 + 0x9c & 3;
      uVar2 = *(uint *)(uVar4 + 0x9c & 0xfffffffc);
      *(uint *)(uVar4 + 0xa8) =
           (uint)*(ushort *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x28);
    }
    else if (uVar3 == 5) {
      uVar3 = uVar4 + 0x9c & 3;
      uVar2 = *(uint *)(uVar4 + 0x9c & 0xfffffffc);
      *(uint *)(uVar4 + 0xa8) =
           (uint)*(ushort *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x2a);
    }
    iVar5 = iVar5 + 1;
  }
  return;
}

