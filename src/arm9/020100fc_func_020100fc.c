/* Decompiled C draft; module arm9; ROM address 020100fc. No matching claim. */
#include "types.h"
#include "deps/020100fc_func_020100fc.h"

void func_020100fc(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0;
  if (*(char *)(param_1 + 9) != '\0') {
    do {
      uVar2 = *(ushort *)(param_1 + 8 + (uint)*(ushort *)(param_1 + 0xe)) * uVar3 +
              param_1 + 8 + (uint)*(ushort *)(param_1 + 0xe) + 4;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      iVar4 = param_1 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
      ModelBlock_SomeTexPltFn_9(iVar4);
      func_0201023c(iVar4);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(byte *)(param_1 + 9));
    return;
  }
  return;
}

