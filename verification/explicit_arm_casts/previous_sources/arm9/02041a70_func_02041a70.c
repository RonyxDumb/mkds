/* Decompiled C draft; module arm9; ROM address 02041a70. No matching claim. */
#include "types.h"
#include "deps/02041a70_func_02041a70.h"

undefined4 func_02041a70(undefined4 param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_18 [12];
  
  VecFx32_Subtract(param_1,param_2,auStack_18);
  iVar2 = Vector3_DotProduct(auStack_18,param_2 + 0x24);
  uVar3 = param_2 + 0x10U & 3;
  uVar4 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
  lVar1 = (ulonglong)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) * 0x64000 + 0x800;
  if (((int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) < iVar2) ||
     (iVar2 < 0)) {
    return 0;
  }
  iVar2 = Vector3_DotProduct(auStack_18,param_2 + 0x18);
  uVar3 = param_2 + 0xcU & 3;
  uVar4 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  lVar1 = (ulonglong)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) * 0x32000 + 0x800;
  uVar3 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  if (((int)(iVar2 + uVar3) < 0 == SBORROW4(iVar2,-uVar3)) && (iVar2 <= (int)uVar3)) {
    iVar2 = Vector3_DotProduct(auStack_18,param_2 + 0x30);
    uVar3 = param_2 + 0x14U & 3;
    uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    lVar1 = (ulonglong)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) * 0x32000 + 0x800;
    uVar3 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    if (((int)(iVar2 + uVar3) < 0 == SBORROW4(iVar2,-uVar3)) && (iVar2 <= (int)uVar3)) {
      return 1;
    }
    return 0;
  }
  return 0;
}

