/* Decompiled C draft; module arm9_ov003; ROM address 021be708. No matching claim. */
#include "types.h"
#include "deps/021be708_FUN_021be708.h"

undefined4 FUN_021be708(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = func_0x0200fca0();
  *DAT_021be7a8 = param_3;
  if (param_2 == 0) {
    func_0x0214d168(*DAT_021be7ac,0,0x60);
  }
  else {
    func_0x0214d1fc(param_2,*DAT_021be7ac,0x60);
  }
  func_0x0214d02c(param_1,*DAT_021be7b0,0xc0);
  iVar2 = FUN_021be9b8();
  if (iVar2 == 1) {
    *DAT_021be7b4 = 8;
    func_0x0200fcb4(uVar1);
    return 1;
  }
  if ((*DAT_021be7b4 == 3) &&
     (iVar2 = func_0x021a5e84(*DAT_021be7b0,*DAT_021be7ac,*DAT_021be7a8), iVar2 == 3)) {
    *DAT_021be7b4 = 8;
    func_0x0200fcb4(uVar1);
    return 1;
  }
  func_0x0200fcb4(uVar1);
  return 0;
}

