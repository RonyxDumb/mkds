/* Decompiled C draft; module arm9_ov003; ROM address 021c12cc. No matching claim. */
#include "types.h"
#include "deps/021c12cc_FUN_021c12cc.h"

void FUN_021c12cc(int param_1,int param_2)

{
  uint *puVar1;
  
  if (-1 < param_1) {
    if (param_1 < 10) {
      puVar1 = *(uint **)(*DAT_021c1350 + param_1 * 4 + 0x10);
      *puVar1 = *puVar1 & DAT_021c1354;
      *(ushort *)(puVar1 + 1) =
           (ushort)puVar1[1] & (ushort)DAT_021c1358 |
           (ushort)*(byte *)(DAT_021c135c + param_2) << 0xc;
      return;
    }
    if (param_1 + -10 < 2) {
      puVar1 = *(uint **)(*DAT_021c1350 + (param_1 + -10) * 4 + 0x38);
      *puVar1 = *puVar1 & DAT_021c1354;
      *(ushort *)(puVar1 + 1) =
           (ushort)puVar1[1] & (ushort)DAT_021c1358 |
           (ushort)*(byte *)(DAT_021c135c + param_2) << 0xc;
      return;
    }
    FUN_021d1890(*(undefined4 *)(*DAT_021c1350 + (param_1 + -0xc) * 4 + 0x40),0xffffffff,0,
                 *(undefined1 *)(DAT_021c1360 + param_2));
  }
  return;
}

