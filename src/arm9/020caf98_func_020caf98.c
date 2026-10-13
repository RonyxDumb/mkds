/* Decompiled C draft; module arm9; ROM address 020caf98. No matching claim. */
#include "types.h"
#include "deps/020caf98_func_020caf98.h"

void func_020caf98(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  
  if (param_1 != 0) {
    uVar1 = func_020cb224();
    iVar2 = func_020cb1f4(uVar1,1);
    if (iVar2 == 0) {
      iVar2 = func_020cb1f4(uVar1,2);
      if (iVar2 == 0) {
        iVar2 = func_020ae408(uVar1,0x40);
        if (iVar2 == 0) {
          iVar2 = func_020ae408(uVar1,0x80);
          if (iVar2 == 0) {
            iVar2 = func_020cb11c(uVar1);
            if (iVar2 != 0) {
              uVar3 = func_020cb0f4(uVar1);
              uVar1 = func_020cb0cc(uVar1);
              iVar2 = func_020291c4(uVar3,uVar1,*(undefined4 *)(*piRam020cb0bc + iRam020cb0c8));
              if (iVar2 == -1) {
                iVar2 = func_02128210(uVar3,uVar1);
                if (iVar2 != 0) {
                  func_020ccc74(2,0x1b);
                  func_02128310(1);
                }
              }
              else {
                if (*(int *)(*piRam020cb0bc + iRam020cb0c4) == iVar2) {
                  *(undefined4 *)(*piRam020cb0bc + iRam020cb0c0) = 1;
                }
                *(int *)(*piRam020cb0bc + iRam020cb0c4) = iVar2;
                func_020ccc74(3,0x1f);
                func_020cb1cc(5);
              }
            }
          }
          else {
            iVar2 = *piRam020cb0bc;
            _s32_div_f(*(int *)(iVar2 + iRam020cb0c4) + 6,5);
            *(undefined4 *)(iVar2 + iRam020cb0c4) = extraout_r1_00;
            MaybePlaySomeSseqFromSarc0(0);
          }
        }
        else {
          iVar2 = *piRam020cb0bc;
          _s32_div_f(*(int *)(iVar2 + iRam020cb0c4) + 4,5);
          *(undefined4 *)(iVar2 + iRam020cb0c4) = extraout_r1;
          MaybePlaySomeSseqFromSarc0(0);
        }
      }
      else {
        func_020ccc74(2,0x1b);
        func_02128310(1);
      }
    }
    else {
      func_020ccc74(3,0x1f);
      func_020cb1cc(5);
      *(undefined4 *)(*piRam020cb0bc + iRam020cb0c0) = 1;
    }
  }
  func_020cb2d4();
  return;
}

