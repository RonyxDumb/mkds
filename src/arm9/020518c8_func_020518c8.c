/* Decompiled C draft; module arm9; ROM address 020518c8. No matching claim. */
#include "types.h"
#include "deps/020518c8_func_020518c8.h"

void func_020518c8(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = uRam02051950;
  *(undefined4 *)
   ((*(uint *)(uRam02051950 & 0xfffffffc) >> (uRam02051950 & 3) * 8 |
    *(uint *)(uRam02051950 & 0xfffffffc) << (uRam02051950 & 3) * -8 + 0x20) + 0xc) = 0xc;
  uVar1 = uRam02051954;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(undefined4 *)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x10) = 1;
  iVar2 = func_021441d0(uVar1,param_1);
  uVar3 = uRam02051950;
  if (iVar2 == 0) {
    *(undefined4 *)
     ((*(uint *)(uRam02051950 & 0xfffffffc) >> (uRam02051950 & 3) * 8 |
      *(uint *)(uRam02051950 & 0xfffffffc) << (uRam02051950 & 3) * -8 + 0x20) + 0x10) = 0;
    return;
  }
  if (iVar2 != 2) {
    *(undefined4 *)
     ((*(uint *)(uRam02051950 & 0xfffffffc) >> (uRam02051950 & 3) * 8 |
      *(uint *)(uRam02051950 & 0xfffffffc) << (uRam02051950 & 3) * -8 + 0x20) + 8) = 2;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(undefined4 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x10) = 0;
    return;
  }
  return;
}

