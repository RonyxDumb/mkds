/* Decompiled C draft; module arm9_ov001; ROM address 0218cedc. No matching claim. */
#include "types.h"
#include "deps/0218cedc_FUN_0218cedc.h"

void FUN_0218cedc(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(*DAT_0218cf84 + 8) == 4) {
    iVar1 = func_0x020a126c();
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 == 0) {
    iVar1 = FUN_021871f8(param_2,1);
    if (iVar1 != 0) {
      FUN_0218d3ec(param_2);
    }
  }
  else {
    iVar1 = FUN_021871f8(param_2,1);
    if (iVar1 != 0) {
      if (*(int *)(*DAT_0218cf84 + 8) == 4) {
        iVar1 = func_0x020a1084((short)*(char *)(*DAT_0218cf84 + 0x62));
      }
      else {
        iVar1 = 0;
      }
      if (iVar1 == 0) {
        FUN_0218d2c4(param_2);
      }
      else {
        FUN_0218d374(param_2);
      }
    }
  }
  iVar1 = func_0x020d2c2c((undefined4 *)(uintptr_t)(param_2 + DAT_0218cf88),(undefined4 *)(uintptr_t)(param_2 + 0x10),
                          *(undefined4 *)(*(int *)(param_2 + 0xa0) + DAT_0218cf8c),
                          (int)*(short *)(param_2 + 100),9,0);
  if (iVar1 == 2) {
    func_0x020d2774(param_2,DAT_0218cf90);
  }
  FUN_021864ac(param_1,param_2);
  return;
}

