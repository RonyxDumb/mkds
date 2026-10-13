/* Decompiled C draft; module arm9; ROM address 0205a750. No matching claim. */
#include "types.h"
#include "deps/0205a750_func_0205a750.h"

void func_0205a750(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = func_0x0219bb50();
  uVar2 = uRam0205a7a8;
  iVar4 = (*(uint *)(uRam0205a7a8 & 0xfffffffc) >> (uRam0205a7a8 & 3) * 8 |
          *(uint *)(uRam0205a7a8 & 0xfffffffc) << (uRam0205a7a8 & 3) * -8 + 0x20) + 0x16c;
  iVar5 = iVar4 + iVar1 * 0x88;
  *(undefined2 *)(iVar5 + 0xe) = 0;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x728;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(undefined2 *)(iVar5 + 0xc) = 2;
  *(undefined4 *)(iVar4 + iVar1 * 0x88) = param_1;
  *(uint *)(iVar5 + 8) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x78;
  *(undefined4 *)(iVar5 + 4) = 0x13;
  return;
}

