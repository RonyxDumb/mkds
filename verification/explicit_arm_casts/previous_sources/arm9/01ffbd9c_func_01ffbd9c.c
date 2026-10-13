/* Decompiled C draft; module arm9; ROM address 01ffbd9c. No matching claim. */
#include "types.h"
#include "deps/01ffbd9c_func_01ffbd9c.h"

void func_01ffbd9c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar1 = param_1 + 0x2a4U & 3;
  uVar2 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc);
  uVar3 = param_1 + 0xd0U & 3;
  uVar5 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  FX_DivAsync(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,
              uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
  uVar1 = param_1 + 0x44U & 3;
  uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x10) == 0) {
    GetMQRacerVector333(param_1,param_1 + 0x278);
  }
  else {
    Vector3_Cross(param_1 + 0x120,param_1 + 0x244,param_1 + 0x278);
  }
  uVar4 = FX_GetDivResult();
  *(undefined4 *)(param_1 + 0x2a0) = uVar4;
  uVar1 = param_1 + 0x2a0U & 3;
  uVar3 = *(uint *)(param_1 + 0x2a0U & 0xfffffffc);
  if (0x1000 < (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
    *(undefined4 *)(param_1 + 0x2a0) = 0x1000;
    uVar1 = param_1 + 0xd0U & 3;
    uVar3 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
    *(uint *)(param_1 + 0x2a4) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  }
  return;
}

