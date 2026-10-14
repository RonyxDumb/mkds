/* Decompiled C draft; module arm9; ROM address 0209bfe0. No matching claim. */
#include "types.h"
#include "deps/0209bfe0_func_0209bfe0.h"

undefined4 func_0209bfe0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  uVar2 = func_02100138(0x1a8);
  local_14 = func_0209bc5c(uVar2,param_1);
  uVar1 = local_14 + 0x11cU & 3;
  uVar3 = *(uint *)(local_14 + 0x11cU & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
    return 0;
  }
  *(undefined2 *)(local_14 + 0xb8) = 0x8000;
  *(undefined4 *)(local_14 + 0xc4) = 0x1000;
  *(undefined4 *)(local_14 + 200) = 0x400;
  *(undefined4 *)(local_14 + 0xcc) = 0xffffffd7;
  *(undefined4 *)(local_14 + 0xd0) = 0x1000;
  *(undefined4 *)(local_14 + 0xd4) = 0;
  *(undefined2 *)(local_14 + 0xd8) = 0;
  *(undefined4 *)(local_14 + 0xe4) = 0x1000;
  *(undefined4 *)(local_14 + 0xe8) = 0x400;
  *(undefined4 *)(local_14 + 0xec) = 0xffffffd7;
  *(undefined4 *)(local_14 + 0xf0) = 0x1000;
  *(undefined4 *)(local_14 + 0xf4) = 0;
  *(undefined4 *)(local_14 + 0x11c) = 1;
  uVar1 = local_14 + 0x78U & 3;
  uVar3 = *(uint *)(local_14 + 0x78U & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 4) == 0) {
    uVar1 = local_14 + 0x70U & 3;
    uVar3 = *(uint *)(local_14 + 0x70U & 0xfffffffc);
    uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar1 = iRam0209c0cc + 0x68U & 3;
    uVar3 = *(uint *)(iRam0209c0cc + 0x68U & 0xfffffffc);
    if (uVar4 == (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
      local_10 = 2;
    }
    else {
      uVar1 = iRam0209c0cc + 0x8cU & 3;
      uVar3 = *(uint *)(iRam0209c0cc + 0x8cU & 0xfffffffc);
      if (uVar4 == (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
        local_10 = 3;
      }
      else {
        local_10 = 4;
      }
    }
    local_14 = local_14 + 4;
    local_18 = uRam0209c0d0;
    local_c = func_020d4ef4();
    func_0210b7a8((uint)(uintptr_t)(&local_18));
  }
  return 1;
}

