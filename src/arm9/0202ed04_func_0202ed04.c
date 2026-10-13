/* Decompiled C draft; module arm9; ROM address 0202ed04. No matching claim. */
#include "types.h"
#include "deps/0202ed04_func_0202ed04.h"

void func_0202ed04(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *piRam0202ed44;
  if (*(int *)(iVar2 + iRam0202ed48) == 0) {
    *(undefined4 *)(iVar2 + iRam0202ed4c) = 0;
  }
  else {
    iVar1 = *(int *)(iVar2 + iRam0202ed4c);
    if (iVar1 == 0) {
      func_0202ed50(0);
      *(undefined4 *)(*piRam0202ed44 + iRam0202ed48) = 0;
    }
    else {
      *(int *)(iVar2 + iRam0202ed4c) = iVar1 + -1;
    }
  }
  return;
}

