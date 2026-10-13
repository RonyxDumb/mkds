/* Decompiled C draft; module arm9; ROM address 0212dd64. No matching claim. */
#include "types.h"
#include "deps/0212dd64_func_0212dd64.h"

undefined4
func_0212dd64(undefined4 param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined1 local_40 [8];
  undefined1 local_38 [8];
  char acStack_30 [2];
  undefined2 uStack_2e;
  ushort uStack_2c;
  
  SND_func_0043(local_38);
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = func_020219f0(param_2,acStack_30,local_40);
  if (iVar1 != 0) {
    do {
      if (((acStack_30[0] == '\x01') && (param_3 == uStack_2c)) &&
         (iVar1 = func_0212de34(param_1,uStack_2e,param_4,param_5), iVar1 == 0)) {
        return 0;
      }
      iVar1 = func_020219f0(param_2,acStack_30,local_40);
    } while (iVar1 != 0);
  }
  return 1;
}

