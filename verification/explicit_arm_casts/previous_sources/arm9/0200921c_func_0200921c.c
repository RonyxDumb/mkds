/* Decompiled C draft; module arm9; ROM address 0200921c. No matching claim. */
#include "types.h"
#include "deps/0200921c_func_0200921c.h"

undefined4 func_0200921c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = func_020091fc(param_3);
  if (iVar2 == 0) {
    return 0;
  }
  CopyMemory16(param_3,uRam02009298,0xc0);
  iVar2 = iRam0200929c;
  uVar1 = uRam02009298;
  *piRam020092a0 = iRam0200929c;
  iVar2 = func_020088dc(iVar2 + 8,0x68);
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = func_02009098(uVar1,param_1);
  if (iVar2 < 0) {
    return 0;
  }
  func_02008e10(uVar1,iVar2,param_2);
  func_02008ff0(iVar2,param_1);
  return 1;
}

