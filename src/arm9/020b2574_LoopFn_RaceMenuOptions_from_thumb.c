/* Decompiled C draft; module arm9; ROM address 020b2574. No matching claim. */
#include "types.h"
#include "deps/020b2574_LoopFn_RaceMenuOptions_from_thumb.h"

void LoopFn_RaceMenuOptions_from_thumb(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = piRam020b2884;
  ((undefined4 *)*piRam020b2884)[1] = *(undefined4 *)*piRam020b2884;
  iVar3 = *piVar1;
  *(int *)(iVar3 + 0x34) = *(int *)(iVar3 + 0x34) + 1;
  iVar3 = *piVar1;
  if (0x31 < *(int *)(iVar3 + 0x34)) {
    *(undefined4 *)(iVar3 + 0x34) = 0;
  }
  iVar3 = SaveDataHolderIsBusy();
  if (iVar3 != 0) {
    return;
  }
  iVar3 = GetRaceMode();
  if ((((iVar3 == 0) || (iVar3 = GetRaceMode(), iVar3 == 1)) &&
      (iVar3 = GetDisplayMode_0(), iVar3 == 2)) && (iVar3 = func_0203c0bc(), iVar3 != 0)) {
    return;
  }
  if (((*(int *)(*piRam020b2884 + 0x14) == 0) && (*(int *)(*piRam020b2884 + 0x18) == 0)) &&
     (iVar3 = func_020b32ec(), iVar3 == 0)) {
    iVar3 = func_020b2bc8();
    if (iVar3 == 0) {
      iVar3 = func_020b29c4();
      if (iVar3 != 0) {
        uVar2 = Const8_0();
        iVar3 = func_020b2b24(uVar2,8);
        if (iVar3 == 0) {
          iVar3 = func_020b302c();
          if (iVar3 == 0) {
            uVar2 = Const8_0();
            iVar3 = func_020b2b24(uVar2,1);
            if (iVar3 == 0) {
              uVar2 = Const8_0();
              iVar3 = func_020b2b24(uVar2,2);
              if (iVar3 == 0) {
                uVar2 = Const8_0();
                iVar3 = func_020ae408(uVar2,0x40);
                if (iVar3 == 0) {
                  uVar2 = Const8_0();
                  iVar3 = func_020ae408(uVar2,0x80);
                  if (iVar3 != 0) {
                    MaybeOnMenuOptionScroll_from_thumb(1);
                  }
                }
                else {
                  MaybeOnMenuOptionScroll_from_thumb(0xffffffff);
                }
              }
              else {
                iVar3 = func_020b2e98();
                if (iVar3 != 0) {
                  func_02105c4c();
                  *(undefined4 *)(*piRam020b2884 + 0x18) = 1;
                }
              }
            }
            else {
              iVar3 = func_020b2e98();
              if (iVar3 != 0) {
                if (*(int *)(*piRam020b2884 + 0x28) == 0) {
                  func_02105c4c();
                }
                else {
                  func_020b3278();
                }
                piVar1 = piRam020b2884;
                *(undefined4 *)(*piRam020b2884 + 0x14) = 1;
                *(undefined4 *)(*piVar1 + 0x10) = 1;
              }
            }
          }
          else {
            *(undefined4 *)(*piRam020b2884 + 0x14) = 1;
          }
        }
        else {
          iVar3 = func_020b2e98();
          if (iVar3 == 0) {
            func_02105d70();
            func_020b2f88(1);
          }
          else {
            func_02105c4c();
            *(undefined4 *)(*piRam020b2884 + 0x18) = 1;
          }
        }
      }
    }
    else {
      iVar3 = func_020b2b70();
      if (iVar3 != 0) {
        iVar3 = GetRaceMode();
        if (((iVar3 == 4) && (iVar3 = IsCurrentMissionNotBeaten(), iVar3 != 0)) &&
           (iVar3 = IsCurrentMission_Boss6OrBoss7_from_thumb(), iVar3 != 0)) {
          uVar2 = Const8_0();
          iVar3 = func_020b2b24(uVar2,1);
          if (iVar3 == 0) {
            Const8_0();
            iVar3 = func_020b2a74();
            if (iVar3 == 0) goto LAB_020b287e;
          }
          piVar1 = piRam020b2884;
          *(undefined4 *)(*piRam020b2884 + 0x24) = 10;
          iVar3 = *piVar1;
          *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(iVar3 + 0x24);
          *(undefined4 *)(*piVar1 + 0xc) = 1;
          func_020b3278();
        }
        else {
          iVar3 = GetRaceMode();
          if ((iVar3 == 4) && (iVar3 = func_020b2ecc(), iVar3 != 0)) {
            uVar2 = Const8_0();
            iVar3 = func_020b2b24(uVar2,1);
            if (iVar3 == 0) {
              Const8_0();
              iVar3 = func_020b2a74();
              if (iVar3 == 0) goto LAB_020b287e;
            }
            piVar1 = piRam020b2884;
            *(undefined4 *)(*piRam020b2884 + 0x24) = 6;
            iVar3 = *piVar1;
            *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(iVar3 + 0x24);
            *(undefined4 *)(*piVar1 + 0xc) = 1;
            func_020b3278();
            SetB488_B6(1);
          }
          else {
            iVar3 = GetRaceMode();
            if ((iVar3 == 4) && (iVar3 = IsCurrentMissionNotBeaten(), iVar3 != 0)) {
              uVar2 = Const8_0();
              iVar3 = func_020b2b24(uVar2,1);
              if (iVar3 == 0) {
                Const8_0();
                iVar3 = func_020b2a74();
                if (iVar3 == 0) goto LAB_020b287e;
              }
              piVar1 = piRam020b2884;
              *(undefined4 *)(*piRam020b2884 + 0x24) = 6;
              iVar3 = *piVar1;
              *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(iVar3 + 0x24);
              *(undefined4 *)(*piVar1 + 0xc) = 1;
              func_020b3278();
            }
            else {
              uVar2 = Const8_0();
              iVar3 = func_020b2b24(uVar2,8);
              if (iVar3 == 0) {
                iVar3 = func_020b302c();
                if (iVar3 == 0) {
                  uVar2 = Const8_0();
                  iVar3 = func_020b2b24(uVar2,1);
                  if (iVar3 == 0) {
                    uVar2 = Const8_0();
                    iVar3 = func_020b2b24(uVar2,2);
                    if (iVar3 == 0) {
                      uVar2 = Const8_0();
                      iVar3 = func_020ae408(uVar2,0x40);
                      if (iVar3 == 0) {
                        uVar2 = Const8_0();
                        iVar3 = func_020ae408(uVar2,0x80);
                        if (iVar3 != 0) {
                          MaybeOnMenuOptionScroll_from_thumb(1);
                        }
                      }
                      else {
                        MaybeOnMenuOptionScroll_from_thumb(0xffffffff);
                      }
                    }
                    else {
                      iVar3 = func_020b2e98();
                      if (iVar3 != 0) {
                        func_02105c4c();
                        *(undefined4 *)(*piRam020b2884 + 0x18) = 1;
                      }
                    }
                  }
                  else {
                    iVar3 = func_020b2e98();
                    if (iVar3 == 0) {
                      func_02105d70();
                      func_020b2f88(1);
                    }
                    else {
                      if (*(int *)(*piRam020b2884 + 0x28) == 0) {
                        func_02105c4c();
                      }
                      else {
                        func_020b3278();
                      }
                      piVar1 = piRam020b2884;
                      *(undefined4 *)(*piRam020b2884 + 0x14) = 1;
                      *(undefined4 *)(*piVar1 + 0x10) = 1;
                    }
                  }
                }
                else {
                  *(undefined4 *)(*piRam020b2884 + 0x14) = 1;
                }
              }
              else {
                iVar3 = func_020b2e98();
                if (iVar3 == 0) {
                  func_02105d70();
                  func_020b2f88(1);
                }
                else {
                  func_02105c4c();
                  *(undefined4 *)(*piRam020b2884 + 0x18) = 1;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_020b287e:
  piVar1 = piRam020b2884;
  iVar3 = *(int *)(*piRam020b2884 + 0x14);
  if ((iVar3 != 0) && (*(int *)(*piRam020b2884 + 0x14) = iVar3 + 1, 0xf < *(int *)(*piVar1 + 0x14)))
  {
    iVar3 = func_020b2bc8();
    if (iVar3 == 0) {
      iVar3 = func_020b2e98();
      if (iVar3 != 0) {
        *(undefined4 *)(*piRam020b29a8 + 0x24) = *(undefined4 *)(*piRam020b29a8 + 0x28);
        func_020b2f88(0);
      }
    }
    else {
      iVar3 = func_020b2e98();
      if (iVar3 == 0) {
        func_020b2f88(1);
      }
      else {
        *(undefined4 *)(*piRam020b29a8 + 0x24) = *(undefined4 *)(*piRam020b29a8 + 0x28);
        func_020b2f88(0);
      }
    }
    piVar1 = piRam020b29a8;
    *(undefined4 *)(*piRam020b29a8 + 0x14) = 0;
    *(undefined4 *)(*piVar1 + 0x10) = 0;
  }
  piVar1 = piRam020b29a8;
  iVar3 = *(int *)(*piRam020b29a8 + 0x18);
  if ((iVar3 != 0) && (*(int *)(*piRam020b29a8 + 0x18) = iVar3 + 1, 4 < *(int *)(*piVar1 + 0x18))) {
    iVar3 = func_020b2bc8();
    if (iVar3 == 0) {
      iVar3 = func_020b2e98();
      if (iVar3 != 0) {
        func_020b2f88(0);
      }
    }
    else {
      iVar3 = func_020b2e98();
      if (iVar3 == 0) {
        func_020b2f88(1);
      }
      else {
        func_020b2f88(0);
      }
    }
    *(undefined4 *)(*piRam020b29a8 + 0x18) = 0;
  }
  iVar3 = GetPMaybeState_0();
  if ((((iVar3 != 0) && (iVar3 = GetRaceMode(), iVar3 == 5)) &&
      (iVar3 = func_020b2bc8(), piVar1 = piRam020b29a8, iVar3 != 0)) &&
     (*(int *)(*piRam020b29a8 + 0x1c) = *(int *)(*piRam020b29a8 + 0x1c) + 1,
     iRam020b29ac < *(int *)(*piVar1 + 0x1c))) {
    iVar3 = func_020b24f8();
    if (iVar3 == 4) {
      uVar2 = 7;
    }
    else {
      uVar2 = 2;
    }
    *(undefined4 *)(*piRam020b29a8 + 0x24) = uVar2;
  }
  iVar3 = IsRaceOptionMenuOn_from_thumb();
  piVar1 = piRam020b29a8;
  if (iVar3 == 0) {
    *(undefined4 *)(*piRam020b29a8 + 0x2c) = 0;
    *(undefined4 *)(*piVar1 + 0x30) = 0;
  }
  else {
    iVar3 = *(int *)(*piRam020b29a8 + 0x30);
    *(int *)(*piRam020b29a8 + 0x30) = iVar3 + 1;
    if (0 < iVar3) {
      *(undefined4 *)(*piVar1 + 0x2c) = 2;
      *(undefined4 *)(*piVar1 + 0x30) = 1;
    }
  }
  return;
}

