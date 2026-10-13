/* Decompiled C draft; module arm9_ov001; ROM address 02181678. No matching claim. */
#include "types.h"
#include "deps/02181678_func_ov001_02181678.h"

void func_ov001_02181678(uint param_1)

{
  int iVar1;
  
  iVar1 = *piRam0218168c;
  if (*(ushort *)(iVar1 + 4) <= param_1) {
    param_1 = (uint)*(ushort *)(iVar1 + 4);
  }
  *(short *)(iVar1 + 10) = *(short *)(iVar1 + 10) + (short)param_1;
  return;
}

