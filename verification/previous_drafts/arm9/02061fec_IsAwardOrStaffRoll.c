/* Decompiled C draft; module arm9; ROM address 02061fec. No matching claim. */
#include "types.h"
#include "deps/02061fec_IsAwardOrStaffRoll.h"

int IsAwardOrStaffRoll(void)

{
  return (int)*(short *)(*(uint *)(uRam02061ffc & 0xfffffffc) >> (uRam02061ffc & 3) * 8 |
                        *(uint *)(uRam02061ffc & 0xfffffffc) << (uRam02061ffc & 3) * -8 + 0x20);
}

