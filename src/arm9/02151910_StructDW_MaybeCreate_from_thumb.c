/* Decompiled C draft; module arm9; ROM address 02151910. No matching claim. */
#include "types.h"
#include "deps/02151910_StructDW_MaybeCreate_from_thumb.h"

void StructDW_MaybeCreate_from_thumb(undefined4 *param_1)

{
  uint uVar1;
  
  Mem_CpuCopy8((ushort *)(uintptr_t)(uRam02151990),param_1,6);
  uVar1 = param_1[1] & uRam02151994;
  *param_1 = *param_1;
  param_1[1] = uVar1;
  Mem_CpuCopy8((ushort *)(uintptr_t)(uRam02151998),param_1 + 2,6);
  param_1[2] = (uint)param_1[2] >> 3 | param_1[3] << 0x1d;
  param_1[3] = (uint)param_1[3] >> 3;
  uVar1 = param_1[3] & uRam02151994;
  param_1[2] = param_1[2];
  param_1[3] = uVar1;
  Mem_CpuCopy8((ushort *)(uintptr_t)(uRam0215199c),param_1 + 4,2);
  *(short *)(param_1 + 4) = (short)((int)(uint)*(ushort *)(param_1 + 4) >> 6);
  *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) & (ushort)uRam021519a0;
  Mem_CpuCopy8((ushort *)(uintptr_t)(uRam021519a4),(uint *)(uintptr_t)((int)param_1 + 0x12),2);
  return;
}

