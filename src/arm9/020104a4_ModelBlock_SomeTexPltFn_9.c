/* Decompiled C draft; module arm9; ROM address 020104a4. No matching claim. */
#include "types.h"
#include "deps/020104a4_ModelBlock_SomeTexPltFn_9.h"

void ModelBlock_SomeTexPltFn_9(int param_1)

{
  uint uVar1;
  int iVar3;
  int iVar4;
  uint uVar2;
  
  uVar2 = param_1 + 8U & 3;
  uVar1 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar1 = 0;
  iVar4 = param_1 + uVar2;
  iVar3 = iVar4 + (uint)*(ushort *)(param_1 + uVar2);
  if (*(char *)(iVar3 + 1) != '\0') {
    do {
      if ((*(byte *)(*(ushort *)(iVar3 + (uint)*(ushort *)(iVar3 + 6)) * uVar1 +
                     iVar3 + (uint)*(ushort *)(iVar3 + 6) + 7) & 1) != 0) {
        func_0201063c(iVar4);
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(byte *)(iVar3 + 1));
    return;
  }
  return;
}

