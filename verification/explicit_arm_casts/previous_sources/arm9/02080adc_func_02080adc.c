/* Decompiled C draft; module arm9; ROM address 02080adc. No matching claim. */
#include "types.h"
#include "deps/02080adc_func_02080adc.h"

void func_02080adc(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  param_1[1] = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  *param_1 = param_2;
  uVar1 = (uint)(param_1 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar5 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x18;
  uVar2 = uVar5 & 3;
  uVar3 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x18;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  VecFx32_Subtract(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,
                   uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,param_1 + 2);
  Vector3_MaybeNormalize(param_1 + 2,param_1 + 2);
  return;
}

