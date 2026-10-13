/* Decompiled C draft; module arm9; ROM address 02010168. No matching claim. */
#include "types.h"
#include "deps/02010168_func_02010168.h"

uint func_02010168(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = 1;
  uVar4 = 0;
  if (*(char *)(param_1 + 9) != '\0') {
    do {
      uVar1 = *(ushort *)(param_1 + 8 + (uint)*(ushort *)(param_1 + 0xe)) * uVar4 +
              param_1 + 8 + (uint)*(ushort *)(param_1 + 0xe) + 4;
      uVar2 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      iVar5 = param_1 + (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
      uVar1 = ModelBlock_SomeTexPltFn_10(iVar5,param_2);
      uVar2 = ModelBlock_SomeTexPltFn_11(iVar5,param_2);
      uVar4 = uVar4 + 1;
      uVar3 = uVar3 & uVar1 & uVar2;
    } while (uVar4 < *(byte *)(param_1 + 9));
  }
  return uVar3;
}

