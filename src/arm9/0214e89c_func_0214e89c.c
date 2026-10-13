/* Decompiled C draft; module arm9; ROM address 0214e89c. No matching claim. */
#include "types.h"
#include "deps/0214e89c_func_0214e89c.h"

undefined4 func_0214e89c(undefined2 *param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  WaitForTPFlags(1);
  iVar2 = iRam0214e8f0;
  if ((*(ushort *)(iRam0214e8f0 + 0x34) & 1) == 0) {
    uVar1 = *(undefined2 *)(iRam0214e8f0 + 6);
    *param_1 = *(undefined2 *)(iRam0214e8f0 + 4);
    param_1[1] = uVar1;
    uVar1 = *(undefined2 *)(iVar2 + 10);
    param_1[2] = *(undefined2 *)(iVar2 + 8);
    param_1[3] = uVar1;
    return 0;
  }
  return 1;
}

