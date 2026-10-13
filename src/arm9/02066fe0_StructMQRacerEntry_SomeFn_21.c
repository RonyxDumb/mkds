/* Decompiled C draft; module arm9; ROM address 02066fe0. No matching claim. */
#include "types.h"
#include "deps/02066fe0_StructMQRacerEntry_SomeFn_21.h"

void StructMQRacerEntry_SomeFn_21(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  undefined4 unaff_r4;
  uint uStack_14;
  
  uVar5 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 0x1000) != 0) {
    return;
  }
  uVar5 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  *(uint *)(param_1 + 0x7c) = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20 | 0x1000;
  uVar5 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if ((((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 0x400) == 0) &&
     (((uVar5 = *(uint *)(uRam0206746c & 0xfffffffc) >> (uRam0206746c & 3) * 8 |
                *(uint *)(uRam0206746c & 0xfffffffc) << (uRam0206746c & 3) * -8 + 0x20,
       *(short *)(uVar5 + 0x70) != 0 || (*(short *)(uVar5 + 0x90) != 0)) &&
      (iVar3 = IsRacerFinishedRace(*(undefined2 *)(param_1 + 0x74)), uVar5 = uRam02067474,
      iVar3 != 0)))) {
    uVar6 = *(uint *)(uRam02067470 & 0xfffffffc) >> (uRam02067470 & 3) * 8 |
            *(uint *)(uRam02067470 & 0xfffffffc) << (uRam02067470 & 3) * -8 + 0x20;
    uVar2 = (uint)*(ushort *)(param_1 + 0x74) * 0x30 + uVar6 + 0x70;
    uVar7 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
    bVar8 = false;
    if ((uVar2 < 4) && ((1 << (uVar2 & 0xff) & 0xdU) != 0)) {
      bVar8 = true;
    }
    if (bVar8) {
      uVar2 = param_1 + 0x7cU & 3;
      uVar7 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      uVar2 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
      if (((uVar2 & 6) == 0) && ((uVar2 & 8) == 0)) {
        uVar2 = param_1 + 0x78U & 3;
        uVar7 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
        *(undefined4 *)(iRam02067478 + (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) * 0x5c) = 3
        ;
        uVar2 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        uVar5 = (uint)*(ushort *)(param_1 + 0x74) * 0x8c +
                (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 0x14;
        uVar2 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        if ((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) == 1) {
          uVar5 = param_1 + 0x310U & 3;
          uVar2 = *(uint *)(param_1 + 0x310U & 0xfffffffc);
          func_0208c260(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
          uVar5 = param_1 + 0x7cU & 3;
          uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
          *(uint *)(param_1 + 0x7c) = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20 | 2;
          uVar5 = param_1 + 0x7cU & 3;
          uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
          if (((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 2) != 0) {
            uVar5 = 0;
            do {
              if (uVar5 != 0) {
                uVar2 = param_1 + 0x2ccU & 3;
                uVar7 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
                iVar3 = (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) + uVar5 * 4;
                uVar2 = iVar3 + 0x38;
                uVar7 = uVar2 & 3;
                uVar2 = *(uint *)(uVar2 & 0xfffffffc);
                *(uint *)(iVar3 + 0x38) = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) << 2;
                uVar2 = param_1 + 0x2ccU & 3;
                uVar7 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
                uVar2 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
                iVar3 = uVar2 + uVar5 * 4;
                uVar2 = uVar2 + 0x38;
                uVar7 = uVar2 & 3;
                uVar2 = *(uint *)(uVar2 & 0xfffffffc);
                uVar6 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
                uVar2 = iVar3 + 0x38;
                uVar7 = uVar2 & 3;
                uVar2 = *(uint *)(uVar2 & 0xfffffffc);
                if ((int)uVar6 < (int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20)) {
                  *(uint *)(iVar3 + 0x38) = uVar6;
                }
              }
              uVar5 = uVar5 + 1 & 0xffff;
            } while (uVar5 < 0xc);
          }
        }
        else {
          uVar5 = param_1 + 0x7cU & 3;
          uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
          *(uint *)(param_1 + 0x7c) = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20 | 8;
        }
      }
    }
    else {
      uVar5 = uVar6 + 0x1c & 3;
      uVar2 = *(uint *)(uVar6 + 0x1c & 0xfffffffc);
      if (((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) == 1) &&
         (uVar5 = (uint)*(ushort *)(param_1 + 0x74) * 0x8c +
                  (*(uint *)(uRam02067474 & 0xfffffffc) >> (uRam02067474 & 3) * 8 |
                  *(uint *)(uRam02067474 & 0xfffffffc) << (uRam02067474 & 3) * -8 + 0x20) + 0x14,
         uVar2 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
         (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) != 1)) {
        uVar5 = param_1 + 0x7cU & 3;
        uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
        *(uint *)(param_1 + 0x7c) = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20 | 0x200000;
      }
      else {
        uVar5 = uVar6 + 8 & 3;
        uVar2 = *(uint *)(uVar6 + 8 & 0xfffffffc);
        if ((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) == 4) {
          uVar5 = param_1 + 0x7cU & 3;
          uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
          *(uint *)(param_1 + 0x7c) = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20 | 0x200000;
          uVar5 = param_1 + 0x48U & 3;
          uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
          *(uint *)(param_1 + 0x48) = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20 | 0x2000;
        }
      }
    }
    uVar5 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 4) != 0) {
      StructMQRacerEntry_SomeFn_35(param_1,0);
    }
  }
  StructMQRacerEntry_SomeFn_37(param_1);
  func_02103890(*(undefined2 *)(param_1 + 0x74));
  func_02081768(*(undefined2 *)(param_1 + 0x74));
  uVar5 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 0x40) != 0) {
    uVar5 = param_1 + 0x4cU & 3;
    uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 0xffffffbf;
    func_0207b1a8(param_1);
    *(undefined4 *)(param_1 + 0x29c) = 0;
    func_020817b8(*(undefined2 *)(param_1 + 0x74));
    DriverContext_UpdateCharacterAnimation(param_1,0,1);
    uVar5 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if ((((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 1) != 0) &&
       (uVar5 = (*(uint *)(uRam02067470 & 0xfffffffc) >> (uRam02067470 & 3) * 8 |
                *(uint *)(uRam02067470 & 0xfffffffc) << (uRam02067470 & 3) * -8 + 0x20) + 0xc,
       uVar2 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
       uVar5 >> uVar2 * 8 == 0 && uVar5 << uVar2 * -8 + 0x20 == 0)) {
      func_02106dc8();
    }
    uVar5 = param_1 + 0x4cU & 3;
    uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 0x2000) != 0) {
      StructMQRacerEntry_SomeFn_36(param_1);
    }
  }
  uVar5 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 0x10000000) != 0) &&
      (uVar5 = param_1 + iRam0206747c + 0x24, uVar2 = uVar5 & 3,
      uVar5 = *(uint *)(uVar5 & 0xfffffffc),
      uVar5 >> uVar2 * 8 == 0 && uVar5 << uVar2 * -8 + 0x20 == 0)) &&
     (*(undefined4 *)(param_1 + iRam0206747c + 0x24) = 1, uVar5 = param_1 + 0x7cU & 3,
     uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc),
     ((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 0x200) != 0)) {
    uVar5 = param_1 + 0x514U & 3;
    uVar2 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    uVar7 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    uVar5 = uVar7 + 0x2c;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar7 + 0x2c) = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) ^ 0x200000;
  }
  uVar5 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 1) == 0) {
    uVar5 = (*(uint *)(uRam02067470 & 0xfffffffc) >> (uRam02067470 & 3) * 8 |
            *(uint *)(uRam02067470 & 0xfffffffc) << (uRam02067470 & 3) * -8 + 0x20) + 8;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
    if (((uVar5 == 3) || (uVar5 == 5)) &&
       (uVar5 = (uint)*(ushort *)(param_1 + 0x74) * 0x8c +
                (*(uint *)(uRam02067474 & 0xfffffffc) >> (uRam02067474 & 3) * 8 |
                *(uint *)(uRam02067474 & 0xfffffffc) << (uRam02067474 & 3) * -8 + 0x20) + 0x14,
       uVar2 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
       (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) == 1)) {
      uStack_14 = 0;
      iVar3 = func_020617a8(&uStack_14);
      if ((iVar3 != 0) && (0xb4 < uStack_14)) {
        NNSi_MaybeSndPlayerStartSeq(uRam02067480,0,0x45);
      }
    }
  }
  else {
    func_020617d8();
    uVar7 = *(uint *)(uRam02067470 & 0xfffffffc) >> (uRam02067470 & 3) * 8 |
            *(uint *)(uRam02067470 & 0xfffffffc) << (uRam02067470 & 3) * -8 + 0x20;
    uVar5 = uVar7 + 8 & 3;
    uVar2 = *(uint *)(uVar7 + 8 & 0xfffffffc);
    uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    if (((uVar5 == 0) || (uVar5 == 1)) ||
       (((uVar5 = uVar7 + 0x1c & 3, uVar2 = *(uint *)(uVar7 + 0x1c & 0xfffffffc),
         (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) != 1 ||
         (uVar5 = (uint)*(ushort *)(param_1 + 0x74) * 0x8c +
                  (*(uint *)(uRam02067474 & 0xfffffffc) >> (uRam02067474 & 3) * 8 |
                  *(uint *)(uRam02067474 & 0xfffffffc) << (uRam02067474 & 3) * -8 + 0x20) + 0x14,
         uVar2 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
         (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) == 1)) &&
        ((bVar1 = *(byte *)(uVar7 + 0x3d0), bVar1 < 2 ||
         (uVar5 = GetDriverPlace(*(undefined2 *)(param_1 + 0x74)), uVar5 != bVar1)))))) {
      func_02075eb8();
      func_02081f30();
    }
    else {
      func_02075cf0();
    }
  }
  uVar7 = *(uint *)(uRam02067470 & 0xfffffffc) >> (uRam02067470 & 3) * 8 |
          *(uint *)(uRam02067470 & 0xfffffffc) << (uRam02067470 & 3) * -8 + 0x20;
  uVar5 = uVar7 + 8;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) == 2) {
    return;
  }
  bVar8 = true;
  uVar5 = iRam02067484 + 4U & 3;
  uVar2 = *(uint *)(iRam02067484 + 4U & 0xfffffffc);
  uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  if ((uVar5 != 2) && (uVar5 != 3)) {
    bVar8 = false;
  }
  if (!bVar8) {
    return;
  }
  if ((uint)*(ushort *)(param_1 + 0x74) == (int)*(char *)(uVar7 + 0x62)) {
    iVar3 = func_02110e58();
    if (iVar3 == 0) {
      unaff_r4 = 9;
    }
    else if (iVar3 == 1) {
      unaff_r4 = 10;
    }
    else if (iVar3 == 2) {
      unaff_r4 = 0xb;
    }
    uVar5 = param_1 + 0x3ccU & 3;
    uVar2 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
    func_0210b198(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20,unaff_r4,0x6e,7);
    return;
  }
  GetDriverPlace();
  uVar4 = func_02110fb8();
  uVar5 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 0x840) != 0) {
    return;
  }
  uVar5 = param_1 + 0x3ccU & 3;
  uVar2 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
  StructMQRacerEntry_SomeFn_5(param_1,uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20,uVar4);
  return;
}

