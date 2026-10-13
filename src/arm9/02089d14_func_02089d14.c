/* Decompiled C draft; module arm9; ROM address 02089d14. No matching claim. */
#include "types.h"
#include "deps/02089d14_func_02089d14.h"

void func_02089d14(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = iRam02089d68;
  uVar4 = uRam02089d64;
  uVar5 = iRam02089d60 + param_1 * 4;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)((*(uint *)(uRam02089d64 & 0xfffffffc) >> (uRam02089d64 & 3) * 8 |
            *(uint *)(uRam02089d64 & 0xfffffffc) << (uRam02089d64 & 3) * -8 + 0x20) + 0x794) =
       uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  iVar3 = iRam02089d6c;
  uVar5 = iVar2 + param_1 * 4;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x798) =
       uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  uVar5 = uVar4 + 0x794;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  (*(code *)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20))(uVar4 + iVar3);
  return;
}

