/* Decompiled C draft; module arm9; ROM address 0208e098. No matching claim. */
#include "types.h"
#include "deps/0208e098_CreateExplosionInstances.h"

void CreateExplosionInstances(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  uint local_38;
  undefined4 local_28;
  
  uVar1 = uRam0208e22c;
  uVar8 = 0;
  local_38 = 0;
  local_28 = 0x1000;
  do {
    uVar5 = (uint)*(ushort *)(iRam0208e230 + uVar8 * 0x2c);
    puVar7 = (ushort *)(iRam0208e230 + uVar8 * 0x2c);
    if (uVar5 != 0) {
      uVar2 = Mem_AllocateHeap(param_1,uVar5 << 2);
      *(undefined4 *)
       ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
        *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + uVar8 * 4 + 0x48) = uVar2;
      if (*puVar7 != 0) {
        uVar5 = local_38;
        do {
          uVar4 = (uint)(puVar7 + 0xc) & 3;
          uVar6 = *(uint *)((uint)(puVar7 + 0xc) & 0xfffffffc);
          iVar3 = Mem_AllocateHeap(param_1,uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
          uVar4 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + uVar8 * 4 + 0x48;
          uVar6 = uVar4 & 3;
          uVar4 = *(uint *)(uVar4 & 0xfffffffc);
          *(int *)((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + uVar5 * 4) = iVar3;
          uVar4 = (uint)(puVar7 + 2) & 3;
          uVar6 = *(uint *)((uint)(puVar7 + 2) & 0xfffffffc);
          if (uVar6 >> uVar4 * 8 == 0 && uVar6 << uVar4 * -8 + 0x20 == 0) {
            *(undefined4 *)(iVar3 + 0x90) = 0;
          }
          else {
            uVar2 = Mem_AllocateHeap(param_1,0x38);
            *(undefined4 *)(iVar3 + 0x90) = uVar2;
          }
          uVar4 = (uint)(puVar7 + 4) & 3;
          uVar6 = *(uint *)((uint)(puVar7 + 4) & 0xfffffffc);
          if (uVar6 >> uVar4 * 8 == 0 && uVar6 << uVar4 * -8 + 0x20 == 0) {
            *(undefined4 *)(iVar3 + 0x94) = 0;
          }
          else {
            uVar2 = Mem_AllocateHeap(param_1,0x38);
            *(undefined4 *)(iVar3 + 0x94) = uVar2;
          }
          uVar4 = (uint)(puVar7 + 6) & 3;
          uVar6 = *(uint *)((uint)(puVar7 + 6) & 0xfffffffc);
          if (uVar6 >> uVar4 * 8 == 0 && uVar6 << uVar4 * -8 + 0x20 == 0) {
            *(undefined4 *)(iVar3 + 0x98) = 0;
          }
          else {
            uVar2 = Mem_AllocateHeap(param_1,0x38);
            *(undefined4 *)(iVar3 + 0x98) = uVar2;
          }
          *(uint *)(iVar3 + 0x8c) = uVar8;
          uVar4 = (uint)(puVar7 + 8) & 3;
          uVar6 = *(uint *)((uint)(puVar7 + 8) & 0xfffffffc);
          *(uint *)(iVar3 + 0x80) = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
          uVar4 = (uint)(puVar7 + 10) & 3;
          uVar6 = *(uint *)((uint)(puVar7 + 10) & 0xfffffffc);
          *(uint *)(iVar3 + 0x84) = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
          IntrusiveListWrapper_InsertLast
                    ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                     *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xc + uVar8 * 0xc,
                     iVar3);
          if (uVar8 == 2) {
            uVar6 = *(uint *)(uRam0208e234 & 0xfffffffc) >> (uRam0208e234 & 3) * 8 |
                    *(uint *)(uRam0208e234 & 0xfffffffc) << (uRam0208e234 & 3) * -8 + 0x20;
            uVar4 = uVar6 & 3;
            uVar6 = *(uint *)(uVar6 & 0xfffffffc);
            uVar2 = uRam0208e238;
            if ((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) != 0xc) {
              uVar2 = local_28;
            }
            *(undefined4 *)(iVar3 + 0x9c) = uVar2;
            *(undefined4 *)(iVar3 + 0xa0) = uVar2;
            *(undefined4 *)(iVar3 + 0xa4) = uVar2;
          }
          uVar5 = uVar5 + 1 & 0xffff;
        } while (uVar5 < *puVar7);
      }
    }
    uVar8 = uVar8 + 1 & 0xffff;
  } while (uVar8 < 5);
  return;
}

