/* Decompiled C draft; module arm9; ROM address 021422a0. No matching claim. */
#include "types.h"
#include "deps/021422a0_func_021422a0.h"

int func_021422a0(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint local_10 [4];
  
  puVar4 = local_10;
  if (param_1 == 0) {
    return 0x20;
  }
  iVar2 = 0;
  param_1 = param_1 & 0xff;
  while (param_1 == 0) {
    puVar4 = (uint *)((int)puVar4 + 1);
    iVar2 = iVar2 + 8;
    param_1 = (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
              *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xff;
  }
  uVar3 = ~param_1 & 0xff |
          (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
          *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xffffff00;
  uVar1 = (4 - ((uint)puVar4 & 3)) * 8 & 0x1f;
  *puVar4 = uVar3 >> uVar1 | uVar3 << 0x20 - uVar1;
  if (((*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
       *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 1) == 0) {
    return iVar2;
  }
  do {
    uVar3 = (int)((*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                  *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xff) >>
            1 | (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xffffff00
    ;
    uVar1 = (4 - ((uint)puVar4 & 3)) * 8 & 0x1f;
    *puVar4 = uVar3 >> uVar1 | uVar3 << 0x20 - uVar1;
    iVar2 = iVar2 + 1;
  } while (((*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
            *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 1) != 0);
  return iVar2;
}

