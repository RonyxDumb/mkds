/* Decompiled C draft; module arm9; ROM address 02133fd8. No matching claim. */
#include "types.h"
#include "deps/02133fd8_OnAssertionFailed.h"

void OnAssertionFailed(void)

{
  func_02139e20(1);
  *puRam02134004 = 1;
  CheckZetaInvokeBeta();
  return;
}

