/* Decompiled C draft; module arm9_ov000; ROM address 021a5c24. No matching claim. */
#include "types.h"
#include "deps/021a5c24_FUN_021a5c24.h"

undefined4 FUN_021a5c24(void)

{
  short sVar1;
  undefined4 uVar2;
  short *psVar3;
  int iVar4;
  
  uVar2 = func_0x0200fca0();
  iVar4 = *DAT_021a5d98;
  if (iVar4 != 0) {
    switch(*(undefined4 *)(iVar4 + DAT_021a5d9c)) {
    default:
      func_0x0200fcb4(uVar2);
      return 1;
    case 1:
      func_0x0200fcb4();
      return 0;
    case 3:
    case 9:
    case 0xc:
      goto switchD_021a5c58_caseD_3;
    case 6:
      FUN_021a57fc(0xd);
      *(undefined2 *)(*DAT_021a5d98 + DAT_021a5da0) = 9;
      func_0x0200fcb4(uVar2);
      return 3;
    case 0xd:
      func_0x0200fcb4();
      return 2;
    }
  }
  func_0x0200fcb4();
  return 1;
switchD_021a5c58_caseD_3:
  if (*(char *)(iVar4 + DAT_021a5da4) == '\x01') {
    FUN_021a57fc(0xd);
    *(undefined2 *)(*DAT_021a5d98 + DAT_021a5da0) = 9;
  }
  else {
    psVar3 = (short *)func_0x0214259c();
    func_0x0200ee3c((uint)(uintptr_t)(psVar3),2);
    sVar1 = *psVar3;
    if (sVar1 == 0) {
      iVar4 = func_0x02142c24();
      if (iVar4 == 0) {
        FUN_021a57fc(1);
        *(undefined2 *)(*DAT_021a5d98 + DAT_021a5da0) = 0;
        func_0x0200fcb4(uVar2);
        return 0;
      }
    }
    else if (sVar1 == 1) {
      iVar4 = func_0x02143f08(DAT_021a5da8);
    }
    else if (sVar1 == 2) {
      iVar4 = func_0x02143e78(DAT_021a5da8);
    }
    else {
      *(undefined1 *)(*DAT_021a5d98 + DAT_021a5da4) = 1;
      iVar4 = func_0x02143dd0(DAT_021a5dac);
    }
    if (iVar4 != 2) {
      if ((iVar4 != 3) && (iVar4 == 8)) {
        func_0x0200fcb4(uVar2);
        return 4;
      }
      FUN_021a57fc(0xb);
      func_0x0200fcb4(uVar2);
      return 7;
    }
    FUN_021a57fc(0xd);
    *(undefined2 *)(*DAT_021a5d98 + DAT_021a5da0) = 9;
  }
  func_0x0200fcb4(uVar2);
  return 3;
}

