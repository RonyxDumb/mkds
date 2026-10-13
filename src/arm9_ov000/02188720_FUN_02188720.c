/* Decompiled C draft; module arm9_ov000; ROM address 02188720. No matching claim. */
#include "types.h"
#include "deps/02188720_FUN_02188720.h"

undefined4 FUN_02188720(void)

{
  char local_8 [8];
  
  local_8[0] = FUN_02188528();
  if ((local_8[0] != '\0') && (local_8[0] != '\x12')) {
    FUN_021892f4(local_8);
    FUN_02188534(local_8[0]);
    return 0;
  }
  FUN_021885ec();
  return 1;
}

