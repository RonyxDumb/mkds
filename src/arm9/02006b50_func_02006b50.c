/* Decompiled C draft; module arm9; ROM address 02006b50. No matching claim. */
#include "types.h"
#include "deps/02006b50_func_02006b50.h"

void func_02006b50(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = func_020070b8();
  iVar2 = func_02005cc8(uVar1,0,param_1,param_2);
  if (((((iVar2 == 0) && (iVar2 = func_02005d4c(uVar1,0,param_1,param_2), iVar2 == 0)) &&
       (iVar2 = func_02005b80(uVar1,0,param_1,param_2), iVar2 == 0)) &&
      ((iVar2 = func_02005d08(uVar1,0,param_1,param_2), iVar2 == 0 &&
       (iVar2 = func_02005bec(uVar1,0,param_1,param_2), iVar2 == 0)))) &&
     ((iVar2 = func_02005b18(uVar1,0,param_1,param_2), iVar2 == 0 &&
      ((iVar2 = func_02005a30(uVar1,param_1,param_2), iVar2 == 0 &&
       (iVar2 = func_0200589c(uVar1,param_1,param_2), iVar2 == 0)))))) {
    func_020068b4(param_1,uRam02006be8,0);
  }
  return;
}

