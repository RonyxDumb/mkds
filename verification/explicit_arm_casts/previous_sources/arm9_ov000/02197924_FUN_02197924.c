/* Decompiled C draft; module arm9_ov000; ROM address 02197924. No matching claim. */
#include "types.h"
#include "deps/02197924_FUN_02197924.h"

undefined4 FUN_02197924(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_90 [8];
  undefined1 auStack_88 [136];
  
  *DAT_02197a60 = param_1;
  if (param_2 != 0) {
    *DAT_02197a64 = param_2;
  }
  if (*DAT_02197a68 != 1) {
    return 1;
  }
  if (*DAT_02197a6c == 0) {
    FUN_0219742c();
  }
  FUN_0218e8b8();
  uVar1 = FUN_0218e8c4();
  *DAT_02197a70 = uVar1;
  if (*DAT_02197a74 != -1) {
    FUN_02197634();
  }
  *DAT_02197a78 = 0;
  iVar2 = FUN_0218e374(DAT_02197a7c);
  if (iVar2 == -1) {
    func_0x0213a2d0(auStack_88,DAT_02197a80);
    func_0x0213a1c0(auStack_88,DAT_02197a84);
    func_0x0213a1c0(auStack_88,DAT_02197a7c);
  }
  else {
    func_0x0213a2d0(auStack_88,DAT_02197a7c);
  }
  iVar2 = FUN_02197064(auStack_88,DAT_02197a88,auStack_90,0);
  if (iVar2 == 0) {
    return 2;
  }
  iVar2 = FUN_0218e554(2,1,0);
  *DAT_02197a74 = iVar2;
  if (iVar2 == -1) {
    return 1;
  }
  FUN_0218e80c();
  iVar2 = FUN_0218e4b4(*DAT_02197a74,auStack_90,8);
  if (iVar2 == -1) {
    iVar2 = FUN_0218e368(*DAT_02197a74);
    if (((iVar2 != -6) && (iVar2 != -0x4c)) && (iVar2 != -0x1a)) {
      *DAT_02197a8c = 1;
      FUN_0218e53c(*DAT_02197a74);
      return 3;
    }
  }
  iVar2 = FUN_021a3690(0x40);
  *DAT_02197a90 = iVar2;
  if (iVar2 == 0) {
    return 3;
  }
  *DAT_02197a94 = 0x40;
  *DAT_02197a78 = 0;
  uVar1 = FUN_0218e8c4();
  *DAT_02197a98 = uVar1;
  *DAT_02197a8c = 2;
  return 6;
}

