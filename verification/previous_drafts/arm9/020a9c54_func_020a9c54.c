/* Decompiled C draft; module arm9; ROM address 020a9c54. No matching claim. */
#include "types.h"
#include "deps/020a9c54_func_020a9c54.h"

void func_020a9c54(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 + 300U & 3;
  uVar2 = *(uint *)(param_2 + 300U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    return;
  }
  uVar1 = param_2 + 0x78U & 3;
  uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
  if (iRam020a9ccc <= (int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x3fffffe0)) {
    return;
  }
  if (*(ushort *)(param_2 + 0x118) == 0) {
    return;
  }
  if (*(ushort *)(param_2 + 0x118) < 0x1d) {
    func_020e53ac(param_2 + 0xe8,0);
    return;
  }
  return;
}

