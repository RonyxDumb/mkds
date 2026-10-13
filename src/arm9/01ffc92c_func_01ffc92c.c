/* Decompiled C draft; module arm9; ROM address 01ffc92c. No matching claim. */
#include "types.h"
#include "deps/01ffc92c_func_01ffc92c.h"

undefined4 func_01ffc92c(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  uVar1 = GetDriverPlace(*(undefined2 *)(param_1 + 0x74));
  uVar2 = param_1 + 0x3d8U & 3;
  uVar4 = *(uint *)(param_1 + 0x3d8U & 0xfffffffc);
  if (uVar1 != (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20)) {
    uVar2 = param_1 + 0x7cU & 3;
    uVar4 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & 1) != 0) {
      func_0210689c(uVar1 - 1 & 0xff);
    }
    uVar2 = param_1 + 0x3d8U & 3;
    uVar4 = *(uint *)(param_1 + 0x3d8U & 0xfffffffc);
    if (((int)uVar1 < (int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20)) &&
       ((int)uVar1 <
        (int)(uint)*(byte *)((*(uint *)(uRam01ffc9dc & 0xfffffffc) >> (uRam01ffc9dc & 3) * 8 |
                             *(uint *)(uRam01ffc9dc & 0xfffffffc) << (uRam01ffc9dc & 3) * -8 + 0x20)
                            + 0x3d0))) {
      uVar2 = (uint)*(char *)((*(uint *)(uRam01ffc9e0 & 0xfffffffc) >> (uRam01ffc9e0 & 3) * 8 |
                              *(uint *)(uRam01ffc9e0 & 0xfffffffc) << (uRam01ffc9e0 & 3) * -8 + 0x20
                              ) + (uVar1 + 1 & 0xff) + 0x473);
      if ((-1 < (int)uVar2) &&
         (iVar3 = GetDriverEntry(uVar2 & 0xffff), uVar2 = iVar3 + 0x7cU & 3,
         uVar4 = *(uint *)(iVar3 + 0x7cU & 0xfffffffc),
         ((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & uRam01ffc9e4) == 0)) {
        uVar5 = 1;
      }
    }
  }
  *(uint *)(param_1 + 0x3d8) = uVar1;
  return uVar5;
}

