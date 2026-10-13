/* Decompiled C draft; module arm9; ROM address 020e33c0. No matching claim. */
#include "types.h"
#include "deps/020e33c0_func_020e33c0.h"

void func_020e33c0(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = param_1 + 0xacU & 3;
  uVar3 = *(uint *)(param_1 + 0xacU & 0xfffffffc);
  *(uint *)(param_1 + 8) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x14) = 0x4800;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffe;
  uVar1 = param_1 + 0x78U & 3;
  uVar3 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  if ((((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 3) != 0) &&
     (iVar2 = func_0203c5e4(), iVar2 == 0)) {
    return;
  }
  uVar1 = param_1 + 0x9cU & 3;
  uVar3 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
  func_0208b7bc(0x30,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  return;
}

