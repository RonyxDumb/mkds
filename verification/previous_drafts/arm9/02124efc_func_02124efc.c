/* Decompiled C draft; module arm9; ROM address 02124efc. No matching claim. */
#include "types.h"
#include "deps/02124efc_func_02124efc.h"

void func_02124efc(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_2) {
    do {
      *param_1 = 1;
      *(undefined2 *)(param_1 + 1) = 0;
      *(undefined2 *)((int)param_1 + 6) = 0;
      param_1[2] = 0;
      *(undefined2 *)(param_1 + 3) = 0;
      *(undefined2 *)((int)param_1 + 0xe) = 0;
      param_1[4] = 0;
      MTX_Identity22_(param_1 + 5);
      MTX_Identity22_(param_1 + 9);
      param_1[0xd] = 1;
      param_1[0xe] = 0xffffffff;
      param_1[0xf] = 0;
      param_1 = param_1 + 0x10;
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_2);
  }
  return;
}

