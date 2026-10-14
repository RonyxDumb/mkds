/* Decompiled C draft; module arm9; ROM address 02057d9c. No matching claim. */
#include "types.h"
#include "deps/02057d9c_WaitForWorkerTask.h"

void WaitForWorkerTask(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = uRam02057dec;
  uVar2 = (*(uint *)(uRam02057dec & 0xfffffffc) >> (uRam02057dec & 3) * 8 |
          *(uint *)(uRam02057dec & 0xfffffffc) << (uRam02057dec & 3) * -8 + 0x20) + 0xf8;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
    return;
  }
  do {
    WaitForIRQ(1,1);
    uVar2 = uVar1 & 3;
    uVar3 = *(uint *)(uVar1 & 0xfffffffc);
    uVar2 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0xf8;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  } while (uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0);
  return;
}

