/* Decompiled C draft; module arm9; ROM address 0205eeb0. No matching claim. */
#include "types.h"
#include "deps/0205eeb0_func_0205eeb0.h"

void func_0205eeb0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(DAT_0205ef6c & 0xfffffffc) >> (DAT_0205ef6c & 3) * 8 |
          *(uint *)(DAT_0205ef6c & 0xfffffffc) << (DAT_0205ef6c & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0xc & 3;
  uVar1 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0) {
    return;
  }
  uVar2 = uVar3 + 8 & 3;
  uVar1 = *(uint *)(uVar3 + 8 & 0xfffffffc);
  switch(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    uVar2 = uVar3 + 0x18 & 3;
    uVar1 = *(uint *)(uVar3 + 0x18 & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 == 0) {
      func_0205f498();
      return;
    }
    if (uVar2 != 1) {
      return;
    }
    func_0205f218();
    return;
  case 3:
    func_0205f700();
    return;
  case 4:
    SomeMissionLevelStageChecking();
    return;
  case 5:
    func_0205ef70();
  }
  return;
}

