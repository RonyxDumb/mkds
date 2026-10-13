/* Decompiled C draft; module arm9; ROM address 020718c8. No matching claim. */
#include "types.h"
#include "deps/020718c8_func_020718c8.h"

void func_020718c8(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = GetAED0PlayerUnk(*(undefined2 *)(param_1 + 0x74));
  iVar2 = func_0210a588();
  func_0210ddf4(uRam0207190c,iVar1 + iVar2,uRam02071910,param_1,param_2);
  return;
}

