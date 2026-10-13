/* Decompiled C draft; module arm9; ROM address 0210f35c. No matching claim. */
#include "types.h"
#include "deps/0210f35c_func_0210f35c.h"

bool func_0210f35c(int param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 uVar5;
  
  if (param_1 == 0) {
    uVar2 = func_02108e6c(10);
  }
  else {
    uVar2 = func_02108e6c(0xb);
  }
  uVar4 = iRam0210f448 + param_1 * 0x10;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  if (uVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(undefined1 *)((uVar4 - 1) + iRam0210f44c + param_1 * 0x10);
  }
  bVar1 = uVar4 != 0;
  if (bVar1) {
    if ((((*(uint *)(uRam0210f450 & 0xfffffffc) >> (uRam0210f450 & 3) * 8 |
          *(uint *)(uRam0210f450 & 0xfffffffc) << (uRam0210f450 & 3) * -8 + 0x20) & 1) != 0) &&
       (uVar4 = iRam0210f454 + 0xcU & 3, uVar3 = *(uint *)(iRam0210f454 + 0xcU & 0xfffffffc),
       uVar3 >> uVar4 * 8 != 0 || uVar3 << uVar4 * -8 + 0x20 != 0)) {
      if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar2,0);
      }
      if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar2,0);
      }
      NNSi_MaybeSndPlayerStartSeq(uVar2,0,param_2);
    }
    if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
        *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
      func_02105b28(uVar2,uVar5);
    }
  }
  return bVar1;
}

