/* Decompiled C draft; module arm9; ROM address 0208155c. No matching claim. */
#include "types.h"
#include "deps/0208155c_func_0208155c.h"

void func_0208155c(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 * 0x58 +
          (*(uint *)(uRam0208159c & 0xfffffffc) >> (uRam0208159c & 3) * 8 |
          *(uint *)(uRam0208159c & 0xfffffffc) << (uRam0208159c & 3) * -8 + 0x20) + 0x2c;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  if (uVar3 == 0) {
    return;
  }
  if (param_2 == 0) {
    param_1 = 1;
  }
  uVar1 = uVar3 + 0x24 & 3;
  uVar2 = *(uint *)(uVar3 + 0x24 & 0xfffffffc);
  if (param_2 != 0) {
    param_1 = 0;
  }
  *(uint *)(uVar3 + 0x24) =
       (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffff7 | (param_1 & 1) << 3;
  return;
}

