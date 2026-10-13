/* Decompiled C draft; module arm9_ov001; ROM address 0218e92c. No matching claim. */
#include "types.h"
#include "deps/0218e92c_FUN_0218e92c.h"

void FUN_0218e92c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  FUN_02187218(param_1,5,DAT_0218ea48);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ea4c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ea50));
  FUN_02188d1c(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ea54),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ea58));
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ea5c),DAT_0218ea60);
  FUN_021875c0(param_1,0,0,0,DAT_0218ea64,0);
  FUN_021875c0(param_1,0,0,0,DAT_0218ea68,0);
  FUN_021875c0(param_1,0,0,0,DAT_0218ea6c,0);
  if (*DAT_0218ea70 != 4) {
    *DAT_0218ea74 = *DAT_0218ea70;
  }
  *DAT_0218ea70 = 4;
  FUN_02188200(param_1,DAT_0218ea78);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218ea7c;
  if (*(int *)(*DAT_0218ea80 + 8) == 4) {
    iVar1 = func_ov001_02181800();
  }
  else {
    iVar1 = 0;
  }
  iVar4 = *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218ea84);
  if (iVar1 <= iVar4) {
    if (*(int *)(*DAT_0218ea80 + 8) == 4) {
      iVar4 = func_ov001_02181800();
    }
    else {
      iVar4 = 0;
    }
  }
  FUN_02182a3c(iVar4);
  uVar2 = func_0x02133068(*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xc),2);
  puVar5 = (undefined4 *)(param_1 + DAT_0218ea88);
  *puVar5 = uVar2;
  puVar3 = (undefined4 *)(param_1 + DAT_0218ea8c);
  *puVar3 = *puVar5;
  puVar5 = (undefined4 *)(param_1 + DAT_0218ea90);
  *puVar5 = *puVar3;
  *(undefined4 *)(param_1 + DAT_0218ea94) = *puVar5;
  return;
}

