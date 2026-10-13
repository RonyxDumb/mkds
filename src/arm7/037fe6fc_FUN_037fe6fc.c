/* Decompiled C draft; module arm7; ROM address 037fe6fc. No matching claim. */
#include "types.h"
#include "deps/037fe6fc_FUN_037fe6fc.h"

uint FUN_037fe6fc(int param_1)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  
  uVar4 = 0;
  piVar3 = (int *)(param_1 + 0x28);
  do {
    uVar2 = param_1 + 0x28U & 3;
    uVar1 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    uVar2 = FUN_037fe7ec(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
    *piVar3 = (*(uint *)((uint)piVar3 & 0xfffffffc) >> ((uint)piVar3 & 3) * 8 |
              *(uint *)((uint)piVar3 & 0xfffffffc) << ((uint)piVar3 & 3) * -8 + 0x20) + 1;
    uVar4 = uVar2 & 0x7f | uVar4 << 7;
  } while ((uVar2 & 0x80) != 0);
  return uVar4;
}

