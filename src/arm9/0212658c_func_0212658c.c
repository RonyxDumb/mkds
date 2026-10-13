/* Decompiled C draft; module arm9; ROM address 0212658c. No matching claim. */
#include "types.h"
#include "deps/0212658c_func_0212658c.h"

void func_0212658c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  
  (**(code **)(*piRam02126618 + iRam0212661c + 0x18))(*piRam02126618 + iRam0212661c,0xf);
  G2d_Text_SomeFn_from_thumb
            (*piRam02126618 + iRam02126628,0,0,(uint)*(byte *)(iRam02126620 + 2) << 3,
             (uint)*(byte *)(iRam02126620 + 3) << 3,1,uRam02126624,1,param_1);
  TextSystemContext_DisableAllSprites_from_thumb();
  *(undefined4 *)(*piRam02126618 + iRam0212662c) = 1;
  TextSystemContext_StartDialog_from_thumb();
  piVar1 = piRam02126618;
  *(undefined4 *)(*piRam02126618 + 0x28) = 0;
  *(undefined4 *)(*piVar1 + 0x30) = 0;
  *(undefined4 *)(*piVar1 + 0x20) = param_6;
  *(undefined4 *)(*piVar1 + 0x24) = param_7;
  *(undefined4 *)(*piVar1 + iRam02126630) = param_2;
  *(undefined4 *)(*piVar1 + iRam02126634) = param_3;
  *(undefined4 *)(*piVar1 + 0x3c) = param_4;
  *(undefined4 *)(*piVar1 + 0x40) = param_5;
  return;
}

