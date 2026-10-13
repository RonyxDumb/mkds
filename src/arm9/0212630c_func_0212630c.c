/* Decompiled C draft; module arm9; ROM address 0212630c. No matching claim. */
#include "types.h"
#include "deps/0212630c_func_0212630c.h"

void func_0212630c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                  undefined4 param_9)

{
  int *piVar1;
  
  (**(code **)(*piRam0212641c + iRam02126420 + 0x18))(*piRam0212641c + iRam02126420,0xf);
  (**(code **)(*piRam0212641c + iRam02126424 + 0x18))(*piRam0212641c + iRam02126424,0xe);
  (**(code **)(*piRam0212641c + iRam02126428 + 0x18))(*piRam0212641c + iRam02126428,0xd);
  G2d_Text_SomeFn_from_thumb
            (*piRam0212641c + iRam02126434,0,0,(uint)*pbRam0212642c << 3,(uint)pbRam0212642c[1] << 3
             ,1,uRam02126430,1,param_1);
  G2d_Text_SomeFn_1_from_thumb
            (*piRam0212641c + iRam02126438,0,0,(uint)pbRam0212642c[10] << 3,
             (uint)pbRam0212642c[0xb] << 3,2,uRam02126430,1,param_2);
  G2d_Text_SomeFn_1_from_thumb
            (*piRam0212641c + iRam0212643c,0,0,(uint)pbRam0212642c[0xc] << 3,
             (uint)pbRam0212642c[0xd] << 3,2,uRam02126430,1,param_3);
  TextSystemContext_DisableAllSprites_from_thumb();
  piVar1 = piRam0212641c;
  *(undefined4 *)(*piRam0212641c + iRam02126440) = 1;
  *(undefined4 *)(*piVar1 + iRam02126444) = 1;
  *(undefined4 *)(*piVar1 + iRam02126448) = 1;
  TextSystemContext_StartDialog_from_thumb();
  piVar1 = piRam0212641c;
  *(undefined4 *)(*piRam0212641c + 0x28) = 2;
  *(undefined4 *)(*piVar1 + 0x2c) = param_4;
  *(undefined4 *)(*piVar1 + 0x30) = 0;
  *(undefined4 *)(*piVar1 + 0x20) = param_9;
  *(undefined4 *)(*piVar1 + 0x24) = 0;
  *(undefined4 *)(*piVar1 + iRam0212644c) = param_5;
  *(undefined4 *)(*piVar1 + iRam02126450) = param_6;
  *(undefined4 *)(*piVar1 + 0x3c) = param_7;
  *(undefined4 *)(*piVar1 + 0x40) = param_8;
  return;
}

