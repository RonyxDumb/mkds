/* Decompiled C draft; module arm9; ROM address 02040de0. No matching claim. */
#include "types.h"
#include "deps/02040de0_func_02040de0.h"

int func_02040de0(undefined4 param_1,int param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int local_48;
  int local_44;
  undefined1 auStack_40 [12];
  undefined1 auStack_34 [16];
  
  uVar9 = (*(uint *)(uRam02040f74 & 0xfffffffc) >> (uRam02040f74 & 3) * 8 |
          *(uint *)(uRam02040f74 & 0xfffffffc) << (uRam02040f74 & 3) * -8 + 0x20) + param_2 * 4 +
          0xd8;
  uVar10 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar9 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
  local_48 = 0;
  GetDriverMaybeSfxPosition(auStack_40,param_1);
  local_44 = 0;
  while ((local_48 == 0 && (uVar9 != 0))) {
    uVar10 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
             *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
    if (*(char *)(uVar10 + 0x42) == '\0') {
      iVar5 = func_02041a70(auStack_40,uVar10);
    }
    else {
      iVar5 = local_44;
      if (*(char *)(uVar10 + 0x42) == '\x01') {
        VecFx32_Subtract(auStack_40,uVar10,auStack_34);
        iVar6 = Vector3_DotProduct(auStack_34,uVar10 + 0x24);
        uVar1 = uVar10 + 0x10 & 3;
        uVar11 = *(uint *)(uVar10 + 0x10 & 0xfffffffc);
        lVar2 = (ulonglong)(uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) * 0x32000 + 0x800;
        if (iVar6 <= (int)((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000)) {
          iVar7 = Vector3_DotProduct(auStack_34,uVar10 + 0x18);
          iVar8 = Vector3_DotProduct(auStack_34,uVar10 + 0x30);
          uVar1 = uVar10 + 0xc & 3;
          uVar10 = *(uint *)(uVar10 + 0xc & 0xfffffffc);
          lVar2 = (ulonglong)(uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20) * 0x32000 + 0x800;
          iVar6 = (int)((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) >> 4;
          lVar4 = (longlong)iVar6 * (longlong)iVar6 + 0x800;
          lVar2 = (longlong)(iVar7 >> 4) * (longlong)(iVar7 >> 4) + 0x800;
          lVar3 = (longlong)(iVar8 >> 4) * (longlong)(iVar8 >> 4) + 0x800;
          if ((int)(((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) +
                   ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000)) <=
              (int)((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000)) {
            iVar5 = 1;
          }
        }
      }
    }
    uVar10 = uVar9 + 4 & 3;
    uVar9 = *(uint *)(uVar9 + 4 & 0xfffffffc);
    uVar9 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
    if (iVar5 != 0) {
      local_48 = 1;
    }
  }
  return local_48;
}

