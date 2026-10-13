/* Decompiled C draft; module arm9; ROM address 020565e4. No matching claim. */
#include "types.h"
#include "deps/020565e4_StructNKPG_CopyToTime_from_thumb.h"

undefined4 StructNKPG_CopyToTime_from_thumb(int param_1,ushort *param_2)

{
  if ((*(uint *)(param_1 + 8) & 1) == 0) {
    return 0;
  }
  *(byte *)(param_2 + 1) = (byte)((*(uint *)(param_1 + 8) << 0x11) >> 0x19);
  *(byte *)((int)param_2 + 3) = (byte)((uint)(*(int *)(param_1 + 8) << 10) >> 0x19);
  *param_2 = (ushort)((uint)*(undefined4 *)(param_1 + 8) >> 0x16);
  return 1;
}

