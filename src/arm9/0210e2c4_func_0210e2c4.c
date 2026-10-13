/* Decompiled C draft; module arm9; ROM address 0210e2c4. No matching claim. */
#include "types.h"
#include "deps/0210e2c4_func_0210e2c4.h"

void func_0210e2c4(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  param_1[3] = param_2;
  *param_1 = param_3;
  iVar4 = 0;
  param_1[1] = 0;
  uVar3 = (uint)(param_1 + 3) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  param_1[2] = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  param_1[4] = param_4;
  uVar3 = (uint)(param_1 + 2) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar3 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  if (param_3 < 1) {
    return;
  }
  do {
    *(undefined4 *)(uVar3 + 4) = 0;
    func_0212c6a0((undefined4 *)(uintptr_t)(uVar3));
    uVar1 = (uint)(param_1 + 4) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
    iVar4 = iVar4 + 1;
    uVar3 = uVar3 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  } while (iVar4 < param_3);
  return;
}

