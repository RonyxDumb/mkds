/* Decompiled C draft; module arm9; ROM address 020fc268. No matching claim. */
#include "types.h"
#include "deps/020fc268_func_020fc268.h"

void func_020fc268(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  func_020f2228(param_1,0xd000);
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) != 0) {
    return;
  }
  uVar2 = param_1 + 0xd4U & 3;
  uVar1 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
  func_0210b7ec(param_1 + 0x300,(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x3fffffe0);
  uVar2 = param_1 + 0x270U & 3;
  uVar1 = *(uint *)(param_1 + 0x270U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 1) {
    func_02109078(param_1,uVar2,0x7f,0);
    return;
  }
  return;
}

