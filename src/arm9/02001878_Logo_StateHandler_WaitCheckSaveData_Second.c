/* Decompiled C draft; module arm9; ROM address 02001878. No matching claim. */
#include "types.h"
#include "deps/02001878_Logo_StateHandler_WaitCheckSaveData_Second.h"

void Logo_StateHandler_WaitCheckSaveData_Second(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = uRam020019a8;
  uVar5 = *(uint *)(uRam020019a0 & 0xfffffffc) >> (uRam020019a0 & 3) * 8 |
          *(uint *)(uRam020019a0 & 0xfffffffc) << (uRam020019a0 & 3) * -8 + 0x20;
  if (*(char *)(uVar5 + 0x28) == '\0') {
    uVar4 = *(uint *)(uRam020019a4 & 0xfffffffc) >> (uRam020019a4 & 3) * 8 |
            *(uint *)(uRam020019a4 & 0xfffffffc) << (uRam020019a4 & 3) * -8 + 0x20;
    uVar2 = uVar4 + 0xc;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
      uVar2 = 0;
    }
    else {
      uVar4 = uVar4 + 0x10;
      uVar2 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    }
  }
  else {
    uVar2 = 1;
  }
  if (uVar2 != 0) {
    return;
  }
  uVar5 = uVar5 + 0x2c;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  if (uVar5 == 0) {
    uVar2 = *(uint *)(uRam020019a8 & 0xfffffffc) >> (uRam020019a8 & 3) * 8 |
            *(uint *)(uRam020019a8 & 0xfffffffc) << (uRam020019a8 & 3) * -8 + 0x20;
    uVar5 = uVar2 + 0x2c & 3;
    uVar3 = *(uint *)(uVar2 + 0x2c & 0xfffffffc);
    if (-1 < (int)((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) << 0x1f)) {
      *(undefined2 *)(uVar2 + 0x28) = 8;
      *(undefined2 *)(uVar2 + 0x2a) = 1;
      return;
    }
    *(undefined2 *)(uVar2 + 0x28) = 5;
    *(undefined2 *)(uVar2 + 0x2a) = 1;
    return;
  }
  if (uVar5 == 3) {
    uVar4 = *(uint *)(uRam020019a8 & 0xfffffffc) >> (uRam020019a8 & 3) * 8 |
            *(uint *)(uRam020019a8 & 0xfffffffc) << (uRam020019a8 & 3) * -8 + 0x20;
    uVar5 = uVar4 + 0x2c;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar4 + 0x2c) = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20 | 2;
    uVar5 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    *(undefined2 *)(uVar5 + 0x28) = 2;
    *(undefined2 *)(uVar5 + 0x2a) = 1;
    return;
  }
  uVar5 = (*(uint *)(uRam020019a4 & 0xfffffffc) >> (uRam020019a4 & 3) * 8 |
          *(uint *)(uRam020019a4 & 0xfffffffc) << (uRam020019a4 & 3) * -8 + 0x20) + 4;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) != 4) {
    uVar5 = *(uint *)(uRam020019a8 & 0xfffffffc) >> (uRam020019a8 & 3) * 8 |
            *(uint *)(uRam020019a8 & 0xfffffffc) << (uRam020019a8 & 3) * -8 + 0x20;
    *(undefined2 *)(uVar5 + 0x28) = 8;
    *(undefined2 *)(uVar5 + 0x2a) = 1;
    return;
  }
  uVar4 = *(uint *)(uRam020019a8 & 0xfffffffc) >> (uRam020019a8 & 3) * 8 |
          *(uint *)(uRam020019a8 & 0xfffffffc) << (uRam020019a8 & 3) * -8 + 0x20;
  uVar5 = uVar4 + 0x2c;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(uVar4 + 0x2c) = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 0xfffffffd;
  uVar5 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  *(undefined2 *)(uVar5 + 0x28) = 6;
  *(undefined2 *)(uVar5 + 0x2a) = 1;
  return;
}

