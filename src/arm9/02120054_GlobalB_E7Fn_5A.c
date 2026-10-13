/* Decompiled C draft; module arm9; ROM address 02120054. No matching claim. */
#include "types.h"
#include "deps/02120054_GlobalB_E7Fn_5A.h"

void GlobalB_E7Fn_5A(void)

{
  uint uVar1;
  
  func_0x021a3250(uRam0212008c);
  func_0x021a323c(uRam02120090);
  uVar1 = *(uint *)(uRam02120094 & 0xfffffffc) >> (uRam02120094 & 3) * 8 |
          *(uint *)(uRam02120094 & 0xfffffffc) << (uRam02120094 & 3) * -8 + 0x20;
  *(undefined2 *)(uVar1 + 0x10) = 1;
  *(undefined2 *)(uVar1 + 0x12) = 1;
  return;
}

