/* Decompiled C draft; module arm9; ROM address 0209905c. No matching claim. */
#include "types.h"
#include "deps/0209905c_func_0209905c.h"

void func_0209905c(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint uVar2;
  
  uVar2 = param_2 + 0xccU & 3;
  uVar1 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    if (uVar2 != 1) {
      return;
    }
    uVar2 = param_2 + 0xd0U & 3;
    uVar1 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 != 0) {
      uVar2 = uVar2 + 8;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      for (uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20; uVar2 != 0;
          uVar2 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                  *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) {
        *(undefined2 *)(uVar2 + 0x26) = *(undefined2 *)(uVar2 + 0x24);
      }
      func_0208b6b0((undefined4 *)(uintptr_t)(param_2 + 0xd0));
    }
    func_020d2398(param_2);
    return;
  }
  uVar2 = param_2 + 0xc4U & 3;
  uVar5 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
  uVar1 = param_2 + 200U & 3;
  uVar3 = *(uint *)(param_2 + 200U & 0xfffffffc);
  *(uint *)(param_2 + 0xc4) =
       (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) +
       (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  uVar2 = param_2 + 200U & 3;
  uVar1 = *(uint *)(param_2 + 200U & 0xfffffffc);
  *(uint *)(param_2 + 200) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) - 0x1000;
  uVar2 = param_2 + 0xc4U & 3;
  uVar1 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
  if ((int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) < 1) {
    *(undefined4 *)(param_2 + 0xc4) = 0;
    *(undefined4 *)(param_2 + 200) = 0x5800;
    uVar2 = param_2 + 0x78U & 3;
    uVar1 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
    if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 4) == 0) {
      uVar2 = param_2 + 0x70U & 3;
      uVar1 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
      uVar3 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
      uVar2 = iRam02099200 + 0x68U & 3;
      uVar1 = *(uint *)(iRam02099200 + 0x68U & 0xfffffffc);
      if (uVar3 == (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20)) {
        local_10 = 2;
      }
      else {
        uVar2 = iRam02099200 + 0x8cU & 3;
        uVar1 = *(uint *)(iRam02099200 + 0x8cU & 0xfffffffc);
        if (uVar3 == (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20)) {
          local_10 = 3;
        }
        else {
          local_10 = 4;
        }
      }
      local_14 = param_2 + 4;
      local_18 = uRam02099204;
      local_c = func_020d4ef4();
      func_0210b7a8((uint)(uintptr_t)(&local_18));
    }
  }
  iVar4 = func_020d8cc8(param_2 + 0xa0);
  if ((iVar4 == 0) ||
     (uVar2 = param_2 + 0xb8U & 3, uVar1 = *(uint *)(param_2 + 0xb8U & 0xfffffffc),
     uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0)) {
    func_020d8918(param_2 + 0xa0,(uint *)(uintptr_t)(param_2 + 4),(uint *)(uintptr_t)(param_2 + 0x10));
    uVar2 = param_2 + 0xc4U & 3;
    uVar3 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
    uVar1 = param_2 + 8U & 3;
    uVar5 = *(uint *)(param_2 + 8U & 0xfffffffc);
    *(uint *)(param_2 + 8) =
         (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) +
         (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0xf000;
  }
  else {
    *(undefined4 *)(param_2 + 0xcc) = 1;
  }
  uVar2 = param_2 + 0xd0U & 3;
  uVar1 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 == 0) {
    return;
  }
  if ((*(ushort *)(param_2 + 2) & 0x12) != 0) {
    uVar1 = uVar2 + 0x24 & 3;
    uVar3 = *(uint *)(uVar2 + 0x24 & 0xfffffffc);
    *(uint *)(uVar2 + 0x24) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 2;
    return;
  }
  func_0208b5b0(uVar2,param_2 + 4);
  uVar2 = param_2 + 0xd0U & 3;
  uVar1 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
  uVar3 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar2 = uVar3 + 0x24;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(uVar3 + 0x24) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffd;
  return;
}

