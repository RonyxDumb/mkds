/* Decompiled C draft; module arm9; ROM address 0212beb4. No matching claim. */
#include "types.h"
#include "deps/0212beb4_func_0212beb4.h"

void func_0212beb4(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = IntrusiveListWrapper_NextItem(uRam0212bf10,0);
  uVar1 = uRam0212bf10;
  while ((iVar2 != 0 && (*(byte *)(iVar2 + 0x3d) <= *(byte *)(param_1 + 0x3d)))) {
    iVar2 = IntrusiveListWrapper_NextItem(uVar1);
  }
  IntrusiveListWrapper_SomeFn_0(uRam0212bf10,iVar2,param_1);
  return;
}

