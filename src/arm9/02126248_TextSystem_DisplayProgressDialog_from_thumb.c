/* Decompiled C draft; module arm9; ROM address 02126248. No matching claim. */
#include "types.h"
#include "deps/02126248_TextSystem_DisplayProgressDialog_from_thumb.h"

void TextSystem_DisplayProgressDialog_from_thumb
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  int *piVar1;
  
  (**(code **)(*piRam021262d0 + iRam021262d4 + 0x18))(*piRam021262d0 + iRam021262d4,0xf);
  G2d_Text_SomeFn_from_thumb
            (*piRam021262d0 + iRam021262e0,0,0,(uint)*(byte *)(iRam021262d8 + 4) << 3,
             (uint)*(byte *)(iRam021262d8 + 5) << 3,1,uRam021262dc,1,param_1);
  TextSystemContext_DisableAllSprites_from_thumb();
  *(undefined4 *)(*piRam021262d0 + iRam021262e4) = 1;
  TextSystemContext_StartDialog_from_thumb();
  piVar1 = piRam021262d0;
  *(undefined4 *)(*piRam021262d0 + 0x28) = 0;
  *(undefined4 *)(*piVar1 + 0x30) = 0;
  *(undefined4 *)(*piVar1 + 0x20) = 0;
  *(undefined4 *)(*piVar1 + 0x24) = param_6;
  *(undefined4 *)(*piVar1 + iRam021262e8) = param_2;
  *(undefined4 *)(*piVar1 + iRam021262ec) = param_3;
  *(undefined4 *)(*piVar1 + 0x3c) = param_4;
  *(undefined4 *)(*piVar1 + 0x40) = param_5;
  return;
}

