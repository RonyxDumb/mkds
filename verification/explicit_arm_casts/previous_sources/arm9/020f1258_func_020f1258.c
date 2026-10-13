/* Decompiled C draft; module arm9; ROM address 020f1258. No matching claim. */
#include "types.h"
#include "deps/020f1258_func_020f1258.h"

int func_020f1258(int param_1,int param_2,int param_3,int param_4)

{
  longlong lVar1;
  longlong lVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int aiStack_30 [2];
  int iStack_28;
  
  iVar4 = GetDriverEntry(param_2);
  if ((*(ushort *)(param_1 + 0x78) & 0x8000) == 0) {
    uVar3 = *(ushort *)(param_1 + 0x78) & 0xff;
  }
  else {
    uVar3 = 8;
  }
  uVar5 = GetDriverPlace(param_2);
  if (((uVar3 < 8) && (param_4 != 0)) && (uVar6 = GetDriverPlace(uVar3), uVar6 <= uVar5)) {
    if (uVar6 != 1) {
      return 0;
    }
    if (3 < uVar5) {
      return 0;
    }
  }
  uVar6 = iVar4 + 0x7cU & 3;
  uVar10 = *(uint *)(iVar4 + 0x7cU & 0xfffffffc);
  if (((((uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) & uRam020f1490) != 0) ||
      (uVar6 = iVar4 + 0x4cU & 3, uVar10 = *(uint *)(iVar4 + 0x4cU & 0xfffffffc),
      ((uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) & 0x800) != 0)) ||
     ((uVar5 != 1 &&
      (uVar5 = iVar4 + 0x180U & 3, uVar6 = *(uint *)(iVar4 + 0x180U & 0xfffffffc),
      uVar6 >> uVar5 * 8 != 0 || uVar6 << uVar5 * -8 + 0x20 != 0)))) {
    return 0;
  }
  GetDriverMaybeSfxPosition(aiStack_30,param_2);
  VecFx32_Subtract(aiStack_30,param_1 + 0x50,aiStack_30);
  iVar4 = (aiStack_30[0] >> 0xc) * (aiStack_30[0] >> 0xc) + (iStack_28 >> 0xc) * (iStack_28 >> 0xc);
  if ((iRam020f1494 < iVar4) || ((param_3 != 0 && (param_3 < iVar4)))) {
    return 0;
  }
  iVar7 = VecFx32_CrossProduct_0(param_1 + 0x5c,aiStack_30);
  if (iVar7 < 0) {
    return 0;
  }
  iVar8 = VecFx32_CrossProduct_0(aiStack_30,aiStack_30);
  iVar9 = VecFx32_CrossProduct_0(param_1 + 0x5c,param_1 + 0x5c);
  lVar1 = (longlong)iVar9 * (longlong)(iVar8 >> 0xc);
  lVar2 = (longlong)iVar7 * (longlong)(iVar7 >> 0xc);
  uVar5 = (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = (uint)lVar1 >> 0xc | uVar5;
  if ((int)((uVar6 << 10) >> 0xc | (((int)uVar6 >> 0x1f) << 10 | uVar5 >> 0x16) << 0x14) <=
      (int)((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14)) {
    iVar7 = VecFx32_CrossProduct_0(param_1 + 0xf0,aiStack_30);
    iVar7 = (iVar7 >> 0xc) * (iVar7 >> 0xc);
    if (iVar7 - iRam020f1498 != 0 && iRam020f1498 <= iVar7) {
      return 0;
    }
    uVar5 = param_1 + 0x74U & 3;
    uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & 0x10000000) == 0) {
      *(uint *)(param_1 + 0x228) =
           param_2 * 0x210 +
           (*(uint *)(uRam020f149c & 0xfffffffc) >> (uRam020f149c & 3) * 8 |
           *(uint *)(uRam020f149c & 0xfffffffc) << (uRam020f149c & 3) * -8 + 0x20);
      *(undefined4 *)(param_1 + 0x22c) = 0;
      *(undefined4 *)(param_1 + 0x230) = 0;
      *(undefined4 *)(param_1 + 0x234) = 0;
      *(undefined4 *)(param_1 + 0x238) = 0;
      return iVar4;
    }
    return 0;
  }
  return 0;
}

