/* Decompiled C draft; module arm9; ROM address 020a6cb4. No matching claim. */
#include "types.h"
#include "deps/020a6cb4_func_020a6cb4.h"

void func_020a6cb4(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = func_02100138(0x6b);
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
    if (iVar4 == param_1) {
      *(undefined4 *)(uVar3 + 0xa0) = 0;
      *(undefined4 *)(uVar3 + 0xa4) = 1;
    }
    else {
      *(undefined4 *)(uVar3 + 0xa4) = 0;
    }
    iVar4 = iVar4 + 1;
  }
  return;
}

