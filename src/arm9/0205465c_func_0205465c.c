/* Decompiled C draft; module arm9; ROM address 0205465c. No matching claim. */
#include "types.h"
#include "deps/0205465c_func_0205465c.h"

undefined4 func_0205465c(void)

{
  undefined4 uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(uRam020546d4 & 0xfffffffc) >> (uRam020546d4 & 3) * 8 |
          *(uint *)(uRam020546d4 & 0xfffffffc) << (uRam020546d4 & 3) * -8 + 0x20;
  if (uVar4 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  }
  if (uVar3 != 1) {
    return 2;
  }
  if (uVar4 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  }
  if (uVar3 == 1) {
    if ((*(ushort *)(uVar4 + 0x454) & 0x40) == 0) {
      cVar2 = *(char *)(uVar4 + 0x84);
    }
    else {
      cVar2 = *(char *)(uVar4 + 0x1699);
    }
  }
  else {
    cVar2 = '\0';
  }
  if (cVar2 != '\0') {
    return 0;
  }
  uVar3 = uVar4 + 0x1e38 & 3;
  uVar4 = *(uint *)(uVar4 + 0x1e38 & 0xfffffffc);
  if (uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0) {
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

