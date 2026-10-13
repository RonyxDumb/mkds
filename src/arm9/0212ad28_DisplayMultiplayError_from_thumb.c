/* Decompiled C draft; module arm9; ROM address 0212ad28. No matching claim. */
#include "types.h"
#include "deps/0212ad28_DisplayMultiplayError_from_thumb.h"

void DisplayMultiplayError_from_thumb(int param_1,undefined4 param_2)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  
  piVar1 = piRam0212ae04;
  if ((*(int *)(*piRam0212ae04 + 0xc) == 0) && (param_1 != -1)) {
    *(undefined4 *)(*piRam0212ae04 + 0xc) = 1;
    *(undefined4 *)(*piVar1 + 4) = param_2;
    *(int *)*piVar1 = param_1;
    uVar4 = GetMultiplayerErrorString_from_thumb();
    *(undefined4 *)(*piVar1 + 8) = uVar4;
    if (*(int *)*piVar1 == 4) {
      MaybeFormatMultiplayNetErrorCode_from_thumb();
    }
    DrawMultiplayError_from_thumb();
    iVar5 = GetCurrentSceneId();
    uVar3 = uRam0212ae0c;
    puVar2 = puRam0212ae08;
    if (iVar5 == 2) {
      iVar5 = func_020b19a0();
      uVar3 = uRam0212ae0c;
      puVar2 = puRam0212ae08;
      if (iVar5 == 0) {
        *puRam0212ae08 = *puRam0212ae08 & uRam0212ae0c | uRam0212ae10;
        *puRam0212ae14 = *puRam0212ae14 & uVar3;
        *puRam0212ae18 = 0;
        *puVar2 = *puVar2 & uRam0212ae1c;
      }
      else {
        *puRam0212ae08 =
             *puRam0212ae08 & uRam0212ae0c | ((*puRam0212ae08 & uRam0212ae20) >> 8 | 2) << 8;
      }
      UpdateBldcntBldalphaBldy(puRam0212ae24,0x1d,0,8,8,0xfffffff5);
      return;
    }
    *puRam0212ae08 = *puRam0212ae08 & uRam0212ae0c | uRam0212ae10;
    *puRam0212ae14 = *puRam0212ae14 & uVar3;
    *puRam0212ae18 = 0;
    *puVar2 = *puVar2 & uRam0212ae1c;
    *puRam0212ae24 = 0;
    *puRam0212ae28 = 0;
  }
  return;
}

