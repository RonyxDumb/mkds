/* Decompiled C draft; module arm9; ROM address 0208af40. No matching claim. */
#include "types.h"
#include "deps/0208af40_CreateLoadPhysicalParams.h"

void CreateLoadPhysicalParams(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = Mem_AllocateHeap(param_1,0x14);
  *puRam0208afd8 = uVar2;
  uVar2 = Mem_AllocateHeap(param_1,param_2 * 0x98);
  *(undefined4 *)
   (*(uint *)((uint)puRam0208afd8 & 0xfffffffc) >> ((uint)puRam0208afd8 & 3) * 8 |
   *(uint *)((uint)puRam0208afd8 & 0xfffffffc) << ((uint)puRam0208afd8 & 3) * -8 + 0x20) = uVar2;
  uVar2 = Mem_AllocateHeap(param_1,param_2 << 3);
  *(undefined4 *)
   ((*(uint *)((uint)puRam0208afd8 & 0xfffffffc) >> ((uint)puRam0208afd8 & 3) * 8 |
    *(uint *)((uint)puRam0208afd8 & 0xfffffffc) << ((uint)puRam0208afd8 & 3) * -8 + 0x20) + 4) =
       uVar2;
  uVar2 = FindFileBuffer_KME_KM1_KM2_KSB_from_thumb(uRam0208afdc);
  *(undefined4 *)
   ((*(uint *)((uint)puRam0208afd8 & 0xfffffffc) >> ((uint)puRam0208afd8 & 3) * 8 |
    *(uint *)((uint)puRam0208afd8 & 0xfffffffc) << ((uint)puRam0208afd8 & 3) * -8 + 0x20) + 0xc) =
       uVar2;
  uVar2 = FindFileBuffer_KME_KM1_KM2_KSB_from_thumb(uRam0208afe0);
  puVar1 = puRam0208afd8;
  *(undefined4 *)
   ((*(uint *)((uint)puRam0208afd8 & 0xfffffffc) >> ((uint)puRam0208afd8 & 3) * 8 |
    *(uint *)((uint)puRam0208afd8 & 0xfffffffc) << ((uint)puRam0208afd8 & 3) * -8 + 0x20) + 0x10) =
       uVar2;
  uVar3 = (uint)puVar1 & 3;
  uVar4 = *(uint *)((uint)puVar1 & 0xfffffffc);
  uVar5 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar3 = uVar5 + 0xc;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x10;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar5 + 8) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  return;
}

