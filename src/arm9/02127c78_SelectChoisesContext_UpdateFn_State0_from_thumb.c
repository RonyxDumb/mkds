/* Decompiled C draft; module arm9; ROM address 02127c78. No matching claim. */
#include "types.h"
#include "deps/02127c78_SelectChoisesContext_UpdateFn_State0_from_thumb.h"

void SelectChoisesContext_UpdateFn_State0_from_thumb(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (*(int *)(*piRam02127d10 + 0x24) != 0) {
    SelectChoisesContext_UpdateGraphics_from_thumb();
    *(undefined4 *)(*piRam02127d10 + 8) = 1;
    local_20 = 0;
    *(undefined4 *)(*piRam02127d10 + 0x24) = 0;
    *(undefined4 *)(*piRam02127d10 + 0xc) = 0;
    *(undefined4 *)(*piRam02127d10 + 0x20) = 0;
    if (*(int *)(*piRam02127d10 + iRam02127d14) != 0) {
      iVar3 = 0;
      local_1c = 0;
      iVar4 = iVar3;
      do {
        iVar1 = 5;
        iVar2 = local_1c;
        do {
          if (*psRam02127d18 != 2) {
            AllocateReserveTEQSub
                      (0x14,(*(int *)(*piRam02127d10 + iRam02127d1c) + (iVar2 + iVar3) * 0x20 + 5) *
                            0x20,*(int *)(iVar4 + *piRam02127d10 + iRam02127d20) + iVar1 * 0x20,
                       uRam02127d24);
          }
          iVar1 = iVar1 + 0x20;
          iVar2 = iVar2 + 1;
        } while (iVar2 < 2);
        iVar3 = iVar3 + 2;
        iVar4 = iVar4 + 4;
        local_20 = local_20 + 1;
      } while (local_20 < 2);
    }
  }
  return;
}

