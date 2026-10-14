/* Decompiled C draft; module arm9; ROM address 02010b50. No matching claim. */
#include "types.h"
#include "deps/02010b50_func_02010b50.h"

void func_02010b50(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint in_r12;
  uint uVar4;
  int in_lr;
  bool bVar5;
  
  if (param_2 == 0) {
    return;
  }
  do {
    uVar3 = 0;
    if (*(char *)(param_2 + 0x19) != '\0') {
      do {
        uVar2 = 0;
        bVar5 = (*(ushort *)(param_2 + uVar3 * 2 + 0x1a) & 0x100) != 0;
        if (bVar5) {
          in_lr = (int)uVar3 >> 5;
          uVar2 = uVar3 & 0x1f;
          uVar4 = param_1 + in_lr * 4;
          uVar1 = uVar4 & 3;
          uVar4 = *(uint *)(uVar4 & 0xfffffffc);
          in_r12 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
        }
        uVar3 = uVar3 + 1;
        if (bVar5) {
          *(uint *)(param_1 + in_lr * 4) = in_r12 | 1 << uVar2;
        }
      } while ((int)uVar3 < (int)(uint)*(byte *)(param_2 + 0x19));
    }
    uVar3 = param_2 + 0x10 & 3;
    uVar2 = *(uint *)(param_2 + 0x10 & 0xfffffffc);
    param_2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  } while (param_2 != 0);
  return;
}

