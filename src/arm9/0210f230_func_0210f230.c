/* Decompiled C draft; module arm9; ROM address 0210f230. No matching claim. */
#include "types.h"
#include "deps/0210f230_func_0210f230.h"

bool func_0210f230(int param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 uVar7;
  
  if (param_1 == 0) {
    uVar3 = func_02108e6c(10);
  }
  else {
    uVar3 = func_02108e6c(0xb);
  }
  uVar6 = iRam0210f348 + param_1 * 0x10;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  if (uVar6 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = *(undefined1 *)((uVar6 - 1) + iRam0210f34c + param_1 * 0x10);
  }
  bVar2 = uVar6 != 0;
  if (bVar2) {
    uVar5 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8;
    iVar1 = *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    if (uVar5 == 0 && iVar1 == 0) {
      if ((((*(uint *)(uRam0210f350 & 0xfffffffc) >> (uRam0210f350 & 3) * 8 |
            *(uint *)(uRam0210f350 & 0xfffffffc) << (uRam0210f350 & 3) * -8 + 0x20) & 1) != 0) &&
         (uVar6 = iRam0210f354 + 0xcU & 3, uVar4 = *(uint *)(iRam0210f354 + 0xcU & 0xfffffffc),
         uVar4 >> uVar6 * 8 != 0 || uVar4 << uVar6 * -8 + 0x20 != 0)) {
        if (uVar5 != 0 || iVar1 != 0) {
          func_0212c6f0(uVar3,0);
        }
        if (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 != 0 ||
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar3,0);
        }
        NNSi_MaybeSndPlayerStartSeq(uVar3,0,param_2);
      }
      func_02105b28(uVar3,uVar7);
    }
    else if ((uVar5 != 0 || iVar1 != 0) &&
            (uVar5 = iRam0210f358 + param_1 * 0x10, uVar4 = uVar5 & 3,
            uVar5 = *(uint *)(uVar5 & 0xfffffffc),
            uVar6 != (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20))) {
      func_02105b28(uVar3,uVar7);
    }
  }
  else {
    func_0212c6f0(uVar3,10);
  }
  return bVar2;
}

