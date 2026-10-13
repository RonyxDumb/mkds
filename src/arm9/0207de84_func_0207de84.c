/* Decompiled C draft; module arm9; ROM address 0207de84. No matching claim. */
#include "types.h"
#include "deps/0207de84_func_0207de84.h"

void func_0207de84(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  
  uVar4 = func_02061f90();
  if (*(ushort *)(param_2 + 4) == uVar4) {
    bVar11 = false;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    uVar4 = (uint)*(ushort *)(param_2 + 4) * 0x30 +
            (*(uint *)(uRam0207e078 & 0xfffffffc) >> (uRam0207e078 & 3) * 8 |
            *(uint *)(uRam0207e078 & 0xfffffffc) << (uRam0207e078 & 3) * -8 + 0x20) + 0x70;
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
    if ((uVar4 < 4) && ((1 << (uVar4 & 0xff) & 0xdU) != 0)) {
      bVar11 = true;
    }
    if (bVar11) {
      uVar5 = GetDriverPlace();
      *(undefined4 *)(param_1 + 0x14) = uVar5;
    }
    else {
      uVar5 = func_020854c0();
      *(undefined4 *)(param_1 + 0x14) = uVar5;
    }
    uVar4 = func_02085424();
    *(uint *)(param_1 + 8) =
         *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
         *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    iVar6 = func_02085390();
    if (iVar6 != 0) {
      uVar4 = param_1 + 8U & 3;
      uVar7 = *(uint *)(param_1 + 8U & 0xfffffffc);
      *(int *)(param_1 + 8) = (int)(uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) >> 1;
    }
    uVar7 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
            *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
    uVar9 = param_2 + 0xa8 & 3;
    uVar8 = *(uint *)(param_2 + 0xa8 & 0xfffffffc);
    uVar1 = param_1 + 8U & 3;
    uVar10 = *(uint *)(param_1 + 8U & 0xfffffffc);
    uVar4 = uVar7 + 0xcc;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = (uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20) +
            (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
    if ((uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) == 2) {
      uVar4 = 0x3000;
    }
    uVar7 = uVar7 + 0x4c;
    uVar9 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    if (0xa000 < (int)uVar4) {
      uVar4 = 0xa000;
    }
    if (((uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) & 0x8000000) != 0) {
      uVar7 = (uint)((ulonglong)uRam0207e07c * (ulonglong)uVar4);
      uVar4 = uVar7 + 0x800 >> 0xc |
              (((int)uVar4 >> 0x1f) * uRam0207e07c +
               (int)((ulonglong)uRam0207e07c * (ulonglong)uVar4 >> 0x20) +
              (uint)(0xfffff7ff < uVar7)) * 0x100000;
    }
    uVar7 = param_2 + 0x90 & 3;
    uVar9 = *(uint *)(param_2 + 0x90 & 0xfffffffc);
    if (uVar9 >> uVar7 * 8 == 0 && uVar9 << uVar7 * -8 + 0x20 == 0) {
      *(uint *)(param_1 + 0xc) = uVar4;
      uVar4 = param_2 + 0x70 & 3;
      uVar7 = *(uint *)(param_2 + 0x70 & 0xfffffffc);
      uVar4 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
      if (0x5000 < (int)uVar4) {
        uVar4 = uVar4 - 0x5000;
        lVar3 = (ulonglong)uVar4 * 0x5b;
        uVar4 = (uint)lVar3 >> 0xc |
                (((int)uVar4 >> 0x1f) * 0x5b + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000;
        if (0x1000 < (int)uVar4) {
          uVar4 = 0x1000;
        }
        lVar3 = (ulonglong)
                (0x1000 - ((uint)((ulonglong)uRam0207e080 * (ulonglong)uVar4) >> 0xc |
                          (((int)uVar4 >> 0x1f) * uRam0207e080 +
                          (int)((ulonglong)uRam0207e080 * (ulonglong)uVar4 >> 0x20)) * 0x100000)) *
                0xa000;
        *(uint *)(param_1 + 0xc) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
      }
      func_0207d9f0(param_1,param_2);
      uVar4 = param_1 + 0x10U & 3;
      uVar7 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      uVar4 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
    }
    uVar7 = param_1 + 0xcU & 3;
    uVar9 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    uVar7 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
    if ((int)uVar7 < (int)uVar4) {
      uVar4 = uVar7;
    }
    if (0xa000 < (int)uVar4) {
      uVar4 = 0xa000;
    }
    *(uint *)(param_1 + 4) = uVar4;
  }
  uVar9 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar4 = uVar9 + 0x180 & 3;
  uVar7 = *(uint *)(uVar9 + 0x180 & 0xfffffffc);
  if (uVar7 >> uVar4 * 8 == 0 && uVar7 << uVar4 * -8 + 0x20 == 0) {
    uVar4 = uVar9 + 0x4c & 3;
    uVar7 = *(uint *)(uVar9 + 0x4c & 0xfffffffc);
    if (((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) & 0x10000000) == 0) {
      uVar4 = uVar9 + 0x48 & 3;
      uVar7 = *(uint *)(uVar9 + 0x48 & 0xfffffffc);
      if (((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) & uRam0207e084) == 0) {
        uVar4 = param_1 + 4U & 3;
        uVar7 = *(uint *)(param_1 + 4U & 0xfffffffc);
        *(uint *)(uVar9 + 0xcc) = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
      }
      return;
    }
    return;
  }
  return;
}

