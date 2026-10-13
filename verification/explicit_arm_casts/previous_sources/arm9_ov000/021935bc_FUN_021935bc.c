/* Decompiled C draft; module arm9_ov000; ROM address 021935bc. No matching claim. */
#include "types.h"
#include "deps/021935bc_FUN_021935bc.h"

undefined4 FUN_021935bc(undefined4 param_1,uint param_2,uint *param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (int)param_2 >> 0x18 & 0xff;
  uVar3 = (int)param_2 >> 0x10 & 0xff;
  param_2 = param_2 & DAT_02193624;
  iVar1 = FUN_02193634(uVar2,uVar3,param_2);
  if (iVar1 == 0) {
    func_0x0213442c(DAT_02193628,DAT_0219362c,0,0xb7);
  }
  iVar1 = FUN_02193634(uVar2,uVar3,param_2);
  if (iVar1 == 0) {
    FUN_02196590(param_1,DAT_02193630);
    return 2;
  }
  *param_3 = uVar2;
  *param_4 = uVar3;
  *param_5 = param_2;
  return 0;
}

