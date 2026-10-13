/* Decompiled C draft; module arm9_ov001; ROM address 021832cc. No matching claim. */
#include "types.h"
#include "deps/021832cc_FUN_021832cc.h"

void FUN_021832cc(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(*DAT_0218342c + 8) == 4) {
    iVar1 = func_0x020a126c();
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 == 0) {
    iVar1 = FUN_021871f8(param_2,8);
    if ((iVar1 != 0) && (iVar1 = FUN_021871d0(param_2), iVar1 != 0)) {
      FUN_02183880(param_2);
    }
    iVar1 = FUN_021871f8(param_2,5);
    if (((((iVar1 != 0) &&
          (iVar2 = *(int *)(param_2 + 0xa0), iVar1 = FUN_02188220(param_2),
          *(int *)(iVar2 + DAT_02183430) <= iVar1)) &&
         (iVar1 = FUN_02188104(param_2,*(undefined4 *)(*(int *)(param_2 + 0xa0) + DAT_02183434),
                               *(undefined4 *)(*(int *)(param_2 + 0xa0) + DAT_02183438)), iVar1 != 0
         )) && ((iVar1 = FUN_02188000(param_2,*(undefined4 *)
                                               (*(int *)(param_2 + 0xa0) + DAT_0218343c),
                                      *(undefined4 *)(*(int *)(param_2 + 0xa0) + DAT_02183440)),
                iVar1 != 0 &&
                (iVar2 = func_0x0207a974(*(undefined2 *)(iVar1 + 0x74)),
                (*(uint *)(iVar2 + 0x48) & DAT_02183444) != 0)))) &&
       (0 < *(short *)(iVar1 + DAT_02183448))) {
      FUN_02183dec(param_2);
    }
    iVar1 = FUN_021871f8(param_2,3);
    if ((iVar1 != 0) &&
       (iVar1 = FUN_021881a8(param_2,*(undefined4 *)(param_2 + 0x9c),
                             *(undefined4 *)(*(int *)(param_2 + 0xa0) + DAT_0218344c),0), iVar1 == 0
       )) {
      FUN_021839ac(param_2);
    }
    iVar1 = FUN_021871f8(param_2,2);
    if ((iVar1 != 0) &&
       (iVar1 = FUN_02188104(param_2,*(undefined4 *)(*(int *)(param_2 + 0xa0) + 0xdc),
                             *(undefined4 *)(*(int *)(param_2 + 0xa0) + 0xe0)), iVar1 != 0)) {
      FUN_02183ad8((ushort *)(uintptr_t)(param_2));
    }
    iVar1 = FUN_021871f8(param_2,1);
    if (iVar1 != 0) {
      FUN_02183894(param_2);
    }
  }
  else {
    iVar1 = FUN_021871f8(param_2,1);
    if (iVar1 != 0) {
      if (*(int *)(*DAT_0218342c + 8) == 4) {
        iVar1 = func_0x020a1084((short)*(char *)(*DAT_0218342c + 0x62));
      }
      else {
        iVar1 = 0;
      }
      if (iVar1 == 0) {
        FUN_02183f0c((ushort *)(uintptr_t)(param_2));
      }
      else {
        FUN_02183850(param_2);
      }
    }
  }
  FUN_021864ac(param_1,param_2);
  return;
}

