/* Decompiled C draft; module arm9; ROM address 020ea868. No matching claim. */
#include "types.h"
#include "deps/020ea868_func_020ea868.h"

void func_020ea868(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 0x6e);
  if (param_4 < uVar1) {
    *(short *)(param_1 + 0x6e) = (short)param_4;
    func_0207aec8();
    *(ushort *)(param_1 + 0x6e) = uVar1;
    return;
  }
  func_0207aec8();
  return;
}

