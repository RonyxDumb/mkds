/* Decompiled C draft; module arm9; ROM address 0212bf14. No matching claim. */
#include "types.h"
#include "deps/0212bf14_func_0212bf14.h"

void func_0212bf14(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = IntrusiveListWrapper_NextItem(param_1,0);
  while ((iVar1 != 0 && (*(byte *)(iVar1 + 0x3d) <= *(byte *)(param_2 + 0x3d)))) {
    iVar1 = IntrusiveListWrapper_NextItem(param_1);
  }
  IntrusiveListWrapper_SomeFn_0(param_1,iVar1,param_2);
  *(undefined4 *)(param_2 + 4) = param_1;
  return;
}

