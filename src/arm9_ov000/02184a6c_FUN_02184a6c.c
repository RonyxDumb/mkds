/* Decompiled C draft; module arm9_ov000; ROM address 02184a6c. No matching claim. */
#include "types.h"
#include "deps/02184a6c_FUN_02184a6c.h"

void FUN_02184a6c(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)func_0x02036bec(param_1,4);
  *DAT_02184aa0 = puVar1;
  *puVar1 = param_1;
  FUN_02184a50();
  uVar2 = func_ov000_021804f4();
  uVar3 = func_ov000_021804e0();
  func_0x02028864(param_1,2,uVar2,uVar3);
  return;
}

