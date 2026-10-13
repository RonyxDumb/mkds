/* Decompiled C draft; module arm7; ROM address 038013f4. No matching claim. */
#include "types.h"
#include "deps/038013f4_FUN_038013f4.h"

void FUN_038013f4(uint param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = DAT_03801430;
  uVar1 = (uint)(DAT_03801430 + 1) & 3;
  uVar3 = *(uint *)((uint)(DAT_03801430 + 1) & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == param_1) {
    DAT_03801430[1] = 5;
    *puVar2 = 0;
    FUN_037f9088((uint *)(uintptr_t)(DAT_03801434));
  }
  return;
}

