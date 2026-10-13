/* Decompiled C draft; module arm9; ROM address 020e7a84. No matching claim. */
#include "types.h"
#include "deps/020e7a84_E7Fn2_13.h"

void E7Fn2_13(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  func_02147288(uRam020e7b54,uRam020e7b58,iRam020e7b5c);
  iVar4 = (*(uint *)((uint)piRam020e7b60 & 0xfffffffc) >> ((uint)piRam020e7b60 & 3) * 8 |
          *(uint *)((uint)piRam020e7b60 & 0xfffffffc) << ((uint)piRam020e7b60 & 3) * -8 + 0x20) -
          iRam020e7b64;
  *piRam020e7b60 = iVar4;
  iVar1 = iRam020e7b5c;
  if (-0x3000 < iVar4) {
    iVar4 = -0x3000;
  }
  uVar2 = iRam020e7b5c + 4U & 3;
  uVar3 = *(uint *)(iRam020e7b5c + 4U & 0xfffffffc);
  iVar4 = (*(uint *)((uint)piRam020e7b68 & 0xfffffffc) >> ((uint)piRam020e7b68 & 3) * 8 |
          *(uint *)((uint)piRam020e7b68 & 0xfffffffc) << ((uint)piRam020e7b68 & 3) * -8 + 0x20) +
          iVar4;
  *piRam020e7b68 = iVar4;
  *(uint *)(iVar1 + 4) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + iVar4;
  if (iVar4 < 1) {
    uVar2 = *(uint *)(uRam020e7b6c & 0xfffffffc) >> (uRam020e7b6c & 3) * 8 |
            *(uint *)(uRam020e7b6c & 0xfffffffc) << (uRam020e7b6c & 3) * -8 + 0x20;
    if ((uVar2 == 0) || (uVar2 == 1)) {
      StateDualHandler_SetState(uRam020e7b70,2);
    }
    else if (uVar2 == 3) {
      StateDualHandler_SetState(uRam020e7b70,3);
    }
    else {
      StateDualHandler_SetState(uRam020e7b70,5);
    }
  }
  *puRam020e7b78 =
       *(uint *)(uRam020e7b74 & 0xfffffffc) >> (uRam020e7b74 & 3) * 8 |
       *(uint *)(uRam020e7b74 & 0xfffffffc) << (uRam020e7b74 & 3) * -8 + 0x20;
  return;
}

