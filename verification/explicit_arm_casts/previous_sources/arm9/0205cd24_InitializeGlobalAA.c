/* Decompiled C draft; module arm9; ROM address 0205cd24. No matching claim. */
#include "types.h"
#include "deps/0205cd24_InitializeGlobalAA.h"

void InitializeGlobalAA(undefined4 param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  uVar5 = (*(uint *)(uRam0205cfc0 & 0xfffffffc) >> (uRam0205cfc0 & 3) * 8 |
          *(uint *)(uRam0205cfc0 & 0xfffffffc) << (uRam0205cfc0 & 3) * -8 + 0x20) + 8;
  uVar7 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) != 5) {
    return;
  }
  uVar3 = Mem_AllocateHeap(param_1,0x760);
  *puRam0205cfc4 = uVar3;
  uVar3 = Mem_AllocateHeapAligned(param_1,0x6c,0x20);
  puVar2 = puRam0205cfc4;
  uStack_30 = 0;
  iVar11 = 0;
  iVar9 = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puRam0205cfc4 & 0xfffffffc) >> ((uint)puRam0205cfc4 & 3) * 8 |
    *(uint *)((uint)puRam0205cfc4 & 0xfffffffc) << ((uint)puRam0205cfc4 & 3) * -8 + 0x20) + 0x754) =
       uVar3;
  uStack_2c = 0;
  do {
    uVar3 = Mem_AllocateHeapAligned(param_1,0x14,0x20);
    *(undefined4 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + iVar11 + 0x328) =
         uVar3;
    iVar8 = uStack_2c;
    iVar10 = uStack_2c;
    do {
      uVar3 = Mem_AllocateHeapAligned(param_1,0x14,0x20);
      iVar10 = iVar10 + 1;
      *(undefined4 *)
       (iVar8 + iVar9 + (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
                        *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) +
       1000) = uVar3;
      iVar8 = iVar8 + 0xc;
    } while (iVar10 < 4);
    iVar11 = iVar11 + 0xc;
    uStack_30 = uStack_30 + 1;
    iVar9 = iVar9 + 0x30;
  } while (uStack_30 < 0x10);
  *(undefined1 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0xfc) =
       *(undefined1 *)
        ((*(uint *)(uRam0205cfc8 & 0xfffffffc) >> (uRam0205cfc8 & 3) * 8 |
         *(uint *)(uRam0205cfc8 & 0xfffffffc) << (uRam0205cfc8 & 3) * -8 + 0x20) + 4);
  uVar5 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
          *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x754;
  uVar7 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  Mem_CpuFill8(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,0,0x6c);
  iVar9 = iRam0205cfcc;
  puVar2 = puRam0205cfc4;
  iVar8 = 0;
  iVar11 = 0;
  do {
    Mem_CpuFill8((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
                 *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x104 +
                 iVar11,0,0x68);
    iVar8 = iVar8 + 1;
    iVar10 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
             *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + iVar9;
    *(byte *)(iVar10 + iVar11) = *(byte *)(iVar10 + iVar11) & 0xfe;
    iVar11 = iVar11 + 0x88;
  } while (iVar8 < 4);
  uVar5 = *(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
          *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20;
  uVar7 = 0;
  *(undefined1 *)(uVar5 + 0x748) = 0;
  *(undefined1 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x749) =
       *(undefined1 *)(uVar5 + 0xfc);
  puVar2 = puRam0205cfc4;
  do {
    *(undefined1 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + uVar7 + 0x74a) = 0;
    iVar9 = uVar7 * 2;
    uVar7 = uVar7 + 1 & 0xff;
    *(undefined2 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + iVar9 + 0x740) = 0;
  } while (uVar7 < 4);
  func_0205ad88();
  func_0205a6b4();
  puVar2 = puRam0205cfc4;
  uVar7 = 0;
  uVar5 = *(uint *)((uint)puRam0205cfc4 & 0xfffffffc) >> ((uint)puRam0205cfc4 & 3) * 8 |
          *(uint *)((uint)puRam0205cfc4 & 0xfffffffc) << ((uint)puRam0205cfc4 & 3) * -8 + 0x20;
  *(ushort *)(uVar5 + 0x75c) = *(ushort *)(uVar5 + 0x75c) | 1;
  uVar5 = *(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
          *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20;
  *(ushort *)(uVar5 + 0x75c) = *(ushort *)(uVar5 + 0x75c) | 0x40;
  uVar5 = *(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
          *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20;
  *(undefined2 *)(uVar5 + 0x10) = 0;
  *(undefined2 *)(uVar5 + 0x12) = 1;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x758) = 0;
  iVar9 = iRam0205cfcc;
  uVar5 = uRam0205cfc8;
  do {
    iVar11 = uVar7 * 0x88;
    uVar4 = uVar5 & 3;
    uVar6 = *(uint *)(uVar5 & 0xfffffffc);
    cVar1 = *(char *)((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + uVar7 + 6);
    *(undefined4 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + iVar11 + 0x184) = 0;
    if (cVar1 < '\0') {
      iVar8 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
              *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + iVar9;
      *(byte *)(iVar8 + iVar11) = *(byte *)(iVar8 + iVar11) & 1;
    }
    else {
      uVar4 = func_0205d27c(cVar1);
      iVar8 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
              *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + iVar9;
      *(byte *)(iVar8 + iVar11) = *(byte *)(iVar8 + iVar11) & 1 | (byte)((uVar4 & 0x7f) << 1);
    }
    uVar7 = uVar7 + 1 & 0xff;
  } while (uVar7 < 4);
  StateDualHandler_Create
            (*(uint *)((uint)puRam0205cfc4 & 0xfffffffc) >> ((uint)puRam0205cfc4 & 3) * 8 |
             *(uint *)((uint)puRam0205cfc4 & 0xfffffffc) << ((uint)puRam0205cfc4 & 3) * -8 + 0x20,
             uRam0205cfd0,6,0);
  return;
}

