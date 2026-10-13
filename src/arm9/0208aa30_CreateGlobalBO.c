/* Decompiled C draft; module arm9; ROM address 0208aa30. No matching claim. */
#include "types.h"
#include "deps/0208aa30_CreateGlobalBO.h"

void CreateGlobalBO(undefined4 param_1)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar4 = Mem_AllocateHeap(param_1,uRam0208aae8);
  *puRam0208aaec = uVar4;
  LoadSeveralBMModels(param_1);
  puVar3 = puRam0208aaf0;
  puVar2 = puRam0208aaec;
  *(undefined4 *)
   ((*(uint *)((uint)puRam0208aaec & 0xfffffffc) >> ((uint)puRam0208aaec & 3) * 8 |
    *(uint *)((uint)puRam0208aaec & 0xfffffffc) << ((uint)puRam0208aaec & 3) * -8 + 0x20) + 0x73c) =
       9;
  *puVar3 = 0;
  uVar6 = (uint)puVar2 & 3;
  uVar7 = *(uint *)((uint)puVar2 & 0xfffffffc);
  G3i_OrthoW_(0x60000,0xfffa0000,0xfff80000,0x80000,0,0x1000,0x200,1,
              (uint *)(uintptr_t)((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + iRam0208aaf4));
  iVar5 = iRam0208aaf8;
  uVar6 = *(uint *)((uint)puRam0208aaec & 0xfffffffc) >> ((uint)puRam0208aaec & 3) * 8 |
          *(uint *)((uint)puRam0208aaec & 0xfffffffc) << ((uint)puRam0208aaec & 3) * -8 + 0x20;
  *(undefined2 *)(uVar6 + 0x784) = 0;
  iVar5 = uVar6 + iVar5;
  uVar1 = (undefined2)uRam0208aafc;
  *(undefined2 *)(iVar5 + 2) = 0;
  *(undefined2 *)(iVar5 + 4) = uVar1;
  *(undefined4 *)(iVar5 + 8) = 0;
  return;
}

