/* Decompiled C draft; module arm9_ov000; ROM address 021a4e28. No matching claim. */
#include "types.h"
#include "deps/021a4e28_FUN_021a4e28.h"

void FUN_021a4e28(int param_1)

{
  int iVar1;
  
  switch(*(undefined2 *)(param_1 + 2)) {
  case 0:
    if (*(int *)(*DAT_021a4ef4 + DAT_021a4ef8) == 0xc) {
      FUN_021a57fc(10);
      FUN_021a574c();
      return;
    }
    iVar1 = func_0x021436d0(DAT_021a4efc,0);
    if (iVar1 != 2) {
      if (iVar1 == 3) {
        FUN_021a57fc(10);
        FUN_021a574c();
        return;
      }
      if (iVar1 == 8) {
        FUN_021a57fc(0xc);
        FUN_021a58a4(1,*DAT_021a4ef4 + DAT_021a4f00,0,DAT_021a4f04);
        return;
      }
      FUN_021a57fc(0xb);
      FUN_021a58a4(7,*DAT_021a4ef4 + DAT_021a4f00,0,DAT_021a4f08);
      return;
    }
    break;
  case 1:
  case 3:
    FUN_021a57fc(10);
    FUN_021a574c();
    return;
  default:
    FUN_021a57fc(0xb);
    FUN_021a58a4(7,*DAT_021a4ef4 + DAT_021a4f00,0,DAT_021a4f0c);
  }
  return;
}

