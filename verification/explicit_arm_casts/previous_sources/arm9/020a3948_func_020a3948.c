/* Decompiled C draft; module arm9; ROM address 020a3948. No matching claim. */
#include "types.h"
#include "deps/020a3948_func_020a3948.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020a3948(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined1 auStack_ac [36];
  undefined1 auStack_88 [36];
  uint uStack_64;
  uint uStack_60;
  uint uStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint uVar9;
  
  uVar9 = param_2 + 0xa4U & 3;
  uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  if ((-1 < (int)(uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20)) &&
     (iVar3 = GetDriverEntry(), *(short *)(iVar3 + 900) == 0)) {
    return;
  }
  uVar6 = uRam020a3e20;
  uVar2 = uRam020a3e18;
  uVar9 = param_2 + 0xf4U & 3;
  uVar8 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
  uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  if ((uVar9 == 1) &&
     (uVar8 = param_2 + 0xf8U & 3, uVar4 = *(uint *)(param_2 + 0xf8U & 0xfffffffc),
     uVar4 >> uVar8 * 8 == 0 && uVar4 << uVar8 * -8 + 0x20 == 0)) {
    uVar9 = param_2 + 0x78U & 3;
    uVar8 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
    uVar9 = (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) & 0x3fffffe0;
    if (uVar9 < uRam020a3e14) {
      uVar9 = param_2 + 4U & 3;
      uVar6 = *(uint *)(param_2 + 4U & 0xfffffffc);
      *(uint *)(param_2 + 0xe8) =
           (*(uint *)(uRam020a3e18 & 0xfffffffc) >> (uRam020a3e18 & 3) * 8 |
           *(uint *)(uRam020a3e18 & 0xfffffffc) << (uRam020a3e18 & 3) * -8 + 0x20) +
           ((int)(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) >> 1);
      uVar9 = uVar2 + 4 & 3;
      uVar4 = *(uint *)(uVar2 + 4 & 0xfffffffc);
      uVar6 = param_2 + 8U & 3;
      uVar8 = *(uint *)(param_2 + 8U & 0xfffffffc);
      *(uint *)(param_2 + 0xec) =
           (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) +
           ((int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) >> 1);
      uVar9 = uVar2 + 8 & 3;
      uVar8 = *(uint *)(uVar2 + 8 & 0xfffffffc);
      uVar2 = param_2 + 0xcU & 3;
      uVar6 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
      *(uint *)(param_2 + 0xf0) =
           (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) +
           ((int)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) >> 1);
      *(undefined4 *)(param_2 + 0xe4) = 0x800;
    }
    else if (uVar9 < uRam020a3e1c) {
      uVar9 = param_2 + 4U & 3;
      uVar2 = *(uint *)(param_2 + 4U & 0xfffffffc);
      uVar9 = uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20;
      *(uint *)(param_2 + 0xe8) =
           ((*(uint *)(uRam020a3e20 & 0xfffffffc) >> (uRam020a3e20 & 3) * 8 |
            *(uint *)(uRam020a3e20 & 0xfffffffc) << (uRam020a3e20 & 3) * -8 + 0x20) + uVar9) -
           ((int)uVar9 >> 3);
      uVar9 = param_2 + 8U & 3;
      uVar2 = *(uint *)(param_2 + 8U & 0xfffffffc);
      uVar8 = uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20;
      uVar9 = uVar6 + 4 & 3;
      uVar2 = *(uint *)(uVar6 + 4 & 0xfffffffc);
      *(uint *)(param_2 + 0xec) =
           ((uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20) + uVar8) - ((int)uVar8 >> 3);
      uVar9 = param_2 + 0xcU & 3;
      uVar2 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
      uVar8 = uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20;
      uVar9 = uVar6 + 8 & 3;
      uVar2 = *(uint *)(uVar6 + 8 & 0xfffffffc);
      *(uint *)(param_2 + 0xf0) =
           ((uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20) + uVar8) - ((int)uVar8 >> 3);
      *(undefined4 *)(param_2 + 0xe4) = 0xe00;
    }
    else {
      *(undefined4 *)(param_2 + 0xe8) = *(undefined4 *)(param_2 + 4);
      *(undefined4 *)(param_2 + 0xec) = *(undefined4 *)(param_2 + 8);
      *(undefined4 *)(param_2 + 0xf0) = *(undefined4 *)(param_2 + 0xc);
      *(undefined4 *)(param_2 + 0xe4) = 0x1000;
    }
    uStack_b8 = 0x1e;
    func_01ff9048(0x14,&uStack_b8,1);
    uVar5 = func_020e6cf8(param_2 + 0xe8);
    func_01ff9048(0x19,uVar5,0xc);
    if (*(ushort *)(param_2 + 0x7e) != 0) {
      iVar3 = (int)(uint)*(ushort *)(param_2 + 0x7e) >> 4;
      MTX_RotZ33__from_thumb
                (auStack_ac,(int)*(short *)(iRam020a3e24 + (iVar3 * 2 + 1) * 2),
                 (int)*(short *)(iRam020a3e24 + iVar3 * 4));
      func_01ff9048(0x1a,auStack_ac,9);
    }
    uVar9 = param_2 + 0xe4U & 3;
    uVar2 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
    uStack_64 = uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20;
    uStack_60 = uStack_64;
    uStack_5c = uStack_64;
    func_01ff9048(0x1b,&uStack_64,3);
    uVar9 = param_2 + 0xd0U & 3;
    uVar8 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
    uVar2 = param_2 + 0xd8U & 3;
    uVar6 = *(uint *)(param_2 + 0xd8U & 0xfffffffc);
    iVar3 = (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) +
            (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
    if (iVar3 != 0x1000) {
      iStack_58 = iVar3;
      iStack_54 = iVar3;
      iStack_50 = iVar3;
      func_01ff9048(0x1b,&iStack_58,3);
    }
    uVar5 = func_020d3c44();
    StructMapObject_MaybeSetPolygonId
              (*(uint *)(uRam020a3e28 & 0xfffffffc) >> (uRam020a3e28 & 3) * 8 |
               *(uint *)(uRam020a3e28 & 0xfffffffc) << (uRam020a3e28 & 3) * -8 + 0x20,uVar5);
    uVar9 = param_2 + 0xa8U & 3;
    uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    StructMapObject_SetNsbtpFrame
              (*(uint *)(uRam020a3e28 & 0xfffffffc) >> (uRam020a3e28 & 3) * 8 |
               *(uint *)(uRam020a3e28 & 0xfffffffc) << (uRam020a3e28 & 3) * -8 + 0x20,
               (uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20) & 0xffff);
    DrawObject2D3D(param_1,*(uint *)(uRam020a3e28 & 0xfffffffc) >> (uRam020a3e28 & 3) * 8 |
                           *(uint *)(uRam020a3e28 & 0xfffffffc) << (uRam020a3e28 & 3) * -8 + 0x20,
                   param_2);
    return;
  }
  if ((int)uVar9 < 1) {
    return;
  }
  uVar8 = param_2 + 0x78U & 3;
  uVar4 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
  uVar8 = (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) & 0x3fffffe0;
  if (uVar8 < uRam020a3e14) {
    uVar6 = param_2 + 0xb0U & 3;
    uVar8 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
    *(uint *)(param_2 + 0xe8) =
         (*(uint *)(uRam020a3e18 & 0xfffffffc) >> (uRam020a3e18 & 3) * 8 |
         *(uint *)(uRam020a3e18 & 0xfffffffc) << (uRam020a3e18 & 3) * -8 + 0x20) +
         ((int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) >> 1);
    uVar6 = uVar2 + 4 & 3;
    uVar7 = *(uint *)(uVar2 + 4 & 0xfffffffc);
    uVar8 = param_2 + 0xb4U & 3;
    uVar4 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    *(uint *)(param_2 + 0xec) =
         (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) +
         ((int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) >> 1);
    uVar6 = uVar2 + 8 & 3;
    uVar4 = *(uint *)(uVar2 + 8 & 0xfffffffc);
    uVar2 = param_2 + 0xb8U & 3;
    uVar8 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
    *(uint *)(param_2 + 0xf0) =
         (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) +
         ((int)(uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) >> 1);
    *(undefined4 *)(param_2 + 0xe4) = 0x800;
  }
  else if (uVar8 < uRam020a3e1c) {
    uVar2 = param_2 + 0xb0U & 3;
    uVar8 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
    uVar2 = uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20;
    *(uint *)(param_2 + 0xe8) =
         ((*(uint *)(uRam020a3e20 & 0xfffffffc) >> (uRam020a3e20 & 3) * 8 |
          *(uint *)(uRam020a3e20 & 0xfffffffc) << (uRam020a3e20 & 3) * -8 + 0x20) + uVar2) -
         ((int)uVar2 >> 3);
    uVar2 = param_2 + 0xb4U & 3;
    uVar8 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    uVar4 = uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20;
    uVar2 = uVar6 + 4 & 3;
    uVar8 = *(uint *)(uVar6 + 4 & 0xfffffffc);
    *(uint *)(param_2 + 0xec) =
         ((uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) + uVar4) - ((int)uVar4 >> 3);
    uVar2 = param_2 + 0xb8U & 3;
    uVar8 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
    uVar8 = uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20;
    uVar2 = uVar6 + 8 & 3;
    uVar6 = *(uint *)(uVar6 + 8 & 0xfffffffc);
    *(uint *)(param_2 + 0xf0) =
         ((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) + uVar8) - ((int)uVar8 >> 3);
    *(undefined4 *)(param_2 + 0xe4) = 0xe00;
  }
  else {
    *(undefined4 *)(param_2 + 0xe8) = *(undefined4 *)(param_2 + 0xb0);
    *(undefined4 *)(param_2 + 0xec) = *(undefined4 *)(param_2 + 0xb4);
    *(undefined4 *)(param_2 + 0xf0) = *(undefined4 *)(param_2 + 0xb8);
    *(undefined4 *)(param_2 + 0xe4) = 0x1000;
  }
  uStack_b4 = 0x1e;
  func_01ff9048(0x14,&uStack_b4,1);
  uVar5 = MaybeGetBBMtxAtPosition(param_2 + 0xe8);
  func_01ff9048(0x19,uVar5,0xc);
  uVar2 = param_2 + 0xe4U & 3;
  uVar6 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
  uStack_4c = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
  uStack_48 = uStack_4c;
  uStack_44 = uStack_4c;
  func_01ff9048(0x1b,&uStack_4c,3);
  uVar2 = uRam020a3e28;
  iVar3 = 0;
  if (0 < (int)uVar9) {
    do {
      uVar8 = param_2 + 0xf8U & 3;
      uVar7 = *(uint *)(param_2 + 0xf8U & 0xfffffffc);
      uVar6 = iRam020a3e2c + (uVar9 - 1) * 0x10 + iVar3 * 4;
      uVar4 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
      uVar6 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + uVar4 * 4;
      uVar8 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar8 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
      func_01ff9048(0x11,0,0);
      iVar1 = (int)(uint)*(ushort *)(uVar4 * 2 + iRam020a3e30 + (uVar9 - 1) * 8) >> 4;
      MTX_RotZ33__from_thumb
                (auStack_88,(int)*(short *)(iRam020a3e24 + (iVar1 * 2 + 1) * 2),
                 (int)*(short *)(iRam020a3e24 + iVar1 * 4));
      func_01ff9048(0x1a,auStack_88,9);
      uVar6 = uVar8 + 0xd0;
      uVar4 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
      if (uVar6 != 0x1000) {
        uStack_40 = uVar6;
        uStack_3c = uVar6;
        uStack_38 = uVar6;
        func_01ff9048(0x1b,&uStack_40,3);
      }
      uStack_34 = 0;
      uStack_30 = uRam020a3e34;
      uStack_2c = 0;
      func_01ff9048(0x1c,&uStack_34,3);
      uVar5 = func_020d3c44();
      StructMapObject_MaybeSetPolygonId
                (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                 *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20,uVar5);
      uVar8 = uVar8 + 0xa8;
      uVar6 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      StructMapObject_SetNsbtpFrame
                (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                 *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20,
                 (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) & 0xffff);
      DrawObject2D3D(param_1,*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                             *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20,param_2);
      uStack_b0 = 1;
      func_01ff9048(0x12,&uStack_b0,1);
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)uVar9);
    return;
  }
  return;
}

