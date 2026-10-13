/* Decompiled C draft; module arm9; ROM address 0205a6b4. No matching claim. */
#include "types.h"
#include "deps/0205a6b4_func_0205a6b4.h"

void func_0205a6b4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = uRam0205a718;
  uVar5 = 0;
  do {
    iVar6 = uVar5 * 0x88;
    uVar1 = uVar2 & 3;
    uVar3 = *(uint *)(uVar2 & 0xfffffffc);
    iVar4 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x16c;
    uVar5 = uVar5 + 1 & 0xffff;
    *(undefined4 *)(iVar4 + iVar6) = 0x13;
    iVar4 = iVar4 + iVar6;
    *(undefined4 *)(iVar4 + 4) = 0x13;
    *(undefined4 *)(iVar4 + 8) = 0;
    *(undefined2 *)(iVar4 + 0xc) = 0;
    *(undefined4 *)(iVar4 + 0x10) = 0x13;
    *(undefined2 *)(iVar4 + 0x14) = 0;
  } while (uVar5 < 4);
  return;
}

