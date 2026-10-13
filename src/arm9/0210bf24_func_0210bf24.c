/* Decompiled C draft; module arm9; ROM address 0210bf24. No matching claim. */
#include "types.h"
#include "deps/0210bf24_func_0210bf24.h"

void func_0210bf24(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = iRam0210bfb4 + 0x10U & 3;
  uVar1 = *(uint *)(iRam0210bfb4 + 0x10U & 0xfffffffc);
  if (uVar1 >> uVar3 * 8 != 0 || uVar1 << uVar3 * -8 + 0x20 != 0) {
    iVar2 = GetSomeSndPlayer(uRam0210bfb8);
    func_0210c084(iVar2,0);
    uVar3 = iVar2 + 0x10U & 3;
    uVar1 = *(uint *)(iVar2 + 0x10U & 0xfffffffc);
    uVar3 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
    if (uVar3 != 0) {
      func_0210bc54(uVar3,iVar2);
      func_0210bfbc(uVar3 - 0xc);
    }
    func_0210cfe8(iVar2);
    func_0210bcf4(param_1,param_2,param_3,iVar2);
    return;
  }
  return;
}

