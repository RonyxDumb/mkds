/* Decompiled C draft; module arm9; ROM address 0204176c. No matching claim. */
#include "types.h"
#include "deps/0204176c_func_0204176c.h"

undefined4 func_0204176c(undefined4 param_1,undefined4 *param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ushort uVar10;
  uint uVar11;
  int local_38;
  int local_34;
  undefined1 auStack_30 [12];
  
  local_38 = 0;
  uVar10 = 0;
  if (*(short *)((*(uint *)(uRam02041940 & 0xfffffffc) >> (uRam02041940 & 3) * 8 |
                 *(uint *)(uRam02041940 & 0xfffffffc) << (uRam02041940 & 3) * -8 + 0x20) + 0x78) !=
      0) {
    local_34 = 1;
    do {
      iVar5 = GetGlobalPENkmAREAByIndex_from_thumb(uVar10);
      if (*(char *)(iVar5 + 0x44) == '\x02') {
        if (*(char *)(iVar5 + 0x42) == '\0') {
          iVar6 = func_02041a70(param_1,iVar5);
        }
        else {
          iVar6 = local_38;
          if (*(char *)(iVar5 + 0x42) == '\x01') {
            VecFx32_Subtract(param_1,iVar5,(int *)(void *)(auStack_30));
            iVar7 = Vector3_DotProduct((uint)(uintptr_t)(auStack_30),iVar5 + 0x24);
            uVar1 = iVar5 + 0x10U & 3;
            uVar11 = *(uint *)(iVar5 + 0x10U & 0xfffffffc);
            lVar2 = (ulonglong)(uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) * 0x32000 + 0x800
            ;
            if (iVar7 <= (int)((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000)) {
              iVar8 = Vector3_DotProduct((uint)(uintptr_t)(auStack_30),iVar5 + 0x18);
              iVar9 = Vector3_DotProduct((uint)(uintptr_t)(auStack_30),iVar5 + 0x30);
              uVar1 = iVar5 + 0xcU & 3;
              uVar11 = *(uint *)(iVar5 + 0xcU & 0xfffffffc);
              lVar2 = (ulonglong)(uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) * 0x32000 +
                      0x800;
              iVar7 = (int)((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) >> 4;
              lVar4 = (longlong)iVar7 * (longlong)iVar7 + 0x800;
              lVar3 = (longlong)(iVar8 >> 4) * (longlong)(iVar8 >> 4) + 0x800;
              lVar2 = (longlong)(iVar9 >> 4) * (longlong)(iVar9 >> 4) + 0x800;
              if ((int)(((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
                       ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000)) <=
                  (int)((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000)) {
                iVar6 = local_34;
              }
            }
          }
        }
        if (iVar6 != 0) {
          if (*(short *)(iVar5 + 0x3c) == 0) {
            *param_2 = 1;
          }
          else {
            *param_2 = 0;
          }
          return 1;
        }
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < *(ushort *)
                       ((*(uint *)(uRam02041940 & 0xfffffffc) >> (uRam02041940 & 3) * 8 |
                        *(uint *)(uRam02041940 & 0xfffffffc) << (uRam02041940 & 3) * -8 + 0x20) +
                       0x78));
  }
  return 0;
}

