/* Decompiled C draft; module arm7; ROM address 037f9960. No matching claim. */
#include "types.h"
#include "deps/037f9960_FUN_037f9960.h"

void FUN_037f9960(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  while (uVar1 = param_1 + 0x6cU & 3, uVar3 = *(uint *)(param_1 + 0x6cU & 0xfffffffc),
        uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
    iVar2 = FUN_037f9584((uint *)(uintptr_t)(param_1 + 0x6c));
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar2 + 8) = 0;
    FUN_037f9088();
  }
  return;
}

