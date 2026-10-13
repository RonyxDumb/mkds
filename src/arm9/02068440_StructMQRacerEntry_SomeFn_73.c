/* Decompiled C draft; module arm9; ROM address 02068440. No matching claim. */
#include "types.h"
#include "deps/02068440_StructMQRacerEntry_SomeFn_73.h"

void StructMQRacerEntry_SomeFn_73(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(param_1 + 0x2fc) = param_2;
  uVar1 = param_1 + 0x2fcU & 3;
  uVar2 = *(uint *)(param_1 + 0x2fcU & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 2) {
    uVar3 = func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
    uVar1 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    func_0208c884(uVar3,((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x10) != 0);
    DriverContext_MaybeQueuePlaySfx(param_1,0xd2,0x7f,0);
    return;
  }
  return;
}

