/* Decompiled C draft; module arm9; ROM address 02125fd4. No matching claim. */
#include "types.h"
#include "deps/02125fd4_TextSystem_DisplayDoubleButtonDialog_from_thumb.h"

void TextSystem_DisplayDoubleButtonDialog_from_thumb
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  
  (**(code **)(*piRam021260e4 + iRam021260e8 + 0x18))(*piRam021260e4 + iRam021260e8,0xf);
  (**(code **)(*piRam021260e4 + iRam021260ec + 0x18))(*piRam021260e4 + iRam021260ec,0xe);
  (**(code **)(*piRam021260e4 + iRam021260f0 + 0x18))(*piRam021260e4 + iRam021260f0,0xd);
  G2d_Text_SomeFn_from_thumb
            (*piRam021260e4 + iRam021260fc,0,0,(uint)*(byte *)(iRam021260f4 + 4) << 3,
             (uint)*(byte *)(iRam021260f4 + 5) << 3,1,uRam021260f8,1,param_1);
  G2d_Text_SomeFn_1_from_thumb
            (*piRam021260e4 + iRam02126100,0,0,(uint)*(byte *)(iRam021260f4 + 10) << 3,
             (uint)*(byte *)(iRam021260f4 + 0xb) << 3,2,uRam021260f8,1,param_2);
  G2d_Text_SomeFn_1_from_thumb
            (*piRam021260e4 + iRam02126104,0,0,(uint)*(byte *)(iRam021260f4 + 0xc) << 3,
             (uint)*(byte *)(iRam021260f4 + 0xd) << 3,2,uRam021260f8,1,param_3);
  TextSystemContext_DisableAllSprites_from_thumb();
  piVar1 = piRam021260e4;
  *(undefined4 *)(*piRam021260e4 + iRam02126108) = 1;
  *(undefined4 *)(*piVar1 + iRam0212610c) = 1;
  *(undefined4 *)(*piVar1 + iRam02126110) = 1;
  TextSystemContext_StartDialog_from_thumb();
  piVar1 = piRam021260e4;
  *(undefined4 *)(*piRam021260e4 + 0x28) = 2;
  *(undefined4 *)(*piVar1 + 0x2c) = param_4;
  *(undefined4 *)(*piVar1 + 0x30) = 0;
  *(undefined4 *)(*piVar1 + 0x20) = 0;
  *(undefined4 *)(*piVar1 + 0x24) = 0;
  *(undefined4 *)(*piVar1 + iRam02126114) = param_5;
  *(undefined4 *)(*piVar1 + iRam02126118) = param_6;
  *(undefined4 *)(*piVar1 + 0x3c) = param_7;
  *(undefined4 *)(*piVar1 + 0x40) = param_8;
  return;
}

