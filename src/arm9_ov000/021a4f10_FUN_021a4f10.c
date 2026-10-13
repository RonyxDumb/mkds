/* Decompiled C draft; module arm9_ov000; ROM address 021a4f10. No matching claim. */
#include "types.h"
#include "deps/021a4f10_FUN_021a4f10.h"

void FUN_021a4f10(int param_1)

{
  if (*(short *)(param_1 + 2) != 0) {
    FUN_021a57fc(0xb);
    FUN_021a58a4(7,*DAT_021a4fc4 + DAT_021a4fcc,0,DAT_021a4fdc);
    return;
  }
  if (*(short *)(param_1 + 4) != 0xe) {
    if (*(short *)(param_1 + 4) != 0xf) {
      FUN_021a57fc(0xb);
      FUN_021a58a4(7,*DAT_021a4fc4 + DAT_021a4fcc,*(undefined2 *)(param_1 + 4),DAT_021a4fd8);
      return;
    }
    FUN_021a6c08((int)(uint)*(ushort *)(*(int *)(param_1 + 8) + 0xe) >> 8);
    func_0x0200ee3c(*(undefined4 *)(param_1 + 8),DAT_021a4fd4);
    FUN_021a6bb4(*(undefined4 *)(param_1 + 8));
    return;
  }
  if (*(int *)(*DAT_021a4fc4 + DAT_021a4fc8) == 0xc) {
    FUN_021a57fc(8);
    FUN_021a574c();
    return;
  }
  FUN_021a57fc(9);
  FUN_021a58a4(0,*DAT_021a4fc4 + DAT_021a4fcc,0,DAT_021a4fd0);
  return;
}

