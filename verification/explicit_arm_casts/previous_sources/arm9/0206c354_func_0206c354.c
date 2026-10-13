/* Decompiled C draft; module arm9; ROM address 0206c354. No matching claim. */
#include "types.h"
#include "deps/0206c354_func_0206c354.h"

undefined4 func_0206c354(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [12];
  
  uVar6 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) & 0x10) == 0) {
    return 0;
  }
  local_38 = *puRam0206c444;
  uStack_34 = puRam0206c444[1];
  uStack_30 = puRam0206c444[2];
  uStack_2c = puRam0206c444[3];
  uVar3 = param_1 + 0x1d0U & 3;
  uVar4 = *(uint *)(param_1 + 0x1d0U & 0xfffffffc);
  uVar5 = 1;
  uVar6 = 0;
  puVar1 = (undefined4 *)puRam0206c448;
  if (param_3 != 0) {
    uVar5 = 4;
    puVar1 = &local_38;
  }
  VecFx32_AddScale1(-(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20),param_2,param_1 + 0x80,
                    auStack_28);
  uVar3 = param_1 + 0xc0U & 3;
  uVar4 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
  uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar3 = uVar4 * 0x8000;
  VecFx32_AddScale1(uVar3 + 0x800 >> 0xc | ((uVar4 >> 0x11) + (uint)(0xfffff7ff < uVar3)) * 0x100000
                    ,param_1 + 300,auStack_28,auStack_28);
  uVar2 = uRam0206c44c;
  if (uVar5 != 0) {
    do {
      uVar3 = (uint)((int)puVar1 + uVar6 * 4) & 3;
      uVar4 = *(uint *)((int)puVar1 + uVar6 * 4 & 0xfffffffc);
      func_0208b748(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,auStack_28,param_1,uVar2);
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < uVar5);
  }
  return 1;
}

