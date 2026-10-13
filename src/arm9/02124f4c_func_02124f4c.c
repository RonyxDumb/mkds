/* Decompiled C draft; module arm9; ROM address 02124f4c. No matching claim. */
#include "types.h"
#include "deps/02124f4c_func_02124f4c.h"

int func_02124f4c(undefined4 param_1,int param_2)

{
  int iVar1;
  short extraout_r1;
  int iVar2;
  int iVar3;
  
  iVar1 = func_02125004();
  iVar3 = 0;
  if (0 < iVar1) {
    iVar2 = 0;
    do {
      MaybeBoundsCheck(param_1,10);
      *(short *)(((param_2 + iVar1 * 2) - iVar2) + -2) = extraout_r1 + (short)uRam02124fa8;
      param_1 = MaybeBoundsCheck(param_1,10);
      iVar2 = iVar2 + 2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  *(undefined2 *)(param_2 + iVar1 * 2) = 0;
  return iVar1;
}

