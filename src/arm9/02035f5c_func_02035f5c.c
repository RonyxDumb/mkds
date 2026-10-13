/* Decompiled C draft; module arm9; ROM address 02035f5c. No matching claim. */
#include "types.h"
#include "deps/02035f5c_func_02035f5c.h"

undefined4 func_02035f5c(int param_1)

{
  undefined4 extraout_r1;
  int iVar1;
  
  switch(*(undefined4 *)(*DAT_02036034 + DAT_02036038)) {
  case 0:
    iVar1 = func_0205579c(0,1);
    if (iVar1 == 1) {
      *(undefined4 *)(*DAT_02036034 + DAT_02036038) = 2;
    }
    break;
  case 2:
    iVar1 = func_02055730(0);
    if (iVar1 == 1) {
      func_020360e4();
      StructP_SetAFlag4_SkipBattleIntro();
      *(undefined4 *)(*DAT_02036034 + DAT_02036038) = 4;
    }
    break;
  case 4:
    iVar1 = func_02058cac();
    if (iVar1 == 1) {
      iVar1 = func_02035e44();
      if (iVar1 != 0) {
        func_02035e38();
      }
      func_0205e5c4(1);
      *(undefined4 *)(*DAT_02036034 + DAT_02036038) = 6;
    }
    break;
  case 6:
    iVar1 = func_0203606c();
    if (iVar1 == 0) {
      func_02036058(1);
      func_02036044(4);
      if (param_1 != 0) {
        func_02035e30(param_1,1);
      }
      *(undefined4 *)(*DAT_02036034 + DAT_02036038) = 0xb;
    }
  }
  iVar1 = *DAT_02036034;
  _s32_div_f(*(int *)(iVar1 + DAT_0203603c) + 1,DAT_02036040);
  *(undefined4 *)(iVar1 + DAT_0203603c) = extraout_r1;
  return 0xffffffff;
}

