/* Decompiled C draft; module arm9; ROM address 02120c30. No matching claim. */
#include "types.h"
#include "deps/02120c30_func_02120c30.h"

int func_02120c30(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = func_0x021a2a88(param_1,(*(uint *)(uRam02120d04 & 0xfffffffc) >> (uRam02120d04 & 3) * 8 |
                                  *(uint *)(uRam02120d04 & 0xfffffffc) <<
                                  (uRam02120d04 & 3) * -8 + 0x20) + iRam02120d08,5);
  iVar2 = func_0x021a2a88(param_1,(*(uint *)(uRam02120d04 & 0xfffffffc) >> (uRam02120d04 & 3) * 8 |
                                  *(uint *)(uRam02120d04 & 0xfffffffc) <<
                                  (uRam02120d04 & 3) * -8 + 0x20) + iRam02120d0c,3);
  iVar3 = func_0x021a2a88(param_1,(*(uint *)(uRam02120d04 & 0xfffffffc) >> (uRam02120d04 & 3) * 8 |
                                  *(uint *)(uRam02120d04 & 0xfffffffc) <<
                                  (uRam02120d04 & 3) * -8 + 0x20) + iRam02120d10,0xffffffff);
  if (((iVar1 == 5) || (iVar2 == 3)) || (iVar3 < 0)) {
    return 0;
  }
  iVar2 = (int)*(short *)((*(uint *)(uRam02120d04 & 0xfffffffc) >> (uRam02120d04 & 3) * 8 |
                          *(uint *)(uRam02120d04 & 0xfffffffc) << (uRam02120d04 & 3) * -8 + 0x20) +
                         0x43e);
  if (iVar3 < iVar2) {
    iVar2 = iVar2 - iVar3;
  }
  else {
    iVar2 = iVar3 - iVar2;
  }
  if (iVar2 < 1000) {
    if (iVar1 == 1) {
      return 2000 - iVar2;
    }
    if (iVar1 == 4) {
      return 1000 - iVar2;
    }
  }
  return 0;
}

