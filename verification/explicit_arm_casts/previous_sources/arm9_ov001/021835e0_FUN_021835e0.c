/* Decompiled C draft; module arm9_ov001; ROM address 021835e0. No matching claim. */
#include "types.h"
#include "deps/021835e0_FUN_021835e0.h"

undefined4 FUN_021835e0(ushort *param_1)

{
  int iVar1;
  
  if ((*param_1 == DAT_02183668) &&
     (iVar1 = func_0x0209b620(*(undefined4 *)((int)param_1 + DAT_0218366c)), iVar1 == 2)) {
    FUN_02187af4(param_1);
    FUN_021872e0(param_1,DAT_0218367c,0,0,0,DAT_02183670,DAT_02183674,DAT_02183678,0);
    FUN_021872e0(param_1,DAT_0218367c,0,0,0,DAT_02183670,DAT_02183674,DAT_02183680,0);
    FUN_021872e0(param_1,DAT_0218367c,0,0,0,DAT_02183684,DAT_02183674,DAT_02183688,0);
    func_0x020d2774(param_1,DAT_0218368c);
  }
  return 0;
}

