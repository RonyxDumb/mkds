/* Decompiled C draft; module arm9; ROM address 02067778. No matching claim. */
#include "types.h"
#include "deps/02067778_func_02067778.h"

undefined4 func_02067778(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_18 [4];
  
  uVar4 = param_1 + 0x3dcU & 3;
  uVar1 = *(uint *)(param_1 + 0x3dcU & 0xfffffffc);
  if (((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) == 8) &&
     (uVar4 = param_1 + 0x44U & 3, uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
     ((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) & 0x80000000) == 0)) {
    *(undefined2 *)(param_1 + 0x238) = 0x3c;
  }
  else {
    DriverContext_MaybeApplyBoost(param_1,0,0x3c);
    local_18[0] = *puRam02067830;
    local_18[1] = puRam02067830[1];
    local_18[2] = puRam02067830[2];
    uVar4 = param_1 + 0x3e4U & 3;
    uVar1 = *(uint *)(param_1 + 0x3e4U & 0xfffffffc);
    uVar4 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
    if ((0 < (int)uVar4) &&
       ((uVar1 = param_1 + 0x7cU & 3, uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc),
        ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 1) != 0 &&
        (iVar3 = DriverContext_MaybeQueuePlaySfx(param_1,local_18[uVar4 - 1],0x7f,0), iVar3 != 0))))
    {
      *(byte *)(iVar3 + 0x19) = *(byte *)(iVar3 + 0x19) | 0x10;
    }
  }
  func_020839d8(param_1);
  uVar4 = param_1 + 0x48U & 3;
  uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20 | 0x400000;
  return 8;
}

