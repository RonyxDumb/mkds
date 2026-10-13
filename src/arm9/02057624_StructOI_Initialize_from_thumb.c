/* Decompiled C draft; module arm9; ROM address 02057624. No matching claim. */
#include "types.h"
#include "deps/02057624_StructOI_Initialize_from_thumb.h"

void StructOI_Initialize_from_thumb(undefined2 *param_1)

{
  Mem_CpuFill8((uint *)(void *)(param_1),0,0x24);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = param_1[6] & 0xff80;
  param_1[6] = param_1[6] & (ushort)uRam020576ac | 0x80;
  param_1[6] = param_1[6] & (ushort)uRam020576b0 | (ushort)uRam020576b4;
  Mem_CpuFill8((uint *)(void *)(param_1 + 7),0,0x14);
  *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) & 0xfe;
  *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) & 0xfd;
  *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) & 0xfb;
  *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) & 0xf7;
  return;
}

