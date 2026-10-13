/* Decompiled C draft; module arm9; ROM address 020562e8. No matching claim. */
#include "types.h"
#include "deps/020562e8_func_020562e8.h"

void func_020562e8(void)

{
  undefined1 uVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_18;
  
  CleanSaveDataHolderFlagBytes_from_thumb();
  piVar2 = piRam020563c0;
  uVar6 = 0;
  local_18 = 0;
  do {
    if (((uint)*(byte *)(*piRam020563c4 + iRam020563c8) & 1 << uVar6) != 0) {
      iVar4 = iRam020563cc * uVar6;
      uVar5 = local_18;
      do {
        pbVar3 = (byte *)(*piRam020563c4 + iRam020563d0 + iVar4 + iRam020563d4 + uVar5);
        if (uVar6 == 0) {
          *(byte *)(*piVar2 + uVar5 + 0x30) = *pbVar3;
          *(byte *)(*piVar2 + uVar5 + 0x34) = *pbVar3;
        }
        else {
          *(byte *)(*piVar2 + uVar5 + 0x30) = *(byte *)(*piVar2 + uVar5 + 0x30) & *pbVar3;
          *(byte *)(*piVar2 + uVar5 + 0x34) = *(byte *)(*piVar2 + uVar5 + 0x34) | *pbVar3;
        }
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 < 4);
      uVar5 = CheckExtraKartUnlockFlagsWith_from_thumb
                        (*piRam020563c4 + iRam020563d0 + iVar4 + iRam020563d4);
      uVar1 = (undefined1)uVar5;
      if (uVar6 == 0) {
        *(undefined1 *)(*piVar2 + 0x38) = uVar1;
        *(undefined1 *)(*piVar2 + 0x39) = uVar1;
      }
      else {
        if (*(byte *)(*piVar2 + 0x38) < uVar5) {
          *(undefined1 *)(*piVar2 + 0x38) = uVar1;
        }
        if (uVar5 < *(byte *)(*piVar2 + 0x39)) {
          *(undefined1 *)(*piVar2 + 0x39) = uVar1;
        }
      }
    }
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 8);
  return;
}

