/* Decompiled C draft; module arm9; ROM address 020a6d8c. No matching claim. */
#include "types.h"
#include "deps/020a6d8c_func_020a6d8c.h"

void func_020a6d8c(undefined4 param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = func_020a1238();
  if (2 < uVar2) {
    return;
  }
  bVar1 = *(byte *)((*(uint *)(uRam020a6e6c & 0xfffffffc) >> (uRam020a6e6c & 3) * 8 |
                    *(uint *)(uRam020a6e6c & 0xfffffffc) << (uRam020a6e6c & 3) * -8 + 0x20) + 0x3d0)
  ;
  iVar3 = func_020a1238();
  iVar4 = func_020a119c();
  if (iVar3 + iVar4 < (int)(bVar1 + 1)) {
    uVar2 = param_2 + 0xa8U & 3;
    uVar5 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    *(uint *)(param_2 + 0xa8) = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 1;
    uVar2 = param_2 + 0xa8U & 3;
    uVar5 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    if ((int)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) < 0x5b) {
      return;
    }
    *(undefined4 *)(param_2 + 0xa8) = 0;
    uVar2 = uRam020a6e6c;
    while( true ) {
      uVar5 = func_020a1238();
      if (2 < uVar5) {
        return;
      }
      uVar5 = uVar2 & 3;
      uVar6 = *(uint *)(uVar2 & 0xfffffffc);
      bVar1 = *(byte *)((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x3d0);
      iVar3 = func_020a1238();
      iVar4 = func_020a119c();
      if ((int)(bVar1 + 1) <= iVar3 + iVar4) break;
      iVar3 = func_020a6f94(param_1);
      if (iVar3 == 0) {
        return;
      }
    }
    return;
  }
  return;
}

