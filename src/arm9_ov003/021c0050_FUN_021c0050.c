/* Decompiled C draft; module arm9_ov003; ROM address 021c0050. No matching claim. */
#include "types.h"
#include "deps/021c0050_FUN_021c0050.h"

void FUN_021c0050(int param_1,int param_2)

{
  uint *puVar1;
  
  if (-1 < param_1) {
    if (param_1 < 0x2f) {
      puVar1 = *(uint **)(*DAT_021c00d8 + param_1 * 4 + 0x30);
      *puVar1 = *puVar1 & DAT_021c00dc;
      *(ushort *)(puVar1 + 1) =
           (ushort)puVar1[1] & (ushort)DAT_021c00e0 |
           (ushort)*(byte *)(DAT_021c00e4 + param_2) << 0xc;
      return;
    }
    if (param_1 + -0x2f < 4) {
      puVar1 = *(uint **)(*DAT_021c00d8 + (param_1 + -0x2f) * 4 + 0xec);
      *puVar1 = *puVar1 & DAT_021c00dc;
      *(ushort *)(puVar1 + 1) =
           (ushort)puVar1[1] & (ushort)DAT_021c00e0 |
           (ushort)*(byte *)(DAT_021c00e4 + param_2) << 0xc;
      return;
    }
    FUN_021d1890(*(undefined4 *)(*DAT_021c00d8 + (param_1 + -0x33) * 4 + 0xfc),0xffffffff,0,
                 *(undefined1 *)(DAT_021c00e8 + param_2));
  }
  return;
}

