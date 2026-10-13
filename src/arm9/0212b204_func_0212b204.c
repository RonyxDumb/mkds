/* Decompiled C draft; module arm9; ROM address 0212b204. No matching claim. */
#include "types.h"
#include "deps/0212b204_func_0212b204.h"

void func_0212b204(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar2 = uRam0212b25c;
  puVar5 = (uint *)(*(uint *)(uRam0212b25c & 0xfffffffc) >> (uRam0212b25c & 3) * 8 |
                   *(uint *)(uRam0212b25c & 0xfffffffc) << (uRam0212b25c & 3) * -8 + 0x20);
  puVar1 = puVar5 + 1;
  uVar3 = (uint)puVar1 & 3;
  uVar4 = *(uint *)((uint)puVar1 & 0xfffffffc);
  *puVar5 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 0) {
    return;
  }
  if (uVar3 == 1) {
    FormatSomeStaffRollBmgString();
    return;
  }
  return;
}

