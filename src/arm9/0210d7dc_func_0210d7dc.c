/* Decompiled C draft; module arm9; ROM address 0210d7dc. No matching claim. */
#include "types.h"
#include "deps/0210d7dc_func_0210d7dc.h"

void func_0210d7dc(undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  
  if (*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 != 0 ||
      *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20 != 0) {
    func_0212c6f0(param_3,0);
  }
  uVar1 = NNS_SndArcGetSeqInfo(param_1);
  Sound_MaybeGetRawFilePointer
            (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
             *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20);
  func_0212ed58(param_3,param_1);
  func_0212c678(param_3,param_2);
  return;
}

