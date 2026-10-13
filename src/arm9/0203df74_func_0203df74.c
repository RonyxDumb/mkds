/* Decompiled C draft; module arm9; ROM address 0203df74. No matching claim. */
#include "types.h"
#include "deps/0203df74_func_0203df74.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_0203df74(undefined4 param_1,int param_2)

{
  longlong lVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ushort *puVar12;
  uint local_28;
  
  uVar11 = (uint)*(ushort *)(param_2 + 0x38);
  local_28 = 0;
  uVar5 = (uint)*(short *)(param_2 + 0x32);
  iVar4 = HasDriverFlagBBit11(((uint)*(ushort *)(param_2 + 0x3c) << 0x18) >> 0x1c);
  if (iVar4 != 0) {
    return;
  }
  iVar4 = DriverStatus_SomeFn_0(param_2,&local_28,param_1,uVar11);
  if (iVar4 == 0) {
    if ((int)local_28 < 0) {
      uVar5 = StructRC_SomeFn_1(param_2,&local_28,param_1,uVar11);
      if (uVar5 == 0xffffffff) {
        uVar5 = StructRC_SomeFn(param_2,&local_28,param_1,uVar11);
      }
    }
    else {
      uVar5 = StructRC_SomeFn(param_2,&local_28,param_1,uVar11);
      if (uVar5 == 0xffffffff) {
        uVar5 = StructRC_SomeFn_1(param_2,&local_28,param_1,uVar11);
      }
    }
    uVar11 = uRam0203e368;
    if (uVar5 == 0xffffffff) {
      uVar5 = 0;
      uVar7 = *(uint *)(uRam0203e368 & 0xfffffffc) >> (uRam0203e368 & 3) * 8 |
              *(uint *)(uRam0203e368 & 0xfffffffc) << (uRam0203e368 & 3) * -8 + 0x20;
      if (*(short *)(uVar7 + 0x50) != 0) {
        do {
          uVar8 = uVar7 + 0x4c & 3;
          uVar7 = *(uint *)(uVar7 + 0x4c & 0xfffffffc);
          uVar7 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
          uVar3 = *(ushort *)(uVar7 + uVar5 * 0xc);
          uVar2 = uVar3 + *(short *)(uVar7 + uVar5 * 0xc + 2);
          for (; uVar3 < uVar2; uVar3 = uVar3 + 1) {
            iVar4 = DriverStatus_SomeFn_0(param_2,&local_28,param_1,uVar5);
            if (iVar4 != 0) {
              uVar5 = (uint)(short)uVar3;
              goto LAB_0203e144;
            }
          }
          uVar7 = uVar11 & 3;
          uVar8 = *(uint *)(uVar11 & 0xfffffffc);
          uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
          uVar5 = uVar5 + 1 & 0xffff;
        } while (uVar5 < *(ushort *)(uVar7 + 0x50));
      }
      uVar5 = 0xffffffff;
    }
LAB_0203e144:
    if (uVar5 == 0xffffffff) {
      return;
    }
    uVar11 = 0;
    uVar7 = *(uint *)(uRam0203e368 & 0xfffffffc) >> (uRam0203e368 & 3) * 8 |
            *(uint *)(uRam0203e368 & 0xfffffffc) << (uRam0203e368 & 3) * -8 + 0x20;
    if (*(short *)(uVar7 + 0x50) != 0) {
      uVar8 = uVar7 + 0x4c & 3;
      uVar6 = *(uint *)(uVar7 + 0x4c & 0xfffffffc);
      uVar8 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
      do {
        uVar6 = (uint)*(ushort *)(uVar8 + uVar11 * 0xc);
        if ((uVar6 <= (uVar5 & 0xffff)) &&
           ((uVar5 & 0xffff) < (uVar6 + *(ushort *)(uVar8 + uVar11 * 0xc + 2) & 0xffff)))
        goto LAB_0203e1c8;
        uVar11 = uVar11 + 1 & 0xffff;
      } while (uVar11 < *(ushort *)(uVar7 + 0x50));
    }
    uVar11 = 0;
  }
LAB_0203e1c8:
  uVar7 = (*(uint *)(uRam0203e368 & 0xfffffffc) >> (uRam0203e368 & 3) * 8 |
          *(uint *)(uRam0203e368 & 0xfffffffc) << (uRam0203e368 & 3) * -8 + 0x20) + 0x4c;
  uVar8 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  puVar12 = (ushort *)(uVar7 + uVar11 * 0xc);
  if (puVar12[1] == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FX_Div(((uVar5 & 0xffff) - (uint)*(ushort *)(uVar7 + uVar11 * 0xc)) * 0x1000 + local_28,
                   (uint)puVar12[1] << 0xc);
  }
  uVar7 = *(uint *)(uRam0203e36c & 0xfffffffc) >> (uRam0203e36c & 3) * 8 |
          *(uint *)(uRam0203e36c & 0xfffffffc) << (uRam0203e36c & 3) * -8 + 0x20;
  uVar11 = uVar7 + 0x4e4 & 3;
  uVar8 = *(uint *)(uVar7 + 0x4e4 & 0xfffffffc);
  lVar1 = (longlong)(int)(iVar4 + (uint)(byte)puVar12[5] * 0x1000) *
          (longlong)(int)(uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) + 0x800;
  uVar8 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  uVar11 = 0;
  if (uVar5 != 0xffffffff) {
    uVar6 = *(uint *)(uRam0203e368 & 0xfffffffc) >> (uRam0203e368 & 3) * 8 |
            *(uint *)(uRam0203e368 & 0xfffffffc) << (uRam0203e368 & 3) * -8 + 0x20;
    uVar10 = (uint)*(ushort *)(uVar6 + 0x98);
    if (uVar10 != 0) {
      uVar11 = uVar10 - 1;
      uVar6 = uVar7 + 0x4d4 & 3;
      uVar9 = *(uint *)(uVar7 + 0x4d4 & 0xfffffffc);
      uVar6 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
    }
    uVar9 = uVar7 + 0x4d4 & 3;
    uVar7 = *(uint *)(uVar7 + 0x4d4 & 0xfffffffc);
    if (uVar10 != 0) {
      uVar6 = uVar6 + uVar11 * 4;
      uVar11 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar11 = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20;
    }
    uVar7 = (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) + (*(short *)(param_2 + 0x34) + 1) * 4
    ;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    if ((int)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) < (int)uVar8) {
      if ((*(short *)(param_2 + 0x32) == 0) && ((int)uVar11 < (int)uVar8)) {
        func_0203e370(param_2,uVar5);
      }
      else {
        uVar11 = param_2 + 0x40U & 3;
        uVar5 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
        local_28 = uVar5 >> uVar11 * 8 | uVar5 << uVar11 * -8 + 0x20;
        if (puVar12[1] == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FX_Div(((uint)*(ushort *)(param_2 + 0x32) - (uint)*puVar12) * 0x1000 + local_28,
                         (uint)puVar12[1] << 0xc);
        }
        uVar11 = (*(uint *)(uRam0203e36c & 0xfffffffc) >> (uRam0203e36c & 3) * 8 |
                 *(uint *)(uRam0203e36c & 0xfffffffc) << (uRam0203e36c & 3) * -8 + 0x20) + 0x4e4;
        uVar5 = uVar11 & 3;
        uVar11 = *(uint *)(uVar11 & 0xfffffffc);
        lVar1 = (longlong)(int)(iVar4 + (uint)(byte)puVar12[5] * 0x1000) *
                (longlong)(int)(uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) + 0x800;
        uVar8 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
      }
    }
    else {
      func_0203e370(param_2,uVar5);
    }
  }
  uVar7 = uRam0203e36c;
  *(uint *)(param_2 + 0x40) = local_28;
  *(uint *)(param_2 + 0x48) = uVar8;
  uVar5 = param_2 + 0x24U & 3;
  uVar10 = *(uint *)(param_2 + 0x24U & 0xfffffffc);
  uVar11 = uVar7 & 3;
  uVar8 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = param_2 + 0x48U & 3;
  uVar6 = *(uint *)(param_2 + 0x48U & 0xfffffffc);
  uVar11 = (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) + 0x4e8;
  uVar8 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  lVar1 = (longlong)
          (int)((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) +
               ((uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) - 1) * 0x1000) *
          (longlong)(int)(uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20) + 0x800;
  *(uint *)(param_2 + 0x44) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  return;
}

