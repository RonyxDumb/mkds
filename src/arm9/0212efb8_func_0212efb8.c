/* Decompiled C draft; module arm9; ROM address 0212efb8. No matching claim. */
#include "types.h"
#include "deps/0212efb8_func_0212efb8.h"

void func_0212efb8(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  Os_Mutex_Lock(uRam0212f04c);
  uVar2 = *(uint *)(uRam0212f050 & 0xfffffffc) >> (uRam0212f050 & 3) * 8 |
          *(uint *)(uRam0212f050 & 0xfffffffc) << (uRam0212f050 & 3) * -8 + 0x20;
  if (uVar2 != 0) {
    Os_Mutex_Lock(uVar2 + iRam0212f054);
  }
  uVar2 = param_1 + 0x110U & 3;
  uVar1 = *(uint *)(param_1 + 0x110U & 0xfffffffc);
  if ((int)((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) << 0x1e) < 0) {
    func_0212c918(param_1);
  }
  uVar2 = param_1 + 0x110U & 3;
  uVar1 = *(uint *)(param_1 + 0x110U & 0xfffffffc);
  if ((int)((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) << 0x1f) < 0) {
    File_If1Set2AndUnk20(param_1 + 0x5c);
  }
  func_0212ef48(param_1);
  Os_Mutex_Unlock(uRam0212f04c);
  uVar2 = *(uint *)(uRam0212f050 & 0xfffffffc) >> (uRam0212f050 & 3) * 8 |
          *(uint *)(uRam0212f050 & 0xfffffffc) << (uRam0212f050 & 3) * -8 + 0x20;
  if (uVar2 != 0) {
    Os_Mutex_Unlock(uVar2 + iRam0212f054);
    return;
  }
  return;
}

