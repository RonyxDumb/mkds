/* Decompiled C draft; module arm9; ROM address 0206d020. No matching claim. */
#include "types.h"
#include "deps/0206d020_DriverContext_MaybeApplyBoost.h"

void DriverContext_MaybeApplyBoost(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x180U & 3;
  uVar2 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    return;
  }
  uVar1 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x1000) != 0) {
    return;
  }
  uVar1 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x10000000) != 0) {
    return;
  }
  uVar1 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x20;
  if (*(short *)(param_1 + 0x238) < param_3) {
    *(short *)(param_1 + 0x238) = (short)param_3;
  }
  if ((param_2 != 1) && (param_2 != 3)) {
    uVar1 = param_1 + 0x48U & 3;
    uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x20000000;
  }
  StructMQRacerEntry_SomeFn_70(param_1);
  uVar1 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xffff7fff;
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 1) == 0) {
    DriverContext_MaybeQueuePlaySfx(param_1,0x9f,0x7f,0);
    return;
  }
  func_02084034(param_2 != 0,param_1);
  func_02074874(uRam0206d134);
  func_02055c80(5);
  if (param_2 == 3) {
    DriverContext_MaybeQueuePlaySfx(param_1,0xa2,0x7f,0);
    return;
  }
  return;
}

