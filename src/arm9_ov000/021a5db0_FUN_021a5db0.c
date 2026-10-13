/* Decompiled C draft; module arm9_ov000; ROM address 021a5db0. No matching claim. */
#include "types.h"
#include "deps/021a5db0_FUN_021a5db0.h"

undefined4 FUN_021a5db0(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = func_0x0200fca0();
  iVar3 = *DAT_021a5e70;
  if (iVar3 == 0) {
    func_0x0200fcb4();
    return 1;
  }
  iVar2 = *(int *)(iVar3 + DAT_021a5e74);
  if (iVar2 != 3) {
    if (iVar2 != 9) {
      if (iVar2 != 10) {
        func_0x0200fcb4();
        return 1;
      }
      func_0x0200fcb4();
      return 2;
    }
    if (*(char *)(iVar3 + DAT_021a5e78) == '\x01') {
      FUN_021a57fc(10);
      *(undefined2 *)(*DAT_021a5e70 + DAT_021a5e7c) = 6;
    }
    else {
      iVar3 = func_0x021443b0(DAT_021a5e80);
      if (iVar3 != 2) {
        if ((iVar3 != 3) && (iVar3 == 8)) {
          func_0x0200fcb4(uVar1);
          return 4;
        }
        FUN_021a57fc(0xb);
        func_0x0200fcb4(uVar1);
        return 7;
      }
      FUN_021a57fc(10);
      *(undefined2 *)(*DAT_021a5e70 + DAT_021a5e7c) = 6;
    }
    func_0x0200fcb4(uVar1);
    return 3;
  }
  func_0x0200fcb4();
  return 0;
}

