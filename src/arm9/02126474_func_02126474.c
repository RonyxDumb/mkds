/* Decompiled C draft; module arm9; ROM address 02126474. No matching claim. */
#include "types.h"
#include "deps/02126474_func_02126474.h"

void func_02126474(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  
  (**(code **)(*piRam02126544 + iRam02126548 + 0x18))(*piRam02126544 + iRam02126548,0xf);
  (**(code **)(*piRam02126544 + iRam0212654c + 0x18))(*piRam02126544 + iRam0212654c,0xe);
  G2d_Text_SomeFn_from_thumb
            (*piRam02126544 + iRam02126558,0,0,(uint)*pbRam02126550 << 3,(uint)pbRam02126550[1] << 3
             ,1,uRam02126554,1,param_1);
  G2d_Text_SomeFn_1_from_thumb
            (*piRam02126544 + iRam0212655c,0,0,(uint)pbRam02126550[8] << 3,
             (uint)pbRam02126550[9] << 3,2,uRam02126554,1,param_2);
  TextSystemContext_DisableAllSprites_from_thumb();
  piVar1 = piRam02126544;
  *(undefined4 *)(*piRam02126544 + iRam02126560) = 1;
  *(undefined4 *)(*piVar1 + iRam02126564) = 1;
  TextSystemContext_StartDialog_from_thumb();
  piVar1 = piRam02126544;
  *(undefined4 *)(*piRam02126544 + 0x28) = 1;
  *(undefined4 *)(*piVar1 + 0x2c) = 0;
  *(undefined4 *)(*piVar1 + 0x30) = 0;
  *(undefined4 *)(*piVar1 + 0x20) = param_7;
  *(undefined4 *)(*piVar1 + 0x24) = 0;
  *(undefined4 *)(*piVar1 + iRam02126568) = param_3;
  *(undefined4 *)(*piVar1 + iRam0212656c) = param_4;
  *(undefined4 *)(*piVar1 + 0x3c) = param_5;
  *(undefined4 *)(*piVar1 + 0x40) = param_6;
  return;
}

