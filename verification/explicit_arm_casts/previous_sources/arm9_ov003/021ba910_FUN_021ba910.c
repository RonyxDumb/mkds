/* Decompiled C draft; module arm9_ov003; ROM address 021ba910. No matching claim. */
#include "types.h"
#include "deps/021ba910_FUN_021ba910.h"

undefined4 FUN_021ba910(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = func_0x0200fca0();
  *DAT_021ba9b0 = param_3;
  if (param_2 == 0) {
    func_0x0214d168(*DAT_021ba9b4,0,0x50);
  }
  else {
    func_0x0214d1fc(param_2,*DAT_021ba9b4,0x50);
  }
  func_0x0214d02c(param_1,*DAT_021ba9b8,0xc0);
  iVar2 = FUN_021bac0c();
  if (iVar2 == 1) {
    *DAT_021ba9bc = 8;
    func_0x0200fcb4(uVar1);
    return 1;
  }
  if ((*DAT_021ba9bc == 3) &&
     (iVar2 = func_0x021a5e84(*DAT_021ba9b8,*DAT_021ba9b4,*DAT_021ba9b0), iVar2 == 3)) {
    *DAT_021ba9bc = 8;
    func_0x0200fcb4(uVar1);
    return 1;
  }
  func_0x0200fcb4(uVar1);
  return 0;
}

