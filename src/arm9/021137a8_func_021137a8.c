/* Decompiled C draft; module arm9; ROM address 021137a8. No matching claim. */
#include "types.h"
#include "deps/021137a8_func_021137a8.h"

void func_021137a8(short param_1)

{
  short sVar1;
  int iVar2;
  
  sVar1 = func_02113f1c();
  sVar1 = sVar1 + param_1;
  iVar2 = func_02114398(sVar1);
  if (iVar2 != 0) {
    func_02114260(sVar1);
    NNSi_MaybeSndPlayerStartSeq(uRam021137f0,0,0x25);
    return;
  }
  func_0211427c(sVar1);
  NNSi_MaybeSndPlayerStartSeq(uRam021137f0,0,0x24);
  return;
}

