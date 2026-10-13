/* Decompiled C draft; module arm9_ov001; ROM address 0219b380. No matching claim. */
#include "types.h"
#include "deps/0219b380_FUN_0219b380.h"

void FUN_0219b380(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_0219b4d8(param_2);
  func_0x020364e8();
  uVar2 = func_0x020364e0();
  uVar2 = func_0x02036bec(uVar2,0x38);
  *(undefined4 *)(param_1 + 0x24) = uVar2;
  func_0x020ea514(4,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x24),
                  *(undefined4 *)(param_1 + 0x18),uVar1);
  return;
}

