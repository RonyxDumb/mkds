/* Decompiled C draft; module arm9; ROM address 020515b0. No matching claim. */
#include "types.h"
#include "deps/020515b0_func_020515b0.h"

void func_020515b0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = uRam02051638;
  *(undefined4 *)
   ((*(uint *)(uRam02051638 & 0xfffffffc) >> (uRam02051638 & 3) * 8 |
    *(uint *)(uRam02051638 & 0xfffffffc) << (uRam02051638 & 3) * -8 + 0x20) + 0xc) = 0x10;
  uVar1 = uRam0205163c;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(undefined4 *)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0x10) = 1;
  iVar2 = func_02143634(uVar1,param_1);
  if (iVar2 == 7) {
    uVar4 = *(uint *)(uRam02051638 & 0xfffffffc) >> (uRam02051638 & 3) * 8 |
            *(uint *)(uRam02051638 & 0xfffffffc) << (uRam02051638 & 3) * -8 + 0x20;
    uVar3 = uVar4 + 4 & 3;
    uVar5 = *(uint *)(uVar4 + 4 & 0xfffffffc);
    if ((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) == 9) {
      if (uVar4 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
      }
      if (uVar3 == 1) {
        *(undefined1 *)(uVar4 + 0x8a) = 0;
      }
    }
    *(undefined4 *)
     ((*(uint *)(uRam02051638 & 0xfffffffc) >> (uRam02051638 & 3) * 8 |
      *(uint *)(uRam02051638 & 0xfffffffc) << (uRam02051638 & 3) * -8 + 0x20) + 0x10) = 0;
    return;
  }
  return;
}

