/* Decompiled C draft; module arm9; ROM address 020b681c. No matching claim. */
#include "types.h"
#include "deps/020b681c_func_020b681c.h"

void func_020b681c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = GetCurrentInternalCourseId_0();
  if (iVar1 == 0xe) {
    func_020b6b18(param_1,param_2,uRam020b69e0,0xfffffff6,uRam020b69d8,uRam020b69dc);
    return;
  }
  if (iVar1 == 0x12) {
    func_020b6b18(param_1,param_2,0xfffff7c0,0xfffffc18,0xf30,uRam020b69e4);
    return;
  }
  if (iVar1 == 0x14) {
    func_020b6b18(param_1,param_2,0,uRam020b69f0,uRam020b69e8,uRam020b69ec);
    return;
  }
  if (iVar1 == 0x1c) {
    func_020b6b18(param_1,param_2,0xffffff42,uRam020b69fc,uRam020b69f4,uRam020b69f8);
    return;
  }
  if (iVar1 == 0x1e) {
    func_020b6b18(param_1,param_2,uRam020b6a08,0xffffffec,uRam020b6a00,uRam020b6a04);
    return;
  }
  if (iVar1 == 0x21) {
    func_020b6b18(param_1,param_2,uRam020b6a14,0xffffffe2,uRam020b6a0c,uRam020b6a10);
    return;
  }
  if (iVar1 == 0x26) {
    func_020b6b18(param_1,param_2,0xfffffff6,uRam020b69e0,uRam020b69dc,uRam020b69d8);
    return;
  }
  func_020b6a98(param_1,param_2);
  return;
}

