/* Decompiled C draft; module arm9_ov000; ROM address 021affcc. No matching claim. */
#include "types.h"
#include "deps/021affcc_FUN_021affcc.h"

void FUN_021affcc(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_1 + param_2 != param_3) {
    func_0x0214d1fc((ushort *)(uintptr_t)(param_3),(uint *)(uintptr_t)(param_1 + param_2),param_4);
  }
  func_0x0214d1fc((ushort *)(uintptr_t)(DAT_021b000c),(uint *)(uintptr_t)(param_1 + 6),6);
  iVar1 = FUN_021a6974(param_1,param_1 + 6,param_2 + param_4 + -6);
  *(bool *)DAT_021b0010 = iVar1 < 0;
  return;
}

