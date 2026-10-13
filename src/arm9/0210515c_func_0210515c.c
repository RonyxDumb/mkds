/* Decompiled C draft; module arm9; ROM address 0210515c. No matching claim. */
#include "types.h"
#include "deps/0210515c_func_0210515c.h"

void func_0210515c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = uRam021051d0;
  uVar1 = uRam021051cc;
  *(undefined4 *)
   ((*(uint *)(uRam021051cc & 0xfffffffc) >> (uRam021051cc & 3) * 8 |
    *(uint *)(uRam021051cc & 0xfffffffc) << (uRam021051cc & 3) * -8 + 0x20) + param_1 * 0x210 + 0x14
   ) = 0x13;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar2 = uVar4 + 8;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) != 5) {
    return;
  }
  if (param_1 != *(char *)(uVar4 + 0x62)) {
    uVar2 = uVar1 & 3;
    uVar3 = *(uint *)(uVar1 & 0xfffffffc);
    func_020efd84((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + param_1 * 0x210,0xe);
    return;
  }
  return;
}

