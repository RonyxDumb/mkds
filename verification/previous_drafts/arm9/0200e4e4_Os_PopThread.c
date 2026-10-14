/* Decompiled C draft; module arm9; ROM address 0200e4e4. No matching claim. */
#include "types.h"
#include "deps/0200e4e4_Os_PopThread.h"

void Os_PopThread(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = iRam0200e528 + 8U & 3;
  uVar3 = *(uint *)(iRam0200e528 + 8U & 0xfffffffc);
  uVar1 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar3 = 0;
  while ((uVar2 = uVar1, uVar2 != 0 && (uVar2 != param_1))) {
    uVar1 = uVar2 + 0x68 & 3;
    uVar3 = *(uint *)(uVar2 + 0x68 & 0xfffffffc);
    uVar1 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar3 = uVar2;
  }
  if (uVar3 == 0) {
    uVar1 = param_1 + 0x68 & 3;
    uVar3 = *(uint *)(param_1 + 0x68 & 0xfffffffc);
    *(uint *)(iRam0200e528 + 8) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  }
  else {
    uVar1 = param_1 + 0x68 & 3;
    uVar2 = *(uint *)(param_1 + 0x68 & 0xfffffffc);
    *(uint *)(uVar3 + 0x68) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  return;
}

