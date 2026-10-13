/* Decompiled C draft; module arm9; ROM address 021200fc. No matching claim. */
#include "types.h"
#include "deps/021200fc_GlobalB_E7Fn_1B.h"

void GlobalB_E7Fn_1B(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = func_0211f91c();
  if (iVar1 != 0) {
    uVar2 = *(uint *)(uRam02120140 & 0xfffffffc) >> (uRam02120140 & 3) * 8 |
            *(uint *)(uRam02120140 & 0xfffffffc) << (uRam02120140 & 3) * -8 + 0x20;
    *(undefined2 *)(uVar2 + 0x18) = 2;
    *(undefined2 *)(uVar2 + 0x1a) = 1;
    return;
  }
  return;
}

