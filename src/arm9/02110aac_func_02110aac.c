/* Decompiled C draft; module arm9; ROM address 02110aac. No matching claim. */
#include "types.h"
#include "deps/02110aac_func_02110aac.h"

void func_02110aac(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = func_02108e6c(1);
  uVar4 = uRam02110c34;
  if ((param_1 != 0) && (uVar4 = uRam02110c38, param_1 == 1)) {
    uVar4 = 0x200;
  }
  if (uVar4 == uRam02110c38) {
    if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
        *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
      func_0212c6f0(uVar2,0);
    }
  }
  else {
    uVar3 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
    if (((uVar3 == 0) || (*(ushort *)(uVar3 + 0x3a) != uVar4)) || (*(short *)(uVar3 + 0x38) != 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      func_0212c6f0(uVar2,0);
      if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar2,0);
      }
      NNSi_MaybeSndPlayerStartSeq(uVar2,0,uVar4);
    }
  }
  uVar3 = func_02108e6c(2);
  uVar2 = uRam02110c3c;
  if (param_2 == 0) {
    uVar2 = uRam02110c38;
  }
  if (uVar4 != uRam02110c38) {
    uVar2 = uRam02110c38;
  }
  if (uVar2 == uRam02110c38) {
    if (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 == 0 &&
        *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20 == 0) {
      return;
    }
    func_0212c6f0(uVar3,0);
    return;
  }
  uVar4 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  if (((uVar4 == 0) || (*(ushort *)(uVar4 + 0x3a) != uVar2)) || (*(short *)(uVar4 + 0x38) != 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    return;
  }
  func_0212c6f0(uVar3,0);
  if (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 != 0 ||
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20 != 0) {
    func_0212c6f0(uVar3,0);
  }
  NNSi_MaybeSndPlayerStartSeq(uVar3,0,uVar2);
  return;
}

