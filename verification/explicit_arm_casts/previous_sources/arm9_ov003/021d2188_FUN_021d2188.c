/* Decompiled C draft; module arm9_ov003; ROM address 021d2188. No matching claim. */
#include "types.h"
#include "deps/021d2188_FUN_021d2188.h"

void FUN_021d2188(int param_1)

{
  undefined4 uVar1;
  
  thunk_FUN_021d3488(1,*(undefined4 *)(param_1 + 0x34));
  if (param_1 == *DAT_021d21ec + DAT_021d21f0) {
    uVar1 = func_0x0214a054();
    func_0x0214cfe4(0,uVar1,(uint)DAT_021d21f4[1] * (uint)*DAT_021d21f4 * 0x20);
  }
  else {
    uVar1 = func_0x0214a054();
    func_0x0214cfe4(0,uVar1,(uint)DAT_021d21f4[3] * (uint)DAT_021d21f4[2] * 0x20);
  }
  FUN_021d2808(param_1 + 0x30);
  return;
}

