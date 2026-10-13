/* Decompiled C draft; module arm9_ov000; ROM address 021a438c. No matching claim. */
#include "types.h"
#include "deps/021a438c_FUN_021a438c.h"

void FUN_021a438c(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint local_18;
  uint local_14;
  
  func_0x02138510(param_2,DAT_021a43fc,&local_18,&local_14);
  uVar1 = local_14 & 0xffff;
  local_18 = local_18 << 0x18 & DAT_021a4400 |
             local_18 << 8 & DAT_021a4404 | local_18 >> 0x18 | local_18 >> 8 & DAT_021a4408;
  if (((local_18 != 0) && (uVar1 != 0)) &&
     ((*(uint *)(param_1 + DAT_021a440c) != local_18 ||
      (*(ushort *)(param_1 + DAT_021a4410) != uVar1)))) {
    *(uint *)(param_1 + DAT_021a440c) = local_18;
    *(short *)(param_1 + DAT_021a4410) = (short)local_14;
    (**(code **)(param_1 + 0xa8))(local_18,uVar1,*(undefined4 *)(param_1 + DAT_021a4414));
  }
  return;
}

