/* Decompiled C draft; module arm9_ov000; ROM address 021a6024. No matching claim. */
#include "types.h"
#include "deps/021a6024_FUN_021a6024.h"

undefined4 FUN_021a6024(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = func_0x0200fca0();
  if (*DAT_021a6098 == 0) {
    func_0x0200fcb4();
    return 1;
  }
  iVar2 = *(int *)(*DAT_021a6098 + DAT_021a609c);
  if (iVar2 == 3) {
    func_0x0200fcb4();
    return 0;
  }
  if (iVar2 == 6) {
    FUN_021a57fc(7);
    *(undefined2 *)(*DAT_021a6098 + DAT_021a60a0) = 4;
    func_0x0200fcb4(uVar1);
    return 3;
  }
  if (iVar2 != 7) {
    func_0x0200fcb4();
    return 1;
  }
  func_0x0200fcb4();
  return 2;
}

