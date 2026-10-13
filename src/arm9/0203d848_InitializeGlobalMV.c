/* Decompiled C draft; module arm9; ROM address 0203d848. No matching claim. */
#include "types.h"
#include "deps/0203d848_InitializeGlobalMV.h"

void InitializeGlobalMV(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = Mem_AllocateHeap(param_1,uRam0203d8e4);
  uVar3 = uRam0203d8e8 & 3;
  uVar4 = *(uint *)(uRam0203d8e8 & 0xfffffffc);
  *puRam0203d8ec = uVar2;
  uVar2 = Mem_AllocateHeap(param_1,(*(ushort *)
                                     ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x98) + 1)
                                   * 4);
  *(undefined4 *)
   ((*(uint *)((uint)puRam0203d8ec & 0xfffffffc) >> ((uint)puRam0203d8ec & 3) * 8 |
    *(uint *)((uint)puRam0203d8ec & 0xfffffffc) << ((uint)puRam0203d8ec & 3) * -8 + 0x20) + 0x4d4) =
       uVar2;
  uVar2 = FindFileBuffer_MAR_EFT_from_thumb(uRam0203d8f0);
  *(undefined4 *)
   ((*(uint *)((uint)puRam0203d8ec & 0xfffffffc) >> ((uint)puRam0203d8ec & 3) * 8 |
    *(uint *)((uint)puRam0203d8ec & 0xfffffffc) << ((uint)puRam0203d8ec & 3) * -8 + 0x20) + 0x4dc) =
       uVar2;
  uVar2 = FindFileBuffer_MAR_EFT_from_thumb(uRam0203d8f4);
  puVar1 = puRam0203d8ec;
  *(undefined4 *)
   ((*(uint *)((uint)puRam0203d8ec & 0xfffffffc) >> ((uint)puRam0203d8ec & 3) * 8 |
    *(uint *)((uint)puRam0203d8ec & 0xfffffffc) << ((uint)puRam0203d8ec & 3) * -8 + 0x20) + 0x4c8) =
       uVar2;
  uVar3 = (uint)puVar1 & 3;
  uVar4 = *(uint *)((uint)puVar1 & 0xfffffffc);
  uVar3 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x4c8;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  LoadCurrentCourseRanktime(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
  uVar3 = (*(uint *)(uRam0203d8f8 & 0xfffffffc) >> (uRam0203d8f8 & 3) * 8 |
          *(uint *)(uRam0203d8f8 & 0xfffffffc) << (uRam0203d8f8 & 3) * -8 + 0x20) + 8;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) == 4) {
    SomethingMissionModeType5Areas(param_1);
  }
  CreateGlobalMV();
  return;
}

