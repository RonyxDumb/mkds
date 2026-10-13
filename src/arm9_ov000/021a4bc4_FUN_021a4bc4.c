/* Decompiled C draft; module arm9_ov000; ROM address 021a4bc4. No matching claim. */
#include "types.h"
#include "deps/021a4bc4_FUN_021a4bc4.h"

void FUN_021a4bc4(int param_1)

{
  short sVar1;
  ushort uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  short *psVar6;
  
  piVar3 = DAT_021a4dcc;
  if (*(short *)(param_1 + 2) == 0) {
    *(undefined1 *)(*DAT_021a4dcc + DAT_021a4dd0) = 0;
    *(undefined2 *)(*piVar3 + DAT_021a4dd4) = 0;
    switch(*(undefined4 *)(*piVar3 + DAT_021a4dd8)) {
    default:
      FUN_021a57fc(0xb);
      FUN_021a58a4(7,0,*(undefined4 *)(*DAT_021a4dcc + DAT_021a4dd8),DAT_021a4e20);
      return;
    case 5:
    case 6:
      FUN_021a57fc(3);
      FUN_021a58a4(1,0,0,DAT_021a4ddc);
      return;
    case 7:
      FUN_021a57fc(3);
      FUN_021a58a4(0,0,0,DAT_021a4de0);
      return;
    case 8:
      psVar6 = (short *)(*piVar3 + DAT_021a4de4);
      sVar1 = *psVar6;
      *psVar6 = 0;
      if (sVar1 == 0x12) {
        uVar2 = *(ushort *)(*piVar3 + DAT_021a4de8);
        if ((uVar2 & 0x24) != 0x24) {
          *(ushort *)(*piVar3 + DAT_021a4de8) = uVar2 | 0x24;
          uVar4 = *(uint *)(*piVar3 + DAT_021a4dec);
          iVar5 = func_0x021437d8(DAT_021a4df8,(ushort *)(uintptr_t)(*piVar3 + DAT_021a4dfc),0,
                                  (uVar4 & DAT_021a4df4) != DAT_021a4df4,
                                  (uVar4 & DAT_021a4df0) == DAT_021a4df0);
          if (iVar5 == 2) {
            return;
          }
          if ((iVar5 != 3) && (iVar5 == 8)) {
            FUN_021a57fc(0xc);
            FUN_021a58a4(1,*DAT_021a4dcc + DAT_021a4dfc,0x12,DAT_021a4e00);
            return;
          }
          FUN_021a57fc(0xb);
          FUN_021a58a4(7,*DAT_021a4dcc + DAT_021a4dfc,0x12,DAT_021a4e04);
          return;
        }
      }
      FUN_021a57fc(3);
      FUN_021a58a4(1,*DAT_021a4dcc + DAT_021a4dfc,sVar1,DAT_021a4e08);
      return;
    case 9:
    case 0xc:
      FUN_021a57fc(3);
      FUN_021a58a4(0,*DAT_021a4dcc + DAT_021a4dfc,1,DAT_021a4e0c);
      return;
    case 10:
      FUN_021a57fc(3);
      FUN_021a58a4(0,*DAT_021a4dcc + DAT_021a4dfc,0,DAT_021a4e10);
      return;
    case 0xd:
      iVar5 = func_0x02143e78(DAT_021a4e14);
      if (iVar5 != 2) {
        if ((iVar5 != 3) && (iVar5 == 8)) {
          FUN_021a57fc(0xc);
          FUN_021a58a4(1,0,0,DAT_021a4e18);
          return;
        }
        FUN_021a57fc(0xb);
        FUN_021a58a4(7,0,0,DAT_021a4e1c);
        return;
      }
    }
  }
  else {
    FUN_021a57fc(0xb);
    FUN_021a58a4(7,0,0,DAT_021a4e24);
  }
  return;
}

