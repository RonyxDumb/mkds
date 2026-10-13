/* Decompiled C draft; module arm9; ROM address 020d7b34. No matching claim. */
#include "types.h"
#include "deps/020d7b34_func_020d7b34.h"

void func_020d7b34(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = iRam020d7b84;
  iVar1 = (int)((uint)(param_1 << 0xf) >> 0x10) >> 4;
  *param_2 = 0;
  param_2[1] = (int)*(short *)(iVar2 + iVar1 * 4);
  param_2[2] = 0;
  param_2[3] = (int)*(short *)(iVar2 + (iVar1 * 2 + 1) * 2);
  return;
}

