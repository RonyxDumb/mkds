/* Decompiled C draft; module arm9; ROM address 02041588. No matching claim. */
#include "types.h"
#include "deps/02041588_func_02041588.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int func_02041588(undefined4 param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  ushort uVar10;
  uint uVar11;
  int local_3c;
  undefined1 auStack_34 [16];
  
  uVar9 = *(uint *)(uRam02041768 & 0xfffffffc) >> (uRam02041768 & 3) * 8 |
          *(uint *)(uRam02041768 & 0xfffffffc) << (uRam02041768 & 3) * -8 + 0x20;
  local_3c = 0;
  if (*(short *)(uVar9 + 0x102) == 0) {
    return 0;
  }
  uVar10 = 0;
  if (*(short *)(uVar9 + 0x78) != 0) {
    do {
      iVar4 = GetGlobalPENkmAREAByIndex_from_thumb(uVar10);
      if (*(char *)(iVar4 + 0x44) == '\x04') {
        if (*(char *)(iVar4 + 0x42) == '\0') {
          iVar5 = func_02041a70(param_1,iVar4);
        }
        else {
          iVar5 = local_3c;
          if (*(char *)(iVar4 + 0x42) == '\x01') {
            VecFx32_Subtract(param_1,iVar4,(int *)(void *)(auStack_34));
            iVar6 = Vector3_DotProduct((uint)(uintptr_t)(auStack_34),iVar4 + 0x24);
            uVar9 = iVar4 + 0x10U & 3;
            uVar11 = *(uint *)(iVar4 + 0x10U & 0xfffffffc);
            lVar1 = (ulonglong)(uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) * 0x32000 + 0x800
            ;
            iVar5 = 0;
            if (iVar6 <= (int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000)) {
              iVar7 = Vector3_DotProduct((uint)(uintptr_t)(auStack_34),iVar4 + 0x18);
              iVar8 = Vector3_DotProduct((uint)(uintptr_t)(auStack_34),iVar4 + 0x30);
              uVar9 = iVar4 + 0xcU & 3;
              uVar11 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
              lVar1 = (ulonglong)(uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) * 0x32000 +
                      0x800;
              iVar6 = (int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) >> 4;
              lVar3 = (longlong)iVar6 * (longlong)iVar6 + 0x800;
              lVar1 = (longlong)(iVar7 >> 4) * (longlong)(iVar7 >> 4) + 0x800;
              lVar2 = (longlong)(iVar8 >> 4) * (longlong)(iVar8 >> 4) + 0x800;
              if ((int)(((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) +
                       ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000)) <=
                  (int)((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000)) {
                iVar5 = 1;
              }
            }
          }
        }
        if (iVar5 != 0) {
          uVar9 = (*(uint *)(uRam02041768 & 0xfffffffc) >> (uRam02041768 & 3) * 8 |
                  *(uint *)(uRam02041768 & 0xfffffffc) << (uRam02041768 & 3) * -8 + 0x20) + 0xa0;
          uVar11 = uVar9 & 3;
          uVar9 = *(uint *)(uVar9 & 0xfffffffc);
          return *(short *)(iVar4 + 0x40) * 0x28 +
                 (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20);
        }
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < *(ushort *)
                       ((*(uint *)(uRam02041768 & 0xfffffffc) >> (uRam02041768 & 3) * 8 |
                        *(uint *)(uRam02041768 & 0xfffffffc) << (uRam02041768 & 3) * -8 + 0x20) +
                       0x78));
  }
  return 0;
}

