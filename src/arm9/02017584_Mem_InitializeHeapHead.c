/* Decompiled C draft; module arm9; ROM address 02017584. No matching claim. */
#include "types.h"
#include "deps/02017584_Mem_InitializeHeapHead.h"

void Mem_InitializeHeapHead
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               ushort param_5)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  *param_1 = param_2;
  param_1[6] = param_3;
  param_1[7] = param_4;
  param_1[8] = 0;
  uVar1 = (uint)(param_1 + 8) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  param_1[8] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xffffff00;
  uVar1 = (uint)(param_1 + 8) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  param_1[8] = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | param_5 & 0xff;
  IntrusiveListWrapper_InitializeEmpty(param_1 + 3,4);
  if (*(uint *)((uint)puRam0201760c & 0xfffffffc) >> ((uint)puRam0201760c & 3) * 8 == 0 &&
      *(uint *)((uint)puRam0201760c & 0xfffffffc) << ((uint)puRam0201760c & 3) * -8 + 0x20 == 0) {
    IntrusiveListWrapper_InitializeEmpty((undefined4 *)(uintptr_t)(uRam02017610),4);
    *puRam0201760c = 1;
  }
  uVar2 = Mem_FindTopParentHeapHeadList((undefined4)(uintptr_t)(param_1));
  IntrusiveListWrapper_InsertLast(uVar2,(int)(uintptr_t)(param_1));
  return;
}

