/* Decompiled C draft; module arm9; ROM address 02041944. No matching claim. */
#include "types.h"
#include "deps/02041944_func_02041944.h"

undefined4 func_02041944(undefined4 param_1,int param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined1 auStack_20 [16];
  
  uVar8 = 0;
  if (*(char *)(param_2 + 0x42) == '\0') {
    uVar8 = func_02041a70();
  }
  else if (*(char *)(param_2 + 0x42) == '\x01') {
    VecFx32_Subtract(param_1,param_2,(int *)(void *)(auStack_20));
    iVar5 = Vector3_DotProduct((uint)(uintptr_t)(auStack_20),param_2 + 0x24);
    uVar1 = param_2 + 0x10U & 3;
    uVar9 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
    uVar8 = 0;
    lVar2 = (ulonglong)(uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) * 0x32000 + 0x800;
    if (iVar5 <= (int)((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000)) {
      iVar6 = Vector3_DotProduct((uint)(uintptr_t)(auStack_20),param_2 + 0x18);
      iVar7 = Vector3_DotProduct((uint)(uintptr_t)(auStack_20),param_2 + 0x30);
      uVar1 = param_2 + 0xcU & 3;
      uVar9 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
      uVar8 = 0;
      lVar2 = (ulonglong)(uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) * 0x32000 + 0x800;
      iVar5 = (int)((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) >> 4;
      lVar2 = (longlong)iVar5 * (longlong)iVar5 + 0x800;
      lVar3 = (longlong)(iVar6 >> 4) * (longlong)(iVar6 >> 4) + 0x800;
      lVar4 = (longlong)(iVar7 >> 4) * (longlong)(iVar7 >> 4) + 0x800;
      if ((int)(((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
               ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000)) <=
          (int)((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000)) {
        uVar8 = 1;
      }
    }
  }
  return uVar8;
}

