/* Decompiled C draft; module arm9; ROM address 02126138. No matching claim. */
#include "types.h"
#include "deps/02126138_TextSystem_DisplaySingleButtonDialog_from_thumb.h"

void TextSystem_DisplaySingleButtonDialog_from_thumb
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  int *piVar1;
  
  (**(code **)(*piRam02126204 + iRam02126208 + 0x18))(*piRam02126204 + iRam02126208,0xf);
  (**(code **)(*piRam02126204 + iRam0212620c + 0x18))(*piRam02126204 + iRam0212620c,0xe);
  G2d_Text_SomeFn_from_thumb
            (*piRam02126204 + iRam02126218,0,0,(uint)*(byte *)(iRam02126210 + 4) << 3,
             (uint)*(byte *)(iRam02126210 + 5) << 3,1,uRam02126214,1,param_1);
  G2d_Text_SomeFn_1_from_thumb
            (*piRam02126204 + iRam0212621c,0,0,(uint)*(byte *)(iRam02126210 + 8) << 3,
             (uint)*(byte *)(iRam02126210 + 9) << 3,2,uRam02126214,1,param_2);
  TextSystemContext_DisableAllSprites_from_thumb();
  piVar1 = piRam02126204;
  *(undefined4 *)(*piRam02126204 + iRam02126220) = 1;
  *(undefined4 *)(*piVar1 + iRam02126224) = 1;
  TextSystemContext_StartDialog_from_thumb();
  piVar1 = piRam02126204;
  *(undefined4 *)(*piRam02126204 + 0x28) = 1;
  *(undefined4 *)(*piVar1 + 0x2c) = 0;
  *(undefined4 *)(*piVar1 + 0x30) = 0;
  *(undefined4 *)(*piVar1 + 0x20) = 0;
  *(undefined4 *)(*piVar1 + 0x24) = 0;
  *(undefined4 *)(*piVar1 + iRam02126228) = param_3;
  *(undefined4 *)(*piVar1 + iRam0212622c) = param_4;
  *(undefined4 *)(*piVar1 + 0x3c) = param_5;
  *(undefined4 *)(*piVar1 + 0x40) = param_6;
  return;
}

