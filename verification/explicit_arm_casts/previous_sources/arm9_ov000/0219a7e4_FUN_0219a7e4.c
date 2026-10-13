/* Decompiled C draft; module arm9_ov000; ROM address 0219a7e4. No matching claim. */
#include "types.h"
#include "deps/0219a7e4_FUN_0219a7e4.h"

void FUN_0219a7e4(undefined1 *param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 local_40 [8];
  uint local_38;
  undefined1 local_2c [8];
  uint local_24;
  
  puVar4 = local_40;
  iVar3 = FUN_0219b0ec();
  if (iVar3 != 0) {
    cVar1 = param_1[7];
    if ((cVar1 == '\x05') || (cVar1 == '\a')) {
      if (0x13 < param_2) {
        iVar3 = 0x14;
        do {
          uVar2 = *param_1;
          param_1 = param_1 + 1;
          *puVar4 = uVar2;
          puVar4 = puVar4 + 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        iVar3 = FUN_0219b1f8(local_38 << 0x18 & DAT_0219a8b0 |
                             local_38 << 8 & DAT_0219a8b4 |
                             local_38 >> 0x18 | local_38 >> 8 & DAT_0219a8b8);
        if (iVar3 != 0) {
          if (cVar1 == '\x05') {
            FUN_0219a9e4(iVar3,local_40,param_3);
            return;
          }
          FUN_0219a958(iVar3,local_40,param_3);
          return;
        }
      }
    }
    else if (0x14 < param_2) {
      puVar4 = local_2c;
      iVar3 = 0x15;
      do {
        uVar2 = *param_1;
        param_1 = param_1 + 1;
        *puVar4 = uVar2;
        puVar4 = puVar4 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      iVar3 = FUN_0219b1f8(local_24 << 0x18 & DAT_0219a8b0 |
                           local_24 << 8 & DAT_0219a8b4 |
                           local_24 >> 0x18 | local_24 >> 8 & DAT_0219a8b8);
      if (iVar3 != 0) {
        FUN_0219a8bc(iVar3,local_2c,param_3);
      }
    }
  }
  return;
}

