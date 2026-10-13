/* Decompiled C draft; module arm9; ROM address 0209fdb4. No matching claim. */
#include "types.h"
#include "deps/0209fdb4_func_0209fdb4.h"

void func_0209fdb4(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar4;
  
  uVar5 = uRam020a0024;
  uVar4 = param_2 + 0xecU & 3;
  uVar3 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar4 == 0) {
    uVar4 = 0;
    if (*(char *)((*(uint *)(uRam020a0024 & 0xfffffffc) >> (uRam020a0024 & 3) * 8 |
                  *(uint *)(uRam020a0024 & 0xfffffffc) << (uRam020a0024 & 3) * -8 + 0x20) + 0x3d0)
        != '\0') {
      do {
        uVar3 = func_0203c8c0(uVar4 & 0xffff);
        if (1 < uVar3) {
          bVar1 = true;
          goto LAB_0209fe24;
        }
        uVar3 = uVar5 & 3;
        uVar7 = *(uint *)(uVar5 & 0xfffffffc);
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 <
               (int)(uint)*(byte *)((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0x3d0));
    }
    bVar1 = false;
LAB_0209fe24:
    if (bVar1) {
      *(undefined4 *)(param_2 + 0xec) = 1;
    }
  }
  else if (uVar4 == 1) {
    uVar4 = param_2 + 0xa0U & 3;
    uVar5 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    *(uint *)(param_2 + 0xa0) = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0x1000;
    uVar4 = param_2 + 0xa0U & 3;
    uVar5 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    if (-1 < (int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xa0) = 0;
      *(undefined4 *)(param_2 + 0xec) = 2;
    }
    uVar4 = param_2 + 0xc0U & 3;
    uVar5 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
    *(ushort *)(param_2 + 0xa8) =
         *(short *)(param_2 + 0xa8) +
         ((ushort)(uVar5 >> uVar4 * 8) | (ushort)(uVar5 << uVar4 * -8 + 0x20));
    iVar6 = Maybe_helper_0a0044(*(undefined2 *)(param_2 + 0xa8));
    uVar4 = param_2 + 0xb8U & 3;
    uVar5 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
    iVar6 = func_020a0028((int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) / 2,0x1000 - iVar6)
    ;
    uVar4 = param_2 + 0xb4U & 3;
    uVar7 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    uVar5 = param_2 + 0xacU & 3;
    uVar3 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    *(uint *)(param_2 + 0xb0) =
         ((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + iVar6) -
         (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
    uVar4 = param_2 + 0xacU & 3;
    uVar7 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    uVar5 = param_2 + 0xb0U & 3;
    uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
    *(uint *)(param_2 + 0xac) =
         (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) +
         (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
    uVar4 = param_2 + 0xb8U & 3;
    uVar5 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
    uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    if ((int)uVar4 < 1) {
      if ((int)uVar4 < 0) {
        uVar5 = param_2 + 0xbcU & 3;
        uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        iVar6 = uVar4 + (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
        if (-1 < iVar6) {
          iVar6 = 0;
        }
        *(int *)(param_2 + 0xb8) = iVar6;
      }
    }
    else {
      uVar5 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      iVar6 = uVar4 + (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
      if (iVar6 < 1) {
        iVar6 = 0;
      }
      *(int *)(param_2 + 0xb8) = iVar6;
    }
    uVar4 = param_2 + 0xc0U & 3;
    uVar5 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
    uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    if ((int)uVar4 < 1) {
      if ((int)uVar4 < 0) {
        uVar5 = param_2 + 0xc4U & 3;
        uVar3 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
        iVar6 = uVar4 + (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
        if (-1 < iVar6) {
          iVar6 = 0;
        }
        *(int *)(param_2 + 0xc0) = iVar6;
      }
    }
    else {
      uVar5 = param_2 + 0xc4U & 3;
      uVar3 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
      iVar6 = uVar4 + (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
      if (iVar6 < 1) {
        iVar6 = 0;
      }
      *(int *)(param_2 + 0xc0) = iVar6;
    }
  }
  else if (uVar4 == 2) {
    func_020d8cc8(param_2 + 200);
    func_020d8bf8(param_2 + 200,param_2 + 4,param_2 + 0x10);
    uVar4 = param_2 + 0xc0U & 3;
    uVar5 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
    *(ushort *)(param_2 + 0xa8) =
         *(short *)(param_2 + 0xa8) +
         ((ushort)(uVar5 >> uVar4 * 8) | (ushort)(uVar5 << uVar4 * -8 + 0x20));
    iVar6 = Maybe_helper_0a0044(*(undefined2 *)(param_2 + 0xa8));
    uVar4 = param_2 + 0xb8U & 3;
    uVar5 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
    iVar6 = func_020a0028((int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) / 2,0x1000 - iVar6)
    ;
    uVar4 = param_2 + 0xb4U & 3;
    uVar7 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    uVar5 = param_2 + 0xacU & 3;
    uVar3 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    *(uint *)(param_2 + 0xb0) =
         ((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + iVar6) -
         (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
    uVar4 = param_2 + 0xacU & 3;
    uVar7 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    uVar5 = param_2 + 0xb0U & 3;
    uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
    *(uint *)(param_2 + 0xac) =
         (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) +
         (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
    uVar4 = param_2 + 0xb8U & 3;
    uVar5 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
    uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    if ((int)uVar4 < 1) {
      if ((int)uVar4 < 0) {
        uVar5 = param_2 + 0xbcU & 3;
        uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        iVar6 = uVar4 + (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
        if (-1 < iVar6) {
          iVar6 = 0;
        }
        *(int *)(param_2 + 0xb8) = iVar6;
      }
    }
    else {
      uVar5 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      iVar6 = uVar4 + (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
      if (iVar6 < 1) {
        iVar6 = 0;
      }
      *(int *)(param_2 + 0xb8) = iVar6;
    }
    uVar4 = param_2 + 0xc0U & 3;
    uVar5 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
    uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    if ((int)uVar4 < 1) {
      if ((int)uVar4 < 0) {
        uVar5 = param_2 + 0xc4U & 3;
        uVar3 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
        iVar6 = uVar4 + (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
        if (-1 < iVar6) {
          iVar6 = 0;
        }
        *(int *)(param_2 + 0xc0) = iVar6;
      }
    }
    else {
      uVar5 = param_2 + 0xc4U & 3;
      uVar3 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
      iVar6 = uVar4 + (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
      if (iVar6 < 1) {
        iVar6 = 0;
      }
      *(int *)(param_2 + 0xc0) = iVar6;
    }
  }
  uVar4 = param_2 + 0x10U & 3;
  uVar3 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
  uVar5 = param_2 + 0x18U & 3;
  uVar7 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
  uVar2 = FX_Atan2(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,
                   uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
  *(undefined2 *)(param_2 + 0x7e) = uVar2;
  return;
}

