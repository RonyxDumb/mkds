/* Decompiled C draft; module arm9; ROM address 021156bc. No matching claim. */
#include "types.h"
#include "deps/021156bc_func_021156bc.h"

void func_021156bc(void)

{
  int iVar1;
  
  iVar1 = TextSystem_IsDialogIdle_from_thumb();
  if (iVar1 != 0) {
    func_02115e60();
  }
  return;
}

