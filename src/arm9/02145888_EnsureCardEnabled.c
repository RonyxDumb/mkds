/* Decompiled C draft; module arm9; ROM address 02145888. No matching claim. */
#include "types.h"
#include "deps/02145888_EnsureCardEnabled.h"

void EnsureCardEnabled(void)

{
  int iVar1;
  
  iVar1 = Card_IsEnabled();
  if (iVar1 == 0) {
    Os_Terminate();
    return;
  }
  return;
}

