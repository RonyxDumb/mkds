/* Decompiled C draft; module arm9; ROM address 020efea4. No matching claim. */
#include "types.h"
#include "deps/020efea4_func_020efea4.h"

void func_020efea4(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x1fcU & 3;
  uVar1 = *(uint *)(param_1 + 0x1fcU & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x29c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - 2 < 2) {
    return;
  }
  uVar2 = (*(uint *)(uRam020eff3c & 0xfffffffc) >> (uRam020eff3c & 3) * 8 |
          *(uint *)(uRam020eff3c & 0xfffffffc) << (uRam020eff3c & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 5) {
    return;
  }
  uVar2 = param_1 + 0x58U & 3;
  uVar1 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 0xf) {
    return;
  }
  uVar2 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
    uVar2 = param_1 + 0x60U & 3;
    uVar1 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if ((uVar2 != 1) && (uVar2 != 2)) {
      return;
    }
    func_020edad8(param_1 + 0x58);
    return;
  }
  return;
}

