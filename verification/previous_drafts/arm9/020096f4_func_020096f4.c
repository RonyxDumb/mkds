/* Decompiled C draft; module arm9; ROM address 020096f4. No matching claim. */
#include "types.h"
#include "deps/020096f4_func_020096f4.h"

void func_020096f4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *piRam0200971c;
  if (iVar2 == 0) {
    *piRam0200971c = param_1;
  }
  else {
    for (iVar1 = *(int *)(iVar2 + iRam02009720); iVar1 != 0; iVar1 = *(int *)(iVar1 + iRam02009720))
    {
      iVar2 = iVar1;
    }
    *(int *)(iVar2 + iRam02009720) = param_1;
  }
  *(undefined4 *)(param_1 + iRam02009720) = 0;
  return;
}

