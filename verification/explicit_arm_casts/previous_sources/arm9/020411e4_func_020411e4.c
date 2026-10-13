/* Decompiled C draft; module arm9; ROM address 020411e4. No matching claim. */
#include "types.h"
#include "deps/020411e4_func_020411e4.h"

uint func_020411e4(undefined4 param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  ushort uVar9;
  uint uVar10;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined1 auStack_34 [16];
  
  uVar9 = 0;
  if (*(short *)((*(uint *)(uRam020413a0 & 0xfffffffc) >> (uRam020413a0 & 3) * 8 |
                 *(uint *)(uRam020413a0 & 0xfffffffc) << (uRam020413a0 & 3) * -8 + 0x20) + 0x78) !=
      0) {
    local_44 = 0;
    local_3c = 0;
    local_40 = 0;
    local_38 = 1;
    do {
      iVar5 = GetGlobalPENkmAREAByIndex_from_thumb(uVar9);
      if (*(char *)(iVar5 + 0x44) == '\x01') {
        if (*(char *)(iVar5 + 0x42) == '\0') {
          iVar6 = func_02041a70(param_1,iVar5);
        }
        else {
          iVar6 = local_44;
          if (*(char *)(iVar5 + 0x42) == '\x01') {
            VecFx32_Subtract(param_1,iVar5,auStack_34);
            iVar7 = Vector3_DotProduct(auStack_34,iVar5 + 0x24);
            uVar1 = iVar5 + 0x10U & 3;
            uVar10 = *(uint *)(iVar5 + 0x10U & 0xfffffffc);
            lVar2 = (ulonglong)(uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20) * 0x32000 + 0x800
            ;
            iVar6 = local_40;
            if (iVar7 <= (int)((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000)) {
              iVar7 = Vector3_DotProduct(auStack_34,iVar5 + 0x18);
              iVar8 = Vector3_DotProduct(auStack_34,iVar5 + 0x30);
              uVar1 = iVar5 + 0xcU & 3;
              uVar10 = *(uint *)(iVar5 + 0xcU & 0xfffffffc);
              lVar2 = (ulonglong)(uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20) * 0x32000 +
                      0x800;
              iVar6 = (int)((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) >> 4;
              lVar4 = (longlong)iVar6 * (longlong)iVar6 + 0x800;
              lVar3 = (longlong)(iVar7 >> 4) * (longlong)(iVar7 >> 4) + 0x800;
              lVar2 = (longlong)(iVar8 >> 4) * (longlong)(iVar8 >> 4) + 0x800;
              iVar6 = local_3c;
              if ((int)(((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
                       ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000)) <=
                  (int)((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000)) {
                iVar6 = local_38;
              }
            }
          }
        }
        if (iVar6 != 0) {
          return (uint)*(byte *)(iVar5 + 0x43);
        }
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(ushort *)
                      ((*(uint *)(uRam020413a0 & 0xfffffffc) >> (uRam020413a0 & 3) * 8 |
                       *(uint *)(uRam020413a0 & 0xfffffffc) << (uRam020413a0 & 3) * -8 + 0x20) +
                      0x78));
  }
  return 0xffffffff;
}

