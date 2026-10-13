/* Decompiled C draft; module arm7; ROM address 06014a04. No matching claim. */
#include "types.h"
#include "deps/06014a04_FUN_06014a04.h"

void FUN_06014a04(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(DAT_06014b18 & 0xfffffffc) >> (DAT_06014b18 & 3) * 8 |
          *(uint *)(DAT_06014b18 & 0xfffffffc) << (DAT_06014b18 & 3) * -8 + 0x20;
  uVar1 = uVar3 + 0x550 & 3;
  uVar2 = *(uint *)(uVar3 + 0x550 & 0xfffffffc);
  *(uint *)(uVar3 + 0x550) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 1;
  if (((uint)*(ushort *)(param_1 + 0x14) << 0x1c) >> 0x1e == 0) {
    FUN_0600ecf4();
    FUN_06009040(uVar3 + 0x1ac,uVar3 + 0x1a0,param_1 + -0x10);
    FUN_06014b98(param_1,0);
  }
  else {
    FUN_060125a8(uVar3 + 0x1ac,param_1 + -0x10);
  }
  uVar2 = DAT_06014b18;
  *(undefined2 *)
   ((*(uint *)(DAT_06014b18 & 0xfffffffc) >> (DAT_06014b18 & 3) * 8 |
    *(uint *)(DAT_06014b18 & 0xfffffffc) << (DAT_06014b18 & 3) * -8 + 0x20) + 0x454) = 0;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x45c;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if (-1 < (int)((uint)*(ushort *)((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0xc) << 0x12)
     ) {
    *DAT_06014b1c = 8;
    *DAT_06014b20 = 5;
    if (param_2 != 0) {
      if (*(short *)(uVar3 + 0x1a8) != 0) {
        FUN_0601536c(1);
      }
      if (*(short *)(uVar3 + 0x19c) != 0) {
        FUN_0601536c(0);
      }
    }
  }
  if (*(short *)(uVar3 + 0x1b4) == 0) {
    FUN_0600e69c(0);
  }
  else if (param_2 != 0) {
    FUN_0601536c(2);
  }
  return;
}

