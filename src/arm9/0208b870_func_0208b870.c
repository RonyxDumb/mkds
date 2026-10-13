/* Decompiled C draft; module arm9; ROM address 0208b870. No matching claim. */
#include "types.h"
#include "deps/0208b870_func_0208b870.h"

void func_0208b870(undefined4 param_1)

{
  uint uVar1;
  
  func_02018674(*(uint *)(uRam0208b8bc & 0xfffffffc) >> (uRam0208b8bc & 3) * 8 |
                *(uint *)(uRam0208b8bc & 0xfffffffc) << (uRam0208b8bc & 3) * -8 + 0x20,param_1);
  func_02018674(*(uint *)(uRam0208b8c0 & 0xfffffffc) >> (uRam0208b8c0 & 3) * 8 |
                *(uint *)(uRam0208b8c0 & 0xfffffffc) << (uRam0208b8c0 & 3) * -8 + 0x20,param_1);
  uVar1 = *(uint *)(uRam0208b8c4 & 0xfffffffc) >> (uRam0208b8c4 & 3) * 8 |
          *(uint *)(uRam0208b8c4 & 0xfffffffc) << (uRam0208b8c4 & 3) * -8 + 0x20;
  if (uVar1 != 0) {
    func_02018674(uVar1,param_1);
    return;
  }
  return;
}

