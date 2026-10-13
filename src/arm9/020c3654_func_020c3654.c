/* Decompiled C draft; module arm9; ROM address 020c3654. No matching claim. */
#include "types.h"
#include "deps/020c3654_func_020c3654.h"

void func_020c3654(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar6 = DAT_020c3b58;
  uVar1 = *(uint *)(DAT_020c3b58 & 0xfffffffc) >> (DAT_020c3b58 & 3) * 8 |
          *(uint *)(DAT_020c3b58 & 0xfffffffc) << (DAT_020c3b58 & 3) * -8 + 0x20;
  uVar7 = uVar1 + 0x20dc;
  uVar2 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar8 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  *(uint *)(uVar1 + 0x20dc) = uVar8 + 1;
  uVar2 = DAT_020c3b60;
  uVar1 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
  uVar7 = uVar1 + 0x20d8 & 3;
  uVar5 = *(uint *)(uVar1 + 0x20d8 & 0xfffffffc);
  switch(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) {
  case 0:
    *(undefined4 *)(uVar1 + 0x20e0) = 0xffffffe0;
    uVar1 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
    uVar7 = uVar1 + 0xac & 3;
    uVar2 = *(uint *)(uVar1 + 0xac & 0xfffffffc);
    if ((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) != DAT_020c3b5c) {
      *(undefined4 *)(uVar1 + 0x20d8) = 10;
      *(undefined4 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x20dc) = 0;
      return;
    }
    *(undefined4 *)(uVar1 + 0x20d8) = 1;
    *(undefined4 *)
     ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
      *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x20dc) = 0;
    return;
  case 1:
    if (0x13 < (int)uVar8) {
      *(undefined4 *)(uVar1 + 0x20e0) = 0;
      *(undefined4 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x20d8) = 2;
      *(undefined4 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x20dc) = 0;
      return;
    }
    uVar4 = ComputeValueInterpolation_from_thumb(1,0xffffffe0,0,uVar8,0x14);
    *(undefined4 *)
     ((*(uint *)(DAT_020c3b58 & 0xfffffffc) >> (DAT_020c3b58 & 3) * 8 |
      *(uint *)(DAT_020c3b58 & 0xfffffffc) << (DAT_020c3b58 & 3) * -8 + 0x20) + 0x20e0) = uVar4;
    return;
  case 2:
    *(undefined4 *)(uVar1 + 0x20e0) = 0;
    uVar7 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 8;
    uVar2 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    if (((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) == 5) &&
       (iVar3 = func_020b32ec(), uVar7 = DAT_020c3b58, iVar3 != 0)) {
      *(undefined4 *)
       ((*(uint *)(DAT_020c3b58 & 0xfffffffc) >> (DAT_020c3b58 & 3) * 8 |
        *(uint *)(DAT_020c3b58 & 0xfffffffc) << (DAT_020c3b58 & 3) * -8 + 0x20) + 0x20d8) = 3;
      uVar2 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      *(undefined4 *)((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) + 0x20dc) = 0;
      return;
    }
    uVar2 = DAT_020c3b58;
    uVar1 = *(uint *)(DAT_020c3b58 & 0xfffffffc) >> (DAT_020c3b58 & 3) * 8 |
            *(uint *)(DAT_020c3b58 & 0xfffffffc) << (DAT_020c3b58 & 3) * -8 + 0x20;
    uVar7 = uVar1 + 0xac & 3;
    uVar6 = *(uint *)(uVar1 + 0xac & 0xfffffffc);
    uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    if (DAT_020c3b64 == uVar7) {
      *(undefined4 *)(uVar1 + 0x20d8) = 3;
      *(undefined4 *)
       ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
        *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x20dc) = 0;
      return;
    }
    if (DAT_020c3b68 == uVar7) {
      *(undefined4 *)(uVar1 + 0x20d8) = 9;
      *(undefined4 *)
       ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
        *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x20dc) = 0;
      return;
    }
    return;
  case 3:
    if ((int)uVar8 < 0x14) {
      uVar4 = ComputeValueInterpolation_from_thumb(1,0,0xffffffe0,uVar8,0x14);
      *(undefined4 *)
       ((*(uint *)(DAT_020c3b58 & 0xfffffffc) >> (DAT_020c3b58 & 3) * 8 |
        *(uint *)(DAT_020c3b58 & 0xfffffffc) << (DAT_020c3b58 & 3) * -8 + 0x20) + 0x20e0) = uVar4;
      return;
    }
    *(undefined4 *)(uVar1 + 0x20e0) = 0xffffffe0;
    uVar7 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 8;
    uVar2 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    if (((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) == 5) &&
       (iVar3 = func_020b32ec(), uVar7 = DAT_020c3b58, iVar3 != 0)) {
      *(undefined4 *)
       ((*(uint *)(DAT_020c3b58 & 0xfffffffc) >> (DAT_020c3b58 & 3) * 8 |
        *(uint *)(DAT_020c3b58 & 0xfffffffc) << (DAT_020c3b58 & 3) * -8 + 0x20) + 0x20d8) = 7;
      uVar2 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      *(undefined4 *)((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) + 0x20dc) = 0;
      return;
    }
    uVar2 = DAT_020c3b58;
    *(undefined4 *)
     ((*(uint *)(DAT_020c3b58 & 0xfffffffc) >> (DAT_020c3b58 & 3) * 8 |
      *(uint *)(DAT_020c3b58 & 0xfffffffc) << (DAT_020c3b58 & 3) * -8 + 0x20) + 0x20d8) = 4;
    uVar7 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(undefined4 *)((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + 0x20dc) = 0;
    return;
  case 4:
    if (0x13 < (int)uVar8) {
      *(undefined4 *)(uVar1 + 0x20e0) = 0;
      *(undefined4 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x20d8) = 5;
      *(undefined4 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x20dc) = 0;
      return;
    }
    uVar4 = ComputeValueInterpolation_from_thumb(1,0xffffffe0,0,uVar8,0x14);
    *(undefined4 *)
     ((*(uint *)(DAT_020c3b58 & 0xfffffffc) >> (DAT_020c3b58 & 3) * 8 |
      *(uint *)(DAT_020c3b58 & 0xfffffffc) << (DAT_020c3b58 & 3) * -8 + 0x20) + 0x20e0) = uVar4;
    return;
  case 5:
    *(undefined4 *)(uVar1 + 0x20e0) = 0;
    uVar7 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 8;
    uVar2 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    if ((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) != 5) {
      return;
    }
    iVar3 = func_020b32ec();
    uVar7 = DAT_020c3b58;
    if (iVar3 != 0) {
      *(undefined4 *)
       ((*(uint *)(DAT_020c3b58 & 0xfffffffc) >> (DAT_020c3b58 & 3) * 8 |
        *(uint *)(DAT_020c3b58 & 0xfffffffc) << (DAT_020c3b58 & 3) * -8 + 0x20) + 0x20d8) = 6;
      uVar2 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      *(undefined4 *)((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) + 0x20dc) = 0;
      return;
    }
    return;
  case 6:
    if (0x13 < (int)uVar8) {
      *(undefined4 *)(uVar1 + 0x20e0) = 0xffffffe0;
      *(undefined4 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x20d8) = 7;
      *(undefined4 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x20dc) = 0;
      return;
    }
    uVar4 = ComputeValueInterpolation_from_thumb(1,0,0xffffffe0,uVar8,0x14);
    *(undefined4 *)
     ((*(uint *)(DAT_020c3b58 & 0xfffffffc) >> (DAT_020c3b58 & 3) * 8 |
      *(uint *)(DAT_020c3b58 & 0xfffffffc) << (DAT_020c3b58 & 3) * -8 + 0x20) + 0x20e0) = uVar4;
    return;
  case 7:
    if (0x13 < (int)uVar8) {
      *(undefined4 *)(uVar1 + 0x20e0) = 0;
      *(undefined4 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x20d8) = 8;
      *(undefined4 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x20dc) = 0;
      return;
    }
    uVar4 = ComputeValueInterpolation_from_thumb(1,0xffffffe0,0,uVar8,0x14);
    *(undefined4 *)
     ((*(uint *)(DAT_020c3b58 & 0xfffffffc) >> (DAT_020c3b58 & 3) * 8 |
      *(uint *)(DAT_020c3b58 & 0xfffffffc) << (DAT_020c3b58 & 3) * -8 + 0x20) + 0x20e0) = uVar4;
    return;
  case 8:
    break;
  case 9:
    if (0x13 < (int)uVar8) {
      *(undefined4 *)(uVar1 + 0x20e0) = 0;
      *(undefined4 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x20d8) = 10;
      *(undefined4 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x20dc) = 0;
      return;
    }
    uVar4 = ComputeValueInterpolation_from_thumb(1,0,0xffffffe0,uVar8,0x14);
    *(undefined4 *)
     ((*(uint *)(DAT_020c3b58 & 0xfffffffc) >> (DAT_020c3b58 & 3) * 8 |
      *(uint *)(DAT_020c3b58 & 0xfffffffc) << (DAT_020c3b58 & 3) * -8 + 0x20) + 0x20e0) = uVar4;
    return;
  case 10:
    break;
  default:
    return;
  }
  *(undefined4 *)(uVar1 + 0x20e0) = 0;
  return;
}

