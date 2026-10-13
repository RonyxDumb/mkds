/* Decompiled C draft; module arm9; ROM address 020f60d0. No matching claim. */
#include "types.h"
#include "deps/020f60d0_func_020f60d0.h"

void func_020f60d0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = uRam020f6140;
  uVar1 = param_1 + 0x11cU & 3;
  uVar3 = *(uint *)(param_1 + 0x11cU & 0xfffffffc);
  if (600 < (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
    *(undefined4 *)(param_1 + 0x154) = 0;
  }
  func_020f2228(param_1,uVar2);
  uVar1 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 1) == 0) {
    uVar1 = param_1 + 0xd4U & 3;
    uVar3 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
    func_0210ddf4(uRam020f6148,
                  ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x3fffffe0) + iRam020f6144,
                  uRam020f614c,param_1);
    return;
  }
  return;
}

