/* Decompiled C draft; module arm9; ROM address 0208a460. No matching claim. */
#include "types.h"
#include "deps/0208a460_LoadSeveralBMModels.h"

void LoadSeveralBMModels(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  uVar6 = uRam0208a67c;
  iVar9 = 0;
  do {
    uVar10 = uVar6 & 3;
    uVar7 = *(uint *)(uVar6 & 0xfffffffc);
    *(undefined4 *)((uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) + iVar9 * 4) = 0;
    iVar9 = (iVar9 + 1) * 0x10000 >> 0x10;
  } while (iVar9 < 8);
  iVar1 = IsAwardOrStaffRoll_0();
  iVar9 = iRam0208a680;
  uVar6 = uRam0208a67c;
  if (iVar1 != 0) {
    return;
  }
  uVar10 = 0;
  do {
    if (uVar10 == 2) {
      uVar2 = Mem_AllocateHeap(param_1,0x14);
      *(undefined4 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 8) = uVar2;
      uVar3 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
              *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
      uVar8 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      uVar7 = uVar3 + 8 & 3;
      uVar3 = *(uint *)(uVar3 + 8 & 0xfffffffc);
      puVar5 = (uint *)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
      *puVar5 = *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20;
      puVar5[1] = 0;
      uVar7 = uVar8 + 8 & 3;
      uVar3 = *(uint *)(uVar8 + 8 & 0xfffffffc);
      puVar5[2] = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
      uVar7 = uVar8 + 0xc & 3;
      uVar3 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
      puVar5[3] = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
      *(undefined2 *)(puVar5 + 4) = *(undefined2 *)(uVar8 + 0x10);
    }
    else {
      uVar2 = Mem_AllocateHeap(param_1,0x14);
      *(undefined4 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + uVar10 * 4) = uVar2;
      uVar7 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
              *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + uVar10 * 4;
      uVar3 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      LoadModelBMFromMD(param_1,uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20,uVar10 * 0xc + iVar9
                        ,uVar10 & 0xffff);
    }
    uVar10 = (int)((uVar10 + 1) * 0x10000) >> 0x10;
  } while ((int)uVar10 < 3);
  uVar10 = *(uint *)(uRam0208a684 & 0xfffffffc) >> (uRam0208a684 & 3) * 8 |
           *(uint *)(uRam0208a684 & 0xfffffffc) << (uRam0208a684 & 3) * -8 + 0x20;
  uVar6 = uVar10 + 8;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if ((uVar6 != 2) &&
     (uVar10 = uVar10 + 0x1c, uVar7 = uVar10 & 3, uVar10 = *(uint *)(uVar10 & 0xfffffffc),
     (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) != 1)) {
    if (uVar6 != 4) {
      uVar4 = Mem_AllocateHeap(param_1,0x14);
      uVar2 = uRam0208a698;
      uVar10 = uRam0208a67c;
      *(undefined4 *)
       ((*(uint *)(uRam0208a67c & 0xfffffffc) >> (uRam0208a67c & 3) * 8 |
        *(uint *)(uRam0208a67c & 0xfffffffc) << (uRam0208a67c & 3) * -8 + 0x20) + 0xc) = uVar4;
      uVar6 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      uVar6 = (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) + 0xc;
      uVar10 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      LoadModelBMFromMD(param_1,uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20,uVar2,3);
      return;
    }
    uVar4 = Mem_AllocateHeap(param_1,0x14);
    uVar2 = uRam0208a690;
    uVar10 = uRam0208a67c;
    *(undefined4 *)
     ((*(uint *)(uRam0208a67c & 0xfffffffc) >> (uRam0208a67c & 3) * 8 |
      *(uint *)(uRam0208a67c & 0xfffffffc) << (uRam0208a67c & 3) * -8 + 0x20) + 0x18) = uVar4;
    uVar6 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar6 = (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) + 0x18;
    uVar10 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    LoadModelBMFromMD(param_1,uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20,uVar2,6);
    uVar4 = Mem_AllocateHeap(param_1,0x14);
    uVar2 = uRam0208a694;
    uVar10 = uRam0208a67c;
    *(undefined4 *)
     ((*(uint *)(uRam0208a67c & 0xfffffffc) >> (uRam0208a67c & 3) * 8 |
      *(uint *)(uRam0208a67c & 0xfffffffc) << (uRam0208a67c & 3) * -8 + 0x20) + 0x1c) = uVar4;
    uVar6 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar6 = (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) + 0x1c;
    uVar10 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    LoadModelBMFromMD(param_1,uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20,uVar2,7);
    return;
  }
  uVar4 = Mem_AllocateHeap(param_1,0x14);
  uVar2 = uRam0208a688;
  uVar10 = uRam0208a67c;
  *(undefined4 *)
   ((*(uint *)(uRam0208a67c & 0xfffffffc) >> (uRam0208a67c & 3) * 8 |
    *(uint *)(uRam0208a67c & 0xfffffffc) << (uRam0208a67c & 3) * -8 + 0x20) + 0x10) = uVar4;
  uVar6 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar6 = (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) + 0x10;
  uVar10 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  LoadModelBMFromMD(param_1,uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20,uVar2,4);
  uVar4 = Mem_AllocateHeap(param_1,0x14);
  uVar2 = uRam0208a68c;
  uVar10 = uRam0208a67c;
  *(undefined4 *)
   ((*(uint *)(uRam0208a67c & 0xfffffffc) >> (uRam0208a67c & 3) * 8 |
    *(uint *)(uRam0208a67c & 0xfffffffc) << (uRam0208a67c & 3) * -8 + 0x20) + 0x14) = uVar4;
  uVar6 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar6 = (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) + 0x14;
  uVar10 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  LoadModelBMFromMD(param_1,uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20,uVar2,5);
  return;
}

