/* Decompiled C draft; module arm9; ROM address 0204d6f4. No matching claim. */
#include "types.h"
#include "deps/0204d6f4_MaybeSetupRomRootOrOverlays.h"

void MaybeSetupRomRootOrOverlays(int param_1,int param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint *puVar15;
  int *piVar16;
  undefined1 *puVar17;
  int iVar18;
  int local_128;
  int local_11c;
  uint local_110 [4];
  uint local_100;
  uint local_fc;
  uint local_f8;
  uint local_f4;
  uint local_f0 [4];
  int *local_e0 [4];
  undefined1 auStack_d0 [96];
  undefined1 auStack_70 [76];
  uint uVar10;
  
  bVar2 = false;
  if ((param_1 != 0) && (param_2 != 0)) {
    bVar2 = param_2 != 0;
  }
  Fs_File_Initialize((undefined4 *)(void *)(auStack_70));
  uVar5 = Fs_FindArchiveByMountName(uRam0204daa4,3);
  Fs_File_OpenRaw((int)(uintptr_t)(auStack_70),uVar5,0,0x7fffffff,0xffffffff);
  if (param_1 == 0) {
    iVar18 = 0;
    puVar17 = puRam0204daa8;
  }
  else {
    uVar11 = param_1 + 0x24U & 3;
    uVar9 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    uVar10 = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
    uVar11 = param_1 + 0x2cU & 3;
    uVar9 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
    puVar17 = auStack_d0;
    iVar14 = (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) - uVar10;
    iVar18 = iVar14 + uVar10;
    Fs_File_Read(param_1,puVar17,0x60);
    Fs_File_Seek(param_1,iVar14,0);
  }
  if (bVar2) {
    local_110[0] = *(uint *)(uRam0204daac & 0xfffffffc) >> (uRam0204daac & 3) * 8 |
                   *(uint *)(uRam0204daac & 0xfffffffc) << (uRam0204daac & 3) * -8 + 0x20;
    uVar11 = uRam0204daac + 4 & 3;
    uVar9 = *(uint *)(uRam0204daac + 4 & 0xfffffffc);
    local_110[1] = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
    iVar14 = 0;
    local_110[2] = *(uint *)(uRam0204dab0 & 0xfffffffc) >> (uRam0204dab0 & 3) * 8 |
                   *(uint *)(uRam0204dab0 & 0xfffffffc) << (uRam0204dab0 & 3) * -8 + 0x20;
    uVar11 = uRam0204dab0 + 4 & 3;
    uVar9 = *(uint *)(uRam0204dab0 + 4 & 0xfffffffc);
    local_110[3] = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
    uVar11 = (uint)(puVar17 + 0x50) & 3;
    uVar9 = *(uint *)((uint)(puVar17 + 0x50) & 0xfffffffc);
    local_100 = (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) + iVar18;
    uVar11 = (uint)(puVar17 + 0x54) & 3;
    uVar9 = *(uint *)((uint)(puVar17 + 0x54) & 0xfffffffc);
    local_fc = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
    uVar11 = (uint)(puVar17 + 0x58) & 3;
    uVar9 = *(uint *)((uint)(puVar17 + 0x58) & 0xfffffffc);
    local_f8 = (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) + iVar18;
    uVar11 = (uint)(puVar17 + 0x5c) & 3;
    uVar9 = *(uint *)((uint)(puVar17 + 0x5c) & 0xfffffffc);
    local_f4 = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
  }
  else {
    uVar11 = (uint)(puVar17 + 0x48) & 3;
    uVar9 = *(uint *)((uint)(puVar17 + 0x48) & 0xfffffffc);
    local_110[0] = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
    uVar11 = (uint)(puVar17 + 0x4c) & 3;
    uVar9 = *(uint *)((uint)(puVar17 + 0x4c) & 0xfffffffc);
    local_110[1] = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
    uVar11 = (uint)(puVar17 + 0x40) & 3;
    uVar9 = *(uint *)((uint)(puVar17 + 0x40) & 0xfffffffc);
    local_110[2] = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
    uVar11 = (uint)(puVar17 + 0x44) & 3;
    uVar9 = *(uint *)((uint)(puVar17 + 0x44) & 0xfffffffc);
    local_110[3] = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
    uVar11 = (uint)(puVar17 + 0x50) & 3;
    uVar9 = *(uint *)((uint)(puVar17 + 0x50) & 0xfffffffc);
    local_100 = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
    uVar11 = (uint)(puVar17 + 0x54) & 3;
    uVar9 = *(uint *)((uint)(puVar17 + 0x54) & 0xfffffffc);
    local_fc = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
    uVar11 = (uint)(puVar17 + 0x58) & 3;
    uVar9 = *(uint *)((uint)(puVar17 + 0x58) & 0xfffffffc);
    local_f8 = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
    uVar11 = (uint)(puVar17 + 0x5c) & 3;
    uVar9 = *(uint *)((uint)(puVar17 + 0x5c) & 0xfffffffc);
    local_f4 = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
    iVar14 = iVar18;
  }
  local_128 = 4;
  iVar6 = 0;
  do {
    local_f0[iVar6] = local_110[iVar6 * 2 + 1] + 0x1f & 0xffffffe0;
    puVar15 = local_f0 + iVar6;
    iVar6 = iVar6 + 1;
    local_128 = local_128 + *puVar15 + 4;
  } while (iVar6 < 4);
  if (bVar2) {
    iVar6 = 2;
    do {
      iVar3 = iVar6 * 2;
      iVar6 = iVar6 + 1;
      uVar11 = (local_110[iVar3 + 1] >> 5) * 8 + 0x1f & 0xffffffe0;
      local_f0[0] = local_f0[0] + uVar11;
      local_128 = local_128 + uVar11;
    } while (iVar6 < 4);
  }
  uVar5 = Os_DisableIrq();
  uVar11 = iRam0204dab4 + 0x18U & 3;
  uVar10 = *(uint *)(iRam0204dab4 + 0x18U & 0xfffffffc);
  uVar9 = iRam0204dab4 + 0x14U & 3;
  uVar12 = *(uint *)(iRam0204dab4 + 0x14U & 0xfffffffc);
  piVar7 = (int *)(*(code *)(uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20))
                            (uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20,local_128,0);
  Os_RestoreIrq(uVar5);
  iVar6 = 0;
  *piVar7 = iVar14;
  piVar16 = piVar7 + 1;
  do {
    local_e0[iVar6] = piVar16;
    puVar15 = (uint *)local_e0[iVar6];
    *puVar15 = local_110[iVar6 * 2 + 1];
    Fs_File_Seek((int)(uintptr_t)(auStack_70),iVar14 + local_110[iVar6 * 2],0);
    Fs_File_Read(auStack_70,puVar15 + 1,
                 *(uint *)((uint)puVar15 & 0xfffffffc) >> ((uint)puVar15 & 3) * 8 |
                 *(uint *)((uint)puVar15 & 0xfffffffc) << ((uint)puVar15 & 3) * -8 + 0x20);
    piVar4 = local_e0[0];
    puVar15 = local_f0 + iVar6;
    iVar6 = iVar6 + 1;
    piVar16 = (int *)((int)piVar16 + *puVar15 + 4);
  } while (iVar6 < 4);
  if (bVar2) {
    uVar9 = (uint)(puVar17 + 0x48) & 3;
    uVar10 = *(uint *)((uint)(puVar17 + 0x48) & 0xfffffffc);
    local_11c = 2;
    uVar11 = (*(uint *)((uint)local_e0[0] & 0xfffffffc) >> ((uint)local_e0[0] & 3) * 8 |
             *(uint *)((uint)local_e0[0] & 0xfffffffc) << ((uint)local_e0[0] & 3) * -8 + 0x20) >> 3;
    piVar16 = local_e0[0] + uVar11 * 2 + 1;
    do {
      piVar8 = local_e0[local_11c];
      uVar12 = (*(uint *)((uint)piVar8 & 0xfffffffc) >> ((uint)piVar8 & 3) * 8 |
               *(uint *)((uint)piVar8 & 0xfffffffc) << ((uint)piVar8 & 3) * -8 + 0x20) >> 5;
      iVar14 = 0;
      if (uVar12 != 0) {
        do {
          uVar1 = (uint)(piVar8 + iVar14 * 8 + 7) & 3;
          uVar13 = *(uint *)((uint)(piVar8 + iVar14 * 8 + 7) & 0xfffffffc);
          Fs_File_Seek((int)(uintptr_t)(auStack_70),
                       iVar18 + (uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20) +
                       (uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20) * 8,0);
          Fs_File_Read(auStack_70,piVar16,8);
          uVar1 = (uint)(piVar4 + uVar11 * 2 + 1) & 3;
          uVar13 = *(uint *)((uint)(piVar4 + uVar11 * 2 + 1) & 0xfffffffc);
          iVar6 = iVar14 + 1;
          piVar4[uVar11 * 2 + 1] = (uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20) + iVar18;
          uVar1 = (uint)(piVar4 + uVar11 * 2 + 2) & 3;
          uVar13 = *(uint *)((uint)(piVar4 + uVar11 * 2 + 2) & 0xfffffffc);
          piVar16 = piVar16 + 2;
          piVar4[uVar11 * 2 + 2] = (uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20) + iVar18;
          piVar8[iVar14 * 8 + 7] = uVar11;
          uVar11 = uVar11 + 1;
          iVar14 = iVar6;
        } while (iVar6 < (int)uVar12);
      }
      local_11c = local_11c + 1;
    } while (local_11c < 4);
    *local_e0[0] = uVar11 << 3;
  }
  Arm_FlushRange((uint)(uintptr_t)(piVar7),local_128);
  Mem_DcDrainWriteBuffer();
  Fs_File_Close((int)(uintptr_t)(auStack_70));
  iVar18 = iRam0204dab4;
  *(int **)(iRam0204dab4 + 0x20) = piVar7;
  *(int *)(iVar18 + 0x24) = local_128;
  return;
}

