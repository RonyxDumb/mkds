/* Decompiled C draft; module arm9; ROM address 02108adc. No matching claim. */
#include "types.h"
#include "deps/02108adc_func_02108adc.h"

void func_02108adc(void)

{
  func_0212c6f0(uRam02108b24,1);
  if (*(uint *)(uRam02108b24 & 0xfffffffc) >> (uRam02108b24 & 3) * 8 != 0 ||
      *(uint *)(uRam02108b24 & 0xfffffffc) << (uRam02108b24 & 3) * -8 + 0x20 != 0) {
    func_0212c6f0(uRam02108b24,0);
  }
  NNSi_MaybeSndPlayerStartSeq(uRam02108b24,0,uRam02108b28);
  return;
}

