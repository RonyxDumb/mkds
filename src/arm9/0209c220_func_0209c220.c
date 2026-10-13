/* Decompiled C draft; module arm9; ROM address 0209c220. No matching claim. */
#include "types.h"
#include "deps/0209c220_func_0209c220.h"

void func_0209c220(undefined4 param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  if (*(ushort *)(param_2 + 0x100) == uRam0209c4b0) {
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined4 *)(param_2 + 0x14) = 0;
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined2 *)(param_2 + 0xa0) = 0;
  }
  else {
    func_020d8cc8(param_2 + 0xf8);
    func_020d8bf8(param_2 + 0xf8,param_2 + 4,(int *)(uintptr_t)(param_2 + 0x10));
    uVar2 = StructMapObject_SomeFn_1
                      (*(uint *)(uRam0209c4b4 & 0xfffffffc) >> (uRam0209c4b4 & 3) * 8 |
                       *(uint *)(uRam0209c4b4 & 0xfffffffc) << (uRam0209c4b4 & 3) * -8 + 0x20);
    *(short *)(param_2 + 0xa0) = *(short *)(param_2 + 0xa0) + 1;
    if (uVar2 <= *(ushort *)(param_2 + 0xa0)) {
      *(undefined2 *)(param_2 + 0xa0) = 1;
    }
  }
  uVar2 = param_2 + 0x11cU & 3;
  uVar3 = *(uint *)(param_2 + 0x11cU & 0xfffffffc);
  if ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) == 1) {
    uVar2 = param_2 + 0xd0U & 3;
    uVar3 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
    *(ushort *)(param_2 + 0xb8) =
         *(short *)(param_2 + 0xb8) +
         ((ushort)(uVar3 >> uVar2 * 8) | (ushort)(uVar3 << uVar2 * -8 + 0x20));
    uVar4 = Maybe_get_15d4b4_7(*(undefined2 *)(param_2 + 0xb8));
    uVar2 = param_2 + 200U & 3;
    uVar3 = *(uint *)(param_2 + 200U & 0xfffffffc);
    iVar5 = func_0209c4bc(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,uVar4);
    uVar2 = param_2 + 0xc4U & 3;
    uVar8 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
    uVar3 = param_2 + 0xbcU & 3;
    uVar6 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
    *(uint *)(param_2 + 0xc0) =
         ((uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) + iVar5) -
         (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
    uVar2 = param_2 + 0xbcU & 3;
    uVar8 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
    uVar3 = param_2 + 0xc0U & 3;
    uVar6 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
    *(uint *)(param_2 + 0xbc) =
         (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) +
         (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
    uVar2 = param_2 + 200U & 3;
    uVar3 = *(uint *)(param_2 + 200U & 0xfffffffc);
    uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    if ((int)uVar2 < 1) {
      if ((int)uVar2 < 0) {
        uVar3 = param_2 + 0xccU & 3;
        uVar6 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
        iVar5 = uVar2 + (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
        if (-1 < iVar5) {
          iVar5 = 0;
        }
        *(int *)(param_2 + 200) = iVar5;
      }
    }
    else {
      uVar3 = param_2 + 0xccU & 3;
      uVar6 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
      iVar5 = uVar2 + (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
      if (iVar5 < 1) {
        iVar5 = 0;
      }
      *(int *)(param_2 + 200) = iVar5;
    }
    uVar2 = param_2 + 0xd0U & 3;
    uVar3 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
    uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    if ((int)uVar2 < 1) {
      if ((int)uVar2 < 0) {
        uVar3 = param_2 + 0xd4U & 3;
        uVar6 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
        iVar5 = uVar2 + (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
        if (-1 < iVar5) {
          iVar5 = 0;
        }
        *(int *)(param_2 + 0xd0) = iVar5;
      }
    }
    else {
      uVar3 = param_2 + 0xd4U & 3;
      uVar6 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
      iVar5 = uVar2 + (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
      if (iVar5 < 1) {
        iVar5 = 0;
      }
      *(int *)(param_2 + 0xd0) = iVar5;
    }
    uVar2 = param_2 + 0xf0U & 3;
    uVar3 = *(uint *)(param_2 + 0xf0U & 0xfffffffc);
    *(ushort *)(param_2 + 0xd8) =
         *(short *)(param_2 + 0xd8) +
         ((ushort)(uVar3 >> uVar2 * 8) | (ushort)(uVar3 << uVar2 * -8 + 0x20));
    uVar4 = Maybe_get_15d4b4_7(*(undefined2 *)(param_2 + 0xd8));
    uVar2 = param_2 + 0xe8U & 3;
    uVar3 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
    iVar5 = func_0209c4bc(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,uVar4);
    uVar2 = param_2 + 0xe4U & 3;
    uVar8 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
    uVar3 = param_2 + 0xdcU & 3;
    uVar6 = *(uint *)(param_2 + 0xdcU & 0xfffffffc);
    *(uint *)(param_2 + 0xe0) =
         ((uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) + iVar5) -
         (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
    uVar2 = param_2 + 0xdcU & 3;
    uVar8 = *(uint *)(param_2 + 0xdcU & 0xfffffffc);
    uVar3 = param_2 + 0xe0U & 3;
    uVar6 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
    *(uint *)(param_2 + 0xdc) =
         (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) +
         (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
    uVar2 = param_2 + 0xe8U & 3;
    uVar3 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
    uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    if ((int)uVar2 < 1) {
      if ((int)uVar2 < 0) {
        uVar3 = param_2 + 0xecU & 3;
        uVar6 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
        iVar5 = uVar2 + (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
        if (-1 < iVar5) {
          iVar5 = 0;
        }
        *(int *)(param_2 + 0xe8) = iVar5;
      }
    }
    else {
      uVar3 = param_2 + 0xecU & 3;
      uVar6 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
      iVar5 = uVar2 + (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
      if (iVar5 < 1) {
        iVar5 = 0;
      }
      *(int *)(param_2 + 0xe8) = iVar5;
    }
    uVar2 = param_2 + 0xf0U & 3;
    uVar3 = *(uint *)(param_2 + 0xf0U & 0xfffffffc);
    uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    if ((int)uVar2 < 1) {
      if ((int)uVar2 < 0) {
        uVar3 = param_2 + 0xf4U & 3;
        uVar6 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
        iVar5 = uVar2 + (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
        if (-1 < iVar5) {
          iVar5 = 0;
        }
        *(int *)(param_2 + 0xf0) = iVar5;
      }
    }
    else {
      uVar3 = param_2 + 0xf4U & 3;
      uVar6 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
      iVar5 = uVar2 + (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
      if (iVar5 < 1) {
        iVar5 = 0;
      }
      *(int *)(param_2 + 0xf0) = iVar5;
    }
    uVar2 = param_2 + 200U & 3;
    uVar3 = *(uint *)(param_2 + 200U & 0xfffffffc);
    if ((uVar3 >> uVar2 * 8 == 0 && uVar3 << uVar2 * -8 + 0x20 == 0) &&
       (uVar2 = param_2 + 0xe8U & 3, uVar3 = *(uint *)(param_2 + 0xe8U & 0xfffffffc),
       uVar3 >> uVar2 * 8 == 0 && uVar3 << uVar2 * -8 + 0x20 == 0)) {
      *(undefined4 *)(param_2 + 0x11c) = 0;
      uVar2 = param_2 + 0xb4U & 3;
      uVar3 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
      *(uint *)(param_2 + 0x1c) = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    }
    else {
      uVar2 = param_2 + 0xb4U & 3;
      uVar8 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
      uVar3 = param_2 + 0xbcU & 3;
      uVar6 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) *
              (longlong)(int)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
      *(uint *)(param_2 + 0x1c) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    }
  }
  else {
    uVar2 = param_2 + 0xb4U & 3;
    uVar3 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    *(uint *)(param_2 + 0x1c) = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  }
  iVar5 = 0;
  uVar2 = (uint)*(byte *)((*(uint *)(uRam0209c4b8 & 0xfffffffc) >> (uRam0209c4b8 & 3) * 8 |
                          *(uint *)(uRam0209c4b8 & 0xfffffffc) << (uRam0209c4b8 & 3) * -8 + 0x20) +
                         0x3d0);
  if (uVar2 == 0) {
    return;
  }
  do {
    iVar7 = param_2 + iVar5 * 4;
    uVar3 = iVar7 + 0x120;
    uVar6 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    iVar5 = iVar5 + 1;
    if (0 < (int)uVar3) {
      *(uint *)(iVar7 + 0x120) = uVar3 - 1;
    }
  } while (iVar5 < (int)uVar2);
  return;
}

