/* Decompiled C draft; module arm9; ROM address 02094e3c. No matching claim. */
#include "types.h"
#include "deps/02094e3c_func_02094e3c.h"

void func_02094e3c(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02094e88 & 0xfffffffc) >> (uRam02094e88 & 3) * 8 |
          *(uint *)(uRam02094e88 & 0xfffffffc) << (uRam02094e88 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (((uVar2 == 3) || (uVar2 == 5)) && (uVar2 = func_02061818(), uVar2 == 0)) {
    return;
  }
  func_0209bf8c(uVar2);
  return;
}

