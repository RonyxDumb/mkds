/* Decompiled C draft; module arm9; ROM address 02084fb0. No matching claim. */
#include "types.h"
#include "deps/02084fb0_StructML_MaybeInnerLoadModel.h"

void StructML_MaybeInnerLoadModel(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_3 == 0) || (iVar1 = GetCurrentSceneId(), iVar1 != 2)) {
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  else {
    *(int *)(param_1 + 0x54) =
         (int)*(char *)((*(uint *)(uRam020850c0 & 0xfffffffc) >> (uRam020850c0 & 3) * 8 |
                        *(uint *)(uRam020850c0 & 0xfffffffc) << (uRam020850c0 & 3) * -8 + 0x20) +
                       0x57);
  }
  if ((*(char *)(param_2 + 0x18) == '\x01') && (*(char *)(param_2 + 0x19) == '\x01')) {
    *(undefined4 *)(param_1 + 0x58) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  Mode_CreateFromResource(param_1,param_2);
  uVar3 = param_1 + 0x54U & 3;
  uVar2 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
    return;
  }
  uVar3 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar2 = 0;
  if (*(char *)(uVar3 + 0x18) == '\0') {
    return;
  }
  do {
    iVar1 = ModelBlock_SomeTexPltFn_0(uVar3,uVar2);
    if (iVar1 == 1) {
      ModelBlock_SomeTexPltFn_1(uVar3,uVar2,2);
    }
    else {
      iVar1 = ModelBlock_SomeTexPltFn_0(uVar3,uVar2);
      if (iVar1 == 2) {
        ModelBlock_SomeTexPltFn_1(uVar3,uVar2,1);
      }
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < *(byte *)(uVar3 + 0x18));
  return;
}

