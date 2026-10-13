/* Decompiled C draft; module arm9; ROM address 01ffaf18. No matching claim. */
#include "types.h"
#include "deps/01ffaf18_func_01ffaf18.h"

uint func_01ffaf18(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar10;
  bool bVar11;
  uint uVar5;
  uint uVar9;
  
  uVar5 = param_1 + 0x2a8U & 3;
  uVar6 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
  uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0x48U & 3;
  uVar4 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  bVar11 = (int)uVar6 < 0;
  if ((int)uVar6 < 1) {
    uVar6 = -uVar6;
  }
  uVar4 = param_1 + 0x274U & 3;
  uVar8 = *(uint *)(param_1 + 0x274U & 0xfffffffc);
  uVar9 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0xd0U & 3;
  uVar8 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  iVar10 = (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) - uVar9;
  if ((((uVar5 & 4) != 0) &&
      (uVar4 = param_1 + 0x44U & 3, uVar8 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
      ((uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) & 0x100) != 0)) && (0x3000 < iVar10)) {
    iVar10 = 0x3000;
  }
  uVar4 = param_1 + 0x38cU & 3;
  uVar8 = *(uint *)(param_1 + 0x38cU & 0xfffffffc);
  uVar3 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0x394U & 3;
  uVar7 = *(uint *)(param_1 + 0x394U & 0xfffffffc);
  uVar8 = param_1 + 0x39cU & 3;
  uVar2 = *(uint *)(param_1 + 0x39cU & 0xfffffffc);
  lVar1 = (longlong)(int)uVar3 * (longlong)(int)(uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20);
  lVar1 = (longlong)iVar10 *
          (longlong)(int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  iVar10 = (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) +
           uVar9 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  if (iVar10 < (int)uVar6) {
    *(int *)(param_1 + 0x2a8) = iVar10;
  }
  else if ((((int)((uint)((ulonglong)uRam01ffb0c8 * (ulonglong)uVar3) >> 0xc |
                  (((int)uVar3 >> 0x1f) * uRam01ffb0c8 +
                  (int)((ulonglong)uRam01ffb0c8 * (ulonglong)uVar3 >> 0x20)) * 0x100000) <
             (int)uVar6) ||
           (uVar4 = param_1 + 0x44U & 3, uVar8 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
           ((uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) & 0x80000) != 0)) ||
          ((uVar5 & 6) != 0)) {
    *(uint *)(param_1 + 0x2a8) = uVar6;
  }
  else {
    *(undefined4 *)(param_1 + 0x2a8) = 0;
  }
  if (bVar11) {
    uVar5 = param_1 + 0x2a8U & 3;
    uVar6 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
    *(uint *)(param_1 + 0x2a8) = -(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  }
  uVar5 = param_1 + 0x3a0U & 3;
  uVar6 = *(uint *)(param_1 + 0x3a0U & 0xfffffffc);
  uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  if (uVar5 != 0) {
    if ((int)uVar5 < 1) {
      uVar6 = param_1 + 0x2a8U & 3;
      uVar4 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
      uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
      if ((int)uVar6 < 1) {
        if ((int)uVar6 < 1) {
          uVar6 = -uVar6;
        }
        uVar4 = uVar5;
        if ((int)uVar5 < 1) {
          uVar4 = -uVar5;
        }
        if ((int)uVar6 < (int)uVar4) {
          *(uint *)(param_1 + 0x2a8) = uVar5;
        }
      }
      else {
        *(uint *)(param_1 + 0x2a8) = uVar6 + uVar5;
        uVar5 = param_1 + 0x3a0U & 3;
        uVar6 = *(uint *)(param_1 + 0x3a0U & 0xfffffffc);
        uVar4 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
        uVar5 = param_1 + 0x2a8U & 3;
        uVar6 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
        if ((int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) < (int)uVar4) {
          *(uint *)(param_1 + 0x2a8) = uVar4;
        }
      }
    }
    else {
      uVar6 = param_1 + 0x2a8U & 3;
      uVar4 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
      uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
      if ((int)uVar6 < 0) {
        *(uint *)(param_1 + 0x2a8) = uVar6 + uVar5;
        uVar5 = param_1 + 0x3a0U & 3;
        uVar6 = *(uint *)(param_1 + 0x3a0U & 0xfffffffc);
        uVar4 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
        uVar5 = param_1 + 0x2a8U & 3;
        uVar6 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
        if ((int)uVar4 < (int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20)) {
          *(uint *)(param_1 + 0x2a8) = uVar4;
        }
      }
      else {
        if ((int)uVar6 < 1) {
          uVar6 = -uVar6;
        }
        uVar4 = uVar5;
        if ((int)uVar5 < 1) {
          uVar4 = -uVar5;
        }
        if ((int)uVar6 < (int)uVar4) {
          *(uint *)(param_1 + 0x2a8) = uVar5;
        }
      }
    }
  }
  uVar5 = param_1 + 0x274U & 3;
  uVar4 = *(uint *)(param_1 + 0x274U & 0xfffffffc);
  uVar6 = param_1 + 0x2a8U & 3;
  uVar8 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) *
          (longlong)(0x1000 - ((int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) >> 3)) + 0x800
  ;
  return (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
}

