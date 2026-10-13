/* Decompiled C draft; module arm9; ROM address 0202728c. No matching claim. */
#include "types.h"
#include "deps/0202728c_func_0202728c.h"

void func_0202728c(undefined2 param_1)

{
  int iVar1;
  
  if ((*psRam020272b4 != 2) && (iVar1 = *piRam020272b8, *(int *)(iVar1 + iRam020272bc) == 0)) {
    *(undefined2 *)(*(int *)(iVar1 + 0x18) + 0x44) = param_1;
    *(undefined2 *)(*(int *)(iVar1 + 0x18) + 0x84) = *(undefined2 *)(*(int *)(iVar1 + 0x18) + 0x44);
  }
  return;
}

