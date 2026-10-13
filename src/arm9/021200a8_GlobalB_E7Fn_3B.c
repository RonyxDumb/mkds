/* Decompiled C draft; module arm9; ROM address 021200a8. No matching claim. */
#include "types.h"
#include "deps/021200a8_GlobalB_E7Fn_3B.h"

void GlobalB_E7Fn_3B(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = func_02120d14();
  if (iVar1 != 0) {
    uVar2 = *(uint *)(uRam021200ec & 0xfffffffc) >> (uRam021200ec & 3) * 8 |
            *(uint *)(uRam021200ec & 0xfffffffc) << (uRam021200ec & 3) * -8 + 0x20;
    *(undefined2 *)(uVar2 + 0x18) = 4;
    *(undefined2 *)(uVar2 + 0x1a) = 1;
    return;
  }
  return;
}

