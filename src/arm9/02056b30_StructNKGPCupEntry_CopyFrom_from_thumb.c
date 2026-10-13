/* Decompiled C draft; module arm9; ROM address 02056b30. No matching claim. */
#include "types.h"
#include "deps/02056b30_StructNKGPCupEntry_CopyFrom_from_thumb.h"

void StructNKGPCupEntry_CopyFrom_from_thumb(uint *param_1,ushort *param_2)

{
  if ((char)param_2[0xc] != '\0') {
    Mem_CpuCopy8(param_2 + 2,param_1 + 2,0x14);
    *param_1 = *param_1 & 0xfffffffe | 1;
    *param_1 = *param_1 & 0xffffff01 | (*(byte *)((int)param_2 + 0x19) & 0x7f) << 1;
    *(char *)((int)param_1 + 1) = (char)param_2[0xd];
    param_1[1] = param_1[1] & uRam02056bb0 | ((byte)param_2[1] & 0x7f) << 8;
    param_1[1] = param_1[1] & uRam02056bb4 | (*(byte *)((int)param_2 + 3) & 0x7f) << 0xf;
    param_1[1] = param_1[1] & uRam02056bb8 | (*param_2 & uRam02056bbc) << 0x16;
    *(char *)((int)param_1 + 3) = (char)param_2[0xf];
    *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 0x1d);
    *(char *)(param_1 + 1) = (char)param_2[0xe];
  }
  return;
}

