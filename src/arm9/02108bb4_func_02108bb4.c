/* Decompiled C draft; module arm9; ROM address 02108bb4. No matching claim. */
#include "types.h"
#include "deps/02108bb4_func_02108bb4.h"

void func_02108bb4(void)

{
  func_0212c6f0(uRam02108bfc,1);
  if (*(uint *)(uRam02108bfc & 0xfffffffc) >> (uRam02108bfc & 3) * 8 != 0 ||
      *(uint *)(uRam02108bfc & 0xfffffffc) << (uRam02108bfc & 3) * -8 + 0x20 != 0) {
    func_0212c6f0(uRam02108bfc,0);
  }
  NNSi_MaybeSndPlayerStartSeq(uRam02108bfc,0,uRam02108c00);
  return;
}

