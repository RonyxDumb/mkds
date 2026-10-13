/* Decompiled C draft; module arm9; ROM address 020532dc. No matching claim. */
#include "types.h"
#include "deps/020532dc_func_020532dc.h"

void func_020532dc(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = uRam02053340;
  uVar4 = uRam0205333c;
  *(undefined4 *)
   ((*(uint *)(uRam0205333c & 0xfffffffc) >> (uRam0205333c & 3) * 8 |
    *(uint *)(uRam0205333c & 0xfffffffc) << (uRam0205333c & 3) * -8 + 0x20) + 0xc) = 3;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(undefined4 *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x10) = 1;
  iVar3 = func_021454c4(uRam02053344,uVar2,param_1,uVar2,0xf);
  if (iVar3 != 2) {
    func_020533a0();
    return;
  }
  return;
}

