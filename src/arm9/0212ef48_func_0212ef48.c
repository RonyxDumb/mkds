/* Decompiled C draft; module arm9; ROM address 0212ef48. No matching claim. */
#include "types.h"
#include "deps/0212ef48_func_0212ef48.h"

void func_0212ef48(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x110U & 3;
  uVar1 = *(uint *)(param_1 + 0x110U & 0xfffffffc);
  if ((int)((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) << 0x1f) < 0) {
    func_0212ef00();
    Fs_File_Close(param_1 + 0x5c);
    func_0212ee8c(uRam0212efac,param_1);
    uVar2 = *(uint *)(uRam0212efb0 & 0xfffffffc) >> (uRam0212efb0 & 3) * 8 |
            *(uint *)(uRam0212efb0 & 0xfffffffc) << (uRam0212efb0 & 3) * -8 + 0x20;
    if (uVar2 != 0) {
      func_0212ee8c(uVar2 + iRam0212efb4,param_1);
    }
    func_0212f058(param_1);
    return;
  }
  return;
}

