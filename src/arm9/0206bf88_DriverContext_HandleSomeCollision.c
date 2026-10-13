/* Decompiled C draft; module arm9; ROM address 0206bf88. No matching claim. */
#include "types.h"
#include "deps/0206bf88_DriverContext_HandleSomeCollision.h"

void DriverContext_HandleSomeCollision(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & uRam0206c08c;
  *(undefined2 *)(param_1 + 0x238) = 0;
  *(undefined2 *)(param_1 + 0x538) = 0;
  *(undefined2 *)(param_1 + 0x23c) = 0;
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 1) != 0) {
    uVar1 = param_1 + 0x4cU & 3;
    uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if ((((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x10000000) == 0) &&
       (uVar1 = param_1 + 0x48U & 3, uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
       ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x4000000) == 0)) {
      func_02074854();
    }
    func_02055c5c();
  }
  DriverContext_UpdateCharacterAnimation(param_1,1,0);
  *(undefined4 *)(param_1 + 0x180) = param_2;
  uVar1 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & uRam0206c090;
  *(undefined4 *)(param_1 + 0x2c4) = 0;
  *(undefined4 *)(param_1 + 0x2fc) = 0;
  *(undefined2 *)(param_1 + 0x302) = 0;
  *(undefined2 *)(param_1 + 0x300) = *(undefined2 *)(param_1 + 0x302);
  *(undefined4 *)(param_1 + 0x30c) = 0;
  func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
  func_0208c534();
  uVar1 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x2000) != 0) {
    uVar1 = param_1 + 0x4cU & 3;
    uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xffffdfff;
    *(undefined4 *)(param_1 + 0xd8) = 0x1000;
    uVar1 = param_1 + 0x4cU & 3;
    uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x8000000) == 0) {
      StructMQRacerEntry_SomeFn_2(param_1);
    }
    StructMQRacerEntry_SomeFn_3(param_1);
    return;
  }
  return;
}

