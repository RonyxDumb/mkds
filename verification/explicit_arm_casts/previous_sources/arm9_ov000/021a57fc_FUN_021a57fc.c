/* Decompiled C draft; module arm9_ov000; ROM address 021a57fc. No matching claim. */
#include "types.h"
#include "deps/021a57fc_FUN_021a57fc.h"

void FUN_021a57fc(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_0x0200fca0();
  if ((*(int *)(*DAT_021a5858 + DAT_021a585c) == 9) && (param_1 != 9)) {
    func_0x0200f8b8(*DAT_021a5858 + DAT_021a5860);
  }
  if (*(int *)(*DAT_021a5858 + DAT_021a585c) != 0xb) {
    *(int *)(*DAT_021a5858 + DAT_021a585c) = param_1;
  }
  if (param_1 == 9) {
    func_0x0200f950(*DAT_021a5858 + DAT_021a5860,DAT_021a5864,0,DAT_021a5868,0);
  }
  func_0x0200fcb4(uVar1);
  return;
}

