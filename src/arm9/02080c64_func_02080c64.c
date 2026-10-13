/* Decompiled C draft; module arm9; ROM address 02080c64. No matching claim. */
#include "types.h"
#include "deps/02080c64_func_02080c64.h"

bool func_02080c64(uint param_1,undefined4 param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  int local_18 [2];
  int local_10;
  
  uVar7 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar8 = uVar7 + 0x18;
  uVar1 = uVar8 & 3;
  uVar4 = *(uint *)(uVar8 & 0xfffffffc);
  uVar7 = uVar7 + 0x1c;
  uVar8 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  VecFx32_Subtract(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,param_2,local_18);
  lVar2 = (longlong)local_10 * (longlong)local_10 + (longlong)local_18[0] * (longlong)local_18[0];
  iVar6 = (int)((ulonglong)lVar2 >> 0x20);
  lVar3 = (longlong)(int)uVar8 * (longlong)(int)uVar8;
  iVar5 = (int)((ulonglong)lVar3 >> 0x20);
  bVar9 = (uint)lVar2 < (uint)lVar3;
  return (int)(iVar6 - (iVar5 + (uint)bVar9)) < 0 !=
         (SBORROW4(iVar6,iVar5) != SBORROW4(iVar6 - iVar5,(uint)bVar9));
}

