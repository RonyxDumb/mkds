/* Decompiled C draft; module arm9_ov000; ROM address 021a8f0c. No matching claim. */
#include "types.h"
#include "deps/021a8f0c_FUN_021a8f0c.h"

undefined4 FUN_021a8f0c(int param_1,undefined1 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    return 0xffffffd9;
  }
  uVar2 = FUN_021a8830();
  if (param_1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (uint)*(ushort *)(param_1 + 0x74);
  }
  if (uVar2 == 0) {
    uVar3 = 0;
  }
  *param_2 = 8;
  param_2[1] = 2;
  uVar1 = DAT_021a8f78;
  *(ushort *)(param_2 + 2) = (ushort)(uVar3 >> 8) | (ushort)(uVar3 << 8) & (ushort)DAT_021a8f78;
  *(uint *)(param_2 + 4) =
       uVar2 << 0x18 & DAT_021a8f7c | uVar2 << 8 & DAT_021a8f80 | uVar2 >> 0x18 | uVar2 >> 8 & uVar1
  ;
  return 0;
}

