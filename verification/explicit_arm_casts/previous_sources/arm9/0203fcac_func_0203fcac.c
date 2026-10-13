/* Decompiled C draft; module arm9; ROM address 0203fcac. No matching claim. */
#include "types.h"
#include "deps/0203fcac_func_0203fcac.h"

undefined4 func_0203fcac(uint param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  longlong lVar9;
  longlong lVar10;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  
  uVar7 = (*(uint *)(uRam0203fddc & 0xfffffffc) >> (uRam0203fddc & 3) * 8 |
          *(uint *)(uRam0203fddc & 0xfffffffc) << (uRam0203fddc & 3) * -8 + 0x20) + 0x44;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  iVar8 = param_2 * 0x24 + uVar7;
  uVar7 = param_3 * 0x24 + uVar7;
  iVar1 = func_0203fde0(param_1,iVar8,uVar7);
  if (iVar1 != 0) {
    uVar5 = iVar8 + 8U & 3;
    uVar3 = *(uint *)(iVar8 + 8U & 0xfffffffc);
    iStack_28 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
                (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
    uVar5 = param_1 + 8 & 3;
    uVar6 = *(uint *)(param_1 + 8 & 0xfffffffc);
    uVar3 = iVar8 + 0xcU & 3;
    uVar4 = *(uint *)(iVar8 + 0xcU & 0xfffffffc);
    iStack_24 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) -
                (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
    iStack_20 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
                (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20);
    uVar5 = param_1 + 8 & 3;
    uVar6 = *(uint *)(param_1 + 8 & 0xfffffffc);
    uVar3 = uVar7 + 4 & 3;
    uVar4 = *(uint *)(uVar7 + 4 & 0xfffffffc);
    iStack_1c = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) -
                (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
    uVar5 = uVar7 + 0x10 & 3;
    uVar3 = *(uint *)(uVar7 + 0x10 & 0xfffffffc);
    iStack_18 = -(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
    uVar5 = uVar7 + 0x14 & 3;
    uVar7 = *(uint *)(uVar7 + 0x14 & 0xfffffffc);
    iStack_14 = -(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    lVar9 = func_02040d24(&iStack_28,iVar8 + 0x10);
    iVar1 = (int)((ulonglong)lVar9 >> 0x20);
    uVar7 = (uint)lVar9;
    lVar10 = func_02040d24(&iStack_20,&iStack_18);
    uVar5 = (uint)(lVar9 + lVar10);
    iVar8 = (int)((ulonglong)(lVar9 + lVar10) >> 0x20);
    if ((((0 < (int)(iVar1 + (uint)(0x7fffffff < uVar7)) !=
           SBORROW4(-iVar1,(uint)(0x7fffffff < uVar7))) ||
         (0 < (int)(iVar8 + (uint)(0x7fffffff < uVar5)) !=
          SBORROW4(-iVar8,(uint)(0x7fffffff < uVar5)))) ||
        ((int)(iVar1 - ((uVar7 < 0x80000000) - 1)) < 0 !=
         (SBORROW4(iVar1,-1) != SBORROW4(iVar1 + 1,(uint)(uVar7 < 0x80000000))))) ||
       ((int)(iVar8 - ((uVar5 < 0x80000000) - 1)) < 0 !=
        (SBORROW4(iVar8,-1) != SBORROW4(iVar8 + 1,(uint)(uVar5 < 0x80000000))))) {
      uVar7 = uVar7 >> 10 | iVar1 << 0x16;
      uVar5 = uVar5 >> 10 | iVar8 * 0x400000;
    }
    uVar2 = FX_Div(uVar7,uVar5);
    return uVar2;
  }
  return 0xfffff000;
}

