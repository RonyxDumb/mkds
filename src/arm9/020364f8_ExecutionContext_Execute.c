/* Decompiled C draft; module arm9; ROM address 020364f8. No matching claim. */
#include "types.h"
#include "deps/020364f8_ExecutionContext_Execute.h"

undefined4 ExecutionContext_Execute(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  *(uint *)(param_1 + 0x10) =
       *(uint *)((uint)puRam02036584 & 0xfffffffc) >> ((uint)puRam02036584 & 3) * 8 |
       *(uint *)((uint)puRam02036584 & 0xfffffffc) << ((uint)puRam02036584 & 3) * -8 + 0x20;
  uVar1 = param_1 + 0x10 & 3;
  uVar2 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    GetGlobalHeapHandle(0);
  }
  uVar3 = Mem_CreateChildExpHeap();
  *(undefined4 *)(param_1 + 0xc) = uVar3;
  *puRam02036584 = param_1;
  uVar1 = param_1 + 4 & 3;
  uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar3 = (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))(param_2);
  uVar1 = param_1 + 8 & 3;
  uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc);
  pcVar4 = (code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  if (pcVar4 != (code *)0x0) {
    (*pcVar4)();
  }
  uVar1 = param_1 + 0x10 & 3;
  uVar2 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  *puRam02036584 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0xc & 3;
  uVar2 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  Mem_DestroyHeap(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  *(undefined4 *)(param_1 + 0xc) = 0;
  return uVar3;
}

