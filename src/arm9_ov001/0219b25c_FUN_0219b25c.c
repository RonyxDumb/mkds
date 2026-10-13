/* Decompiled C draft; module arm9_ov001; ROM address 0219b25c. No matching claim. */
#include "types.h"
#include "deps/0219b25c_FUN_0219b25c.h"

void FUN_0219b25c(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  func_0x020364e8();
  uVar1 = func_0x020364e0();
  uVar1 = func_0x02036bec(uVar1,0x38);
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  func_0x020ea514(2,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x20),
                  *(undefined4 *)(param_1 + 0x18),param_2);
  return;
}

