/* Decompiled C draft; module arm9; ROM address 0202cb68. No matching claim. */
#include "types.h"
#include "deps/0202cb68_func_0202cb68.h"

void func_0202cb68(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*piRam0202cba0 + param_1 * 0x2c + 0x54);
  if (iVar1 == 0) {
    func_0202cc18(param_1,1);
    return;
  }
  if (iVar1 != 3) {
    return;
  }
  func_0202cc18(param_1,2);
  return;
}

