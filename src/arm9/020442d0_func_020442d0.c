/* Decompiled C draft; module arm9; ROM address 020442d0. No matching claim. */
#include "types.h"
#include "deps/020442d0_func_020442d0.h"

void func_020442d0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = uRam02044378;
  uVar3 = (*(uint *)(uRam02044378 & 0xfffffffc) >> (uRam02044378 & 3) * 8 |
          *(uint *)(uRam02044378 & 0xfffffffc) << (uRam02044378 & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar3 = uVar4 + 8;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar4 + 8) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xfffffffe;
  uVar3 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x1c;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar3 = uVar4 + 8;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar4 + 8) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xfffffffe;
  uVar3 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x14;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar3 = uVar2 + 8;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar2 + 8) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xfffffffe;
  func_02056700();
  WaitForWorkerTask();
  uVar3 = (*(uint *)(uRam0204437c & 0xfffffffc) >> (uRam0204437c & 3) * 8 |
          *(uint *)(uRam0204437c & 0xfffffffc) << (uRam0204437c & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
    func_02145d38();
  }
  uVar3 = (*(uint *)(uRam0204437c & 0xfffffffc) >> (uRam0204437c & 3) * 8 |
          *(uint *)(uRam0204437c & 0xfffffffc) << (uRam0204437c & 3) * -8 + 0x20) + 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
    uVar3 = (*(uint *)(uRam02044378 & 0xfffffffc) >> (uRam02044378 & 3) * 8 |
            *(uint *)(uRam02044378 & 0xfffffffc) << (uRam02044378 & 3) * -8 + 0x20) + 0x14;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar2 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar3 = uVar2 + 8;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar2 + 8) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xfffffffe;
    return;
  }
  return;
}

