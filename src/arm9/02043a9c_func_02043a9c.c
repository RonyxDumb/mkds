/* Decompiled C draft; module arm9; ROM address 02043a9c. No matching claim. */
#include "types.h"
#include "deps/02043a9c_func_02043a9c.h"

void func_02043a9c(int param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    uVar1 = *(uint *)(uRam02043ad0 & 0xfffffffc) >> (uRam02043ad0 & 3) * 8 |
            *(uint *)(uRam02043ad0 & 0xfffffffc) << (uRam02043ad0 & 3) * -8 + 0x20;
    *(ushort *)(uVar1 + 4) = *(ushort *)(uVar1 + 4) | 4;
    return;
  }
  uVar1 = *(uint *)(uRam02043ad0 & 0xfffffffc) >> (uRam02043ad0 & 3) * 8 |
          *(uint *)(uRam02043ad0 & 0xfffffffc) << (uRam02043ad0 & 3) * -8 + 0x20;
  *(ushort *)(uVar1 + 4) = *(ushort *)(uVar1 + 4) & 0xfffb;
  return;
}

