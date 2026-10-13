/* Decompiled C draft; module arm9; ROM address 020c5940. No matching claim. */
#include "types.h"
#include "deps/020c5940_func_020c5940.h"

void func_020c5940(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = (*(uint *)(DAT_020c5cb8 & 0xfffffffc) >> (DAT_020c5cb8 & 3) * 8 |
          *(uint *)(DAT_020c5cb8 & 0xfffffffc) << (DAT_020c5cb8 & 3) * -8 + 0x20) + 4;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar8 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  iVar1 = GetCurrentPlayerRacerId();
  uVar6 = *(uint *)(DAT_020c5cbc & 0xfffffffc) >> (DAT_020c5cbc & 3) * 8 |
          *(uint *)(DAT_020c5cbc & 0xfffffffc) << (DAT_020c5cbc & 3) * -8 + 0x20;
  uVar7 = iVar1 * 0x8c + uVar6 + 0x14;
  uVar4 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  if (((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) == 1) ||
     (uVar6 = uVar6 + 0x4cc, uVar7 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
     uVar6 >> uVar7 * 8 != 0 || uVar6 << uVar7 * -8 + 0x20 != 0)) {
    *(undefined4 *)
     (*(uint *)(DAT_020c5cb8 & 0xfffffffc) >> (DAT_020c5cb8 & 3) * 8 |
     *(uint *)(DAT_020c5cb8 & 0xfffffffc) << (DAT_020c5cb8 & 3) * -8 + 0x20) = 0;
  }
  iVar1 = func_020b1d0c();
  if (iVar1 == 0) {
    return;
  }
  uVar4 = *(uint *)(DAT_020c5cc0 & 0xfffffffc) >> (DAT_020c5cc0 & 3) * 8 |
          *(uint *)(DAT_020c5cc0 & 0xfffffffc) << (DAT_020c5cc0 & 3) * -8 + 0x20;
  uVar7 = uVar4 + 8;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  if ((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) == 4) {
    iVar1 = IsRacerFinishedRace((short)*(char *)(uVar4 + 0x62));
    if (iVar1 == 0) {
      uVar7 = 6;
    }
    else {
      uVar7 = (*(uint *)(DAT_020c5cbc & 0xfffffffc) >> (DAT_020c5cbc & 3) * 8 |
              *(uint *)(DAT_020c5cbc & 0xfffffffc) << (DAT_020c5cbc & 3) * -8 + 0x20) + 0x4e0;
      uVar6 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar7 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    }
    if (((uVar7 != 0) && (iVar1 = func_0207a218(), iVar1 == 0)) && (uVar8 == 0)) {
      return;
    }
  }
  uVar4 = *(uint *)(DAT_020c5cb8 & 0xfffffffc) >> (DAT_020c5cb8 & 3) * 8 |
          *(uint *)(DAT_020c5cb8 & 0xfffffffc) << (DAT_020c5cb8 & 3) * -8 + 0x20;
  uVar7 = uVar4 + 4;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  if ((int)uVar7 < 0x7fffffff) {
    *(uint *)(uVar4 + 4) = uVar7 + 1;
  }
  uVar4 = *(uint *)(DAT_020c5cc0 & 0xfffffffc) >> (DAT_020c5cc0 & 3) * 8 |
          *(uint *)(DAT_020c5cc0 & 0xfffffffc) << (DAT_020c5cc0 & 3) * -8 + 0x20;
  uVar7 = uVar4 + 8;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  switch(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) {
  case 0:
    GetCurrentPlayerRacerId();
    iVar1 = GetDriverPlace();
    *(int *)((*(uint *)(DAT_020c5cb8 & 0xfffffffc) >> (DAT_020c5cb8 & 3) * 8 |
             *(uint *)(DAT_020c5cb8 & 0xfffffffc) << (DAT_020c5cb8 & 3) * -8 + 0x20) + 8) =
         iVar1 + -1;
    GetCurrentPlayerRacerId();
    uVar3 = Int32ToInt8();
    iVar1 = GetSomeLUMaxIndex();
    iVar2 = Int32ToInt8(uVar3);
    uVar5 = *(ushort *)
             (iVar1 * 0x50 +
              (*(uint *)(DAT_020c5cc4 & 0xfffffffc) >> (DAT_020c5cc4 & 3) * 8 |
              *(uint *)(DAT_020c5cc4 & 0xfffffffc) << (DAT_020c5cc4 & 3) * -8 + 0x20) + iVar2 * 10);
    GetCurrentPlayerRacerId();
    iVar1 = func_0205d3f0();
    uVar7 = DAT_020c5cb8;
    *(uint *)((*(uint *)(DAT_020c5cb8 & 0xfffffffc) >> (DAT_020c5cb8 & 3) * 8 |
              *(uint *)(DAT_020c5cb8 & 0xfffffffc) << (DAT_020c5cb8 & 3) * -8 + 0x20) + 0xc) =
         (uint)uVar5 - iVar1;
    if (0x14 < (int)uVar8) {
      uVar6 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      *(undefined4 *)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) = 1;
    }
    return;
  case 1:
    if (0x14 < (int)uVar8) {
      *(undefined4 *)
       (*(uint *)(DAT_020c5cb8 & 0xfffffffc) >> (DAT_020c5cb8 & 3) * 8 |
       *(uint *)(DAT_020c5cb8 & 0xfffffffc) << (DAT_020c5cb8 & 3) * -8 + 0x20) = 1;
    }
    return;
  case 2:
  default:
    *(undefined4 *)
     (*(uint *)(DAT_020c5cb8 & 0xfffffffc) >> (DAT_020c5cb8 & 3) * 8 |
     *(uint *)(DAT_020c5cb8 & 0xfffffffc) << (DAT_020c5cb8 & 3) * -8 + 0x20) = 1;
    break;
  case 3:
    goto LAB_020c5ae0;
  case 4:
    iVar1 = IsRacerFinishedRace((short)*(char *)(uVar4 + 0x62));
    if (iVar1 == 0) {
      uVar7 = 6;
    }
    else {
      uVar7 = (*(uint *)(DAT_020c5cbc & 0xfffffffc) >> (DAT_020c5cbc & 3) * 8 |
              *(uint *)(DAT_020c5cbc & 0xfffffffc) << (DAT_020c5cbc & 3) * -8 + 0x20) + 0x4e0;
      uVar6 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar7 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    }
    if (uVar7 == 0) {
      uVar3 = ComputeMissionInternalScore();
      *(undefined4 *)
       ((*(uint *)(DAT_020c5cb8 & 0xfffffffc) >> (DAT_020c5cb8 & 3) * 8 |
        *(uint *)(DAT_020c5cb8 & 0xfffffffc) << (DAT_020c5cb8 & 3) * -8 + 0x20) + 0x18) = uVar3;
    }
    else {
      *(undefined4 *)
       ((*(uint *)(DAT_020c5cb8 & 0xfffffffc) >> (DAT_020c5cb8 & 3) * 8 |
        *(uint *)(DAT_020c5cb8 & 0xfffffffc) << (DAT_020c5cb8 & 3) * -8 + 0x20) + 0x18) = 9;
    }
    iVar1 = IsRacerFinishedRace((short)*(char *)((*(uint *)(DAT_020c5cc0 & 0xfffffffc) >>
                                                  (DAT_020c5cc0 & 3) * 8 |
                                                 *(uint *)(DAT_020c5cc0 & 0xfffffffc) <<
                                                 (DAT_020c5cc0 & 3) * -8 + 0x20) + 0x62));
    if (iVar1 == 0) {
      uVar7 = 6;
    }
    else {
      uVar7 = (*(uint *)(DAT_020c5cbc & 0xfffffffc) >> (DAT_020c5cbc & 3) * 8 |
              *(uint *)(DAT_020c5cbc & 0xfffffffc) << (DAT_020c5cbc & 3) * -8 + 0x20) + 0x4e0;
      uVar6 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar7 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    }
    if (uVar7 != 0) {
      if (0x4b < (int)uVar8) {
        *(undefined4 *)
         (*(uint *)(DAT_020c5cb8 & 0xfffffffc) >> (DAT_020c5cb8 & 3) * 8 |
         *(uint *)(DAT_020c5cb8 & 0xfffffffc) << (DAT_020c5cb8 & 3) * -8 + 0x20) = 1;
      }
      return;
    }
    if (uVar8 != 1) {
      if (0x1e < (int)uVar8) {
        *(undefined4 *)
         (*(uint *)(DAT_020c5cb8 & 0xfffffffc) >> (DAT_020c5cb8 & 3) * 8 |
         *(uint *)(DAT_020c5cb8 & 0xfffffffc) << (DAT_020c5cb8 & 3) * -8 + 0x20) = 1;
      }
      return;
    }
    uVar7 = (*(uint *)(DAT_020c5cb8 & 0xfffffffc) >> (DAT_020c5cb8 & 3) * 8 |
            *(uint *)(DAT_020c5cb8 & 0xfffffffc) << (DAT_020c5cb8 & 3) * -8 + 0x20) + 0x18;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    switch(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      NNSi_MaybeSndPlayerStartSeq(DAT_020c5cc8,0,0x1b);
      return;
    case 6:
      NNSi_MaybeSndPlayerStartSeq(DAT_020c5cc8,0,0x1c);
      return;
    case 7:
      NNSi_MaybeSndPlayerStartSeq(DAT_020c5cc8,0,0x1d);
      return;
    }
    break;
  case 5:
LAB_020c5ae0:
    GetCurrentPlayerRacerId();
    iVar1 = GetDriverPlace();
    uVar7 = DAT_020c5cc0;
    *(int *)((*(uint *)(DAT_020c5cb8 & 0xfffffffc) >> (DAT_020c5cb8 & 3) * 8 |
             *(uint *)(DAT_020c5cb8 & 0xfffffffc) << (DAT_020c5cb8 & 3) * -8 + 0x20) + 8) =
         iVar1 + -1;
    uVar5 = 0;
    if (*(char *)((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                  *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x3d0) != '\0') {
      do {
        iVar1 = GetDriverPlace(uVar5);
        if (iVar1 == 1) break;
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(byte *)((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                                 *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x3d0))
      ;
    }
    uVar7 = DAT_020c5cb8;
    *(ushort *)
     ((*(uint *)(DAT_020c5cb8 & 0xfffffffc) >> (DAT_020c5cb8 & 3) * 8 |
      *(uint *)(DAT_020c5cb8 & 0xfffffffc) << (DAT_020c5cb8 & 3) * -8 + 0x20) + 0x10) = uVar5;
    if (0x14 < (int)uVar8) {
      uVar6 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      *(undefined4 *)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) = 1;
    }
    return;
  }
  return;
}

