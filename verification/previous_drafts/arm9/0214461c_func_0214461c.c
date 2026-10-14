/* Decompiled C draft; module arm9; ROM address 0214461c. No matching claim. */
#include "types.h"
#include "deps/0214461c_func_0214461c.h"

void func_0214461c(int param_1,ushort *param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 1 << (param_3 & 0xff);
  if (param_1 == 0) {
    return;
  }
  if (param_2 == (ushort *)0x0) {
    return;
  }
  if ((*param_2 & uVar1) == 0) {
    return;
  }
  if ((param_2[1] & uVar1) != 0) {
    func_021445e0(param_1,(uint)*param_2,param_2 + 2);
    return;
  }
  return;
}

