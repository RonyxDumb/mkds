/* Decompiled C draft; module arm9; ROM address 020af66c. No matching claim. */
#include "types.h"
#include "deps/020af66c_SomeUpdateFn.h"

void SomeUpdateFn(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *piVar7;
  
  uVar3 = *(uint *)(DAT_020af860 & 0xfffffffc) >> (DAT_020af860 & 3) * 8 |
          *(uint *)(DAT_020af860 & 0xfffffffc) << (DAT_020af860 & 3) * -8 + 0x20;
  if (uVar3 != 0) {
    *(undefined4 *)(uVar3 + 0x908) = 1;
  }
  uVar1 = DAT_020af860;
  uVar3 = (*(uint *)(DAT_020af864 & 0xfffffffc) >> (DAT_020af864 & 3) * 8 |
          *(uint *)(DAT_020af864 & 0xfffffffc) << (DAT_020af864 & 3) * -8 + 0x20) + 0xc;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar3 == 3) {
    IncrementRaceIntroFrameCounter();
    return;
  }
  if (uVar3 == 5) {
    return;
  }
  if (uVar3 == 6) {
    IncrementStaffRollFrameCount();
    func_0212b204();
    return;
  }
  uVar6 = *(uint *)(DAT_020af860 & 0xfffffffc) >> (DAT_020af860 & 3) * 8 |
          *(uint *)(DAT_020af860 & 0xfffffffc) << (DAT_020af860 & 3) * -8 + 0x20;
  uVar3 = uVar6 + 0x898 & 3;
  uVar4 = *(uint *)(uVar6 + 0x898 & 0xfffffffc);
  if (uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0) {
    return;
  }
  uVar3 = uVar6 + 0x8dc & 3;
  uVar4 = *(uint *)(uVar6 + 0x8dc & 0xfffffffc);
  if (uVar4 >> uVar3 * 8 != 0 || uVar4 << uVar3 * -8 + 0x20 != 0) {
    uVar3 = uVar6 + 0x8e0 & 3;
    uVar4 = *(uint *)(uVar6 + 0x8e0 & 0xfffffffc);
    *(uint *)(uVar6 + 0x8e0) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 1;
    uVar6 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    uVar3 = uVar6 + 0x8e0;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if (0x7f < (int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
      *(undefined4 *)(uVar6 + 0x8dc) = 0;
      *(undefined4 *)
       ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
        *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x8e0) = 0xffffffff;
    }
  }
  IncreaseB358Countdown();
  MaybeWhenFinishFlagpole();
  uVar3 = (*(uint *)(DAT_020af864 & 0xfffffffc) >> (DAT_020af864 & 3) * 8 |
          *(uint *)(DAT_020af864 & 0xfffffffc) << (DAT_020af864 & 3) * -8 + 0x20) + 0xc;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) == 4) {
    func_020d1298();
  }
  uVar3 = (*(uint *)(DAT_020af864 & 0xfffffffc) >> (DAT_020af864 & 3) * 8 |
          *(uint *)(DAT_020af864 & 0xfffffffc) << (DAT_020af864 & 3) * -8 + 0x20) + 8;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar3 == 2) {
    uVar3 = (*(uint *)(DAT_020af868 & 0xfffffffc) >> (DAT_020af868 & 3) * 8 |
            *(uint *)(DAT_020af868 & 0xfffffffc) << (DAT_020af868 & 3) * -8 + 0x20) + 0x4cc;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  }
  else if (uVar3 == 4) {
    uVar3 = func_0203c174();
  }
  else {
    GetCurrentPlayerRacerId();
    iVar2 = IsRacerFinishedRace();
    if ((iVar2 == 0) ||
       (uVar3 = (*(uint *)(DAT_020af860 & 0xfffffffc) >> (DAT_020af860 & 3) * 8 |
                *(uint *)(DAT_020af860 & 0xfffffffc) << (DAT_020af860 & 3) * -8 + 0x20) + 0x8dc,
       uVar4 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
       uVar3 >> uVar4 * 8 != 0 || uVar3 << uVar4 * -8 + 0x20 != 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  if (uVar3 == 0) {
    func_020bab54();
    MaybeWhenLapIsCompleted();
    func_020d2090();
    func_020d0a18();
    func_020ba3ec();
    func_020c5940();
  }
  else {
    func_020bb5cc();
    MaybeWhenLapIsCompleted();
    func_020d0a18();
    func_020c5940();
  }
  MaybeWhenFewSecondsRemaining();
  func_020be3e4();
  uVar3 = (*(uint *)(DAT_020af860 & 0xfffffffc) >> (DAT_020af860 & 3) * 8 |
          *(uint *)(DAT_020af860 & 0xfffffffc) << (DAT_020af860 & 3) * -8 + 0x20) + 0x828;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  switch(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    goto LAB_020af824;
  case 5:
LAB_020af824:
    func_020c31c0();
    goto switchD_020af7f4_default;
  case 6:
  default:
    goto switchD_020af7f4_default;
  }
  func_020be9d4();
  func_020c43c4();
switchD_020af7f4_default:
  InvokeE8Handler();
  uVar4 = DAT_020af860;
  piVar7 = (int *)(*(uint *)(DAT_020af860 & 0xfffffffc) >> (DAT_020af860 & 3) * 8 |
                  *(uint *)(DAT_020af860 & 0xfffffffc) << (DAT_020af860 & 3) * -8 + 0x20);
  *piVar7 = (*(uint *)((uint)piVar7 & 0xfffffffc) >> ((uint)piVar7 & 3) * 8 |
            *(uint *)((uint)piVar7 & 0xfffffffc) << ((uint)piVar7 & 3) * -8 + 0x20) + 1;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  puVar5 = (undefined4 *)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
  if (0xbff < (int)(*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                   *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20)) {
    *puVar5 = 0;
  }
  return;
}

