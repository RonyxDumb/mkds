/* Decompiled C draft; module arm9; ROM address 0207a84c. No matching claim. */
#include "types.h"
#include "deps/0207a84c_IsDriverKilledOrBeingKilled.h"

void IsDriverKilledOrBeingKilled(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0207a860. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0207a86c)(iRam0207a868 * param_1 +
                   (*(uint *)(uRam0207a864 & 0xfffffffc) >> (uRam0207a864 & 3) * 8 |
                   *(uint *)(uRam0207a864 & 0xfffffffc) << (uRam0207a864 & 3) * -8 + 0x20));
  return;
}

