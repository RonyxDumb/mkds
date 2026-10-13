/* Decompiled C draft; module arm9; ROM address 02108a8c. No matching claim. */
#include "types.h"
#include "deps/02108a8c_func_02108a8c.h"

void func_02108a8c(void)

{
  func_0212c6f0(uRam02108ad4,1);
  if (*(uint *)(uRam02108ad4 & 0xfffffffc) >> (uRam02108ad4 & 3) * 8 != 0 ||
      *(uint *)(uRam02108ad4 & 0xfffffffc) << (uRam02108ad4 & 3) * -8 + 0x20 != 0) {
    func_0212c6f0(uRam02108ad4,0);
  }
  NNSi_MaybeSndPlayerStartSeq(uRam02108ad4,0,uRam02108ad8);
  return;
}

