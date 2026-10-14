/* Decompiled C draft; module arm9; ROM address 020d1fd4. No matching claim. */
#include "types.h"
#include "deps/020d1fd4_func_020d1fd4.h"

void func_020d1fd4(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar4;
  uint uVar3;
  
  iVar1 = GetRaceStartCountdown();
  uVar4 = *(uint *)(uRam020d2088 & 0xfffffffc) >> (uRam020d2088 & 3) * 8 |
          *(uint *)(uRam020d2088 & 0xfffffffc) << (uRam020d2088 & 3) * -8 + 0x20;
  uVar3 = uVar4 + 0xc & 3;
  uVar2 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 4) {
    return;
  }
  if (uVar3 == 1) {
    return;
  }
  if (0xb3 < iVar1) {
    return;
  }
  uVar3 = uVar4 + 8 & 3;
  uVar2 = *(uint *)(uVar4 + 8 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 5) {
    if (uVar3 != 3) {
      return;
    }
    uVar3 = uVar4 + 0x1c & 3;
    uVar2 = *(uint *)(uVar4 + 0x1c & 0xfffffffc);
    if ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) != 2) {
      return;
    }
  }
  func_020d1de8(param_1);
  uVar2 = *(uint *)(uRam020d208c & 0xfffffffc) >> (uRam020d208c & 3) * 8 |
          *(uint *)(uRam020d208c & 0xfffffffc) << (uRam020d208c & 3) * -8 + 0x20;
  uVar3 = uVar2 + 0x1c;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (uVar3 >> uVar4 * 8 == 0 && uVar3 << uVar4 * -8 + 0x20 == 0) {
    return;
  }
  uVar2 = uVar2 + 4;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 10) {
    func_020d18d4(param_1);
    return;
  }
  func_020d1a98(param_1);
  return;
}

