/* Decompiled C draft; module arm9; ROM address 02045590. No matching claim. */
#include "types.h"
#include "deps/02045590_PopulateNextRaceConfig.h"

void PopulateNextRaceConfig(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  uVar7 = uRam0204586c;
  *(undefined4 *)
   ((*(uint *)(uRam0204586c & 0xfffffffc) >> (uRam0204586c & 3) * 8 |
    *(uint *)(uRam0204586c & 0xfffffffc) << (uRam0204586c & 3) * -8 + 0x20) + 0x1e8) = 0x14;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x1ec) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x1f0) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 500) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x1f8) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x1fc) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x200) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x204) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x208) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x20c) = 0;
  Mem_CpuFill8((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
               *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x210,0,0x2c);
  uVar2 = uRam0204586c;
  uVar7 = 0;
  *(undefined1 *)
   ((*(uint *)(uRam0204586c & 0xfffffffc) >> (uRam0204586c & 3) * 8 |
    *(uint *)(uRam0204586c & 0xfffffffc) << (uRam0204586c & 3) * -8 + 0x20) + 0x23c) = 0xff;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x23d) = 0xff;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x23e) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x23f) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x240) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x244) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x248) = 1;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x24a) = 0xff;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x24b) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x24c) = 0xff;
  uVar3 = uRam02045870;
  uVar4 = 0;
  do {
    iVar5 = uVar7 * 0x30;
    *(uint *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x250) = uVar7;
    *(uint *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x254) = uVar7 * 3
    ;
    *(uint *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 600) =
         (uint)(uVar7 != 0);
    *(undefined4 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x25c) = 0xffffffff;
    *(undefined4 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x260) = 3;
    *(uint *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x264) = uVar7;
    uVar7 = uVar7 + 1 & 0xffff;
    *(undefined4 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x268) = 3;
    *(undefined2 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x26c) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x270) = 0;
    *(undefined1 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x27c) = 0;
    uVar1 = uVar3 & 3;
    uVar9 = *(uint *)(uVar3 & 0xfffffffc);
    uVar9 = uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20;
    uVar1 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    *(byte *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x27d) =
         (byte)(uVar9 >> uVar1 * 8) | (byte)(uVar9 << uVar1 * -8 + 0x20);
    *(undefined4 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x274) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x278) = 0;
  } while (uVar7 < 8);
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x3b0) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x380) = 1;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x3d0) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x3d1) = 0;
  uVar2 = uRam0204586c;
  uVar7 = 0;
  do {
    iVar5 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + uVar4;
    uVar4 = uVar4 + 1 & 0xffff;
    *(undefined1 *)(iVar5 + 0x3d2) = 0;
  } while (uVar4 < 2);
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x3d4) = 0;
  uVar4 = uRam0204586c;
  do {
    iVar5 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + uVar7;
    uVar7 = uVar7 + 1 & 0xffff;
    *(undefined1 *)(iVar5 + 0x3d5) = 0xff;
  } while (uVar7 < 2);
  uVar7 = 0;
  *(undefined2 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x3d8) = 0;
  uVar2 = uRam0204586c;
  uVar4 = 0;
  do {
    uVar3 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x3dc;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(undefined1 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + uVar7) = 0;
    uVar7 = uVar7 + 1 & 0xffff;
  } while (uVar7 < 0x21);
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x3e0) = 0;
  uVar7 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
  *(undefined1 *)(uVar7 + 0x3ea) = 0;
  *(undefined1 *)(uVar7 + 0x3eb) = 0;
  *(undefined2 *)(uVar7 + 1000) = 0;
  uVar7 = uRam0204586c;
  do {
    uVar2 = uVar7 & 3;
    uVar3 = *(uint *)(uVar7 & 0xfffffffc);
    iVar6 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x3ec;
    iVar8 = iVar6 + uVar4 * 4;
    *(undefined1 *)(iVar8 + 2) = 0;
    iVar5 = uVar4 * 4;
    *(undefined1 *)(iVar8 + 3) = 0;
    uVar4 = uVar4 + 1 & 0xffff;
    *(undefined2 *)(iVar6 + iVar5) = 0;
  } while (uVar4 < 5);
  CreateGlobalLU();
  CreateGlobalRE();
  PrepareRace();
  return;
}

