/* Decompiled C draft; module arm9; ROM address 0210d854. No matching claim. */
#include "types.h"
#include "deps/0210d854_MaybeSendArm7SoundShit.h"

void MaybeSendArm7SoundShit(undefined4 param_1)

{
  func_0212f730((*(uint *)(uRam0210d888 & 0xfffffffc) >> (uRam0210d888 & 3) * 8 |
                *(uint *)(uRam0210d888 & 0xfffffffc) << (uRam0210d888 & 3) * -8 + 0x20) + 0x1f &
                0xffffffe0,0x1000,param_1);
  *puRam0210d88c = param_1;
  return;
}

