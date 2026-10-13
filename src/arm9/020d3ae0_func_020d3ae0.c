/* Decompiled C draft; module arm9; ROM address 020d3ae0. No matching claim. */
#include "types.h"
#include "deps/020d3ae0_func_020d3ae0.h"

void func_020d3ae0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = iRam020d3b08;
  if (iRam020d3b08 <= param_1) {
    *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *puRam020d3b0c;
    param_1 = (param_1 - iVar1) * 0x10000 >> 0x10;
  }
  uVar2 = func_020d2178(param_1);
  *(undefined4 *)(param_2 + 0x74) = uVar2;
  return;
}

