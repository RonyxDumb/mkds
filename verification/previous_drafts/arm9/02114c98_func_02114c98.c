/* Decompiled C draft; module arm9; ROM address 02114c98. No matching claim. */
#include "types.h"
#include "deps/02114c98_func_02114c98.h"

void func_02114c98(void)

{
  int iVar1;
  
  iVar1 = TextSystem_IsDialogIdle_from_thumb();
  if (iVar1 != 0) {
    func_02115cec();
  }
  return;
}

