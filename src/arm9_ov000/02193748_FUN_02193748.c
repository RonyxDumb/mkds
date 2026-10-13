/* Decompiled C draft; module arm9_ov000; ROM address 02193748. No matching claim. */
#include "types.h"
#include "deps/02193748_FUN_02193748.h"

int FUN_02193748(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  switch(*param_2) {
  case 0:
    iVar1 = FUN_02191284();
    break;
  case 1:
    iVar1 = FUN_02194a0c();
    break;
  case 2:
    iVar1 = FUN_02192e04();
    break;
  default:
    FUN_0219690c(param_1,DAT_021937b0,*param_2);
    func_0x0213442c(DAT_021937b4,DAT_021937b8,0,DAT_021937bc);
    break;
  case 4:
    iVar1 = FUN_021964e4();
  }
  if (iVar1 != 0) {
    param_2[7] = iVar1;
  }
  return iVar1;
}

