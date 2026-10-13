/* Decompiled C draft; module arm9_ov000; ROM address 021a70ec. No matching claim. */
#include "types.h"
#include "deps/021a70ec_FUN_021a70ec.h"

undefined4 FUN_021a70ec(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*DAT_021a7148 + 0x18))(param_1 * 0x30);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  func_0x0200eb90(DAT_021a714c,iVar1,param_1);
  iVar2 = iVar1 + param_1 * 4;
  if (0 < param_1) {
    do {
      FUN_021a7048(iVar2);
      iVar2 = iVar2 + 0x2c;
      param_1 = param_1 + -1;
    } while (0 < param_1);
  }
  *DAT_021a7150 = iVar1;
  return 0;
}

