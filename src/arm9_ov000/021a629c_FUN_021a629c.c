/* Decompiled C draft; module arm9_ov000; ROM address 021a629c. No matching claim. */
#include "types.h"
#include "deps/021a629c_FUN_021a629c.h"

undefined4 FUN_021a629c(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = func_0x0200fca0();
  if (*DAT_021a6410 == 0) {
    func_0x0200fcb4();
    return 1;
  }
  iVar3 = *(int *)(*DAT_021a6410 + DAT_021a6414);
  if (iVar3 == 1) {
    FUN_021a5a78((uint *)(uintptr_t)(param_1),param_2);
    uVar2 = func_0x02142e78(*DAT_021a6410,*(uint *)(*DAT_021a6410 + DAT_021a6418) & 0xffff);
    switch(uVar2) {
    case 0:
      goto switchD_021a631c_caseD_0;
    default:
      FUN_021a57fc(0xb);
      func_0x0200fcb4(uVar1);
      return 7;
    case 3:
      FUN_021a57fc(0xb);
      func_0x0200fcb4(uVar1);
      return 7;
    case 4:
      func_0x0200fcb4(uVar1);
      return 5;
    }
  }
  if (iVar3 == 2) {
    func_0x0200fcb4();
    return 2;
  }
  if (iVar3 != 3) {
    func_0x0200fcb4();
    return 1;
  }
  func_0x0200fcb4();
  return 0;
switchD_021a631c_caseD_0:
  iVar3 = func_0x02143280();
  if (iVar3 == 0) {
    iVar3 = func_0x02142c24();
    if (iVar3 != 0) {
      FUN_021a57fc(0xb);
      func_0x0200fcb4(uVar1);
      return 7;
    }
    func_0x0200fcb4(uVar1);
    return 5;
  }
  iVar3 = func_0x021435e8(DAT_021a641c);
  if (iVar3 != 0) {
    FUN_021a57fc(0xb);
    func_0x0200fcb4(uVar1);
    return 7;
  }
  iVar3 = func_0x02143f50(DAT_021a6420);
  if (iVar3 == 2) {
    FUN_021a57fc(2);
    *(undefined2 *)(*DAT_021a6410 + DAT_021a6424) = 1;
    func_0x0200fcb4(uVar1);
    return 3;
  }
  if ((iVar3 != 3) && (iVar3 == 8)) {
    FUN_021a57fc(0xc);
    func_0x0200fcb4(uVar1);
    return 1;
  }
  FUN_021a57fc(0xb);
  func_0x0200fcb4(uVar1);
  return 7;
}

