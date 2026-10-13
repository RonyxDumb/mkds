/* Decompiled C draft; module arm9_ov000; ROM address 021a54b0. No matching claim. */
#include "types.h"
#include "deps/021a54b0_FUN_021a54b0.h"

void FUN_021a54b0(ushort *param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0x14;
  switch(param_1[1]) {
  case 0:
    uVar1 = *param_1;
    if (uVar1 < 0x1a) {
      if (uVar1 < 0x19) {
        switch(uVar1) {
        case 3:
          iVar2 = func_0x02143ec0(DAT_021a569c);
          break;
        case 4:
          iVar2 = func_0x02142c24();
          if (iVar2 != 0) {
            FUN_021a57fc(0xb);
            FUN_021a58a4(7,0,0,DAT_021a56a4);
            return;
          }
          FUN_021a57fc(1);
          FUN_021a58a4(0,0,0,DAT_021a56a0);
          return;
        case 5:
          FUN_021a57fc(3);
          FUN_021a58a4(0,0,0,DAT_021a56a8);
          return;
        case 6:
          iVar2 = func_0x02143f08(DAT_021a569c);
        }
      }
      else {
        iVar2 = *DAT_021a56ac;
        iVar2 = func_0x02145668(DAT_021a569c,*(undefined1 *)(iVar2 + DAT_021a56b0),
                                *(undefined1 *)(iVar2 + DAT_021a56b4),iVar2 + DAT_021a56b8);
      }
    }
    else if (uVar1 < 0x1e) {
      if (uVar1 == 0x1d) {
        iVar2 = func_0x02145530(DAT_021a569c,0);
      }
    }
    else if (uVar1 == 0x27) {
      uVar3 = *(uint *)(*DAT_021a56ac + DAT_021a56bc);
      iVar2 = func_0x021437d8(DAT_021a56c8,(ushort *)(uintptr_t)(*DAT_021a56ac + DAT_021a56cc),0,
                              (uVar3 & DAT_021a56c4) != DAT_021a56c4,
                              (uVar3 & DAT_021a56c0) == DAT_021a56c0);
    }
    if (iVar2 != 2) {
      if ((iVar2 != 3) && (iVar2 == 8)) {
        FUN_021a57fc(0xc);
        if (*(short *)(*DAT_021a56ac + DAT_021a56d0) == 5) {
          iVar2 = *DAT_021a56ac + DAT_021a56cc;
        }
        else {
          iVar2 = 0;
        }
        FUN_021a58a4(1,iVar2,0,DAT_021a56d4);
        return;
      }
      FUN_021a57fc(0xb);
      if (*(short *)(*DAT_021a56ac + DAT_021a56d0) == 5) {
        iVar2 = *DAT_021a56ac + DAT_021a56cc;
      }
      else {
        iVar2 = 0;
      }
      FUN_021a58a4(7,iVar2,0,DAT_021a56d8);
      return;
    }
    break;
  case 1:
    FUN_021a57fc(0xc);
    if (*(short *)(*DAT_021a56ac + DAT_021a56d0) == 5) {
      iVar2 = *DAT_021a56ac + DAT_021a56cc;
    }
    else {
      iVar2 = 0;
    }
    FUN_021a58a4(1,iVar2,0,DAT_021a56dc);
    return;
  default:
    FUN_021a57fc(0xb);
    if (*(short *)(*DAT_021a56ac + DAT_021a56d0) == 5) {
      iVar2 = *DAT_021a56ac + DAT_021a56cc;
    }
    else {
      iVar2 = 0;
    }
    FUN_021a58a4(7,iVar2,0,DAT_021a56e0);
  }
  return;
}

