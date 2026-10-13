/* Decompiled C draft; module arm9; ROM address 021510a4. No matching claim. */
#include "types.h"
#include "deps/021510a4_StructDW_SomeFn_2_from_thumb.h"

int StructDW_SomeFn_2_from_thumb(int param_1)

{
  int iVar1;
  uint local_18;
  uint local_14;
  
  local_18 = *(uint *)(param_1 + 8);
  local_14 = *(uint *)(param_1 + 0xc);
  Mem_CpuCopy8(param_1,iRam0215111c,5);
  *(byte *)(iRam0215111c + 5) =
       (byte)((uint)*(undefined4 *)(param_1 + 4) >> 8) & 7 | (byte)((local_18 & 0x1f) << 3);
  local_18 = local_18 >> 5 | local_14 << 0x1b;
  local_14 = local_14 >> 5;
  Mem_CpuCopy8(&local_18,uRam02151120,4);
  iVar1 = iRam0215111c;
  *(byte *)(iRam0215111c + 10) =
       (byte)local_14 & 0x3f | (byte)((*(ushort *)(param_1 + 0x10) & 3) << 6);
  *(char *)(iVar1 + 0xb) = (char)((int)(uint)*(ushort *)(param_1 + 0x10) >> 2);
  Mem_CpuCopy8(param_1 + 0x12,uRam02151124,2);
  return iRam0215111c;
}

