/* Decompiled C draft; module arm9; ROM address 02077b1c. No matching claim. */
#include "types.h"
#include "deps/02077b1c_func_02077b1c.h"

void func_02077b1c(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = iRam02077b34;
  piVar1 = piRam02077b30;
  *(undefined4 *)(*piRam02077b30 + iRam02077b34) = 0;
  *(undefined4 *)(*piVar1 + iRam02077b38) = *(undefined4 *)(*piVar1 + iVar2);
  return;
}

