/* Decompiled C draft; module arm9; ROM address 020b03bc. No matching claim. */
#include "types.h"
#include "deps/020b03bc_Maybe_race_m_b.h"

void Maybe_race_m_b(void)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar8;
  
  uVar3 = (*(uint *)(DAT_020b0b40 & 0xfffffffc) >> (DAT_020b0b40 & 3) * 8 |
          *(uint *)(DAT_020b0b40 & 0xfffffffc) << (DAT_020b0b40 & 3) * -8 + 0x20) + 0xc;
  uVar7 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
  if (uVar3 == 3) {
    InitializeRaceIntroData();
    return;
  }
  if (uVar3 == 5) {
    return;
  }
  if (uVar3 == 6) {
    LoadSomeEndingStaffRollStuff();
    GetActiveExecutionContext();
    ExecutionContext_GetHeapHandle();
    LoadStaffRollStuff();
    return;
  }
  GetActiveExecutionContext();
  uVar4 = ExecutionContext_GetHeapHandle();
  uVar4 = Mem_AllocateHeap(uVar4,DAT_020b0b44);
  *DAT_020b0b48 = uVar4;
  InitializeGlobalB358();
  AnotherAlloc();
  func_020b65f0();
  CreateGlobalB3C4();
  SomeAlloc();
  uVar3 = (*(uint *)(DAT_020b0b40 & 0xfffffffc) >> (DAT_020b0b40 & 3) * 8 |
          *(uint *)(DAT_020b0b40 & 0xfffffffc) << (DAT_020b0b40 & 3) * -8 + 0x20) + 0xc;
  uVar7 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) == 4) {
    SomeAlloc2();
  }
  func_020bb530();
  CreateGlobalB3EC();
  func_020ba520();
  CreateGlobalB3F0();
  YetAlloc();
  func_020bcb74();
  func_020d20a8();
  func_020d0bd0();
  func_020be7fc();
  func_020beb9c();
  SomeAlloc_0();
  CreateGlobalE8();
  func_020c4780();
  puVar2 = DAT_020b0b48;
  iVar10 = 0;
  *(undefined4 *)
   (*(uint *)((uint)DAT_020b0b48 & 0xfffffffc) >> ((uint)DAT_020b0b48 & 3) * 8 |
   *(uint *)((uint)DAT_020b0b48 & 0xfffffffc) << ((uint)DAT_020b0b48 & 3) * -8 + 0x20) = 0;
  do {
    *(undefined4 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + iVar10 * 4 + 0x80c)
         = 0;
    iVar6 = iVar10 * 4;
    iVar10 = iVar10 + 1;
    *(undefined4 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + iVar6 + 0x814) = 0;
  } while (iVar10 < 7);
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x828) = 1;
  uVar7 = DAT_020b0b40;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x82c) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x830) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x838) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x83c) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x840) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x844) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x848) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x84c) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x850) = 0;
  uVar3 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar8 = uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20;
  uVar3 = uVar8 + 8 & 3;
  uVar7 = *(uint *)(uVar8 + 8 & 0xfffffffc);
  uVar3 = uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20;
  if (uVar3 == 2) {
    if ((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
        *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) == 0x2e) {
      *(undefined4 *)
       ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
        *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x854) = 0x40;
    }
    else {
      *(undefined4 *)
       ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
        *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x854) = 100;
    }
  }
  else if (uVar3 == 4) {
    switch(*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
           *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) {
    case 0x30:
      break;
    case 0x31:
      break;
    case 0x32:
      break;
    case 0x33:
      break;
    default:
      *(undefined4 *)
       ((*(uint *)((uint)DAT_020b0b48 & 0xfffffffc) >> ((uint)DAT_020b0b48 & 3) * 8 |
        *(uint *)((uint)DAT_020b0b48 & 0xfffffffc) << ((uint)DAT_020b0b48 & 3) * -8 + 0x20) + 0x854)
           = 0x86;
      goto LAB_020b05bc;
    }
    *(undefined4 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x854) = 100;
  }
  else {
    *(undefined4 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x854) = 0x86;
  }
LAB_020b05bc:
  puVar2 = DAT_020b0b48;
  iVar10 = 0;
  *(undefined4 *)
   ((*(uint *)((uint)DAT_020b0b48 & 0xfffffffc) >> ((uint)DAT_020b0b48 & 3) * 8 |
    *(uint *)((uint)DAT_020b0b48 & 0xfffffffc) << ((uint)DAT_020b0b48 & 3) * -8 + 0x20) + 0x898) = 0
  ;
  do {
    *(undefined4 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + iVar10 * 4 + 0x89c)
         = 0;
    iVar6 = iVar10 * 4;
    iVar10 = iVar10 + 1;
    *(undefined4 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + iVar6 + 0x8bc) = 0;
  } while (iVar10 < 8);
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x8dc) = 0;
  uVar7 = DAT_020b0b40;
  *(undefined4 *)
   ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
    *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x8e0) = 0xffffffff;
  uVar3 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar8 = uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20;
  uVar3 = uVar8 + 8;
  uVar7 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) == 1) && (1 < *(byte *)(uVar8 + 0x3d0))) {
    *(undefined4 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x8e4) = 1;
  }
  else {
    *(undefined4 *)
     ((*(uint *)((uint)DAT_020b0b48 & 0xfffffffc) >> ((uint)DAT_020b0b48 & 3) * 8 |
      *(uint *)((uint)DAT_020b0b48 & 0xfffffffc) << ((uint)DAT_020b0b48 & 3) * -8 + 0x20) + 0x8e4) =
         0;
  }
  puVar2 = DAT_020b0b48;
  uVar7 = DAT_020b0b40;
  uVar4 = 0;
  *(undefined4 *)
   ((*(uint *)((uint)DAT_020b0b48 & 0xfffffffc) >> ((uint)DAT_020b0b48 & 3) * 8 |
    *(uint *)((uint)DAT_020b0b48 & 0xfffffffc) << ((uint)DAT_020b0b48 & 3) * -8 + 0x20) + 0x908) = 0
  ;
  uVar3 = (uint)puVar2 & 3;
  uVar8 = *(uint *)((uint)puVar2 & 0xfffffffc);
  *(undefined4 *)((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) + 0x90c) = 0;
  uVar3 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar3 = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 8;
  uVar7 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) == 4) {
    uVar4 = IsCurrentMissionLevelStageBeaten_from_thumb();
  }
  puVar2 = DAT_020b0b48;
  *(undefined4 *)
   ((*(uint *)((uint)DAT_020b0b48 & 0xfffffffc) >> ((uint)DAT_020b0b48 & 3) * 8 |
    *(uint *)((uint)DAT_020b0b48 & 0xfffffffc) << ((uint)DAT_020b0b48 & 3) * -8 + 0x20) + 0x910) =
       uVar4;
  uVar3 = (uint)puVar2 & 3;
  uVar7 = *(uint *)((uint)puVar2 & 0xfffffffc);
  Mem_DmaFill32(3,(uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 4,0xc0,0x400);
  Mem_DmaFill32(3,(*(uint *)((uint)DAT_020b0b48 & 0xfffffffc) >> ((uint)DAT_020b0b48 & 3) * 8 |
                  *(uint *)((uint)DAT_020b0b48 & 0xfffffffc) << ((uint)DAT_020b0b48 & 3) * -8 + 0x20
                  ) + DAT_020b0b4c,0xc0,0x400);
  uVar4 = func_020b47c0(DAT_020b0b50);
  Gfx_ReadPalette((int *)(uintptr_t)((*(uint *)((uint)DAT_020b0b48 & 0xfffffffc) >> ((uint)DAT_020b0b48 & 3) * 8 |
                  *(uint *)((uint)DAT_020b0b48 & 0xfffffffc) << ((uint)DAT_020b0b48 & 3) * -8 + 0x20
                  ) + DAT_020b0b54),uVar4);
  uVar4 = func_020b47c0(DAT_020b0b58);
  Gfx_ReadCharGraphicsV2
            ((int *)(uintptr_t)((*(uint *)((uint)DAT_020b0b48 & 0xfffffffc) >> ((uint)DAT_020b0b48 & 3) * 8 |
             *(uint *)((uint)DAT_020b0b48 & 0xfffffffc) << ((uint)DAT_020b0b48 & 3) * -8 + 0x20) +
             DAT_020b0b5c),uVar4);
  uVar4 = func_020b47c0(DAT_020b0b60);
  MaybeReadScreenBlock_0
            ((int *)(uintptr_t)((*(uint *)((uint)DAT_020b0b48 & 0xfffffffc) >> ((uint)DAT_020b0b48 & 3) * 8 |
             *(uint *)((uint)DAT_020b0b48 & 0xfffffffc) << ((uint)DAT_020b0b48 & 3) * -8 + 0x20) +
             DAT_020b0b64),uVar4);
  uVar4 = func_020b47c0(DAT_020b0b68);
  MaybeReadScreenBlock_0
            ((int *)(uintptr_t)((*(uint *)((uint)DAT_020b0b48 & 0xfffffffc) >> ((uint)DAT_020b0b48 & 3) * 8 |
             *(uint *)((uint)DAT_020b0b48 & 0xfffffffc) << ((uint)DAT_020b0b48 & 3) * -8 + 0x20) +
             0x820),uVar4);
  uVar3 = (*(uint *)(DAT_020b0b40 & 0xfffffffc) >> (DAT_020b0b40 & 3) * 8 |
          *(uint *)(DAT_020b0b40 & 0xfffffffc) << (DAT_020b0b40 & 3) * -8 + 0x20) + 8;
  uVar7 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) == 1) {
    uVar4 = func_020b47c0(DAT_020b0b6c);
    Gfx_ReadPalette((int *)(uintptr_t)((*(uint *)((uint)DAT_020b0b48 & 0xfffffffc) >> ((uint)DAT_020b0b48 & 3) * 8 |
                    *(uint *)((uint)DAT_020b0b48 & 0xfffffffc) <<
                    ((uint)DAT_020b0b48 & 3) * -8 + 0x20) + 0x810),uVar4);
    uVar4 = func_020b47c0(DAT_020b0b70);
    Gfx_ReadCharGraphicsV2
              ((int *)(uintptr_t)((*(uint *)((uint)DAT_020b0b48 & 0xfffffffc) >> ((uint)DAT_020b0b48 & 3) * 8 |
               *(uint *)((uint)DAT_020b0b48 & 0xfffffffc) << ((uint)DAT_020b0b48 & 3) * -8 + 0x20) +
               DAT_020b0b74),uVar4);
    uVar4 = func_020b47c0(DAT_020b0b78);
    MaybeReadScreenBlock_0
              ((int *)(uintptr_t)((*(uint *)((uint)DAT_020b0b48 & 0xfffffffc) >> ((uint)DAT_020b0b48 & 3) * 8 |
               *(uint *)((uint)DAT_020b0b48 & 0xfffffffc) << ((uint)DAT_020b0b48 & 3) * -8 + 0x20) +
               DAT_020b0b7c),uVar4);
    uVar3 = (*(uint *)((uint)DAT_020b0b48 & 0xfffffffc) >> ((uint)DAT_020b0b48 & 3) * 8 |
            *(uint *)((uint)DAT_020b0b48 & 0xfffffffc) << ((uint)DAT_020b0b48 & 3) * -8 + 0x20) +
            0x81c;
    uVar7 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar7 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
    uVar3 = uVar7 + 0x14;
    uVar8 = uVar3 & 3;
    uVar5 = *(uint *)(uVar3 & 0xfffffffc);
    uVar7 = uVar7 + 0x10;
    uVar3 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    Arm_FlushRange(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20,
                   uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20);
    uVar3 = (*(uint *)((uint)DAT_020b0b48 & 0xfffffffc) >> ((uint)DAT_020b0b48 & 3) * 8 |
            *(uint *)((uint)DAT_020b0b48 & 0xfffffffc) << ((uint)DAT_020b0b48 & 3) * -8 + 0x20) +
            0x824;
    uVar7 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar8 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
    uVar3 = uVar8 + 8;
    uVar7 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    Arm_FlushRange(uVar8 + 0xc,uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
  }
  iVar10 = GetChoises_s_b_Pallette_from_thumb();
  uVar7 = DAT_020b0b80;
  uVar3 = iVar10 + 0xcU & 3;
  uVar8 = *(uint *)(iVar10 + 0xcU & 0xfffffffc);
  iVar10 = 0;
  do {
    iVar6 = (iVar10 + 0x80) * 2;
    uVar5 = uVar7 & 3;
    uVar9 = *(uint *)(uVar7 & 0xfffffffc);
    iVar10 = iVar10 + 1;
    *(undefined2 *)((uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) + iVar6) =
         *(undefined2 *)((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) + iVar6);
  } while (iVar10 < 0x80);
  iVar10 = GetChoises_s_b_Pallette_from_thumb();
  uVar3 = iVar10 + 0xcU & 3;
  uVar7 = *(uint *)(iVar10 + 0xcU & 0xfffffffc);
  *(undefined2 *)(uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) =
       *(undefined2 *)
        ((*(uint *)(DAT_020b0b80 & 0xfffffffc) >> (DAT_020b0b80 & 3) * 8 |
         *(uint *)(DAT_020b0b80 & 0xfffffffc) << (DAT_020b0b80 & 3) * -8 + 0x20) + 0x200);
  iVar10 = GetChoises_s_b_Pallette_from_thumb();
  uVar3 = iVar10 + 0xcU & 3;
  uVar7 = *(uint *)(iVar10 + 0xcU & 0xfffffffc);
  Arm_FlushRange(uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20,0x200);
  iVar10 = 0;
  do {
    iVar11 = iVar10 + 0xe0;
    iVar6 = GetChoises_s_b_Pallette_from_thumb();
    uVar3 = iVar6 + 0xcU & 3;
    uVar7 = *(uint *)(iVar6 + 0xcU & 0xfffffffc);
    uVar1 = *(undefined2 *)((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + iVar11 * 2);
    uVar3 = func_020c3e2c(0);
    iVar10 = iVar10 + 1;
    uVar3 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0xc;
    uVar7 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(undefined2 *)((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + iVar11 * 2) = uVar1;
  } while (iVar10 < 0x20);
  G2x_SetBlendAlpha_(DAT_020b0b84,0,0x3f,6);
  uVar3 = (*(uint *)(DAT_020b0b40 & 0xfffffffc) >> (DAT_020b0b40 & 3) * 8 |
          *(uint *)(DAT_020b0b40 & 0xfffffffc) << (DAT_020b0b40 & 3) * -8 + 0x20) + 8;
  uVar7 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (uVar3 >> uVar7 * 8 == 0 && uVar3 << uVar7 * -8 + 0x20 == 0) {
    uVar8 = GetRacePaletteBlock(1);
    iVar10 = GetRacePaletteBlock(1);
    uVar3 = iVar10 + 4U & 3;
    uVar7 = *(uint *)(iVar10 + 4U & 0xfffffffc);
    uVar3 = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0x14;
    uVar7 = uVar3 & 3;
    uVar5 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0xc;
    uVar8 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    func_020b6dc4(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20,
                  uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20);
    uVar8 = GetRacePaletteBlock(1);
    uVar3 = GetRacePaletteBlock(1);
    uVar3 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 8;
    uVar7 = uVar3 & 3;
    uVar5 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0xc;
    uVar8 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    Arm_FlushRange(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20,
                   uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20);
    iVar10 = GetRacePaletteBlock(1);
    iVar6 = GetRacePaletteBlock(1);
    uVar3 = iVar10 + 4U & 3;
    uVar7 = *(uint *)(iVar10 + 4U & 0xfffffffc);
    uVar3 = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0x14;
    uVar7 = uVar3 & 3;
    uVar5 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = iVar6 + 4U & 3;
    uVar8 = *(uint *)(iVar6 + 4U & 0xfffffffc);
    uVar3 = (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) + 0x10;
    uVar8 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    Arm_FlushRange(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,
                   uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20);
  }
  uVar8 = GetRacePaletteBlock(6);
  iVar10 = GetRacePaletteBlock(6);
  uVar3 = iVar10 + 4U & 3;
  uVar7 = *(uint *)(iVar10 + 4U & 0xfffffffc);
  uVar3 = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0x14;
  uVar7 = uVar3 & 3;
  uVar5 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
          *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0xc;
  uVar8 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  func_020b6d98(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20,
                uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20);
  uVar3 = GetRacePaletteBlock(6);
  uVar8 = GetRacePaletteBlock(6);
  uVar3 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0xc;
  uVar7 = uVar3 & 3;
  uVar5 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
          *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 8;
  uVar8 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  Arm_FlushRange(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,
                 uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20);
  iVar10 = GetRacePaletteBlock(6);
  iVar6 = GetRacePaletteBlock(6);
  uVar3 = iVar10 + 4U & 3;
  uVar7 = *(uint *)(iVar10 + 4U & 0xfffffffc);
  uVar3 = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0x14;
  uVar7 = uVar3 & 3;
  uVar5 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = iVar6 + 4U & 3;
  uVar8 = *(uint *)(iVar6 + 4U & 0xfffffffc);
  uVar3 = (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) + 0x10;
  uVar8 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  Arm_FlushRange(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,
                 uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20);
  iVar10 = GetRacePaletteBlock(6);
  GetRacePaletteBlock(7);
  uVar3 = iVar10 + 4U & 3;
  uVar7 = *(uint *)(iVar10 + 4U & 0xfffffffc);
  uVar3 = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0x14;
  uVar7 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  func_020b46d0(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,0x10,0,0x10);
  iVar10 = GetRacePaletteBlock(7);
  iVar6 = GetRacePaletteBlock(7);
  uVar3 = iVar10 + 4U & 3;
  uVar7 = *(uint *)(iVar10 + 4U & 0xfffffffc);
  uVar3 = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0x14;
  uVar7 = uVar3 & 3;
  uVar5 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = iVar6 + 4U & 3;
  uVar8 = *(uint *)(iVar6 + 4U & 0xfffffffc);
  uVar3 = (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) + 0x10;
  uVar8 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  Arm_FlushRange(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,
                 uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20);
  iVar10 = GetRacePaletteBlock(6);
  GetRacePaletteBlock(8);
  uVar3 = iVar10 + 4U & 3;
  uVar7 = *(uint *)(iVar10 + 4U & 0xfffffffc);
  uVar3 = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0x14;
  uVar7 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  func_020b46d0(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,0x10,0,0x10);
  iVar10 = GetRacePaletteBlock(8);
  iVar6 = GetRacePaletteBlock(8);
  uVar3 = iVar10 + 4U & 3;
  uVar7 = *(uint *)(iVar10 + 4U & 0xfffffffc);
  uVar3 = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0x14;
  uVar7 = uVar3 & 3;
  uVar5 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = iVar6 + 4U & 3;
  uVar8 = *(uint *)(iVar6 + 4U & 0xfffffffc);
  uVar3 = (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) + 0x10;
  uVar8 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  Arm_FlushRange(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,
                 uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20);
  uVar3 = (*(uint *)(DAT_020b0b40 & 0xfffffffc) >> (DAT_020b0b40 & 3) * 8 |
          *(uint *)(DAT_020b0b40 & 0xfffffffc) << (DAT_020b0b40 & 3) * -8 + 0x20) + 8;
  uVar7 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) == 1) {
    iVar10 = GetRacePaletteBlock(6);
    GetRacePaletteBlock(9);
    uVar3 = iVar10 + 4U & 3;
    uVar7 = *(uint *)(iVar10 + 4U & 0xfffffffc);
    uVar3 = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0x14;
    uVar7 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    func_020b46d0(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,0x10,0,0x10);
    iVar10 = GetRacePaletteBlock(9);
    iVar6 = GetRacePaletteBlock(9);
    uVar3 = iVar10 + 4U & 3;
    uVar7 = *(uint *)(iVar10 + 4U & 0xfffffffc);
    uVar3 = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0x14;
    uVar7 = uVar3 & 3;
    uVar5 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = iVar6 + 4U & 3;
    uVar8 = *(uint *)(iVar6 + 4U & 0xfffffffc);
    uVar3 = (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) + 0x10;
    uVar8 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    Arm_FlushRange(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,
                   uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20);
  }
  MaybeClearGlobalB358();
  func_020b3adc();
  uVar3 = (*(uint *)(DAT_020b0b40 & 0xfffffffc) >> (DAT_020b0b40 & 3) * 8 |
          *(uint *)(DAT_020b0b40 & 0xfffffffc) << (DAT_020b0b40 & 3) * -8 + 0x20) + 8;
  uVar7 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) == 4) {
    *(undefined4 *)
     ((*(uint *)(DAT_020b0b88 & 0xfffffffc) >> (DAT_020b0b88 & 3) * 8 |
      *(uint *)(DAT_020b0b88 & 0xfffffffc) << (DAT_020b0b88 & 3) * -8 + 0x20) + 0x10) = 0;
  }
  return;
}

