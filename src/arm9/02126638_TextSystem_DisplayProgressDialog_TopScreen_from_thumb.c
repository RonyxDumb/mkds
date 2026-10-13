/* Decompiled C draft; module arm9; ROM address 02126638. No matching claim. */
#include "types.h"
#include "deps/02126638_TextSystem_DisplayProgressDialog_TopScreen_from_thumb.h"

void TextSystem_DisplayProgressDialog_TopScreen_from_thumb
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  
  (**(code **)(*piRam021266c4 + iRam021266c8 + 0x18))(*piRam021266c4 + iRam021266c8,0xf);
  G2d_Text_SomeFn_from_thumb
            (*piRam021266c4 + iRam021266d4,0,0,(uint)*pbRam021266cc << 3,(uint)pbRam021266cc[1] << 3
             ,1,uRam021266d0,1,param_1);
  TextSystemContext_DisableAllSprites_from_thumb();
  *(undefined4 *)(*piRam021266c4 + iRam021266d8) = 1;
  TextSystemContext_StartDialog_from_thumb();
  piVar1 = piRam021266c4;
  *(undefined4 *)(*piRam021266c4 + 0x28) = 0;
  *(undefined4 *)(*piVar1 + 0x30) = 0;
  *(undefined4 *)(*piVar1 + 0x20) = param_6;
  *(undefined4 *)(*piVar1 + 0x24) = param_7;
  *(undefined4 *)(*piVar1 + iRam021266dc) = param_2;
  *(undefined4 *)(*piVar1 + iRam021266e0) = param_3;
  *(undefined4 *)(*piVar1 + 0x3c) = param_4;
  *(undefined4 *)(*piVar1 + 0x40) = param_5;
  return;
}

