/* Decompiled C draft; module arm9_ov000; ROM address 021ae01c. No matching claim. */
#include "types.h"
#include "deps/021ae01c_FUN_021ae01c.h"

undefined4 FUN_021ae01c(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x44);
  while (iVar1 == 0) {
    *(undefined4 *)(param_2 + 4) = 3;
    func_0x0200e01c(0);
    iVar1 = *(int *)(param_2 + 0x44);
  }
  *param_1 = iVar1;
  return *(undefined4 *)(param_2 + 0x40);
}

