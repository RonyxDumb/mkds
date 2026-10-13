/* Decompiled C draft; module arm9_ov003; ROM address 021cd4ac. No matching claim. */
#include "types.h"
#include "deps/021cd4ac_FUN_021cd4ac.h"

void FUN_021cd4ac(int param_1)

{
  int iVar1;
  
  iVar1 = *DAT_021cd4d8 + param_1 * 0x100;
  func_0x0214d168((uint *)(uintptr_t)(iVar1),0,0xef);
  *(undefined1 *)(iVar1 + 0xe7) = 0xff;
  FUN_021cd338(param_1);
  return;
}

