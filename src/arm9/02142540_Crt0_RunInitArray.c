/* Decompiled C draft; module arm9; ROM address 02142540. No matching claim. */
#include "types.h"
#include "deps/02142540_Crt0_RunInitArray.h"

void Crt0_RunInitArray(void)

{
  code *pcVar1;
  uint uVar2;
  
  uVar2 = uRam02142574;
  while( true ) {
    if (uVar2 == 0) {
      return;
    }
    pcVar1 = (code *)(*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                     *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20);
    if (pcVar1 == (code *)0x0) break;
    (*pcVar1)();
    uVar2 = uVar2 + 4;
  }
  return;
}

