/* Decompiled C draft; module arm9_ov000; ROM address 0218f848. No matching claim. */
#include "types.h"
#include "deps/0218f848_FUN_0218f848.h"

int FUN_0218f848(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *local_18 [2];
  
  *param_1 = 0;
  local_18[0] = (undefined1 *)FUN_021a3690(DAT_0218f92c);
  if (local_18[0] == (undefined1 *)0x0) {
    return 1;
  }
  func_0x02134de0(local_18[0],0,DAT_0218f92c);
  *local_18[0] = 0;
  *(undefined4 *)(local_18[0] + DAT_0218f930) = 0;
  *(undefined4 *)(local_18[0] + DAT_0218f934) = 1;
  *(undefined4 *)(local_18[0] + DAT_0218f938) = 0;
  *(undefined4 *)(local_18[0] + DAT_0218f93c) = 0;
  *(undefined4 *)(local_18[0] + DAT_0218f940) = 0;
  *(undefined4 *)(local_18[0] + DAT_0218f944) = param_2;
  *(undefined4 *)(local_18[0] + DAT_0218f948) = param_3;
  iVar2 = FUN_02194af4((int *)(void *)(local_18));
  if (iVar2 == 0) {
    FUN_021a3668((undefined4)(uintptr_t)(local_18[0]));
    return 1;
  }
  iVar4 = 0;
  *(undefined4 *)(local_18[0] + DAT_0218f94c) = 0;
  iVar1 = DAT_0218f954;
  iVar2 = DAT_0218f950;
  iVar3 = 0;
  do {
    *(undefined4 *)(local_18[0] + iVar2 + iVar3) = 0;
    *(undefined4 *)(local_18[0] + iVar1 + iVar3) = 0;
    iVar3 = iVar3 + 8;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  *(undefined4 *)(local_18[0] + DAT_0218f958) = 0;
  FUN_0219690c(local_18,DAT_0218f95c);
  iVar2 = FUN_0218f654((int *)(void *)(local_18));
  if (iVar2 != 0) {
    FUN_0218f808((int *)(void *)(local_18));
    return iVar2;
  }
  FUN_0218e8b8();
  FUN_0218e8c4();
  func_0x021384cc();
  *param_1 = local_18[0];
  return 0;
}

