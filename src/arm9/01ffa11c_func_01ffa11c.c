/* Decompiled C draft; module arm9; ROM address 01ffa11c. No matching claim. */
#include "types.h"
#include "deps/01ffa11c_func_01ffa11c.h"

void func_01ffa11c(int param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = VecFx32_CrossProduct_0(param_1 + 0x244);
  uVar3 = param_1 + 0x48U & 3;
  uVar4 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  iVar5 = iRam01ffa1f4;
  if (((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 1) == 0) {
    iVar5 = 0x1ec;
  }
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (iVar2 < iRam01ffa1f0) {
    uVar3 = param_1 + 0x2a0U & 3;
    uVar4 = *(uint *)(param_1 + 0x2a0U & 0xfffffffc);
    lVar1 = (longlong)iVar5 * (longlong)(int)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
    *(uint *)(param_1 + 0x3a8) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    return;
  }
  uVar3 = param_1 + 0x44U & 3;
  uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if ((((((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 0x1000) != 0) &&
       (uVar3 = param_1 + 0x208U & 3, uVar4 = *(uint *)(param_1 + 0x208U & 0xfffffffc),
       uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20, uVar3 = uVar4 & 3,
       uVar4 = *(uint *)(uVar4 & 0xfffffffc),
       uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0)) &&
      (uVar3 = param_1 + 0x1fcU & 3, uVar4 = *(uint *)(param_1 + 0x1fcU & 0xfffffffc),
      uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0)) &&
     (((uVar3 = param_1 + 0x200U & 3, uVar4 = *(uint *)(param_1 + 0x200U & 0xfffffffc),
       uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0 &&
       (uVar3 = param_1 + 0x204U & 3, uVar4 = *(uint *)(param_1 + 0x204U & 0xfffffffc),
       uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0)) &&
      (uVar3 = param_1 + 0x4d0U & 3, uVar4 = *(uint *)(param_1 + 0x4d0U & 0xfffffffc),
      100 < (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20))))) {
    *(undefined4 *)(param_1 + 0x3a8) = 0;
    return;
  }
  uVar3 = param_1 + 0x3a8U & 3;
  uVar4 = *(uint *)(param_1 + 0x3a8U & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  if (iVar5 <= (int)uVar3) {
    return;
  }
  *(uint *)(param_1 + 0x3a8) = uVar3 + 0x14;
  uVar3 = param_1 + 0x3a8U & 3;
  uVar4 = *(uint *)(param_1 + 0x3a8U & 0xfffffffc);
  if (iVar5 < (int)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20)) {
    *(int *)(param_1 + 0x3a8) = iVar5;
  }
  return;
}

