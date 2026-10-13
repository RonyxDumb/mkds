/* Decompiled C draft; module arm9_ov000; ROM address 02198fdc. No matching claim. */
#include "types.h"
#include "deps/02198fdc_FUN_02198fdc.h"

undefined4 FUN_02198fdc(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_0218dc44(*(undefined4 *)(param_1 + 0x60));
  if (iVar1 < 1) {
    func_0x0213442c(DAT_02199030,DAT_02199034,0,DAT_02199038);
  }
  piVar2 = (int *)FUN_0218dbf8(*(undefined4 *)(param_1 + 0x60),iVar1 + -1);
  iVar1 = FUN_02198714(param_1,*(int *)(param_1 + 0x50) + *piVar2,piVar2[1]);
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0x90) = 0;
  return 1;
}

