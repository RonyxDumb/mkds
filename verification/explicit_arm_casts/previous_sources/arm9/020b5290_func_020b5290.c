/* Decompiled C draft; module arm9; ROM address 020b5290. No matching claim. */
#include "types.h"
#include "deps/020b5290_func_020b5290.h"

void func_020b5290(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 uStack_2c;
  int local_28;
  undefined1 auStack_24 [12];
  
  func_020b6a18(&local_40,&local_38);
  uVar2 = GetDirectInputUnitIndex();
  iVar3 = func_020b5628(uVar2,0x20);
  uVar11 = uRam020b5624;
  if (iVar3 != 0) {
    uVar12 = *(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
             *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20;
    uVar4 = uVar12 + 0x8c & 3;
    uVar10 = *(uint *)(uVar12 + 0x8c & 0xfffffffc);
    if (uVar10 >> uVar4 * 8 == 0 && uVar10 << uVar4 * -8 + 0x20 == 0) {
      uVar1 = GetCurrentPlayerRacerId();
      GetDriverVec354((*(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
                      *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20) + 0x90
                      ,uVar1);
    }
    else {
      uVar4 = uVar12 + 0x90 & 3;
      uVar10 = *(uint *)(uVar12 + 0x90 & 0xfffffffc);
      *(uint *)(uVar12 + 0x90) = (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) - 0xa000;
      uVar4 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      uVar10 = uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20;
      uVar11 = uVar10 + 0x90;
      uVar4 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      if ((int)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) < local_40) {
        *(int *)(uVar10 + 0x90) = local_40;
      }
    }
    *(undefined4 *)
     ((*(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
      *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20) + 0x8c) = 600;
  }
  uVar2 = GetDirectInputUnitIndex();
  iVar3 = func_020b5628(uVar2,0x10);
  uVar11 = uRam020b5624;
  if (iVar3 != 0) {
    uVar12 = *(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
             *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20;
    uVar4 = uVar12 + 0x8c & 3;
    uVar10 = *(uint *)(uVar12 + 0x8c & 0xfffffffc);
    if (uVar10 >> uVar4 * 8 == 0 && uVar10 << uVar4 * -8 + 0x20 == 0) {
      uVar1 = GetCurrentPlayerRacerId();
      GetDriverVec354((*(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
                      *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20) + 0x90
                      ,uVar1);
    }
    else {
      uVar4 = uVar12 + 0x90 & 3;
      uVar10 = *(uint *)(uVar12 + 0x90 & 0xfffffffc);
      *(uint *)(uVar12 + 0x90) = (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) + 0xa000;
      uVar4 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      uVar10 = uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20;
      uVar11 = uVar10 + 0x90;
      uVar4 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      if (local_38 < (int)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20)) {
        *(int *)(uVar10 + 0x90) = local_38;
      }
    }
    *(undefined4 *)
     ((*(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
      *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20) + 0x8c) = 600;
  }
  uVar2 = GetDirectInputUnitIndex();
  iVar3 = func_020b5628(uVar2,0x40);
  uVar11 = uRam020b5624;
  if (iVar3 != 0) {
    uVar12 = *(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
             *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20;
    uVar4 = uVar12 + 0x8c & 3;
    uVar10 = *(uint *)(uVar12 + 0x8c & 0xfffffffc);
    if (uVar10 >> uVar4 * 8 == 0 && uVar10 << uVar4 * -8 + 0x20 == 0) {
      uVar1 = GetCurrentPlayerRacerId();
      GetDriverVec354((*(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
                      *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20) + 0x90
                      ,uVar1);
    }
    else {
      uVar4 = uVar12 + 0x98 & 3;
      uVar10 = *(uint *)(uVar12 + 0x98 & 0xfffffffc);
      *(uint *)(uVar12 + 0x98) = (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) - 0xa000;
      uVar4 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      uVar10 = uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20;
      uVar11 = uVar10 + 0x98;
      uVar4 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      if ((int)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) < local_3c) {
        *(int *)(uVar10 + 0x98) = local_3c;
      }
    }
    *(undefined4 *)
     ((*(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
      *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20) + 0x8c) = 600;
  }
  uVar2 = GetDirectInputUnitIndex();
  iVar3 = func_020b5628(uVar2,0x80);
  uVar11 = uRam020b5624;
  if (iVar3 != 0) {
    uVar12 = *(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
             *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20;
    uVar4 = uVar12 + 0x8c & 3;
    uVar10 = *(uint *)(uVar12 + 0x8c & 0xfffffffc);
    if (uVar10 >> uVar4 * 8 == 0 && uVar10 << uVar4 * -8 + 0x20 == 0) {
      uVar1 = GetCurrentPlayerRacerId();
      GetDriverVec354((*(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
                      *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20) + 0x90
                      ,uVar1);
    }
    else {
      uVar4 = uVar12 + 0x98 & 3;
      uVar10 = *(uint *)(uVar12 + 0x98 & 0xfffffffc);
      *(uint *)(uVar12 + 0x98) = (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) + 0xa000;
      uVar4 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      uVar10 = uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20;
      uVar11 = uVar10 + 0x98;
      uVar4 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      if (local_34 < (int)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20)) {
        *(int *)(uVar10 + 0x98) = local_34;
      }
    }
    *(undefined4 *)
     ((*(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
      *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20) + 0x8c) = 600;
  }
  uVar10 = uRam020b5624;
  uVar12 = *(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
           *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20;
  uVar11 = uVar12 + 0x8c;
  uVar4 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  uVar11 = uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20;
  if ((uVar11 != 0) &&
     (*(uint *)(uVar12 + 0x8c) = uVar11 - 1, uVar11 = uVar10 & 3,
     uVar4 = *(uint *)(uVar10 & 0xfffffffc),
     uVar11 = (uVar4 >> uVar11 * 8 | uVar4 << uVar11 * -8 + 0x20) + 0x8c, uVar4 = uVar11 & 3,
     uVar11 = *(uint *)(uVar11 & 0xfffffffc),
     (int)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) < 300)) {
    uVar1 = GetCurrentPlayerRacerId();
    GetDriverVec354(&local_30,uVar1);
    uVar4 = uRam020b5624;
    *(undefined4 *)
     ((*(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
      *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20) + 0x8c) = 300;
    uVar11 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    VecFx32_Subtract(&local_30,(uVar4 >> uVar11 * 8 | uVar4 << uVar11 * -8 + 0x20) + 0x90,auStack_24
                    );
    Vector3_MaybeNormalize(auStack_24,auStack_24);
    iVar3 = (*(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
            *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20) + 0x90;
    VecFx32_AddScale1(0xa000,auStack_24,iVar3,iVar3);
    uVar11 = (*(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
             *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20) + 0x90;
    uVar4 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    iVar3 = func_020b5250(local_30 - (uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20));
    uVar11 = (*(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
             *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20) + 0x90;
    uVar4 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    iVar5 = func_020b5250(local_30 - (uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20));
    uVar11 = (*(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
             *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20) + 0x98;
    uVar4 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    iVar6 = func_020b5250(local_28 - (uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20));
    uVar11 = (*(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
             *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20) + 0x98;
    uVar4 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    iVar7 = func_020b5250(local_28 - (uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20));
    iVar8 = func_020b5250(0xa000);
    iVar9 = func_020b5250(0xa000);
    if (iVar3 * iVar5 + iVar6 * iVar7 < iVar8 * iVar9) {
      uVar11 = *(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
               *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20;
      *(int *)(uVar11 + 0x90) = local_30;
      *(undefined4 *)(uVar11 + 0x94) = uStack_2c;
      *(int *)(uVar11 + 0x98) = local_28;
      *(undefined4 *)(uVar11 + 0x8c) = 0;
    }
  }
  uVar10 = uRam020b5624;
  uVar12 = *(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
           *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20;
  uVar11 = uVar12 + 0x90;
  uVar4 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  if ((int)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) < local_40) {
    *(int *)(uVar12 + 0x90) = local_40;
  }
  uVar11 = uVar10 & 3;
  uVar4 = *(uint *)(uVar10 & 0xfffffffc);
  uVar10 = uVar4 >> uVar11 * 8 | uVar4 << uVar11 * -8 + 0x20;
  uVar11 = uVar10 + 0x90;
  uVar4 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  if (local_38 < (int)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20)) {
    *(int *)(uVar10 + 0x90) = local_38;
  }
  uVar10 = *(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
           *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20;
  uVar11 = uVar10 + 0x98;
  uVar4 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  if ((int)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) < local_3c) {
    *(int *)(uVar10 + 0x98) = local_3c;
  }
  uVar10 = *(uint *)(uRam020b5624 & 0xfffffffc) >> (uRam020b5624 & 3) * 8 |
           *(uint *)(uRam020b5624 & 0xfffffffc) << (uRam020b5624 & 3) * -8 + 0x20;
  uVar11 = uVar10 + 0x98;
  uVar4 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  if (local_34 < (int)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20)) {
    *(int *)(uVar10 + 0x98) = local_34;
  }
  return;
}

