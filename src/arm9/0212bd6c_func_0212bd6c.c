/* Decompiled C draft; module arm9; ROM address 0212bd6c. No matching claim. */
#include "types.h"
#include "deps/0212bd6c_func_0212bd6c.h"

void func_0212bd6c(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = (undefined4 *)
           (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 0;
    *param_1 = 0;
  }
  uVar1 = (uint)(param_1 + 1) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  IntrusiveListWrapper_RemoveItem((uint *)(uintptr_t)(uVar4),(int)(uintptr_t)(param_1));
  param_1[1] = 0;
  uVar1 = (uint)(param_1 + 2) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
    IntrusiveListWrapper_InsertLast(uVar4 + 0xc);
    uVar1 = (uint)(param_1 + 2) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0xc) = 0;
    param_1[2] = 0;
  }
  IntrusiveListWrapper_RemoveItem((uint *)(uintptr_t)(uRam0212bdf4),(int)(uintptr_t)(param_1));
  IntrusiveListWrapper_InsertLast(uRam0212bdf8,(int)(uintptr_t)(param_1));
  *(undefined1 *)(param_1 + 0xb) = 0;
  return;
}

