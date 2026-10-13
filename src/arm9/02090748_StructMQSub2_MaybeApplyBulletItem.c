/* Decompiled C draft; module arm9; ROM address 02090748. No matching claim. */
#include "types.h"
#include "deps/02090748_StructMQSub2_MaybeApplyBulletItem.h"

void StructMQSub2_MaybeApplyBulletItem(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  iVar1 = GetDriverEntry(*(undefined2 *)(param_1 + 0x24));
  local_18 = *(undefined4 *)(iVar1 + 0x80);
  uStack_14 = *(undefined4 *)(iVar1 + 0x84);
  uStack_10 = *(undefined4 *)(iVar1 + 0x88);
  uVar2 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x18;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = func_0207eafc(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20,(undefined4)(uintptr_t)(&local_18),iVar1 + 300,
                        iVar1 + 0x138);
  *(undefined4 *)(param_1 + 0x20) = uVar3;
  uVar2 = iVar1 + 0x48U & 3;
  uVar4 = *(uint *)(iVar1 + 0x48U & 0xfffffffc);
  if ((((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & 0x40000000) == 0) ||
     (uVar2 = iVar1 + 0x3e4U & 3, uVar4 = *(uint *)(iVar1 + 0x3e4U & 0xfffffffc),
     (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) != 1)) {
    iVar5 = func_02080bf4(param_1,(undefined4)(uintptr_t)(&local_18));
    if (iVar5 == 0) {
      iVar5 = func_02080c64(param_1,(undefined4)(uintptr_t)(&local_18));
    }
  }
  else {
    iVar5 = func_02080bf4(param_1,(undefined4)(uintptr_t)(&local_18));
  }
  *(undefined4 *)(iVar1 + 0x2a8) = 0xa800;
  uVar2 = iVar1 + 0x2a8U & 3;
  uVar4 = *(uint *)(iVar1 + 0x2a8U & 0xfffffffc);
  *(uint *)(iVar1 + 0xcc) = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar2 = iVar1 + 0xccU & 3;
  uVar4 = *(uint *)(iVar1 + 0xccU & 0xfffffffc);
  *(uint *)(iVar1 + 0xd0) = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  if (iVar5 != 0) {
    func_0207ff5c((uint *)(uintptr_t)(param_1));
    return;
  }
  func_02090638(param_1);
  return;
}

