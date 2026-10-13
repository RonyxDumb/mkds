/* Decompiled C draft; module arm9_ov000; ROM address 021a5a78. No matching claim. */
#include "types.h"
#include "deps/021a5a78_FUN_021a5a78.h"

void FUN_021a5a78(uint *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_021a5b18;
  if (param_1 == (uint *)0x0) {
    *(undefined4 *)(*DAT_021a5b18 + DAT_021a5b1c) = 3;
    *(undefined4 *)(*piVar1 + DAT_021a5b20) = 0;
    *(undefined4 *)(*piVar1 + DAT_021a5b24) = 0;
    *(undefined4 *)(*piVar1 + DAT_021a5b28) = 0;
  }
  else {
    *(uint *)(*DAT_021a5b18 + DAT_021a5b1c) = *param_1 & 3;
    iVar2 = DAT_021a5b20;
    if (param_1[2] < (4 - (param_1[1] & 3) & 3) + 0xc) {
      *(undefined4 *)(*piVar1 + DAT_021a5b20) = 0;
      *(undefined4 *)(*piVar1 + DAT_021a5b24) = 0;
    }
    else {
      *(uint *)(*piVar1 + DAT_021a5b20) = param_1[1] + 3 & 0xfffffffc;
      iVar3 = DAT_021a5b24;
      *(uint *)(*piVar1 + DAT_021a5b24) = param_1[2] - (4 - (param_1[1] & 3) & 3);
      func_0x0214d168((uint *)(uintptr_t)(*(undefined4 *)(*piVar1 + iVar2)),0,*(undefined4 *)(*piVar1 + iVar3));
    }
    *(uint *)(*DAT_021a5b18 + DAT_021a5b28) = param_1[3];
  }
  *(undefined4 *)(*DAT_021a5b18 + DAT_021a5b2c) = param_2;
  return;
}

