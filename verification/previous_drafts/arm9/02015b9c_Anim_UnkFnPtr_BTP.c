/* Decompiled C draft; module arm9; ROM address 02015b9c. No matching claim. */
#include "types.h"
#include "deps/02015b9c_Anim_UnkFnPtr_BTP.h"

void Anim_UnkFnPtr_BTP(undefined4 param_1,uint param_2,undefined2 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_2 + 8 & 3;
  uVar4 = *(uint *)(param_2 + 8 & 0xfffffffc);
  uVar5 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  iVar2 = func_02013b3c(uVar5,param_3,
                        ((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                         *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) << 4) >> 0x10
                       );
  uVar3 = func_02013bcc(uVar5,*(undefined1 *)(iVar2 + 2));
  uVar1 = param_2 + 0x14 & 3;
  uVar4 = *(uint *)(param_2 + 0x14 & 0xfffffffc);
  func_02015c7c(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,uVar3,param_1);
  if (*(char *)(iVar2 + 3) != -1) {
    uVar3 = func_02013bbc(uVar5);
    uVar1 = param_2 + 0x14 & 3;
    uVar4 = *(uint *)(param_2 + 0x14 & 0xfffffffc);
    func_02015c24(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,uVar3,param_1);
    return;
  }
  return;
}

