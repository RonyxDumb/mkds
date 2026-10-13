/* Decompiled C draft; module arm9_ov001; ROM address 02181660. No matching claim. */
#include "types.h"
#include "deps/02181660_func_ov001_02181660.h"

void func_ov001_02181660(uint param_1)

{
  int iVar1;
  
  iVar1 = *piRam02181674;
  if (*(ushort *)(iVar1 + 4) <= param_1) {
    param_1 = (uint)*(ushort *)(iVar1 + 4);
  }
  *(short *)(iVar1 + 0xc) = *(short *)(iVar1 + 0xc) + (short)param_1;
  return;
}

