/* Decompiled C draft; module arm9; ROM address 020deb2c. No matching claim. */
#include "types.h"
#include "deps/020deb2c_func_020deb2c.h"

void func_020deb2c(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(param_2 + 0x74);
  if (param_4 == 0) {
    if (uVar2 == (int)*(char *)((*(uint *)(uRam020debe8 & 0xfffffffc) >> (uRam020debe8 & 3) * 8 |
                                *(uint *)(uRam020debe8 & 0xfffffffc) <<
                                (uRam020debe8 & 3) * -8 + 0x20) + 0x62)) {
      iVar1 = func_0208b7bc(0x2d,param_1);
      if (iVar1 != 0) {
        func_02081f10(iVar1,uVar2,0x1e);
      }
      iVar1 = func_0208b7bc(0x2e,param_1);
      if (iVar1 != 0) {
        func_02081f10(iVar1,uVar2,0x1e);
      }
    }
    iVar1 = func_0208b7bc(0x2f,param_1);
    if (iVar1 != 0) {
      func_02081f10(iVar1,uVar2,0x1e);
    }
  }
  func_020d26ec(param_2,0xd4);
  func_020fa78c(uVar2,param_3,param_5);
  return;
}

