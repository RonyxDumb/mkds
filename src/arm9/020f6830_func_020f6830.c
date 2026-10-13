/* Decompiled C draft; module arm9; ROM address 020f6830. No matching claim. */
#include "types.h"
#include "deps/020f6830_func_020f6830.h"

void func_020f6830(int param_1,undefined4 param_2,undefined4 param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = param_1 + 0x70U & 3;
  uVar5 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  uVar4 = param_1 + 0x6cU & 3;
  uVar3 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  iVar6 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) -
          (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
  if (iVar6 * iVar6 < iRam020f68a8) {
    iVar6 = VecFx32_CrossProduct_0(param_2,param_3);
    uVar2 = param_1 + 0x44U & 3;
    uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    uVar2 = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) * 0xa8 +
            (*(uint *)(uRam020f68ac & 0xfffffffc) >> (uRam020f68ac & 3) * 8 |
            *(uint *)(uRam020f68ac & 0xfffffffc) << (uRam020f68ac & 3) * -8 + 0x20) + 0x7c;
    uVar4 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if (iVar6 < 1) {
      iVar6 = -iVar6;
    }
    lVar1 = (longlong)iVar6 * (longlong)(int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20);
    *(uint *)(param_1 + 0x100) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar2 = param_1 + 0x100U & 3;
    uVar4 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
    *(int *)(param_1 + 0x100) = (int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) >> 1;
    return;
  }
  return;
}

