/* Decompiled C draft; module arm9; ROM address 020a73b0. No matching claim. */
#include "types.h"
#include "deps/020a73b0_func_020a73b0.h"

void func_020a73b0(undefined4 param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iStack_38;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uVar6;
  
  uVar6 = param_2 + 0xa0U & 3;
  uVar5 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  *(uint *)(param_2 + 0xa0) = uVar6 - 1;
  if ((int)uVar6 < 1) {
    uVar6 = param_2 + 0x1d4U & 3;
    uVar5 = *(uint *)(param_2 + 0x1d4U & 0xfffffffc);
    uVar9 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    *(uint *)(param_2 + 0x1dc) = uVar9;
    uVar6 = param_2 + 0x1d8U & 3;
    uVar5 = *(uint *)(param_2 + 0x1d8U & 0xfffffffc);
    uVar2 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar6 = param_2 + 0x1e4U & 3;
    uVar7 = *(uint *)(param_2 + 0x1e4U & 0xfffffffc);
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x54 +
            (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 0x34;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    lVar1 = (longlong)(int)uVar9 * (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    *(uint *)(param_2 + 0x1e8) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    iVar3 = func_020d8cc8(param_2 + 0x1d8);
    if (iVar3 == 0) {
      *(undefined4 *)(param_2 + 0xa0) = 0;
    }
    else {
      uVar6 = param_2 + 500U & 3;
      uVar5 = *(uint *)(param_2 + 500U & 0xfffffffc);
      *(uint *)(param_2 + 0xa0) =
           (uint)*(ushort *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0xe);
    }
    uVar6 = param_2 + 0x1d8U & 3;
    uVar5 = *(uint *)(param_2 + 0x1d8U & 0xfffffffc);
    uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 8;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if (uVar6 >> uVar5 * 8 == 0 && uVar6 << uVar5 * -8 + 0x20 == 0) {
      func_020d8918(param_2 + 0x1d8,(uint *)(uintptr_t)(param_2 + 4),(uint *)(uintptr_t)(param_2 + 0x10));
    }
    else {
      func_020d8bf8(param_2 + 0x1d8,param_2 + 4,(int *)(uintptr_t)(param_2 + 0x10));
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1dc) = 0;
    *(undefined4 *)(param_2 + 0x1e8) = 0;
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined4 *)(param_2 + 0x14) = 0;
    *(undefined4 *)(param_2 + 0x18) = 0;
  }
  uVar6 = param_2 + 0x1fcU & 3;
  uVar5 = *(uint *)(param_2 + 0x1fcU & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if (uVar6 != 0) {
    if (uVar6 == 2) {
      uVar6 = (uint)*(ushort *)(param_2 + 0x1d0);
      iVar10 = 0;
      iVar3 = param_2;
      if (uVar6 != 0) {
        do {
          uVar6 = iVar3 + 0xb4U & 3;
          uVar5 = *(uint *)(iVar3 + 0xb4U & 0xfffffffc);
          if (0 < (int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20)) {
            uVar6 = iVar3 + 0xb0U & 3;
            uVar7 = *(uint *)(iVar3 + 0xb0U & 0xfffffffc);
            uVar5 = iVar3 + 0xbcU & 3;
            uVar2 = *(uint *)(iVar3 + 0xbcU & 0xfffffffc);
            *(uint *)(iVar3 + 0xb0) =
                 (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) +
                 (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
            uVar6 = iVar3 + 0xb4U & 3;
            uVar7 = *(uint *)(iVar3 + 0xb4U & 0xfffffffc);
            uVar5 = iVar3 + 0xc0U & 3;
            uVar2 = *(uint *)(iVar3 + 0xc0U & 0xfffffffc);
            *(uint *)(iVar3 + 0xb4) =
                 (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) +
                 (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
            uVar6 = iVar3 + 0xb8U & 3;
            uVar7 = *(uint *)(iVar3 + 0xb8U & 0xfffffffc);
            uVar5 = iVar3 + 0xc4U & 3;
            uVar2 = *(uint *)(iVar3 + 0xc4U & 0xfffffffc);
            *(uint *)(iVar3 + 0xb8) =
                 (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) +
                 (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
            uVar6 = iVar3 + 0xc0U & 3;
            uVar5 = *(uint *)(iVar3 + 0xc0U & 0xfffffffc);
            *(uint *)(iVar3 + 0xc0) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) - 0x400;
          }
          uVar6 = (uint)*(ushort *)(param_2 + 0x1d0);
          iVar10 = iVar10 + 1;
          iVar3 = iVar3 + 0x48;
        } while (iVar10 < (int)uVar6);
      }
      if (((*(ushort *)(param_2 + 2) & 0x12) == 0) && (iVar10 = 0, iVar3 = param_2, uVar6 != 0)) {
        do {
          uVar6 = iVar3 + 0xecU & 3;
          uVar7 = *(uint *)(iVar3 + 0xecU & 0xfffffffc);
          uVar5 = iVar3 + 0xf0U & 3;
          uVar2 = *(uint *)(iVar3 + 0xf0U & 0xfffffffc);
          iVar10 = iVar10 + 1;
          *(uint *)(iVar3 + 0xec) =
               (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) +
               (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
          iVar3 = iVar3 + 0x48;
        } while (iVar10 < (int)(uint)*(ushort *)(param_2 + 0x1d0));
      }
      uVar6 = param_2 + 0x9cU & 3;
      uVar5 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
      if (*(short *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x2a) == 0) {
        uVar6 = param_2 + 0xa8U & 3;
        uVar5 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
        uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        *(uint *)(param_2 + 0xa8) = uVar6 - 1;
        if ((int)uVar6 < 1) {
          iVar3 = 0;
          if (*(short *)(param_2 + 0x1d0) != 0) {
            iVar8 = 0;
            iVar10 = param_2;
            do {
              *(undefined2 *)(iVar10 + 0xcc) = 0;
              *(undefined4 *)(iVar10 + 200) = 0;
              *(undefined4 *)(iVar10 + 0xec) = 0;
              *(int *)(iVar10 + 0xf4) = iVar8;
              iVar3 = iVar3 + 1;
              iVar10 = iVar10 + 0x48;
              iVar8 = iVar8 + 0x14;
            } while (iVar3 < (int)(uint)*(ushort *)(param_2 + 0x1d0));
          }
          *(undefined2 *)(param_2 + 0x1d0) = 1;
          *(undefined4 *)(param_2 + 0x1fc) = 3;
          *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffe;
          *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfff7;
          return;
        }
        return;
      }
      return;
    }
    if (uVar6 != 3) {
      return;
    }
    iVar10 = param_2 + 200;
    iVar3 = (*(ushort *)(param_2 + 0x1d0) - 1) * 0x48;
    uVar6 = iVar10 + iVar3;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(uint *)(iVar10 + iVar3) = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0xcd;
    iVar3 = (*(ushort *)(param_2 + 0x1d0) - 1) * 0x48;
    uVar6 = iVar10 + iVar3;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if (0xfff < (int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20)) {
      *(undefined4 *)(iVar10 + iVar3) = 0x1000;
      *(short *)(param_2 + 0x1d0) = *(short *)(param_2 + 0x1d0) + 1;
      if (4 < *(ushort *)(param_2 + 0x1d0)) {
        *(undefined2 *)(param_2 + 0x1d0) = 4;
        *(undefined4 *)(param_2 + 0x1fc) = 0;
      }
      return;
    }
    return;
  }
  if ((*(ushort *)(param_2 + 2) & 0x12) != 0) {
    return;
  }
  iVar3 = 0;
  if (*(short *)(param_2 + 0x1d0) != 0) {
    iStack_38 = 0;
    iVar10 = param_2;
    do {
      uVar6 = param_2 + 0xa4U & 3;
      uVar5 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      if ((int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) < 1) {
        uVar6 = iVar10 + 0xe4U & 3;
        uVar5 = *(uint *)(iVar10 + 0xe4U & 0xfffffffc);
        uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        if (iRam020a7890 < (int)uVar6) {
          *(uint *)(iVar10 + 0xe4) = uVar6 - 0xb6;
        }
        else {
          *(undefined4 *)(iVar10 + 0xe4) = 0x2d8;
        }
      }
      else {
        *(undefined4 *)(iVar10 + 0xe4) = uRam020a788c;
      }
      uVar6 = iVar10 + 0xf4U & 3;
      uVar5 = *(uint *)(iVar10 + 0xf4U & 0xfffffffc);
      uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      *(uint *)(iVar10 + 0xf4) = uVar6 - 1;
      if ((int)uVar6 < 1) {
        *(undefined4 *)(iVar10 + 0xf4) = 0;
        uVar6 = iVar10 + 0xe4U & 3;
        uVar5 = *(uint *)(iVar10 + 0xe4U & 0xfffffffc);
        *(ushort *)(iVar10 + 0xcc) =
             *(short *)(iVar10 + 0xcc) +
             ((ushort)(uVar5 >> uVar6 * 8) | (ushort)(uVar5 << uVar6 * -8 + 0x20));
        uVar4 = Maybe_get_15d4b4_9(*(undefined2 *)(iVar10 + 0xcc));
        uVar6 = iVar10 + 0xdcU & 3;
        uVar5 = *(uint *)(iVar10 + 0xdcU & 0xfffffffc);
        iVar8 = func_020a7894(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,uVar4);
        uVar6 = iVar10 + 0xd8U & 3;
        uVar7 = *(uint *)(iVar10 + 0xd8U & 0xfffffffc);
        uVar5 = iVar10 + 0xd0U & 3;
        uVar2 = *(uint *)(iVar10 + 0xd0U & 0xfffffffc);
        *(uint *)(iVar10 + 0xd4) =
             ((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + iVar8) -
             (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
        uVar6 = iVar10 + 0xd0U & 3;
        uVar7 = *(uint *)(iVar10 + 0xd0U & 0xfffffffc);
        uVar5 = iVar10 + 0xd4U & 3;
        uVar2 = *(uint *)(iVar10 + 0xd4U & 0xfffffffc);
        *(uint *)(iVar10 + 0xd0) =
             (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) +
             (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
        uVar6 = iVar10 + 0xdcU & 3;
        uVar5 = *(uint *)(iVar10 + 0xdcU & 0xfffffffc);
        uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        if ((int)uVar6 < 1) {
          if ((int)uVar6 < 0) {
            uVar5 = iVar10 + 0xe0U & 3;
            uVar2 = *(uint *)(iVar10 + 0xe0U & 0xfffffffc);
            iVar8 = uVar6 + (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
            if (-1 < iVar8) {
              iVar8 = 0;
            }
            *(int *)(iVar10 + 0xdc) = iVar8;
          }
        }
        else {
          uVar5 = iVar10 + 0xe0U & 3;
          uVar2 = *(uint *)(iVar10 + 0xe0U & 0xfffffffc);
          iVar8 = uVar6 + (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
          if (iVar8 < 1) {
            iVar8 = 0;
          }
          *(int *)(iVar10 + 0xdc) = iVar8;
        }
        uVar6 = iVar10 + 0xe4U & 3;
        uVar5 = *(uint *)(iVar10 + 0xe4U & 0xfffffffc);
        uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        if ((int)uVar6 < 1) {
          if ((int)uVar6 < 0) {
            uVar5 = iVar10 + 0xe8U & 3;
            uVar2 = *(uint *)(iVar10 + 0xe8U & 0xfffffffc);
            iVar8 = uVar6 + (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
            if (-1 < iVar8) {
              iVar8 = iStack_38;
            }
            *(int *)(iVar10 + 0xe4) = iVar8;
          }
        }
        else {
          uVar5 = iVar10 + 0xe8U & 3;
          uVar2 = *(uint *)(iVar10 + 0xe8U & 0xfffffffc);
          iVar8 = uVar6 + (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
          if (iVar8 < 1) {
            iVar8 = 0;
          }
          *(int *)(iVar10 + 0xe4) = iVar8;
        }
        uVar6 = iVar10 + 0xd0U & 3;
        uVar5 = *(uint *)(iVar10 + 0xd0U & 0xfffffffc);
        *(uint *)(iVar10 + 0xec) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0xffff;
      }
      iVar3 = iVar3 + 1;
      iVar10 = iVar10 + 0x48;
    } while (iVar3 < (int)(uint)*(ushort *)(param_2 + 0x1d0));
  }
  uVar6 = param_2 + 0xa4U & 3;
  uVar5 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if ((int)uVar6 < 1) {
    return;
  }
  *(uint *)(param_2 + 0xa4) = uVar6 - 1;
  uVar6 = param_2 + 0xacU & 3;
  uVar5 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if (0 < (int)uVar6) {
    *(uint *)(param_2 + 0xac) = uVar6 - 1;
    return;
  }
  if (0x8000 < *(ushort *)(param_2 + 0xcc)) {
    if (*(ushort *)(param_2 + 0xcc) < 0xc000) {
      iStack_30 = param_2 + 4;
      uStack_34 = 0x194;
      uStack_2c = 2;
      uStack_28 = func_020d4ef4();
      func_0210b7a8((uint)(uintptr_t)(&uStack_34));
      *(undefined4 *)(param_2 + 0xac) = 0x14;
      return;
    }
    return;
  }
  return;
}

