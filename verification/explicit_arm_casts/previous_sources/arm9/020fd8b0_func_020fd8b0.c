/* Decompiled C draft; module arm9; ROM address 020fd8b0. No matching claim. */
#include "types.h"
#include "deps/020fd8b0_func_020fd8b0.h"

undefined4 func_020fd8b0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (*(short *)(param_1 + 0x192) != 2) {
    StateDualHandler_Create(param_1 + 0x184,uRam020fd930,4,param_1);
    *(undefined2 *)(param_1 + 0x194) = 2;
    *(undefined2 *)(param_1 + 0x196) = 1;
    uVar1 = param_1 + 0x74U & 3;
    uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x180000) == 0) {
      *(undefined4 *)(param_1 + 0x120) = uRam020fd934;
    }
    uVar1 = param_1 + 0x74U & 3;
    uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(param_1 + 0x74) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xffff7fff;
    uVar1 = param_1 + 0x74U & 3;
    uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(param_1 + 0x74) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x80000;
    *(ushort *)(param_1 + 0x78) = *(ushort *)(param_1 + 0x78) & 0xbfff;
  }
  return 1;
}

