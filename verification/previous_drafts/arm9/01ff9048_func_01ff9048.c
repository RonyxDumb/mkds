/* Decompiled C draft; module arm9; ROM address 01ff9048. No matching claim. */
#include "types.h"
#include "deps/01ff9048_func_01ff9048.h"

void func_01ff9048(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  
  uVar4 = uRam01ff9138;
  piVar5 = (int *)(*(uint *)(uRam01ff9138 & 0xfffffffc) >> (uRam01ff9138 & 3) * 8 |
                  *(uint *)(uRam01ff9138 & 0xfffffffc) << (uRam01ff9138 & 3) * -8 + 0x20);
  if (piVar5 == (int *)0x0) {
    if (*(uint *)(uRam01ff913c & 0xfffffffc) >> (uRam01ff913c & 3) * 8 != 0 ||
        *(uint *)(uRam01ff913c & 0xfffffffc) << (uRam01ff913c & 3) * -8 + 0x20 != 0) {
      func_01ff921c();
    }
  }
  else {
    if (*(uint *)(uRam01ff913c & 0xfffffffc) >> (uRam01ff913c & 3) * 8 != 0 ||
        *(uint *)(uRam01ff913c & 0xfffffffc) << (uRam01ff913c & 3) * -8 + 0x20 != 0) {
      uVar3 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
              *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
      iVar2 = uVar3 + 1;
      if ((uint)(iVar2 + param_3) < 0xc1) {
        *piVar5 = iVar2;
        *(undefined4 *)
         ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + uVar3 * 4 + 4) = param_1;
        if (param_3 != 0) {
          uVar4 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                  *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
          MIi_CpuCopyFast((undefined4 *)(uintptr_t)(param_2),(undefined4 *)(uintptr_t)(uVar4 + 4 +
                                  (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                                  *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) * 4),
                          param_3 << 2);
          piVar5 = (int *)(*(uint *)(uRam01ff9138 & 0xfffffffc) >> (uRam01ff9138 & 3) * 8 |
                          *(uint *)(uRam01ff9138 & 0xfffffffc) << (uRam01ff9138 & 3) * -8 + 0x20);
          *piVar5 = (*(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                    *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20) +
                    param_3;
          return;
        }
        return;
      }
    }
    if (*(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 == 0 &&
        *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20 == 0) {
      if (*(uint *)(uRam01ff913c & 0xfffffffc) >> (uRam01ff913c & 3) * 8 != 0 ||
          *(uint *)(uRam01ff913c & 0xfffffffc) << (uRam01ff913c & 3) * -8 + 0x20 != 0) {
        func_01ff921c();
      }
    }
    else {
      func_01ff9234();
    }
  }
  puVar1 = puRam01ff9140;
  *puRam01ff9140 = param_1;
  MIi_CpuSend32((undefined4 *)(uintptr_t)(param_2),puVar1,param_3 << 2);
  return;
}

