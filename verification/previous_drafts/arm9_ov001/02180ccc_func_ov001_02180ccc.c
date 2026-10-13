/* Decompiled C draft; module arm9_ov001; ROM address 02180ccc. No matching claim. */
#include "types.h"
#include "deps/02180ccc_func_ov001_02180ccc.h"

void func_ov001_02180ccc(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = iRam02180ce4;
  iVar2 = 0;
  do {
    *(undefined2 *)(param_1 + iVar2 * 2) = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < iVar1);
  return;
}

