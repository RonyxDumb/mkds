/* Decompiled C draft; module arm9; ROM address 02120a64. No matching claim. */
#include "types.h"
#include "deps/02120a64_func_02120a64.h"

int func_02120a64(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = func_0x021a2a88(param_1,(*(uint *)(uRam02120b70 & 0xfffffffc) >> (uRam02120b70 & 3) * 8 |
                                  *(uint *)(uRam02120b70 & 0xfffffffc) <<
                                  (uRam02120b70 & 3) * -8 + 0x20) + iRam02120b74,5);
  uVar2 = func_0x021a2a88(param_1,(*(uint *)(uRam02120b70 & 0xfffffffc) >> (uRam02120b70 & 3) * 8 |
                                  *(uint *)(uRam02120b70 & 0xfffffffc) <<
                                  (uRam02120b70 & 3) * -8 + 0x20) + iRam02120b78,3);
  iVar3 = func_0x021a2a88(param_1,(*(uint *)(uRam02120b70 & 0xfffffffc) >> (uRam02120b70 & 3) * 8 |
                                  *(uint *)(uRam02120b70 & 0xfffffffc) <<
                                  (uRam02120b70 & 3) * -8 + 0x20) + iRam02120b7c,0xffffffff);
  if (((iVar1 == 5) || (uVar2 == 3)) || (iVar3 < 0)) {
    return 0;
  }
  if (iVar1 == 4) {
    if (uVar2 == (*(byte *)((*(uint *)(uRam02120b70 & 0xfffffffc) >> (uRam02120b70 & 3) * 8 |
                            *(uint *)(uRam02120b70 & 0xfffffffc) << (uRam02120b70 & 3) * -8 + 0x20)
                           + 0x450) & 0xf)) {
      iVar1 = 1;
    }
    else {
      iVar1 = 2;
    }
    return iVar1 * 2000;
  }
  if (iVar1 == 1) {
    uVar4 = *(uint *)(uRam02120b70 & 0xfffffffc) >> (uRam02120b70 & 3) * 8 |
            *(uint *)(uRam02120b70 & 0xfffffffc) << (uRam02120b70 & 3) * -8 + 0x20;
    iVar1 = (int)*(short *)(uVar4 + 0x43e);
    if (iVar3 < iVar1) {
      iVar1 = iVar1 - iVar3;
    }
    else {
      iVar1 = iVar3 - iVar1;
    }
    if (iVar1 < 1000) {
      if (uVar2 == (*(byte *)(uVar4 + 0x450) & 0xf)) {
        iVar1 = 1000 - iVar1;
      }
      else {
        iVar1 = 2000 - iVar1;
      }
      return iVar1;
    }
  }
  return 0;
}

