/* Decompiled C draft; module arm9; ROM address 0200df3c. No matching claim. */
#include "types.h"
#include "deps/0200df3c_Os_FindReadyThread.h"

void Os_FindReadyThread(void)

{
  uint uVar1;
  uint uVar3;
  uint uVar2;
  
  uVar2 = iRam0200df64 + 8U & 3;
  uVar1 = *(uint *)(iRam0200df64 + 8U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  while( true ) {
    if (uVar2 == 0) {
      return;
    }
    uVar1 = uVar2 + 100 & 3;
    uVar3 = *(uint *)(uVar2 + 100 & 0xfffffffc);
    if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 1) break;
    uVar1 = uVar2 + 0x68 & 3;
    uVar2 = *(uint *)(uVar2 + 0x68 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  return;
}

