/* Decompiled C draft; module arm9; ROM address 02108c1c. No matching claim. */
#include "types.h"
#include "deps/02108c1c_func_02108c1c.h"

void func_02108c1c(void)

{
  func_0212c6f0(uRam02108c74,1);
  Sound_MaybeSetActiveSdat(uRam02108c78);
  if (*(uint *)(uRam02108c74 & 0xfffffffc) >> (uRam02108c74 & 3) * 8 != 0 ||
      *(uint *)(uRam02108c74 & 0xfffffffc) << (uRam02108c74 & 3) * -8 + 0x20 != 0) {
    func_0212c6f0(uRam02108c74,0);
  }
  NNSi_MaybeSndPlayerStartSeq(uRam02108c74,0,8);
  Sound_MaybeSetActiveSdat(uRam02108c7c);
  return;
}

