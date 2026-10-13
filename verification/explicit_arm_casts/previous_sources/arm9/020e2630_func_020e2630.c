/* Decompiled C draft; module arm9; ROM address 020e2630. No matching claim. */
#include "types.h"
#include "deps/020e2630_func_020e2630.h"

void func_020e2630(undefined4 param_1,int param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *unaff_r4;
  int unaff_r5;
  uint local_58;
  int aiStack_54 [4];
  int local_44;
  undefined4 uStack_40;
  int local_3c;
  undefined1 auStack_38 [4];
  int local_34;
  uint local_2c;
  int iStack_28;
  uint uStack_24;
  uint local_20;
  int local_1c;
  uint local_18;
  
  if (0xf < *(short *)(param_2 + 0xfe)) {
    unaff_r4 = (int *)0x1;
  }
  local_44 = *(int *)(param_2 + 4);
  uStack_40 = *(undefined4 *)(param_2 + 8);
  iVar7 = *(int *)(param_2 + 0xc);
  if (*(short *)(param_2 + 0xfe) < 0x10) {
    unaff_r4 = (int *)0x0;
  }
  local_3c = iVar7;
  func_020d8cc8(param_2 + 0xd8);
  if (unaff_r4 == (int *)0x0) {
    func_020d8bc0(param_2 + 0xd8,param_2 + 4);
    iVar7 = param_2 + 0x10;
    VecFx32_Subtract(param_2 + 4,&local_44);
    uVar3 = func_02061f90();
    uVar4 = param_2 + 0xd4U & 3;
    uVar5 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
    if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 7) != uVar3) goto LAB_020e28d4;
  }
  else {
    func_020d8bc0(param_2 + 0xd8,param_2 + 0x144);
    iVar6 = iRam020e2a54;
    uVar4 = param_2 + 0x144U & 3;
    uVar3 = *(uint *)(param_2 + 0x144U & 0xfffffffc);
    *(uint *)(param_2 + 4) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar4 = param_2 + 0x14U & 3;
    uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0x14) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) - iVar6;
    uVar4 = param_2 + 8U & 3;
    uVar8 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar3 = param_2 + 0x14U & 3;
    uVar5 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 8) =
         (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) +
         (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
    uVar4 = param_2 + 0x14cU & 3;
    uVar3 = *(uint *)(param_2 + 0x14cU & 0xfffffffc);
    *(uint *)(param_2 + 0xc) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar4 = param_2 + 4U & 3;
    uVar3 = *(uint *)(param_2 + 4U & 0xfffffffc);
    *(uint *)(param_2 + 0x10) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) - local_44;
    uVar4 = param_2 + 0xcU & 3;
    uVar3 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
    *(uint *)(param_2 + 0x18) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) - local_3c;
  }
  uVar4 = param_2 + 4U & 3;
  uVar3 = *(uint *)(param_2 + 4U & 0xfffffffc);
  local_2c = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (unaff_r4 != (int *)0x0) {
    iVar7 = 0xf000;
  }
  uVar4 = param_2 + 8U & 3;
  uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
  if (unaff_r4 == (int *)0x0) {
    iVar7 = 0;
  }
  iStack_28 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + iVar7;
  uVar4 = param_2 + 0xcU & 3;
  uVar3 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  uStack_24 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  local_20 = local_2c;
  local_1c = iStack_28;
  local_18 = uStack_24;
  iVar7 = func_01ffdee4(&local_2c,0,0,0xf000,8,0xfffffffe,auStack_38,&local_2c,0,&local_58,0,0,0,0);
  if (iVar7 != 0) {
    if ((local_58 & uRam020e2a58) != 0) {
      func_020d7b88(&local_2c,param_2 + 0xb4);
      func_0208ab98(param_2 + iRam020e2a5c,(local_58 & 0x3c000000) >> 0x1a,0x5000);
      if ((*(short *)(param_2 + 0xfe) != 0) &&
         (uVar4 = param_2 + 0x14U & 3, uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc),
         (int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) < 0)) {
        if ((*(ushort *)(param_2 + 2) & 1) == 0) {
          if ((unaff_r4 != (int *)0x0) && (param_2 != 0)) {
            *(undefined2 *)(param_2 + 0xfe) = 0xf;
            *(undefined4 *)(param_2 + 0x14) = 0;
            *(undefined2 *)(param_2 + 0x152) = 600;
          }
        }
        else {
          *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffe;
          uVar4 = param_2 + 0x118U & 3;
          uVar5 = *(uint *)(param_2 + 0x118U & 0xfffffffc);
          uVar3 = param_2 + 0x14U & 3;
          uVar8 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
          lVar1 = (longlong)(int)(uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) *
                  (longlong)
                  (iRam020e2a60 +
                  ((int)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) - 0x14000) >> 9));
          *(uint *)(param_2 + 0x14) =
               -((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
          uVar4 = param_2 + 0xc4U & 3;
          uVar3 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
          *(uint *)(param_2 + 0xc4) = -(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
          uVar2 = uRam020e2a64;
          uVar4 = param_2 + 200U & 3;
          uVar3 = *(uint *)(param_2 + 200U & 0xfffffffc);
          *(uint *)(param_2 + 200) = -(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
          uVar4 = param_2 + 0xccU & 3;
          uVar3 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
          *(uint *)(param_2 + 0xcc) = -(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
          func_020d759c(param_2 + 0xc4,param_2 + 0xb4,param_2 + 0xc4,uVar2);
          *(undefined2 *)(param_2 + 0x152) = 800;
          uVar4 = param_2 + 0x160U & 3;
          uVar3 = *(uint *)(param_2 + 0x160U & 0xfffffffc);
          func_020d2774(param_2,uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
        }
      }
    }
    if (((local_58 & uRam020e2a68) != 0) && (unaff_r4 != (int *)0x0)) {
      uVar4 = param_2 + 8U & 3;
      uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
      *(uint *)(param_2 + 8) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + local_34;
      *(undefined4 *)(param_2 + 0x14) = 0;
    }
  }
LAB_020e28d4:
  if (unaff_r4 == (int *)0x0) {
    if (*(short *)(param_2 + 0xfe) != 0) {
      *(short *)(param_2 + 0xfe) = *(short *)(param_2 + 0xfe) + -1;
      if (*(short *)(param_2 + 0xfe) == 0) {
        *(undefined2 *)(param_2 + 0x152) = *(undefined2 *)(param_2 + 0x150);
      }
      else {
        unaff_r5 = param_2 + 0xb4;
      }
    }
  }
  else {
    uVar4 = param_2 + 0x14U & 3;
    uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if ((int)uVar4 < 0) {
      unaff_r4 = (int *)(uVar4 * -0xc);
      *(short *)(param_2 + 0x152) = (short)((uint)unaff_r4 >> 0xc);
      unaff_r5 = param_2 + 0xb4;
    }
    else {
      unaff_r5 = param_2 + 0xc4;
    }
  }
  uVar4 = param_2 + 0x18U & 3;
  uVar3 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
  uVar5 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar4 = param_2 + 0x10U & 3;
  uVar3 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar4 * (longlong)(int)uVar4 + (longlong)(int)uVar5 * (longlong)(int)uVar5;
  iVar6 = (int)((ulonglong)lVar1 >> 0x20);
  uVar4 = (uint)((uint)lVar1 < 0x10);
  iVar7 = iVar6 - uVar4;
  if (iVar6 < (int)uVar4) {
    unaff_r4 = aiStack_54;
    iVar7 = *(int *)(param_2 + 0xb4);
    lVar1 = CONCAT44(*(undefined4 *)(param_2 + 0xb8),*(undefined4 *)(param_2 + 0xbc));
    uVar5 = *(uint *)(param_2 + 0xc0);
  }
  if (iVar6 < (int)uVar4) {
    *unaff_r4 = iVar7;
    unaff_r4[1] = (int)((ulonglong)lVar1 >> 0x20);
    unaff_r4[2] = (int)lVar1;
    unaff_r4[3] = uVar5;
  }
  else {
    uVar4 = param_2 + 0x10U & 3;
    uVar5 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
    uVar3 = param_2 + 0x18U & 3;
    uVar8 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
    uVar4 = func_02148538(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20,
                          uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20);
    *(short *)(param_2 + 0x7e) =
         (short)((int)(((int)uVar4 >> 0x1f) * uRam020e2a6c +
                       uVar4 * iRam020e2a70 +
                       (int)((ulonglong)uRam020e2a6c * (ulonglong)uVar4 >> 0x20) + 0x800) >> 0xc);
    if (*(short *)(param_2 + 0xfe) == 0) {
      unaff_r5 = param_2 + 0xb4;
    }
    func_020d79b0(unaff_r5,*(undefined2 *)(param_2 + 0x7e),aiStack_54);
  }
  func_020d759c(param_2 + 0xa4,aiStack_54,param_2 + 0xa4,*(undefined2 *)(param_2 + 0x152));
  func_01ffccd0(param_2 + 0x28,param_2 + 0xa4);
  *(short *)(param_2 + 0x10c) = *(short *)(param_2 + 0x10c) + 0x600;
  uVar4 = param_2 + 0x78U & 3;
  uVar3 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((uVar4 & 8) != 0) {
    uVar3 = param_2 + 0x158U & 3;
    uVar5 = *(uint *)(param_2 + 0x158U & 0xfffffffc);
    func_0210b7ec(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20,uVar4 & 0x3fffffe0);
  }
  uVar4 = param_2 + 0x15cU & 3;
  uVar3 = *(uint *)(param_2 + 0x15cU & 0xfffffffc);
  func_020d275c(param_2,uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
  uVar4 = param_2 + 8U & 3;
  uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
  if ((int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) < 0) {
    func_020e1e98(param_2);
    return;
  }
  return;
}

