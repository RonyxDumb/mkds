/* Decompiled C draft; module arm9; ROM address 02126834. No matching claim. */
#include "types.h"
#include "deps/02126834_TextSystemContext_OnSceneUpdate_from_thumb.h"

void TextSystemContext_OnSceneUpdate_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  piVar1 = DAT_021268ec;
  puVar3 = (undefined4 *)*DAT_021268ec;
  if (puVar3[0x14] != 0) {
    puVar3[2] = *puVar3;
    puVar3 = (undefined4 *)*piVar1;
    *puVar3 = puVar3[1];
    switch(*(undefined4 *)*piVar1) {
    case 0:
      TextSystemContext_UpdateFn_State0_from_thumb();
      break;
    case 1:
      TextSystemContext_UpdateFn_State1_from_thumb();
      break;
    case 2:
      TextSystemContext_UpdateFn_State2_from_thumb();
      break;
    case 3:
      TextSystemContext_UpdateFn_State3_from_thumb();
      break;
    case 4:
      TextSystemContext_UpdateFn_State4_from_thumb();
    }
    iVar2 = *DAT_021268ec;
    if ((*(int *)(iVar2 + 0x18) != 0) || (*(int *)(iVar2 + 0x1c) != 0)) {
      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
      piVar1 = DAT_021268ec;
      if (3 < *(int *)(*DAT_021268ec + 0x10)) {
        *(undefined4 *)(*DAT_021268ec + 0x10) = 0;
        iVar2 = *piVar1;
        *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 1;
        iVar2 = *piVar1;
        if (2 < *(int *)(iVar2 + 0x14)) {
          *(undefined4 *)(iVar2 + 0x14) = 0;
        }
        TextSystemContext_UpdateAnimationGraphics_from_thumb();
        AllocateReserveTEQSub(10,0,*DAT_021268ec + 0x54,DAT_021268f0);
        AllocateReserveTEQSub(0x18,0,*DAT_021268ec + DAT_021268f4,DAT_021268f0);
      }
    }
  }
  return;
}

