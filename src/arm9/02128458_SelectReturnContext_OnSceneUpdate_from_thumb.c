/* Decompiled C draft; module arm9; ROM address 02128458. No matching claim. */
#include "types.h"
#include "deps/02128458_SelectReturnContext_OnSceneUpdate_from_thumb.h"

void SelectReturnContext_OnSceneUpdate_from_thumb(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = DAT_021284bc;
  piVar2 = (int *)*DAT_021284bc;
  if (*piVar2 != 0) {
    piVar2[1] = piVar2[2];
    switch(*(undefined4 *)(*piVar1 + 4)) {
    case 0:
      func_021285f8();
      return;
    case 1:
      func_021285b0();
      return;
    case 2:
      func_02128570();
      return;
    case 3:
      func_02128508();
      return;
    case 4:
      func_021284c0();
    }
  }
  return;
}

