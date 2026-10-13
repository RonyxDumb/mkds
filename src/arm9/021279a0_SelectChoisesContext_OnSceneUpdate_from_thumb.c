/* Decompiled C draft; module arm9; ROM address 021279a0. No matching claim. */
#include "types.h"
#include "deps/021279a0_SelectChoisesContext_OnSceneUpdate_from_thumb.h"

void SelectChoisesContext_OnSceneUpdate_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar1 = piRam02127a2c;
  piVar3 = (int *)*piRam02127a2c;
  if (*piVar3 != 0) {
    piVar3[1] = piVar3[2];
    iVar2 = *(int *)(*piVar1 + 4);
    if (iVar2 == 0) {
      SelectChoisesContext_UpdateFn_State0_from_thumb();
    }
    else if (iVar2 == 1) {
      SelectChoisesContext_UpdateFn_State1_from_thumb();
    }
    else if (iVar2 == 2) {
      SelectChoisesContext_UpdateFn_State2_from_thumb();
    }
    piVar1 = piRam02127a2c;
    *(int *)(*piRam02127a2c + 0x10) = *(int *)(*piRam02127a2c + 0x10) + 1;
    iVar2 = *piVar1;
    iVar4 = *(int *)(iVar2 + 0x14);
    if (((iVar4 != 0) && (0x1e < *(int *)(iVar2 + 0x10))) ||
       ((iVar4 == 0 && (0x14 < *(int *)(iVar2 + 0x10))))) {
      *(uint *)(iVar2 + 0x14) = (uint)(iVar4 == 0);
      *(undefined4 *)(*piRam02127a2c + 0x10) = 0;
      func_02127e30();
      if (*psRam02127a30 != 2) {
        AllocateReserveTEQSub(0x18,0,*piRam02127a2c + 0x2c,uRam02127a34);
      }
    }
  }
  return;
}

