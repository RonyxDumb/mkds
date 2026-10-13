/* Decompiled C draft; module arm9; ROM address 0204c090. No matching claim. */
#include "types.h"
#include "deps/0204c090_SomeInitialize.h"

void SomeInitialize(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  
  uVar6 = Os_DisableIrq();
  if (*(uint *)((uint)puRam0204c26c & 0xfffffffc) >> ((uint)puRam0204c26c & 3) * 8 == 0 &&
      *(uint *)((uint)puRam0204c26c & 0xfffffffc) << ((uint)puRam0204c26c & 3) * -8 + 0x20 == 0) {
    *puRam0204c26c = 1;
    func_0204c28c(param_1,param_2,param_3,param_4);
    Os_RestoreIrq(uVar6);
    uVar6 = uRam0204c274;
    puVar3 = puRam0204c270;
    puVar15 = puRam0204c270 + 0x110;
    *puRam0204c270 = 1;
    Arm_FlushRange((uint)(uintptr_t)(puVar15),uVar6);
    Mem_DcDrainWriteBuffer();
    puVar14 = puVar3 + 0x140;
    puVar10 = puVar3 + 0x370;
    puVar13 = (undefined4 *)((int)puVar15 + iRam0204c278);
    puVar3[0x12c0] = puVar14;
    iVar5 = iRam0204c280;
    iVar4 = iRam0204c27c;
    puVar2 = puVar14;
    while (puVar10 < puVar13) {
      *puVar2 = puVar2 + 0x230;
      Fs_File_Initialize(puVar2 + 0xe);
      iVar8 = (int)puVar2 + (iVar4 - (int)puVar14);
      puVar2[0x21] = 0;
      puVar2[0x20] = 0;
      puVar2[0x23] = (iVar8 + (int)((ulonglong)((longlong)iVar5 * (longlong)iVar8) >> 0x20) >> 0xb)
                     - (iVar8 >> 0x1f);
      puVar10 = puVar2 + 0x460;
      puVar2 = puVar2 + 0x230;
    }
    *puVar2 = 0;
    puVar3[0x12c4] = 0;
    puVar3[0x12c3] = 0;
    puVar3[0x12c5] = 0;
    puVar3[0x12c1] = 0;
    puVar3[0x12c2] = 0;
    puVar3[10] = param_5;
    puVar3[0x12c6] = 1;
    puVar3[0x12c7] = 0;
    puVar3[0x12c8] = 0;
    puVar3[0x12ca] = 0;
    puVar3[0x12c9] = 0;
    uVar6 = uRam0204c274;
    uVar1 = (uint)(puVar3 + 10) & 3;
    uVar11 = *(uint *)((uint)(puVar3 + 10) & 0xfffffffc);
    puVar3[0x12cb] = uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20;
    Arm_FlushRange((uint)(uintptr_t)(puVar15),uVar6);
    Mem_DcDrainWriteBuffer();
    uVar1 = (uint)(puVar3 + 10) & 3;
    uVar7 = *(uint *)((uint)(puVar3 + 10) & 0xfffffffc);
    uVar11 = (uint)(puVar3 + 0xb) & 3;
    uVar9 = *(uint *)((uint)(puVar3 + 0xb) & 0xfffffffc);
    func_02006aac(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20,
                  uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20,uRam0204c284);
    MaybeSetupRomRootOrOverlays(param_6,param_7);
    uVar1 = (uint)(puVar3 + 0x12c0) & 3;
    uVar11 = *(uint *)((uint)(puVar3 + 0x12c0) & 0xfffffffc);
    puVar12 = (uint *)(uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20);
    puVar3[0x12c0] =
         *(uint *)((uint)puVar12 & 0xfffffffc) >> ((uint)puVar12 & 3) * 8 |
         *(uint *)((uint)puVar12 & 0xfffffffc) << ((uint)puVar12 & 3) * -8 + 0x20;
    uVar1 = (uint)(puVar3 + 0x12c1) & 3;
    uVar11 = *(uint *)((uint)(puVar3 + 0x12c1) & 0xfffffffc);
    *puVar12 = uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20;
    puVar3[0x12c1] = puVar12;
    puVar12[0x21] = 1;
    Mem_CpuFill8(puVar12,0,0x8c0);
    uVar1 = (uint)(puVar3 + 8) & 3;
    uVar11 = *(uint *)((uint)(puVar3 + 8) & 0xfffffffc);
    StructGO_SomeFn_from_thumb
              (puVar12 + 1,0x20000,uRam0204c288,uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20);
    puVar3[3] = 1;
    func_0204bad8();
    return;
  }
  return;
}

