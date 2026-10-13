/* Decompiled C draft; module arm9_ov001; ROM address 0218df20. No matching claim. */
#include "types.h"
#include "deps/0218df20_FUN_0218df20.h"

void FUN_0218df20(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(*DAT_0218e1d0 + 8) == 4) {
    iVar1 = func_0x020a126c();
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 == 0) {
    if (*(int *)(param_2 + 0xa8) == 0) {
      iVar1 = func_0x0207a974((short)*(char *)(*DAT_0218e1d0 + 0x62));
      if ((*(uint *)(iVar1 + 0x48) & DAT_0218e1d8) != 0) {
        if (*(int *)(*DAT_0218e1d0 + 8) == 4) {
          iVar1 = func_ov001_02181820();
        }
        else {
          iVar1 = 0;
        }
        if (iVar1 == 0) {
          if (*(int *)(*DAT_0218e1d0 + 8) == 4) {
            func_ov001_0218182c(0);
          }
        }
        else if (*(int *)(*DAT_0218e1d0 + 8) == 4) {
          func_ov001_0218182c(*(uint *)(*(int *)(param_2 + 0xa0) + DAT_0218e1ec) & 0xffff);
        }
        if ((*(ushort *)(param_2 + 2) & 1) == 0) {
          FUN_02188200(param_2,DAT_0218e1f0);
          *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *DAT_0218e1f4;
          FUN_0218e7d0(param_2);
        }
      }
      if (*(int *)(*DAT_0218e1d0 + 8) == 4) {
        iVar1 = func_ov001_02181838();
      }
      else {
        iVar1 = 0;
      }
      if ((iVar1 != 0) && (iVar1 = FUN_021871f8(param_2,3), iVar1 != 0)) {
        if (*(int *)(*DAT_0218e1d0 + 8) == 4) {
          iVar1 = func_ov001_02181838();
        }
        else {
          iVar1 = 0;
        }
        if (iVar1 < *(int *)(*(int *)(param_2 + 0xa0) + DAT_0218e1f8)) {
          if ((*(ushort *)(param_2 + 2) & 1) == 0) {
            FUN_02188200(param_2,DAT_0218e1f0);
            *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *DAT_0218e1f4;
            FUN_0218ef30(param_2);
          }
          else {
            FUN_02188200(param_2,DAT_0218e1f0);
            *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *DAT_0218e1f4;
            FUN_0218ee88(param_2);
          }
        }
        else if ((*(ushort *)(param_2 + 2) & 1) == 0) {
          FUN_02188200(param_2,DAT_0218e1f0);
          *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *DAT_0218e1f4;
          FUN_0218e7d0(param_2);
        }
      }
    }
    else {
      iVar1 = FUN_021871f8(param_2,5);
      if ((((iVar1 != 0) &&
           (iVar1 = func_0x0207a974((short)*(char *)(*DAT_0218e1d0 + 0x62)),
           *(int *)(iVar1 + DAT_0218e1d4) == 0)) && ((*(uint *)(iVar1 + 0x48) & DAT_0218e1d8) == 0))
         && (((iVar1 = FUN_02188104(param_2,0,
                                    *(undefined4 *)(*(int *)(param_2 + 0xa0) + DAT_0218e1dc)),
              iVar1 != 0 &&
              (iVar1 = FUN_02188000(param_2,0,
                                    *(undefined4 *)(*(int *)(param_2 + 0xa0) + DAT_0218e1d4)),
              iVar1 != 0)) &&
             (iVar1 = FUN_02188104(param_2,*(undefined4 *)(*(int *)(param_2 + 0xa0) + DAT_0218e1e0),
                                   0), iVar1 != 0)))) {
        FUN_0218e8d8(param_2);
      }
      iVar1 = FUN_021871f8(param_2,3);
      if (iVar1 != 0) {
        uVar2 = FUN_02187fc0(param_2);
        iVar1 = FUN_021881a8(param_2,uVar2,*(undefined4 *)(*(int *)(param_2 + 0xa0) + DAT_0218e1e4),
                             0);
        if (iVar1 != 0) {
          FUN_02187e78(param_2);
        }
        FUN_02188200(param_2,DAT_0218e1e8);
        *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xffbf;
        FUN_02182a3c(0);
        FUN_0218ec40(param_2);
      }
    }
    if (*DAT_0218e1fc == 0) {
      func_0x02110350(*(undefined4 *)(param_2 + 0x94));
    }
    else {
      iVar1 = func_0x02110324();
      if (iVar1 == 0) {
        if (*DAT_0218e1fc == 4) {
          func_0x020d275c(param_2,DAT_0218e204);
        }
      }
      else {
        func_0x020d275c(param_2,DAT_0218e200);
      }
    }
  }
  else {
    iVar1 = FUN_021871f8(param_2,5);
    if (iVar1 != 0) {
      if (*(int *)(*DAT_0218e1d0 + 8) == 4) {
        iVar1 = func_0x020a1084((short)*(char *)(*DAT_0218e1d0 + 0x62));
      }
      else {
        iVar1 = 0;
      }
      if (iVar1 == 0) {
        if (*(int *)(*DAT_0218e1d0 + 8) == 4) {
          iVar1 = func_0x020a128c();
        }
        else {
          iVar1 = 0;
        }
        if (iVar1 == 0) {
          FUN_0218e594(param_2);
        }
        else {
          FUN_0218e5c4(param_2);
        }
      }
      else {
        FUN_0218e710(param_2);
      }
    }
  }
  FUN_021864ac(param_1,param_2);
  return;
}

