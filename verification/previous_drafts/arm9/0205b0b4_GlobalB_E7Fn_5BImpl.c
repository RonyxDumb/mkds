/* Decompiled C draft; module arm9; ROM address 0205b0b4. No matching claim. */
#include "types.h"
#include "deps/0205b0b4_GlobalB_E7Fn_5BImpl.h"

void GlobalB_E7Fn_5BImpl(void)

{
  if ((*(ushort *)
        ((*(uint *)(uRam0205b0f0 & 0xfffffffc) >> (uRam0205b0f0 & 3) * 8 |
         *(uint *)(uRam0205b0f0 & 0xfffffffc) << (uRam0205b0f0 & 3) * -8 + 0x20) + 0x75c) & 0x80) !=
      0) {
    func_0205b0f4();
  }
  StateDualHandler_Execute
            (*(uint *)(uRam0205b0f0 & 0xfffffffc) >> (uRam0205b0f0 & 3) * 8 |
             *(uint *)(uRam0205b0f0 & 0xfffffffc) << (uRam0205b0f0 & 3) * -8 + 0x20);
  return;
}

