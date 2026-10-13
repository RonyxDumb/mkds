/* Decompiled C draft; module arm9; ROM address 0212c700. No matching claim. */
#include "types.h"
#include "deps/0212c700_func_0212c700.h"

undefined4 func_0212c700(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = Sound_Context_Allocate(param_2,param_3 + 0x14,uRam0212c798,0,0);
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(int *)(iVar1 + 0x10) = param_1;
  *(undefined4 *)(iVar1 + 8) = 0;
  iVar2 = Sound_InitializeContext(iVar1 + 0x14,param_3);
  if (iVar2 != 0) {
    iVar3 = param_1 * 0x24 + iRam0212c79c;
    *(int *)(iVar1 + 8) = iVar2;
    IntrusiveListWrapper_InsertLast(iVar3 + 0xc,iVar1);
    return 1;
  }
  return 0;
}

