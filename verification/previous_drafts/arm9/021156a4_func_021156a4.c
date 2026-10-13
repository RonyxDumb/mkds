/* Decompiled C draft; module arm9; ROM address 021156a4. No matching claim. */
#include "types.h"
#include "deps/021156a4_func_021156a4.h"

void func_021156a4(void)

{
  int iVar1;
  
  iVar1 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
  if (iVar1 != 0) {
    func_02115e44();
  }
  return;
}

