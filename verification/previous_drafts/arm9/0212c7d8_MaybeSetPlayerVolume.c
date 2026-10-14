/* Decompiled C draft; module arm9; ROM address 0212c7d8. No matching claim. */
#include "types.h"
#include "deps/0212c7d8_MaybeSetPlayerVolume.h"

void MaybeSetPlayerVolume(int param_1,undefined1 param_2)

{
  *(undefined1 *)(iRam0212c7ec + param_1 * 0x24) = param_2;
  return;
}

