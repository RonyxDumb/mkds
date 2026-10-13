/* Decompiled C draft; module arm9; ROM address 0208b498. No matching claim. */
#include "types.h"
#include "deps/0208b498_func_0208b498.h"

int func_0208b498(undefined4 param_1,uint param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  byte bVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 local_30 [4];
  int local_20;
  int local_1c;
  int local_18;
  
  uVar6 = (*(code *)(*(uint *)(uRam0208b5ac & 0xfffffffc) >> (uRam0208b5ac & 3) * 8 |
                    *(uint *)(uRam0208b5ac & 0xfffffffc) << (uRam0208b5ac & 3) * -8 + 0x20))
                    (local_30,param_1);
  local_20 = (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                  *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) >> 4;
  uVar1 = param_2 + 4 & 3;
  uVar9 = *(uint *)(param_2 + 4 & 0xfffffffc);
  local_1c = (int)(uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 8 & 3;
  uVar9 = *(uint *)(param_2 + 8 & 0xfffffffc);
  local_18 = (int)(uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) >> 4;
  iVar7 = func_02018600(uVar6,local_30[0],(undefined4)(uintptr_t)(&local_20));
  if (iVar7 != 0) {
    uVar1 = iVar7 + 0x20U & 3;
    uVar9 = *(uint *)(iVar7 + 0x20U & 0xfffffffc);
    uVar9 = uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20;
    uVar1 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    bVar2 = *(byte *)((uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) + 0x54);
    if ((bVar2 & 0x80) == 0) {
      if ((bVar2 & 0x40) != 0) {
        uVar1 = iVar7 + 0x80U & 3;
        uVar9 = *(uint *)(iVar7 + 0x80U & 0xfffffffc);
        *(uint *)(iVar7 + 0x80) =
             (uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) & 0xfff8ffff | 0x20000;
      }
    }
    else {
      uVar1 = iVar7 + 0x80U & 3;
      uVar9 = *(uint *)(iVar7 + 0x80U & 0xfffffffc);
      *(uint *)(iVar7 + 0x80) =
           (uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) & 0xfff8ffff | 0x10000;
    }
  }
  if (iVar7 != 0) {
    iVar8 = GetDriverEntry(param_3);
    lVar3 = (longlong)*(int *)(iVar8 + 0x3b0) * (longlong)param_4;
    lVar4 = (longlong)*(int *)(iVar8 + 0x3b4) * (longlong)param_4;
    lVar5 = (longlong)*(int *)(iVar8 + 0x3b8) * (longlong)param_4;
    *(uint *)(iVar7 + 0x40) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
    *(uint *)(iVar7 + 0x44) = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
    *(uint *)(iVar7 + 0x48) = (uint)lVar5 >> 0xc | (int)((ulonglong)lVar5 >> 0x20) << 0x14;
  }
  return iVar7;
}

