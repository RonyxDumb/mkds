/* Decompiled C draft; module arm9; ROM address 021457cc. No matching claim. */
#include "types.h"
#include "deps/021457cc_Card_LockRomResource.h"

void Card_LockRomResource(undefined4 param_1)

{
  Card_LockResource(param_1,1);
  Os_TryLockCard(param_1);
  return;
}

