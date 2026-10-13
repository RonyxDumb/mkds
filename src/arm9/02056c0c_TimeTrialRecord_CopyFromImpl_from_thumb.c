/* Decompiled C draft; module arm9; ROM address 02056c0c. No matching claim. */
#include "types.h"
#include "deps/02056c0c_TimeTrialRecord_CopyFromImpl_from_thumb.h"

void TimeTrialRecord_CopyFromImpl_from_thumb(uint *param_1,ushort *param_2)

{
  if ((*param_1 & 1) != 0) {
    Mem_CpuCopy8((ushort *)(void *)(param_1 + 2),(uint *)(void *)(param_2 + 2),0x14);
    *(byte *)((int)param_2 + 0x19) = (byte)*param_1 >> 1;
    *(char *)(param_2 + 0xd) = (char)param_1[1];
    *(byte *)(param_2 + 1) = (byte)((*param_1 << 0x11) >> 0x19);
    *(byte *)((int)param_2 + 3) = (byte)((*param_1 << 10) >> 0x19);
    *param_2 = (ushort)(*param_1 >> 0x16);
    *(undefined1 *)(param_2 + 0xc) = 1;
    return;
  }
  Mem_CpuFill8((uint *)(void *)(param_2),0,0x20);
  return;
}

