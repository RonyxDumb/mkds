/* Decompiled C draft; module arm9; ROM address 0214d93c. No matching claim. */
#include "types.h"
#include "deps/0214d93c_Rtc_WaitBusy.h"

void Rtc_WaitBusy(void)

{
  do {
  } while ((*(uint *)(uRam0214d950 & 0xfffffffc) >> (uRam0214d950 & 3) * 8 |
           *(uint *)(uRam0214d950 & 0xfffffffc) << (uRam0214d950 & 3) * -8 + 0x20) == 1);
  return;
}

