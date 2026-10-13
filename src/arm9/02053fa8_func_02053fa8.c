/* Decompiled C draft; module arm9; ROM address 02053fa8. No matching claim. */
#include "types.h"
#include "deps/02053fa8_func_02053fa8.h"

void func_02053fa8(void)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  uVar3 = uRam020541f4;
  iVar10 = 0;
  iVar7 = 0;
  uVar2 = (undefined2)uRam020541f0;
  do {
    iVar9 = 0;
    *(undefined2 *)
     ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + iVar10 * 8 + 0x4a) = uVar2;
    uVar4 = *(uint *)(uVar3 & 0xfffffffc);
    do {
      *(undefined1 *)
       ((uVar4 >> (uVar3 & 3) * 8 | uVar4 << (uVar3 & 3) * -8 + 0x20) + 0x44 + iVar7 + iVar9) = 0;
      uVar5 = uRam020541f8;
      uVar1 = uRam020541f4;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 6);
    iVar10 = iVar10 + 1;
    iVar7 = iVar7 + 8;
  } while (iVar10 < 7);
  *(undefined1 *)
   ((*(uint *)(uRam020541f4 & 0xfffffffc) >> (uRam020541f4 & 3) * 8 |
    *(uint *)(uRam020541f4 & 0xfffffffc) << (uRam020541f4 & 3) * -8 + 0x20) + 0x86) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x87) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x84) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x80) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x85) = 0xff;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x88) = 0xff;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x8a) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x8b) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x82) = 0;
  uVar3 = uVar5 & 3;
  uVar4 = *(uint *)(uVar5 & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar4 = uVar3 & 3;
  uVar5 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x7c;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  Mem_CpuCopy8((ushort *)(uintptr_t)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0xc),
               (uint *)(uintptr_t)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20),0x14);
  uVar1 = uRam020541f4;
  uVar3 = (*(uint *)(uRam020541f4 & 0xfffffffc) >> (uRam020541f4 & 3) * 8 |
          *(uint *)(uRam020541f4 & 0xfffffffc) << (uRam020541f4 & 3) * -8 + 0x20) + 0x7c;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar5 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar3 = (*(uint *)(uRam020541fc & 0xfffffffc) >> (uRam020541fc & 3) * 8 |
          *(uint *)(uRam020541fc & 0xfffffffc) << (uRam020541fc & 3) * -8 + 0x20) + 4;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(byte *)(uVar5 + 0x14) =
       *(byte *)(uVar5 + 0x14) & 0xf |
       (byte)(((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xf) << 4);
  iVar7 = 0;
  uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x7c;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  iVar10 = 0;
  *(byte *)(uVar3 + 0x14) = *(byte *)(uVar3 + 0x14) & 0xf0;
  iVar9 = 0;
  do {
    iVar6 = 0;
    iVar8 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x188;
    *(byte *)(iVar8 + iVar10) = *(byte *)(iVar8 + iVar10) & 0xfe;
    *(undefined1 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar10 + 0x187) = 0;
    uVar3 = *(uint *)(uVar1 & 0xfffffffc);
    do {
      *(undefined1 *)
       ((uVar3 >> (uVar1 & 3) * 8 | uVar3 << (uVar1 & 3) * -8 + 0x20) + 0x16c + iVar10 + iVar6) = 0;
      uVar4 = uRam020541f4;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 6);
    iVar7 = iVar7 + 1;
    iVar10 = iVar10 + 0xe0;
  } while (iVar7 < 4);
  *(short *)((*(uint *)(uRam020541f4 & 0xfffffffc) >> (uRam020541f4 & 3) * 8 |
             *(uint *)(uRam020541f4 & 0xfffffffc) << (uRam020541f4 & 3) * -8 + 0x20) + 0x432) =
       (short)uRam020541f0;
  iVar7 = iRam02054200;
  *(undefined1 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x438) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x434) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x439) = 1;
  *(undefined1 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x43a) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x436) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x43c) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x43d) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x43b) = 0;
  uVar3 = *(uint *)(uVar4 & 0xfffffffc);
  do {
    *(undefined1 *)((uVar3 >> (uVar4 & 3) * 8 | uVar3 << (uVar4 & 3) * -8 + 0x20) + iVar7 + iVar9) =
         0;
    uVar1 = uRam020541f4;
    iVar9 = iVar9 + 1;
  } while (iVar9 < 6);
  *(undefined1 *)
   ((*(uint *)(uRam020541f4 & 0xfffffffc) >> (uRam020541f4 & 3) * 8 |
    *(uint *)(uRam020541f4 & 0xfffffffc) << (uRam020541f4 & 3) * -8 + 0x20) + 0x457) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x458) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1699) = 0;
  uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  *(ushort *)(uVar3 + 0x454) = *(ushort *)(uVar3 + 0x454) & 0xfffe;
  CleanSaveDataHolderFlagBytes_from_thumb();
  func_02054208((*(uint *)(uRam020541f4 & 0xfffffffc) >> (uRam020541f4 & 3) * 8 |
                *(uint *)(uRam020541f4 & 0xfffffffc) << (uRam020541f4 & 3) * -8 + 0x20) +
                iRam02054204);
  return;
}

