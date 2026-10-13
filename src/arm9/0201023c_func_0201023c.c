/* Decompiled C draft; module arm9; ROM address 0201023c. No matching claim. */
#include "types.h"
#include "deps/0201023c_func_0201023c.h"

void func_0201023c(int param_1)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = 0;
  param_1 = param_1 + (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  param_1 = param_1 + (uint)*(ushort *)(param_1 + 2);
  if (*(char *)(param_1 + 1) != '\0') {
    do {
      iVar5 = *(ushort *)(param_1 + (uint)*(ushort *)(param_1 + 6)) * uVar3 +
              param_1 + (uint)*(ushort *)(param_1 + 6) + 4;
      bVar2 = *(byte *)(iVar5 + 3);
      uVar3 = uVar3 + 1;
      if ((bVar2 & 1) != 0) {
        *(byte *)(iVar5 + 3) = bVar2 & 0xfe;
      }
    } while (uVar3 < *(byte *)(param_1 + 1));
    return;
  }
  return;
}

