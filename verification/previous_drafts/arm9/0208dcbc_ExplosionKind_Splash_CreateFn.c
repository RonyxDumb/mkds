/* Decompiled C draft; module arm9; ROM address 0208dcbc. No matching claim. */
#include "types.h"
#include "deps/0208dcbc_ExplosionKind_Splash_CreateFn.h"

void ExplosionKind_Splash_CreateFn(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0x90U & 3;
  uVar1 = *(uint *)(param_1 + 0x90U & 0xfffffffc);
  iVar2 = Animation_GetCurrentLength(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20);
  uVar3 = param_1 + 0x90U & 3;
  uVar1 = *(uint *)(param_1 + 0x90U & 0xfffffffc);
  Animation_SetAt(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20,0);
  *(uint *)(param_1 + 0xac) = (uint)(iVar2 << 4) >> 0x10;
  uVar3 = param_1 + 0x94U & 3;
  uVar1 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  uVar3 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    Animation_SetAt(uVar3,0);
    return;
  }
  return;
}

