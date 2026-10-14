/* Decompiled C draft; module arm9; ROM address 020fade4. No matching claim. */
#include "types.h"
#include "deps/020fade4_func_020fade4.h"

undefined4 func_020fade4(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (*(short *)(param_1 + 0x2f6) != 7) {
    StateDualHandler_Create((undefined4 *)(uintptr_t)(param_1 + 0x2e8),uRam020fae6c,8,param_1);
    *(undefined2 *)(param_1 + 0x2f8) = 7;
    *(undefined2 *)(param_1 + 0x2fa) = 1;
    uVar1 = param_1 + 0x74U & 3;
    uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x180000) == 0) {
      *(undefined4 *)(param_1 + 0x120) = uRam020fae70;
    }
    uVar1 = param_1 + 0x74U & 3;
    uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(param_1 + 0x74) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xffff7fff;
    uVar1 = param_1 + 0x74U & 3;
    uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(param_1 + 0x74) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x80000;
    func_020f9c6c(param_1);
    *(ushort *)(param_1 + 0x78) = *(ushort *)(param_1 + 0x78) & 0xbfff;
  }
  return 1;
}

