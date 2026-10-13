/* Decompiled C draft; module arm9; ROM address 020747f4. No matching claim. */
#include "types.h"
#include "deps/020747f4_func_020747f4.h"

void func_020747f4(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = uRam02074824;
  *(int *)((*(uint *)(uRam02074824 & 0xfffffffc) >> (uRam02074824 & 3) * 8 |
           *(uint *)(uRam02074824 & 0xfffffffc) << (uRam02074824 & 3) * -8 + 0x20) + 0x248) =
       param_1;
  if (param_1 == 0) {
    return;
  }
  uVar4 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
  uVar3 = uVar4 + 0x28;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar4 + 0xcc) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xd0) = 0;
  return;
}

