/* Decompiled C draft; module arm9; ROM address 020d2e6c. No matching claim. */
#include "types.h"
#include "deps/020d2e6c_Maybe_MapObj_grpconf.h"

void Maybe_MapObj_grpconf(void)

{
  ushort uVar1;
  short *psVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  short *psVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  int iVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  ushort *puVar18;
  int *piVar19;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  uint *local_4c;
  int local_48;
  uint *local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24 [4];
  
  GetActiveExecutionContext();
  uVar4 = ExecutionContext_GetHeapHandle();
  func_020d22e0();
  sVar3 = func_02061788();
  psVar7 = psRam020d319c;
  *psRam020d319c = sVar3;
  psVar2 = psRam020d31a0;
  *psRam020d31a0 = *psVar7 + 9;
  *psRam020d31a4 = *psVar2 + 1;
  uVar1 = *(ushort *)(*piRam020d31a8 + 4);
  iVar5 = Mem_AllocateHeap(uVar4,uRam020d31ac);
  *piRam020d31b0 = iVar5;
  uVar6 = Mem_AllocateHeap(uVar4,uRam020d31b4);
  *(undefined4 *)*piRam020d31b0 = uVar6;
  uVar6 = Mem_AllocateHeap(uVar4,0x80);
  *puRam020d31b8 = uVar6;
  uVar4 = Mem_AllocateHeap(uVar4,iRam020d31bc);
  *puRam020d31c0 = uVar4;
  piVar19 = piRam020d31b0;
  *(undefined2 *)(*piRam020d31b0 + 4) = 0;
  *(undefined4 *)(*piVar19 + iRam020d31c4) = 0;
  *(undefined4 *)(*piVar19 + iRam020d31c8) = 0;
  *(uint *)(*piRam020d31b0 + iRam020d31d0) = (uint)(*(int *)(*piRam020d31cc + 8) != 5);
  piVar19 = piRam020d31d4;
  *piRam020d31d4 = 0;
  puVar14 = puRam020d31d8;
  do {
    uVar15 = puVar14[*piVar19 * 3 + 1];
    if ((puVar14[*piVar19 * 3] == 0) ||
       ((*(int *)*puRam020d31dc != 1 && (iVar5 = IsAddressInOverlayRegion(uVar15), iVar5 != 0))))
    break;
    if (uVar15 != 0) {
      *(undefined4 *)(uVar15 + 0x20) = 0;
      *(undefined4 *)(uVar15 + 0x24) = 0;
      *(undefined4 *)(uVar15 + 0x28) = 0;
      *(undefined4 *)(uVar15 + 0x2c) = 0;
      *(undefined4 *)(uVar15 + 0x30) = 0;
    }
    iVar5 = *piVar19;
    *piVar19 = iVar5 + 1;
  } while (iVar5 + 1 < 0x85);
  uVar4 = FindFileBuffer_MAR_EFT_from_thumb(uRam020d31e0);
  *puRam020d31e4 = uVar4;
  uVar4 = 1;
  if ((*(int *)(*piRam020d31cc + 8) != 1) && (*(int *)(*piRam020d31cc + 8) != 5)) {
    uVar4 = 0;
  }
  *puRam020d31e8 = uVar4;
  piVar19 = piRam020d31b0;
  *(undefined4 *)(*piRam020d31b0 + iRam020d31ec) = 0;
  *(undefined4 *)(*piVar19 + iRam020d31bc) = 0;
  *(undefined4 *)(*piVar19 + iRam020d31f0) = 0;
  *(undefined4 *)(*piVar19 + iRam020d31f4) = 0;
  *puRam020d31f8 = 0;
  *puRam020d31fc = 0;
  func_02103598();
  func_020d7df8();
  AllocateSomeDtcmBuffers_from_thumb();
  func_020d4bf0();
  *psRam020d3200 = *psRam020d31a4;
  *psRam020d3204 = *psRam020d319c;
  piVar19 = piRam020d31d4;
  iVar5 = 0;
  puVar14 = puRam020d31d8;
  if (0 < *piRam020d31d4) {
    do {
      if ((undefined2 *)puVar14[1] != (undefined2 *)0x0) {
        *(undefined2 *)puVar14[1] = 0;
      }
      iVar5 = iVar5 + 1;
      puVar14 = puVar14 + 3;
    } while (iVar5 < *piVar19);
  }
  piVar19 = piRam020d31b0;
  iVar5 = 0;
  if (uVar1 != 0) {
    do {
      iVar16 = *(int *)*piRam020d31a8 + iVar5 * 0x3c;
      if ((*(int *)(*piRam020d31cc + 8) != 1) || ((*(ushort *)(iVar16 + 0x38) & 1) != 0)) {
        func_020d34e4(*(undefined2 *)(iVar16 + 0x24),(undefined4 *)(uintptr_t)(iVar16),0);
        uVar15 = func_020dff70(*(undefined2 *)(iVar16 + 0x24));
        *(uint *)(*piVar19 + iRam020d31ec) = *(uint *)(*piVar19 + iRam020d31ec) | uVar15;
        uVar15 = func_020e4320(*(undefined2 *)(iVar16 + 0x24));
        *(uint *)(*piVar19 + iRam020d31bc) = *(uint *)(*piVar19 + iRam020d31bc) | uVar15;
        uVar15 = func_020e3af0(*(undefined2 *)(iVar16 + 0x24));
        *(uint *)(*piVar19 + iRam020d31f0) = *(uint *)(*piVar19 + iRam020d31f0) | uVar15;
        uVar15 = func_020ffabc(*(undefined2 *)(iVar16 + 0x24));
        *(uint *)(*piVar19 + iRam020d31f4) = *(uint *)(*piVar19 + iRam020d31f4) | uVar15;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)uVar1);
  }
  iVar5 = *piRam020d31b0;
  if ((((*(int *)(iVar5 + iRam020d31ec) != 0) || (*(int *)(iVar5 + iRam020d31bc) != 0)) ||
      (*(int *)(iVar5 + iRam020d31f0) != 0)) || (*(int *)(iVar5 + iRam020d31f4) != 0)) {
    *puRam020d3208 = 1;
  }
  func_02105214();
  piVar19 = piRam020d31b0;
  iVar5 = 0;
  *(undefined2 *)(*piRam020d31b0 + iRam020d320c) = 0;
  iVar16 = 0;
  local_34 = 0;
  do {
    *(undefined4 *)(*piVar19 + iVar16 + 8) = 0;
    iVar16 = iVar16 + 4;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x18);
  if (0 < *piRam020d31d4) {
    local_44 = puRam020d31d8;
    do {
      psVar7 = (short *)local_44[1];
      if (psVar7 != (short *)0x0) {
        sVar3 = *psVar7;
        local_24[0] = *(int *)(psVar7 + 0x12);
        local_24[1] = *(int *)(local_44[1] + 0x28);
        local_24[2] = *(int *)(local_44[1] + 0x2c);
        local_64 = 0;
        piVar19 = local_24;
        do {
          if (*piVar19 != 0) {
            bVar12 = true;
            iVar16 = 0;
            iVar5 = *piRam020d31b0;
            if (*(short *)(iVar5 + iRam020d320c) != 0) {
              iVar17 = 0;
              do {
                if (*(int *)(iVar5 + iVar17 + 8) == *piVar19) {
                  func_020d4a10(*piVar19,sVar3);
                  bVar12 = false;
                }
                iVar17 = iVar17 + 4;
                iVar16 = iVar16 + 1;
                iVar5 = *piRam020d31b0;
              } while (iVar16 < (int)(uint)*(ushort *)(iVar5 + iRam020d320c));
            }
            if ((bVar12) && (func_020d4a18((undefined4 *)(uintptr_t)(*piVar19)), sVar3 != 0)) {
              func_020d4a10(*piVar19,sVar3);
              iVar5 = *piRam020d31b0;
              uVar1 = *(ushort *)(iVar5 + iRam020d320c);
              *(short *)(iVar5 + iRam020d320c) = *(short *)(iVar5 + iRam020d320c) + 1;
              *(int *)(*piRam020d31b0 + (uint)uVar1 * 4 + 8) = *piVar19;
            }
          }
          piVar19 = piVar19 + 1;
          local_64 = local_64 + 1;
        } while (local_64 < 3);
      }
      local_44 = local_44 + 3;
      local_34 = local_34 + 1;
    } while (local_34 < *piRam020d31d4);
  }
  iVar5 = iRam020d320c;
  piVar19 = piRam020d31b0;
  iVar16 = 0;
  piVar8 = (int *)*piRam020d31b0;
  if (*(short *)((int)piVar8 + iRam020d320c) != 0) {
    iVar17 = 0;
    do {
      func_020d49f0((undefined4 *)(uintptr_t)(*(undefined4 *)((int)piVar8 + iVar17 + 8)));
      iVar17 = iVar17 + 4;
      iVar16 = iVar16 + 1;
      piVar8 = (int *)*piVar19;
    } while (iVar16 < (int)(uint)*(ushort *)((int)piVar8 + iVar5));
  }
  piVar19 = piRam020d31d4;
  local_38 = 0;
  if ((short)piVar8[1] != 0) {
    local_48 = 0;
    local_30 = 0;
    do {
      puVar18 = *(ushort **)(*piVar8 + local_48);
      puVar14 = puRam020d31d8;
      iVar5 = local_30;
      if (0 < *piVar19) {
        do {
          if ((uint)*puVar18 == *puVar14) {
            local_24[0] = *(int *)(puVar14[1] + 0x24);
            local_24[1] = *(int *)(puVar14[1] + 0x28);
            local_24[2] = *(int *)(puVar14[1] + 0x2c);
            if (local_24[0] != 0) {
              func_020d49e0((int *)(uintptr_t)(local_24[0]),(undefined4)(uintptr_t)(puVar18));
            }
            if (local_24[1] != 0) {
              func_020d49e0((int *)(uintptr_t)(local_24[1]),(undefined4)(uintptr_t)(puVar18));
            }
            if (local_24[2] != 0) {
              func_020d49e0((int *)(uintptr_t)(local_24[2]),(undefined4)(uintptr_t)(puVar18));
            }
          }
          iVar5 = iVar5 + 1;
          puVar14 = puVar14 + 3;
        } while (iVar5 < *piVar19);
      }
      local_48 = local_48 + 4;
      local_38 = local_38 + 1;
      piVar8 = (int *)*piRam020d349c;
    } while (local_38 < (int)(uint)*(ushort *)(piVar8 + 1));
  }
  iVar5 = iRam020d34a0;
  piVar19 = piRam020d349c;
  iVar16 = 0;
  if (*(short *)((int)piVar8 + iRam020d34a0) != 0) {
    iVar17 = 0;
    do {
      func_020d4990((int *)(uintptr_t)(*(undefined4 *)((int)piVar8 + iVar17 + 8)));
      iVar17 = iVar17 + 4;
      iVar16 = iVar16 + 1;
      piVar8 = (int *)*piVar19;
    } while (iVar16 < (int)(uint)*(ushort *)((int)piVar8 + iVar5));
  }
  *(undefined4 *)((int)piVar8 + iRam020d34a4) = 1;
  func_020d2e24();
  iVar17 = *piRam020d349c;
  uVar15 = (uint)*(ushort *)(iVar17 + iRam020d34a0);
  iVar16 = 0;
  iVar5 = 0;
  local_60 = 0;
  local_5c = 0;
  iVar10 = 0;
  if (uVar15 != 0) {
    do {
      if (*(int *)(*(int *)(iVar17 + 8) + 0x20) != 0) {
        iVar13 = *(int *)(*(int *)(iVar17 + 8) + 0x18);
        if (iVar13 == 1) {
          iVar16 = iVar16 + 1;
        }
        else if (iVar13 == 2) {
          iVar5 = iVar5 + 1;
        }
      }
      iVar17 = iVar17 + 4;
      iVar10 = iVar10 + 1;
    } while (iVar10 < (int)uVar15);
  }
  local_28 = 0;
  if (uVar15 != 0) {
    iVar17 = 0;
    do {
      iVar9 = *piRam020d349c;
      iVar11 = *(int *)(iVar9 + iVar17 + 8);
      iVar13 = iVar5;
      iVar10 = iVar16;
      if (*(int *)(iVar11 + 0x18) == 1) {
        local_54 = iVar9 + 0x68;
        *(short *)(iVar9 + iRam020d34a8) = *(short *)(iVar9 + iRam020d34a8) + 1;
        if (*(int *)(iVar11 + 0x20) == 0) {
          iVar10 = iVar16 + 1;
          local_58 = iVar16;
        }
        else {
          local_58 = local_60;
          local_60 = local_60 + 1;
        }
      }
      else if (*(int *)(iVar11 + 0x18) == 2) {
        local_54 = iVar9 + 200;
        *(short *)(iVar9 + iRam020d34ac) = *(short *)(iVar9 + iRam020d34ac) + 1;
        if (*(int *)(iVar11 + 0x20) == 0) {
          iVar13 = iVar5 + 1;
          local_58 = iVar5;
        }
        else {
          local_58 = local_5c;
          local_5c = local_5c + 1;
        }
      }
      *(int *)(local_54 + local_58 * 4) = iVar11;
      iVar17 = iVar17 + 4;
      local_28 = local_28 + 1;
      iVar5 = iVar13;
      iVar16 = iVar10;
    } while (local_28 < (int)uVar15);
  }
  piVar19 = piRam020d349c;
  iVar16 = 0;
  *(undefined2 *)(*piRam020d349c + iRam020d34b0) = 0;
  iVar5 = iRam020d34b4;
  iVar17 = 0;
  local_3c = 0;
  do {
    *(undefined4 *)(*piVar19 + iVar17 + iVar5) = 0;
    iVar17 = iVar17 + 4;
    iVar16 = iVar16 + 1;
  } while (iVar16 < 0x10);
  if (0 < *piRam020d34b8) {
    local_4c = puRam020d34bc;
    do {
      psVar7 = (short *)local_4c[1];
      if (psVar7 != (short *)0x0) {
        sVar3 = *psVar7;
        iVar5 = *(int *)(psVar7 + 0x18);
        if (iVar5 != 0) {
          bVar12 = true;
          iVar17 = 0;
          iVar16 = *piRam020d349c;
          if (*(short *)(iVar16 + iRam020d34b0) != 0) {
            iVar10 = 0;
            do {
              if (*(int *)(iVar16 + iVar10 + iRam020d34b4) == iVar5) {
                func_020e6fc4(iVar5,sVar3);
                bVar12 = false;
              }
              iVar10 = iVar10 + 4;
              iVar17 = iVar17 + 1;
              iVar16 = *piRam020d349c;
            } while (iVar17 < (int)(uint)*(ushort *)(iVar16 + iRam020d34b0));
          }
          if ((bVar12) && (func_020e6fcc(iVar5), sVar3 != 0)) {
            func_020e6fc4(iVar5,sVar3);
            iVar16 = *piRam020d349c;
            uVar1 = *(ushort *)(iVar16 + iRam020d34b0);
            *(short *)(iVar16 + iRam020d34b0) = *(short *)(iVar16 + iRam020d34b0) + 1;
            *(int *)(*piRam020d349c + (uint)uVar1 * 4 + iRam020d34b4) = iVar5;
          }
        }
      }
      local_4c = local_4c + 3;
      local_3c = local_3c + 1;
    } while (local_3c < *piRam020d34b8);
  }
  iVar5 = iRam020d34b0;
  piVar19 = piRam020d349c;
  iVar16 = 0;
  piVar8 = (int *)*piRam020d349c;
  if (*(short *)((int)piVar8 + iRam020d34b0) != 0) {
    iVar17 = 0;
    do {
      func_020e6f9c((undefined4 *)(uintptr_t)(*(undefined4 *)((int)piVar8 + iRam020d34b4 + iVar17)));
      iVar17 = iVar17 + 4;
      iVar16 = iVar16 + 1;
      piVar8 = (int *)*piVar19;
    } while (iVar16 < (int)(uint)*(ushort *)((int)piVar8 + iVar5));
  }
  piVar19 = piRam020d34b8;
  local_40 = 0;
  if ((short)piVar8[1] != 0) {
    local_50 = 0;
    local_2c = 0;
    do {
      puVar18 = *(ushort **)(*piVar8 + local_50);
      puVar14 = puRam020d34bc;
      iVar5 = local_2c;
      if (0 < *piVar19) {
        do {
          if (((uint)*puVar18 == *puVar14) && (*(int *)(puVar14[1] + 0x30) != 0)) {
            func_020e6f58((int *)(uintptr_t)(*(int *)(puVar14[1] + 0x30)),(int)(uintptr_t)(puVar18));
          }
          iVar5 = iVar5 + 1;
          puVar14 = puVar14 + 3;
        } while (iVar5 < *piVar19);
      }
      local_50 = local_50 + 4;
      local_40 = local_40 + 1;
      piVar8 = (int *)*piRam020d349c;
    } while (local_40 < (int)(uint)*(ushort *)(piVar8 + 1));
  }
  *(undefined4 *)((int)piVar8 + iRam020d34c0) = 1;
  func_020d2dec();
  return;
}

