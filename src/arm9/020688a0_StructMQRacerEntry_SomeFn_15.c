/* Decompiled C draft; module arm9; ROM address 020688a0. No matching claim. */
#include "types.h"
#include "deps/020688a0_StructMQRacerEntry_SomeFn_15.h"

void StructMQRacerEntry_SomeFn_15(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  
  uVar4 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x10000000) != 0) {
    return;
  }
  uVar4 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  *(uint *)(param_1 + 0x7c) = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20 | 0x10000008;
  uVar4 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20 | 0x2000;
  uVar4 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 1) == 0) goto LAB_020689a4;
  iVar3 = IsRacerFinishedRace((short)*(char *)((*(uint *)(DAT_020689f8 & 0xfffffffc) >>
                                                (DAT_020689f8 & 3) * 8 |
                                               *(uint *)(DAT_020689f8 & 0xfffffffc) <<
                                               (DAT_020689f8 & 3) * -8 + 0x20) + 0x62));
  if (iVar3 == 0) {
    uVar4 = 6;
  }
  else {
    uVar4 = (*(uint *)(DAT_020689fc & 0xfffffffc) >> (DAT_020689fc & 3) * 8 |
            *(uint *)(DAT_020689fc & 0xfffffffc) << (DAT_020689fc & 3) * -8 + 0x20) + 0x4e0;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  }
  switch(uVar4) {
  case 0:
    func_020757d8();
    StructMQRacerEntry_SomeFn_14(param_1,1,1);
    goto LAB_0206898c;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
  }
  uVar4 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 1) != 0) {
    uVar4 = (*(uint *)(DAT_020689f8 & 0xfffffffc) >> (DAT_020689f8 & 3) * 8 |
            *(uint *)(DAT_020689f8 & 0xfffffffc) << (DAT_020689f8 & 3) * -8 + 0x20) + 8;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    if ((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) == 4) {
      func_020a16d0(*(undefined2 *)(param_1 + 0x74));
    }
    uVar4 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20 | 0x20000;
    DriverContext_UpdateCharacterAnimation(param_1,3,1);
  }
LAB_0206898c:
  uVar4 = (*(uint *)(DAT_020689f8 & 0xfffffffc) >> (DAT_020689f8 & 3) * 8 |
          *(uint *)(DAT_020689f8 & 0xfffffffc) << (DAT_020689f8 & 3) * -8 + 0x20) + 8;
  uVar2 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) == 4) {
    RaceModeBattle_OrMissionRun_SomeFn();
  }
LAB_020689a4:
  uVar4 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  if ((uVar4 & 1) == 0) {
    return;
  }
  uVar2 = (*(uint *)(DAT_020689f8 & 0xfffffffc) >> (DAT_020689f8 & 3) * 8 |
          *(uint *)(DAT_020689f8 & 0xfffffffc) << (DAT_020689f8 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if ((uVar2 != 2) && (uVar2 != 4)) {
    return;
  }
  uVar5 = (uVar4 & 0x10000) == 0;
  if (((bool)uVar5) && ((uVar4 & 0x20000) != 0)) {
    uVar5 = 2;
  }
  func_021112fc(uVar5);
  return;
}

