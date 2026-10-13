/* Decompiled C draft; module arm9; ROM address 0202cb2c. No matching claim. */
#include "types.h"
#include "deps/0202cb2c_func_0202cb2c.h"

void func_0202cb2c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*piRam0202cb64 + param_1 * 0x2c + 0x54);
  if (iVar1 == 1) {
    func_0202cc18(param_1,0);
    return;
  }
  if (iVar1 != 2) {
    return;
  }
  func_0202cc18(param_1,3);
  return;
}

