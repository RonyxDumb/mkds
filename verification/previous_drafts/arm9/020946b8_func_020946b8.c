/* Decompiled C draft; module arm9; ROM address 020946b8. No matching claim. */
#include "types.h"
#include "deps/020946b8_func_020946b8.h"

void func_020946b8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = func_02100138(uRam02094720);
  if (uVar2 == 0) {
    return;
  }
  iVar4 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(uVar2 + 4) <= iVar4) {
      return;
    }
    uVar3 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar4 * 4;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    if (uVar3 == 0) break;
    *(undefined4 *)(uVar3 + 0xb4) = 0;
    *(undefined4 *)(uVar3 + 0xb8) = 0;
    iVar4 = iVar4 + 1;
  }
  return;
}

