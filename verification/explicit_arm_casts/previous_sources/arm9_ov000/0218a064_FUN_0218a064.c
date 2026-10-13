/* Decompiled C draft; module arm9_ov000; ROM address 0218a064. No matching claim. */
#include "types.h"
#include "deps/0218a064_FUN_0218a064.h"

void FUN_0218a064(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  func_0x0214d1fc(DAT_0218a0ec,param_3,0x58);
  *(undefined4 *)(param_3 + 4) = *param_1;
  *(undefined4 *)(param_3 + 8) = param_1[1];
  if (*(byte *)(param_2 + DAT_0218a0f0) < 6) {
    iVar1 = FUN_021884d8();
    param_2 = param_2 + iVar1 * 0x100;
    if (*(char *)(param_2 + 0xc0) != '\0') {
      *(undefined4 *)(param_3 + 0xc) = 0;
      uVar2 = FUN_0218a018(param_2 + 0xc0);
      *(undefined4 *)(param_3 + 0x10) = uVar2;
      uVar2 = FUN_02189fd0(*(undefined1 *)(param_2 + 0xd0));
      *(undefined4 *)(param_3 + 0x14) = uVar2;
      uVar2 = FUN_0218a018(param_2 + 0xc4);
      *(undefined4 *)(param_3 + 0x18) = uVar2;
      uVar2 = FUN_0218a018(param_2 + 200);
      *(undefined4 *)(param_3 + 0x1c) = uVar2;
      uVar2 = FUN_0218a018(param_2 + 0xcc);
      *(undefined4 *)(param_3 + 0x20) = uVar2;
      return;
    }
    *(undefined4 *)(param_3 + 0xc) = 1;
    *(undefined4 *)(param_3 + 0x10) = 0;
    *(undefined4 *)(param_3 + 0x14) = 0;
    *(undefined4 *)(param_3 + 0x18) = 0;
    *(undefined4 *)(param_3 + 0x1c) = 0;
    *(undefined4 *)(param_3 + 0x20) = 0;
  }
  return;
}

