/* Decompiled C draft; module arm9; ROM address 02108edc. No matching claim. */
#include "types.h"
#include "deps/02108edc_func_02108edc.h"

void func_02108edc(int param_1,int param_2)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == param_2) {
    if (*puRam02109014 != 0xff) {
      NNSi_MaybeSndPlayerStartSeq(uRam02109018,0);
    }
    if (*puRam02109014 != uRam0210901c) {
      sVar2 = *(short *)((*(uint *)(uRam02109024 & 0xfffffffc) >> (uRam02109024 & 3) * 8 |
                         *(uint *)(uRam02109024 & 0xfffffffc) << (uRam02109024 & 3) * -8 + 0x20) +
                        0x3c);
      if ((sVar2 != 0x65) && (sVar2 != 0xc9)) {
        return;
      }
      NNSi_MaybeSndPlayerStartSeq(uRam02109018,0,0xd4);
      return;
    }
    NNSi_MaybeSndPlayerStartSeq(uRam02109018,0,uRam02109020);
    return;
  }
  sVar2 = *psRam02109028;
  if (sVar2 == 0xff) {
    return;
  }
  if (((*(uint *)(uRam0210902c & 0xfffffffc) >> (uRam0210902c & 3) * 8 |
       *(uint *)(uRam0210902c & 0xfffffffc) << (uRam0210902c & 3) * -8 + 0x20) & 1) != 0) {
    uVar3 = GetSomeSndPlayer(uRam02109030);
    uVar1 = iRam02109034 + 0xcU & 3;
    uVar4 = *(uint *)(iRam02109034 + 0xcU & 0xfffffffc);
    if (uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0) {
      if (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 != 0 ||
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar3,0);
      }
      if (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 != 0 ||
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar3,0);
      }
      NNSi_MaybeSndPlayerStartSeq(uVar3,0,sVar2);
      return;
    }
    return;
  }
  return;
}

