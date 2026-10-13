/* Decompiled C draft; module arm9; ROM address 0210f458. No matching claim. */
#include "types.h"
#include "deps/0210f458_func_0210f458.h"

void func_0210f458(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = *(uint *)(uRam0210f5b4 & 0xfffffffc) >> (uRam0210f5b4 & 3) * 8 |
          *(uint *)(uRam0210f5b4 & 0xfffffffc) << (uRam0210f5b4 & 3) * -8 + 0x20;
  uVar6 = (uint)*(ushort *)(param_1 * 2 + iRam0210f5b8 + uVar4 * 0x10);
  uVar2 = uRam0210f5bc & uVar6;
  if (uVar4 == 3) {
    if (uVar6 == 0x1cc) {
      uVar4 = func_02108e88();
      if (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 != 0 ||
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar4,0);
      }
      uVar4 = func_02108e6c(7);
      if (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 != 0 ||
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar4,0);
      }
    }
  }
  else if (uVar4 == 4) {
    func_02108e38();
  }
  iVar1 = iRam0210f5cc;
  if (uRam0210f5bc <= uVar6) {
    if (3 < uVar2) {
      return;
    }
    uVar2 = ((int)(uVar6 & 0xf000) >> 0xc) - 1U & 0xffff;
    uVar4 = iRam0210f5c8 + uVar2 * 0x10;
    uVar6 = uVar4 & 3;
    uVar5 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = iRam0210f5cc + uVar2 * 0x10;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(iRam0210f5d0 + uVar2 * 0x10) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
    *(uint *)(iVar1 + uVar2 * 0x10) = param_1 - (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
    return;
  }
  if (param_1 < 5) {
    param_1 = param_1 + 7;
  }
  else {
    param_1 = param_1 + 2;
  }
  uVar2 = func_02108e6c(param_1);
  if (((*(uint *)(uRam0210f5c0 & 0xfffffffc) >> (uRam0210f5c0 & 3) * 8 |
       *(uint *)(uRam0210f5c0 & 0xfffffffc) << (uRam0210f5c0 & 3) * -8 + 0x20) & 1) == 0) {
    return;
  }
  uVar4 = iRam0210f5c4 + 0xcU & 3;
  uVar3 = *(uint *)(iRam0210f5c4 + 0xcU & 0xfffffffc);
  if (uVar3 >> uVar4 * 8 == 0 && uVar3 << uVar4 * -8 + 0x20 == 0) {
    return;
  }
  if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
    func_0212c6f0(uVar2,0);
  }
  if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
    func_0212c6f0(uVar2,0);
  }
  NNSi_MaybeSndPlayerStartSeq(uVar2,0,uVar6);
  return;
}

