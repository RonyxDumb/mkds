/* Decompiled C draft; module arm9; ROM address 0207a828. No matching claim. */
#include "types.h"
#include "deps/0207a828_StructMQRacerEntry_SomeFn_21_ById.h"

void StructMQRacerEntry_SomeFn_21_ById(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0207a83c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0207a848)(iRam0207a844 * param_1 +
                   (*(uint *)(uRam0207a840 & 0xfffffffc) >> (uRam0207a840 & 3) * 8 |
                   *(uint *)(uRam0207a840 & 0xfffffffc) << (uRam0207a840 & 3) * -8 + 0x20));
  return;
}

