/* Decompiled C draft; module arm9; ROM address 02025a50. No matching claim. */
#include "types.h"
#include "deps/02025a50_func_02025a50.h"

void func_02025a50(int param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  
  func_02124ed0(param_2,param_3[3],param_3[5],param_3 + 6);
  if (param_1 == 0) {
    uVar1 = 0x13;
    AllocateReserveTEQSub(0xe,0,*(undefined4 *)(param_3[1] + 0xc),uRam02025ab4);
    AllocateReserveTEQSub(0xe,iRam02025ab8,*(int *)(param_3[1] + 0xc) + iRam02025ab8,0x40);
  }
  else {
    uVar1 = 0x23;
    AllocateReserveTEQSub(0x1e,0,*(undefined4 *)(param_3[1] + 0xc),*(undefined4 *)(param_3[1] + 8));
  }
  AllocateReserveTEQSub(uVar1,0,*(undefined4 *)(*param_3 + 0x14),*(undefined4 *)(*param_3 + 0x10));
  return;
}

