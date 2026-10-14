/* Decompiled C draft; module arm9; ROM address 020ca058. No matching claim. */
#include "types.h"
#include "deps/020ca058_Maybe_helper_0ca058.h"

void Maybe_helper_0ca058(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020ca068. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020ca070)(param_1,*(uint *)(uRam020ca06c & 0xfffffffc) >> (uRam020ca06c & 3) * 8 |
                           *(uint *)(uRam020ca06c & 0xfffffffc) << (uRam020ca06c & 3) * -8 + 0x20,0)
  ;
  return;
}

