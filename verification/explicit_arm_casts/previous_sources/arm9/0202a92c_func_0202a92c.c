/* Decompiled C draft; module arm9; ROM address 0202a92c. No matching claim. */
#include "types.h"
#include "deps/0202a92c_func_0202a92c.h"

undefined4 func_0202a92c(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_1c;
  
  local_1c = 0;
  func_0202e4b0();
  func_0202b100();
  iVar4 = DAT_0202ab24;
  piVar1 = DAT_0202ab10;
  iVar2 = *DAT_0202ab10;
  switch(*(undefined4 *)(iVar2 + 0xac)) {
  case 0:
    iVar4 = Bright_IsBothScreensFadedIn();
    if (iVar4 != 0) {
      if (*(int *)(*DAT_0202ab10 + 0xcc) == 1) {
        *(undefined4 *)(*DAT_0202ab10 + 0xac) = 1;
      }
      func_0202b264();
    }
    break;
  case 1:
    iVar4 = func_0202e468();
    if (iVar4 != 0) {
      NNSi_MaybeSndPlayerStartSeq(DAT_0202ab14,0,DAT_0202ab18);
    }
    iVar4 = func_0202e47c();
    if ((iVar4 != 0) || (*(int *)(*DAT_0202ab10 + DAT_0202ab1c) == 0)) {
      iVar4 = func_0202e4a4();
      if (iVar4 == 0) {
        iVar4 = func_0202af60();
      }
      else {
        iVar4 = iVar4 + -1;
      }
      func_02121e84(*(undefined4 *)(DAT_0202ab20 + iVar4 * 4));
      piVar1 = DAT_0202ab10;
      *(undefined4 *)(*DAT_0202ab10 + 0xac) = 2;
      *(undefined4 *)(*piVar1 + 0xb0) = 1;
      func_0202e490(0);
    }
    break;
  case 2:
    iVar4 = func_02121cd0();
    piVar1 = DAT_0202ab10;
    if (iVar4 != 0) {
      *(undefined4 *)(*DAT_0202ab10 + 0xac) = 3;
      func_02025f14(*piVar1 + 0xec,2);
    }
    break;
  case 3:
    *(int *)(iVar2 + DAT_0202ab24) = *(int *)(iVar2 + DAT_0202ab24) + 1;
    if (0x3c < *(int *)(*piVar1 + iVar4)) {
      func_02036e20(0x3c,1);
      piVar1 = DAT_0202ab10;
      *(undefined4 *)(*DAT_0202ab10 + 0xac) = 4;
      *(undefined4 *)(*piVar1 + DAT_0202ab24) = 0;
      NNSi_MaybeSndPlayerStartSeq(DAT_0202ab14,0,DAT_0202ab28);
    }
    break;
  case 4:
    *(int *)(iVar2 + DAT_0202ab24) = *(int *)(iVar2 + DAT_0202ab24) + 1;
    if (*(int *)(*piVar1 + iVar4) < 0x3d) {
      func_0202b3f4();
    }
    else {
      func_02037334(10,1);
      piVar1 = DAT_0202ab10;
      *(undefined4 *)(*DAT_0202ab10 + 0xac) = 5;
      *(undefined4 *)(*piVar1 + DAT_0202ab24) = 0;
      func_0202b2bc();
    }
    break;
  case 5:
    *(int *)(iVar2 + DAT_0202ab24) = *(int *)(iVar2 + DAT_0202ab24) + 1;
    if (0x3c < *(int *)(*piVar1 + iVar4)) {
      Bright_FadeOutBlack(10);
      piVar1 = DAT_0202ab10;
      *(undefined4 *)(*DAT_0202ab10 + 0xac) = 6;
      *(undefined4 *)(*piVar1 + DAT_0202ab24) = 0;
    }
    break;
  case 6:
    *(int *)(iVar2 + DAT_0202ab24) = *(int *)(iVar2 + DAT_0202ab24) + 1;
    if (10 < *(int *)(*piVar1 + iVar4)) {
      *(undefined4 *)(*piVar1 + 0xac) = 7;
      *(undefined4 *)(*piVar1 + iVar4) = 0;
    }
    break;
  case 7:
    local_1c = *(undefined4 *)(iVar2 + 0xb0);
  }
  func_0202afe4();
  func_02025edc(*DAT_0202ab10 + 0xdc);
  piVar1 = DAT_0202ab10;
  iVar5 = 0;
  iVar2 = 0;
  iVar4 = 0;
  do {
    iVar3 = *piVar1 + 0x48 + iVar2;
    func_02124c30(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8),
                  *(undefined4 *)(iVar3 + 0x14),*(undefined4 *)(*piVar1 + iVar4 + 0x80),
                  *(undefined4 *)(iVar3 + 0x18));
    iVar2 = iVar2 + 0x1c;
    iVar4 = iVar4 + 4;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  return local_1c;
}

