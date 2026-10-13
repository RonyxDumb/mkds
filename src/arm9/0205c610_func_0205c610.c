/* Decompiled C draft; module arm9; ROM address 0205c610. No matching claim. */
#include "types.h"
#include "deps/0205c610_func_0205c610.h"

void func_0205c610(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = uRam0205c680;
  uVar4 = *(uint *)(uRam0205c680 & 0xfffffffc) >> (uRam0205c680 & 3) * 8 |
          *(uint *)(uRam0205c680 & 0xfffffffc) << (uRam0205c680 & 3) * -8 + 0x20;
  uVar1 = uVar4 + 0x754 & 3;
  uVar5 = *(uint *)(uVar4 + 0x754 & 0xfffffffc);
  uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  *(short *)(uVar5 + 4) = *(short *)(uVar4 + 0x736) - *(short *)(param_1 * 0x88 + uVar4 + 0x188);
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(undefined1 *)(uVar5 + 8) =
       *(undefined1 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0xfb);
  iVar2 = func_0205c340(param_1 & 0xff,2,8);
  if (iVar2 != 0) {
    *(short *)((*(uint *)(uRam0205c680 & 0xfffffffc) >> (uRam0205c680 & 3) * 8 |
               *(uint *)(uRam0205c680 & 0xfffffffc) << (uRam0205c680 & 3) * -8 + 0x20) + 0x734) =
         (short)param_1;
  }
  return;
}

