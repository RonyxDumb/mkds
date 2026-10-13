/* Decompiled C draft; module arm9; ROM address 020514c0. No matching claim. */
#include "types.h"
#include "deps/020514c0_func_020514c0.h"

void func_020514c0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = uRam02051524;
  *(undefined4 *)
   ((*(uint *)(uRam02051524 & 0xfffffffc) >> (uRam02051524 & 3) * 8 |
    *(uint *)(uRam02051524 & 0xfffffffc) << (uRam02051524 & 3) * -8 + 0x20) + 0xc) = 0x11;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10) = 1;
  uVar2 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x15bc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  iVar3 = func_02145030(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  *(undefined4 *)
   ((*(uint *)(uRam02051524 & 0xfffffffc) >> (uRam02051524 & 3) * 8 |
    *(uint *)(uRam02051524 & 0xfffffffc) << (uRam02051524 & 3) * -8 + 0x20) + 0x10) = 0;
  if (iVar3 != 0) {
    func_020533a0();
    return;
  }
  return;
}

