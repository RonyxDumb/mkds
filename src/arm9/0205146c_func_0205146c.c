/* Decompiled C draft; module arm9; ROM address 0205146c. No matching claim. */
#include "types.h"
#include "deps/0205146c_func_0205146c.h"

void func_0205146c(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = uRam020514bc;
  uVar4 = uRam020514b8;
  *(undefined4 *)
   ((*(uint *)(uRam020514b8 & 0xfffffffc) >> (uRam020514b8 & 3) * 8 |
    *(uint *)(uRam020514b8 & 0xfffffffc) << (uRam020514b8 & 3) * -8 + 0x20) + 0xc) = 0x12;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(undefined4 *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x10) = 1;
  iVar3 = func_02143fbc(uVar2);
  if (iVar3 != 2) {
    func_020533a0();
    return;
  }
  return;
}

