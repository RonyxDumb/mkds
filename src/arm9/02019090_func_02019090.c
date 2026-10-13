/* Decompiled C draft; module arm9; ROM address 02019090. No matching claim. */
#include "types.h"
#include "deps/02019090_func_02019090.h"

void func_02019090(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x40U & 3;
  uVar1 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar2 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  if (-1 < (int)(uVar2 << 10)) {
    if (-1 < (int)(uVar2 << 9)) {
      func_020191f4();
    }
    func_0201910c(param_1);
    return;
  }
  func_0201910c();
  if (-1 < (int)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                 *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) << 9)) {
    func_020191f4(param_1);
    return;
  }
  return;
}

