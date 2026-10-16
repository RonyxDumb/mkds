/* Decompiled C draft; module arm9; ROM address 02006c2c. No matching claim. */
#include "types.h"
#include "deps/02006c2c_func_02006c2c.h"

void func_02006c2c(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = func_020070b8();
  iVar3 = *piRam02006d34;
  while( true ) {
    iVar3 = iVar3 + 1;
    if (0xf < iVar3) {
      iVar3 = 1;
    }
    iVar2 = func_02005cc8(uVar1,iVar3,param_1,param_2);
    if (iVar2 != 0) {
      *piRam02006d34 = iVar3;
      return;
    }
    iVar2 = func_02005d4c(uVar1,iVar3,param_1,param_2);
    if (iVar2 != 0) {
      *piRam02006d34 = iVar3;
      return;
    }
    iVar2 = func_02005b80(uVar1,iVar3,param_1,param_2);
    if (iVar2 != 0) break;
    iVar2 = func_02005d08(uVar1,iVar3,param_1,param_2);
    if (iVar2 != 0) {
      *piRam02006d34 = iVar3;
      return;
    }
    if (iVar3 == *piRam02006d34) {
      iVar3 = func_02005a30(uVar1,param_1,param_2);
      if ((iVar3 == 0) && (iVar3 = func_0200589c(uVar1,param_1,param_2), iVar3 == 0)) {
        iVar3 = *piRam02006d34;
        do {
          iVar3 = iVar3 + 1;
          if (0xf < iVar3) {
            iVar3 = 1;
          }
          iVar2 = func_02005bec(uVar1,iVar3,param_1,param_2);
          if (iVar2 != 0) {
            *piRam02006d34 = iVar3;
            return;
          }
        } while (iVar3 != *piRam02006d34);
        iVar3 = 1;
        do {
          iVar2 = func_02005b18(uVar1,iVar3,param_1,param_2);
          if (iVar2 != 0) {
            return;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0x10);
        func_020068b4(param_1,uRam02006d38,0);
      }
      return;
    }
  }
  *piRam02006d34 = iVar3;
  return;
}

