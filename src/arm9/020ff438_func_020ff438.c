/* Decompiled C draft; module arm9; ROM address 020ff438. No matching claim. */
#include "types.h"
#include "deps/020ff438_func_020ff438.h"

void func_020ff438(int param_1)

{
  uint uVar1;
  undefined1 auStack_c [4];
  uint uVar2;
  
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((uVar2 & 0x180000) == 0) {
    if ((uVar2 & 0x8000) == 0) {
      if ((uVar2 & 0x4000) == 0) {
        uVar2 = param_1 + 0x13cU & 3;
        uVar1 = *(uint *)(param_1 + 0x13cU & 0xfffffffc);
        if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
          func_020f2df0(param_1,uRam020ff530,uRam020ff534,0,auStack_c);
        }
        else {
          func_020f2df0(param_1,0x1ec,uRam020ff52c,0,auStack_c);
        }
        uVar2 = param_1 + 0x74U & 3;
        uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
        uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
        if (((uVar2 & 8) != 0) && ((uVar2 & 3) == 0)) {
          uVar2 = param_1 + 0x13cU & 3;
          uVar1 = *(uint *)(param_1 + 0x13cU & 0xfffffffc);
          if (uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0) {
            uVar2 = param_1 + 0x60U & 3;
            uVar1 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
            *(uint *)(param_1 + 0x60) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) << 1;
          }
          func_02109060(param_1,0xda);
          func_020f6a6c(param_1,(undefined4)(uintptr_t)(auStack_c));
        }
      }
      else {
        func_020f63cc();
      }
    }
    else {
      func_020f68b0();
    }
  }
  else if ((uVar2 & 0x80000) == 0) {
    if ((uVar2 & 0x100000) != 0) {
      func_020f758c();
    }
  }
  else {
    func_020f6e58();
  }
  uVar2 = param_1 + 0x140U & 3;
  uVar1 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  func_02105338(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,(int)*(short *)(param_1 + 0xd8),
                param_1 + 0x68);
  return;
}

