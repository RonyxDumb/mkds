/* Decompiled C draft; module arm9; ROM address 020513ac. No matching claim. */
#include "types.h"
#include "deps/020513ac_func_020513ac.h"

void func_020513ac(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = uRam020513fc;
  uVar4 = uRam020513f8;
  *(undefined4 *)
   ((*(uint *)(uRam020513f8 & 0xfffffffc) >> (uRam020513f8 & 3) * 8 |
    *(uint *)(uRam020513f8 & 0xfffffffc) << (uRam020513f8 & 3) * -8 + 0x20) + 0xc) = 0x13;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(undefined4 *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x10) = 1;
  iVar3 = func_02143b7c(uVar2);
  if (iVar3 != 2) {
    func_020533a0();
    return;
  }
  return;
}

