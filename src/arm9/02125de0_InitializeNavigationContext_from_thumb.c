/* Decompiled C draft; module arm9; ROM address 02125de0. No matching claim. */
#include "types.h"
#include "deps/02125de0_InitializeNavigationContext_from_thumb.h"

void InitializeNavigationContext_from_thumb(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  
  iVar3 = Mem_AllocateHeap(param_1,uRam02125eac);
  piVar1 = piRam02125eb0;
  *piRam02125eb0 = iVar3;
  iVar2 = iRam02125eb8;
  *(undefined4 *)(iVar3 + iRam02125eb8) = uRam02125eb4;
  *(undefined4 *)*piVar1 = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 8) = 0;
  if (*param_2 != 0) {
    local_20 = param_2[1];
    local_1c = param_2[2];
    local_18 = param_2[3];
    local_14 = param_2[4];
    local_10 = *(undefined4 *)(*piVar1 + iVar2);
    *(undefined4 *)*piVar1 = 1;
    uVar4 = TextSystemContext_Initialize_from_thumb(param_1,&local_20);
    *(undefined4 *)(*piRam02125eb0 + iRam02125eb8) = uVar4;
  }
  piVar1 = piRam02125eb0;
  if (param_2[5] != 0) {
    *(undefined4 *)(*piRam02125eb0 + 4) = 1;
    uVar4 = SelectChoisesContext_Initialize_from_thumb
                      (param_1,param_2[6],*(undefined4 *)(*piVar1 + iRam02125eb8));
    *(undefined4 *)(*piRam02125eb0 + iRam02125eb8) = uVar4;
  }
  piVar1 = piRam02125eb0;
  if (param_2[7] != 0) {
    *(undefined4 *)(*piRam02125eb0 + 8) = 1;
    uVar4 = SelectReturnContext_Initialize_from_thumb
                      (param_1,*(undefined4 *)(*piVar1 + iRam02125eb8));
    *(undefined4 *)(*piRam02125eb0 + iRam02125eb8) = uVar4;
  }
  if (param_2[8] != 0) {
    *(int *)(*piRam02125eb0 + 0xc) = param_2[9];
    InitializeBgForBackScreen_from_thumb();
    uVar4 = InitializeBackScreen_from_thumb(*(undefined4 *)(*piRam02125eb0 + iRam02125eb8));
    *(undefined4 *)(*piRam02125eb0 + iRam02125eb8) = uVar4;
  }
  return;
}

