/* Decompiled C draft; module arm9; ROM address 02108b2c. No matching claim. */
#include "types.h"
#include "deps/02108b2c_func_02108b2c.h"

void func_02108b2c(void)

{
  func_0212c6f0(uRam02108b74,1);
  if (*(uint *)(uRam02108b74 & 0xfffffffc) >> (uRam02108b74 & 3) * 8 != 0 ||
      *(uint *)(uRam02108b74 & 0xfffffffc) << (uRam02108b74 & 3) * -8 + 0x20 != 0) {
    func_0212c6f0(uRam02108b74,0);
  }
  NNSi_MaybeSndPlayerStartSeq(uRam02108b74,0,0x204);
  return;
}

