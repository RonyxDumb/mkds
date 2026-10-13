/* Decompiled C draft; module arm9_ov000; ROM address 021a5e84. No matching claim. */
#include "types.h"
#include "deps/021a5e84_FUN_021a5e84.h"

undefined4 FUN_021a5e84(int param_1,byte *param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = func_0x0200fca0();
  piVar1 = DAT_021a5ff8;
  iVar3 = *DAT_021a5ff8;
  if (iVar3 == 0) {
    func_0x0200fcb4();
    return 1;
  }
  iVar4 = *(int *)(iVar3 + DAT_021a5ffc);
  if (iVar4 != 3) {
    if (iVar4 == 8) {
      func_0x0200fcb4();
      return 2;
    }
    if (iVar4 == 9) {
      func_0x0200fcb4();
      return 0;
    }
    func_0x0200fcb4();
    return 1;
  }
  if (param_1 == 0) {
    func_0x0200fcb4();
    return 1;
  }
  if (*(short *)(param_1 + 0x3c) != 0) {
    func_0x0200fcb4();
    return 1;
  }
  if (param_2 == (byte *)0x0) {
    func_0x0214d168((uint *)(uintptr_t)(iVar3 + DAT_021a6008),0,0x52);
  }
  else {
    if ((3 < *param_2) || (3 < param_2[1])) {
      func_0x0200fcb4(uVar2);
      return 1;
    }
    *(byte *)(iVar3 + DAT_021a6000) = *param_2;
    *(byte *)(*piVar1 + DAT_021a6004) = param_2[1];
    iVar3 = *piVar1;
    if (*(char *)(iVar3 + DAT_021a6000) == '\0') {
      func_0x0214d168((uint *)(uintptr_t)(iVar3 + DAT_021a6008),0,0x50);
    }
    else {
      func_0x0214d1fc((ushort *)(void *)(param_2 + 2),(uint *)(uintptr_t)(iVar3 + DAT_021a6008),0x50);
    }
  }
  func_0x0214d1fc((ushort *)(uintptr_t)(param_1),(uint *)(uintptr_t)(*DAT_021a5ff8 + DAT_021a600c),0xc0);
  *(ushort *)(*DAT_021a5ff8 + DAT_021a6014) = *(ushort *)(*DAT_021a5ff8 + DAT_021a6010) | 3;
  FUN_021a5b3c(param_3);
  iVar3 = func_0x021454c4(DAT_021a601c,DAT_021a6018,0x50,DAT_021a6018,DAT_021a6018);
  if (iVar3 == 2) {
    FUN_021a57fc(8);
    *(undefined2 *)(*DAT_021a5ff8 + DAT_021a6020) = 5;
    func_0x0200fcb4(uVar2);
    return 3;
  }
  if ((iVar3 != 3) && (iVar3 == 8)) {
    func_0x0200fcb4(uVar2);
    return 4;
  }
  FUN_021a57fc(0xb);
  func_0x0200fcb4(uVar2);
  return 7;
}

