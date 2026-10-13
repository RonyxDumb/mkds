/* Decompiled C draft; module arm9; ROM address 02036d08. No matching claim. */
#include "types.h"
#include "deps/02036d08_Bright_IsBothScreensFadedOut.h"

undefined4 Bright_IsBothScreensFadedOut(void)

{
  if ((*psRam02036d34 == 0) && (*psRam02036d38 == 0)) {
    return 1;
  }
  return 0;
}

