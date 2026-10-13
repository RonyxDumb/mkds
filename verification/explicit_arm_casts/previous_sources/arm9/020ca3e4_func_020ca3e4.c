/* Decompiled C draft; module arm9; ROM address 020ca3e4. No matching claim. */
#include "types.h"
#include "deps/020ca3e4_func_020ca3e4.h"

void func_020ca3e4(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 0;
  do {
    uVar3 = iRam020ca430 + iVar4 * 4;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    iVar4 = iVar4 + 1;
    uVar3 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 0xa8 +
            (*(uint *)(uRam020ca42c & 0xfffffffc) >> (uRam020ca42c & 3) * 8 |
            *(uint *)(uRam020ca42c & 0xfffffffc) << (uRam020ca42c & 3) * -8 + 0x20) + 0xc;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    iVar2 = iVar2 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  } while (iVar4 < 10);
  func_020c0ba8(uRam020ca434,iVar2);
  return;
}

