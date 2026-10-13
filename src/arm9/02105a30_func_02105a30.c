/* Decompiled C draft; module arm9; ROM address 02105a30. No matching claim. */
#include "types.h"
#include "deps/02105a30_func_02105a30.h"

void func_02105a30(int param_1)

{
  undefined4 unaff_r4;
  
  *piRam02105aac = param_1;
  if (param_1 - 1U < 2) {
    if (param_1 == 1) {
      unaff_r4 = 0x47;
    }
    if (param_1 != 1) {
      unaff_r4 = 0x48;
    }
    Sound_MaybeRestoreHeapState
              (*(uint *)(uRam02105ab0 & 0xfffffffc) >> (uRam02105ab0 & 3) * 8 |
               *(uint *)(uRam02105ab0 & 0xfffffffc) << (uRam02105ab0 & 3) * -8 + 0x20,
               *(uint *)(uRam02105ab4 & 0xfffffffc) >> (uRam02105ab4 & 3) * 8 |
               *(uint *)(uRam02105ab4 & 0xfffffffc) << (uRam02105ab4 & 3) * -8 + 0x20);
    Sound_Context_GetMaybeSavedFrameHeapStateId
              (*(uint *)(uRam02105ab0 & 0xfffffffc) >> (uRam02105ab0 & 3) * 8 |
               *(uint *)(uRam02105ab0 & 0xfffffffc) << (uRam02105ab0 & 3) * -8 + 0x20);
    CheckMaybeLoadSseqOk
              (unaff_r4,*(uint *)(uRam02105ab0 & 0xfffffffc) >> (uRam02105ab0 & 3) * 8 |
                        *(uint *)(uRam02105ab0 & 0xfffffffc) << (uRam02105ab0 & 3) * -8 + 0x20);
    func_0212c6f0(uRam02105ab8,2);
    func_0210d7dc(unaff_r4,0x7f,uRam02105abc);
    return;
  }
  return;
}

