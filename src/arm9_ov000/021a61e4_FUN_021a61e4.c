/* Decompiled C draft; module arm9_ov000; ROM address 021a61e4. No matching claim. */
#include "types.h"
#include "deps/021a61e4_FUN_021a61e4.h"

undefined4 FUN_021a61e4(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = func_0x0200fca0();
  if (*DAT_021a628c == 0) {
    func_0x0200fcb4();
    return 1;
  }
  iVar2 = *(int *)(*DAT_021a628c + DAT_021a6290);
  if (iVar2 == 1) {
    func_0x0200fcb4();
    return 0;
  }
  if (iVar2 != 3) {
    if (iVar2 != 4) {
      func_0x0200fcb4();
      return 1;
    }
    func_0x0200fcb4();
    return 2;
  }
  iVar2 = func_0x02143e78(DAT_021a6294);
  if (iVar2 == 2) {
    FUN_021a57fc(4);
    *(undefined2 *)(*DAT_021a628c + DAT_021a6298) = 2;
    func_0x0200fcb4(uVar1);
    return 3;
  }
  if ((iVar2 != 3) && (iVar2 == 8)) {
    func_0x0200fcb4(uVar1);
    return 4;
  }
  FUN_021a57fc(0xb);
  func_0x0200fcb4(uVar1);
  return 7;
}

