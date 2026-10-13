/* Decompiled C draft; module arm7; ROM address 060188a4. No matching claim. */
#include "types.h"
#include "deps/060188a4_FUN_060188a4.h"

void FUN_060188a4(void)

{
  uint local_10 [2];
  
  do {
    while( true ) {
      thunk_FUN_03804cdc(local_10);
      if ((local_10[0] & 0x20) == 0) break;
      thunk_FUN_03804504();
    }
  } while ((local_10[0] & 1) != 0);
  return;
}

