/* Decompiled C draft; module arm9; ROM address 020fcbb8. No matching claim. */
#include "types.h"
#include "deps/020fcbb8_func_020fcbb8.h"

bool func_020fcbb8(int param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  bool bVar10;
  int aiStack_20 [2];
  int iStack_18;
  
  iVar2 = GetDriverEntry(param_2);
  iVar3 = StructMQRacerEntry_SomeFn_64();
  if (iVar3 != 0) {
    return false;
  }
  uVar5 = param_1 + 0x168U & 3;
  uVar7 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  iVar3 = param_2 * 0x210 +
          (*(uint *)(uRam020fccd4 & 0xfffffffc) >> (uRam020fccd4 & 3) * 8 |
          *(uint *)(uRam020fccd4 & 0xfffffffc) << (uRam020fccd4 & 3) * -8 + 0x20);
  uVar4 = iVar3 + 0x1f0;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) !=
      (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20)) {
    uVar4 = param_1 + 0x74U & 3;
    uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if ((((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x40000000) == 0) &&
       (uVar4 = iVar2 + 0x48U & 3, uVar5 = *(uint *)(iVar2 + 0x48U & 0xfffffffc),
       ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 1) == 0)) {
      bVar10 = false;
    }
    else {
      bVar10 = true;
    }
    VecFx32_Subtract((uint)(uintptr_t)((undefined4 *)(iVar2 + 0x98)),param_1 + 0x50,aiStack_20);
    if (bVar10) {
      param_4 = iRam020fccd8;
    }
    if (!bVar10) {
      param_4 = iRam020fccdc;
    }
    if (param_4 < (aiStack_20[0] >> 0xc) * (aiStack_20[0] >> 0xc) +
                  (iStack_18 >> 0xc) * (iStack_18 >> 0xc)) {
      return false;
    }
    iVar6 = VecFx32_CrossProduct_0(param_1 + 0xf0,(uint)(uintptr_t)(aiStack_20));
    iVar6 = (iVar6 >> 0xc) * (iVar6 >> 0xc);
    if (iVar6 - iRam020fcce0 != 0 && iRam020fcce0 <= iVar6) {
      return false;
    }
  }
  uVar4 = param_1 + 0x74U & 3;
  uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  bVar10 = ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x10000000) == 0;
  if (bVar10) {
    *(int *)(param_1 + 0x228) = iVar3;
    uVar8 = *(undefined4 *)(iVar2 + 0x9c);
    uVar9 = *(undefined4 *)(iVar2 + 0xa0);
    *(undefined4 *)(param_1 + 0x244) = *(undefined4 *)(iVar2 + 0x98);
    *(undefined4 *)(param_1 + 0x248) = uVar8;
    *(undefined4 *)(param_1 + 0x24c) = uVar9;
  }
  return bVar10;
}

