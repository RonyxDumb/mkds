/* Decompiled C draft; module arm9; ROM address 01ff8ff8. No matching claim. */
#include "types.h"
#include "deps/01ff8ff8_func_01ff8ff8.h"

void func_01ff8ff8(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  iVar1 = iRam01ff9044;
  puVar5 = (uint *)(param_1 + 8);
  do {
    *puVar5 = (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
              *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) & 0xffffffbf;
    uVar4 = (uint)*(byte *)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20);
    uVar3 = iVar1 + (uVar4 & 0x1f) * 4;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    (*(code *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20))(param_1,uVar4 & 0xe0);
    uVar3 = param_1 + 8 & 3;
    uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc);
  } while (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x20) == 0);
  return;
}

