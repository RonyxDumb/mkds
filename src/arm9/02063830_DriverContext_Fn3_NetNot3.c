/* Decompiled C draft; module arm9; ROM address 02063830. No matching claim. */
#include "types.h"
#include "deps/02063830_DriverContext_Fn3_NetNot3.h"

void DriverContext_Fn3_NetNot3(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_0207a870();
  if (iVar2 != 0) {
    func_0203c1a8(param_1 + 0x80,*(undefined2 *)(param_1 + 0x74));
  }
  uVar1 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x1000) != 0) {
    StructMQRacerEntry_SomeFn_89(param_1);
  }
  uVar1 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xffffefff;
  func_01ffcc50(param_1);
  return;
}

