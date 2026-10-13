/* Decompiled C draft; module arm9; ROM address 02080bf4. No matching claim. */
#include "types.h"
#include "deps/02080bf4_func_02080bf4.h"

undefined4 func_02080bf4(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 auStack_18 [12];
  
  uVar1 = param_1 + 8 & 3;
  uVar3 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar5 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x18;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar6 = 0;
  if (((uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) ||
      (uVar1 = param_1 + 0xc & 3, uVar3 = *(uint *)(param_1 + 0xc & 0xfffffffc),
      uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0)) ||
     (uVar1 = param_1 + 0x10 & 3, uVar3 = *(uint *)(param_1 + 0x10 & 0xfffffffc),
     uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0)) {
    VecFx32_Subtract(param_2,uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20,auStack_18);
    iVar4 = VecFx32_CrossProduct_0(param_1 + 8,auStack_18);
    if (0 < iVar4) {
      uVar6 = 1;
    }
  }
  return uVar6;
}

