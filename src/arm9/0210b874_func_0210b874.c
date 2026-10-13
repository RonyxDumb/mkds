/* Decompiled C draft; module arm9; ROM address 0210b874. No matching claim. */
#include "types.h"
#include "deps/0210b874_func_0210b874.h"

void func_0210b874(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (param_2 >> 0xc) + 5;
  iVar1 = func_02109078(param_1,uRam0210b8b4,0x7f,iVar2 * 0x10000 >> 0x10);
  if (iVar1 != 0) {
    func_0212c4c4(iVar1,uRam0210b8b8,iVar2);
    return;
  }
  return;
}

