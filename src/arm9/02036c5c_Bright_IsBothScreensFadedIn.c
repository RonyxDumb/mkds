/* Decompiled C draft; module arm9; ROM address 02036c5c. No matching claim. */
#include "types.h"
#include "deps/02036c5c_Bright_IsBothScreensFadedIn.h"

undefined4 Bright_IsBothScreensFadedIn(void)

{
  if ((*psRam02036c88 == 2) && (*psRam02036c8c == 2)) {
    return 1;
  }
  return 0;
}

