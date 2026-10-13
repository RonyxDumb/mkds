/* Decompiled C draft; module arm9; ROM address 0210d120. No matching claim. */
#include "types.h"
#include "deps/0210d120_func_0210d120.h"

void func_0210d120(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = uRam0210d1a0;
  uVar5 = uRam0210d1a0 + 0xc & 3;
  uVar4 = *(uint *)(uRam0210d1a0 + 0xc & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  iVar3 = 0;
  if (0 < (int)(*(uint *)(uRam0210d1a0 & 0xfffffffc) >> (uRam0210d1a0 & 3) * 8 |
               *(uint *)(uRam0210d1a0 & 0xfffffffc) << (uRam0210d1a0 & 3) * -8 + 0x20)) {
    do {
      func_0212c6f0(uVar5,param_1);
      iVar3 = iVar3 + 1;
      *(byte *)(uVar5 + 0x19) = *(byte *)(uVar5 + 0x19) & 0xfb;
      *(byte *)(uVar5 + 0x19) = *(byte *)(uVar5 + 0x19) & 0xf7;
      *(byte *)(uVar5 + 0x19) = *(byte *)(uVar5 + 0x19) & 0xfd;
      uVar4 = uVar1 + 0x10 & 3;
      uVar2 = *(uint *)(uVar1 + 0x10 & 0xfffffffc);
      uVar5 = uVar5 + (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20);
    } while (iVar3 < (int)(*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20));
    return;
  }
  return;
}

