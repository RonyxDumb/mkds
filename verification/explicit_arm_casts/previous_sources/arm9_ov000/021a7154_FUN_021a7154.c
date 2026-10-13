/* Decompiled C draft; module arm9_ov000; ROM address 021a7154. No matching claim. */
#include "types.h"
#include "deps/021a7154_FUN_021a7154.h"

int FUN_021a7154(int param_1,int param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_021a72a4(param_3);
  func_0x0200eb90(param_2,param_1,*(undefined1 *)((int)param_3 + 3));
  func_0x0200edc0(param_2 + 0xe0);
  func_0x0200e28c(param_2 + 0x20,DAT_021a71a0,param_2,param_1 + iVar1,*param_3,
                  *(undefined1 *)(param_3 + 1));
  func_0x0200df68(param_2 + 0x20);
  return param_1 + iVar1;
}

