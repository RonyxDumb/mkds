/* Decompiled C draft; module arm9; ROM address 021106a8. No matching claim. */
#include "types.h"
#include "deps/021106a8_func_021106a8.h"

void func_021106a8(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 3;
  if (param_1 == 0xc) {
    if (param_2 == 0) {
      uVar1 = 0x47;
    }
    else {
      uVar1 = 0x48;
    }
    uVar2 = 0;
  }
  else {
    uVar1 = param_2 + param_1 * 2 & 0xffff;
  }
  NNSi_MaybeSndPlayerStartSeq(uRam0211071c,uVar2,uVar1);
  if (*(uint *)(uRam0211071c & 0xfffffffc) >> (uRam0211071c & 3) * 8 != 0 ||
      *(uint *)(uRam0211071c & 0xfffffffc) << (uRam0211071c & 3) * -8 + 0x20 != 0) {
    func_02105b28(uRam0211071c,100);
  }
  NNSi_MaybeSndPlayerStartSeq(uRam0211071c,0,4);
  return;
}

