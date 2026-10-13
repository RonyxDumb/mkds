/* Decompiled C draft; module arm9; ROM address 02056aa4. No matching claim. */
#include "types.h"
#include "deps/02056aa4_StructNKGPCupEntry_CopyTo_from_thumb.h"

void StructNKGPCupEntry_CopyTo_from_thumb(uint *param_1,ushort *param_2)

{
  if ((*param_1 & 1) != 0) {
    Mem_CpuCopy8((ushort *)(void *)(param_1 + 2),(uint *)(void *)(param_2 + 2),0x14);
    *(byte *)((int)param_2 + 0x19) = (byte)*param_1 >> 1;
    *(undefined1 *)(param_2 + 0xd) = *(undefined1 *)((int)param_1 + 1);
    *(byte *)(param_2 + 1) = (byte)((param_1[1] << 0x11) >> 0x19);
    *(byte *)((int)param_2 + 3) = (byte)((param_1[1] << 10) >> 0x19);
    *param_2 = (ushort)(param_1[1] >> 0x16);
    *(undefined1 *)(param_2 + 0xf) = *(undefined1 *)((int)param_1 + 3);
    *(undefined1 *)((int)param_2 + 0x1d) = *(undefined1 *)((int)param_1 + 2);
    *(char *)(param_2 + 0xe) = (char)param_1[1];
    *(undefined1 *)(param_2 + 0xc) = 1;
    return;
  }
  *(undefined1 *)(param_2 + 0xc) = 0;
  return;
}

