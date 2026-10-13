/* Decompiled C draft; module arm9; ROM address 0200e5c4. No matching claim. */
#include "types.h"
#include "deps/0200e5c4_Os_ThreadQueue_Pop.h"

uint Os_ThreadQueue_Pop(uint *param_1)

{
  uint uVar1;
  uint uVar3;
  uint uVar2;
  
  uVar3 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  if (uVar3 != 0) {
    uVar2 = uVar3 + 0x80 & 3;
    uVar1 = *(uint *)(uVar3 + 0x80 & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    *param_1 = uVar2;
    if (uVar2 == 0) {
      param_1[1] = 0;
      *(undefined4 *)(uVar3 + 0x78) = 0;
    }
    else {
      *(undefined4 *)(uVar2 + 0x7c) = 0;
    }
  }
  return uVar3;
}

