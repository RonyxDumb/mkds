/* Decompiled C draft; module arm9; ROM address 02089ef4. No matching claim. */
#include "types.h"
#include "deps/02089ef4_func_02089ef4.h"

void func_02089ef4(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == 9) {
    *(undefined4 *)
     ((*(uint *)(uRam02089f98 & 0xfffffffc) >> (uRam02089f98 & 3) * 8 |
      *(uint *)(uRam02089f98 & 0xfffffffc) << (uRam02089f98 & 3) * -8 + 0x20) + 0x73c) = 9;
    return;
  }
  uVar3 = (*(uint *)(uRam02089f98 & 0xfffffffc) >> (uRam02089f98 & 3) * 8 |
          *(uint *)(uRam02089f98 & 0xfffffffc) << (uRam02089f98 & 3) * -8 + 0x20) + 0x73c;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) != param_1) || (param_1 == 2)) {
    func_0208a31c();
  }
  uVar4 = uRam02089f98;
  *(undefined2 *)
   ((*(uint *)(uRam02089f98 & 0xfffffffc) >> (uRam02089f98 & 3) * 8 |
    *(uint *)(uRam02089f98 & 0xfffffffc) << (uRam02089f98 & 3) * -8 + 0x20) + 0x740) = 0;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar3 = uVar4 + 0x73c;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  if ((uVar3 != 1) && (uVar3 != 3)) {
    return;
  }
  uVar4 = uVar4 + 0x20;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar3 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 4;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar2 = Animation_GetCurrentLength(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
  *(short *)((*(uint *)(uRam02089f98 & 0xfffffffc) >> (uRam02089f98 & 3) * 8 |
             *(uint *)(uRam02089f98 & 0xfffffffc) << (uRam02089f98 & 3) * -8 + 0x20) + 0x742) =
       (short)(iVar2 >> 0xc);
  return;
}

