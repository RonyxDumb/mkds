/* Decompiled C draft; module arm9; ROM address 0207a790. No matching claim. */
#include "types.h"
#include "deps/0207a790_func_0207a790.h"

void func_0207a790(undefined4 param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  puVar1 = puRam0207a7e8;
  uVar3 = 0;
  *puRam0207a7e8 = 0;
  do {
    iVar2 = func_02040de0(param_1,uVar3);
    if (iVar2 != 0) {
      *puVar1 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20 |
                1 << (uVar3 & 0xff);
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 8);
  return;
}

