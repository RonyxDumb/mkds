/* Decompiled C draft; module arm9_ov003; ROM address 021d1d0c. No matching claim. */
#include "types.h"
#include "deps/021d1d0c_FUN_021d1d0c.h"

void FUN_021d1d0c(undefined2 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = func_0x0200ca9c(1);
  uVar2 = func_0x02147cd8(*(byte *)((int)param_1 + 3) + 1,*param_1);
  if (uVar2 == *(byte *)(param_1 + 1)) {
    func_0x0200fd1c();
  }
  *(undefined4 *)(param_1 + (uint)*(byte *)((int)param_1 + 3) * 2 + 2) = param_2;
  *(char *)((int)param_1 + 3) = (char)uVar2;
  func_0x0200cae4(uVar1);
  return;
}

