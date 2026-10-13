/* Decompiled C draft; module arm9; ROM address 020d34e4. No matching claim. */
#include "types.h"
#include "deps/020d34e4_func_020d34e4.h"

undefined2 * func_020d34e4(uint param_1,undefined4 *param_2,int param_3)

{
  ushort uVar1;
  int *piVar2;
  uint *puVar3;
  undefined2 uVar4;
  int iVar5;
  uint *puVar6;
  undefined4 uVar7;
  undefined2 *puVar8;
  ushort *puVar9;
  int extraout_r1;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  ushort *puVar13;
  short *psVar14;
  uint uVar15;
  uint *puVar16;
  int iVar17;
  int local_34;
  int local_30;
  int local_24;
  ushort *local_20;
  
  puVar3 = puRam020d37ec;
  piVar2 = piRam020d37e8;
  local_34 = 0;
  iVar5 = *piRam020d37e8;
  if (0 < iVar5) {
    local_30 = 0;
    local_24 = 0;
    local_20 = (ushort *)0x0;
    puVar16 = puRam020d37ec;
    do {
      if (param_1 == *puVar16) {
        psVar14 = (short *)puVar16[1];
        if (*psVar14 == 0) {
          puVar6 = puVar3;
          iVar17 = local_30;
          if (0 < iVar5) {
            do {
              uVar15 = puVar6[1];
              if (uVar15 != 0) {
                if ((*(int *)(uVar15 + 0x10) == *(int *)(psVar14 + 8)) &&
                   (*(int *)(uVar15 + 0x24) != 0)) {
                  *(int *)(psVar14 + 0x12) = *(int *)(uVar15 + 0x24);
                }
                if ((*(int *)(uVar15 + 0x10) == *(int *)(psVar14 + 10)) &&
                   (*(int *)(uVar15 + 0x24) != 0)) {
                  *(int *)(psVar14 + 0x14) = *(int *)(uVar15 + 0x24);
                }
                if ((*(int *)(uVar15 + 0x10) == *(int *)(psVar14 + 0xc)) &&
                   (*(int *)(uVar15 + 0x24) != 0)) {
                  *(int *)(psVar14 + 0x16) = *(int *)(uVar15 + 0x24);
                }
                if ((*(int *)(uVar15 + 0x14) == *(int *)(psVar14 + 8)) &&
                   (*(int *)(uVar15 + 0x28) != 0)) {
                  *(int *)(psVar14 + 0x12) = *(int *)(uVar15 + 0x28);
                }
                if ((*(int *)(uVar15 + 0x14) == *(int *)(psVar14 + 10)) &&
                   (*(int *)(uVar15 + 0x28) != 0)) {
                  *(int *)(psVar14 + 0x14) = *(int *)(uVar15 + 0x28);
                }
                if ((*(int *)(uVar15 + 0x14) == *(int *)(psVar14 + 0xc)) &&
                   (*(int *)(uVar15 + 0x28) != 0)) {
                  *(int *)(psVar14 + 0x16) = *(int *)(uVar15 + 0x28);
                }
                if ((*(int *)(uVar15 + 0x18) == *(int *)(psVar14 + 8)) &&
                   (*(int *)(uVar15 + 0x2c) != 0)) {
                  *(int *)(psVar14 + 0x12) = *(int *)(uVar15 + 0x2c);
                }
                if ((*(int *)(uVar15 + 0x18) == *(int *)(psVar14 + 10)) &&
                   (*(int *)(uVar15 + 0x2c) != 0)) {
                  *(int *)(psVar14 + 0x14) = *(int *)(uVar15 + 0x2c);
                }
                if ((*(int *)(uVar15 + 0x18) == *(int *)(psVar14 + 0xc)) &&
                   (*(int *)(uVar15 + 0x2c) != 0)) {
                  *(int *)(psVar14 + 0x16) = *(int *)(uVar15 + 0x2c);
                }
                if ((*(int *)(uVar15 + 0x1c) == *(int *)(psVar14 + 0xe)) &&
                   (*(int *)(uVar15 + 0x30) != 0)) {
                  *(int *)(psVar14 + 0x18) = *(int *)(uVar15 + 0x30);
                }
              }
              iVar17 = iVar17 + 1;
              puVar6 = puVar6 + 3;
            } while (iVar17 < *piVar2);
          }
          if ((*(int *)(psVar14 + 0x10) == 0) && (*(code **)(psVar14 + 6) != (code *)0x0)) {
            uVar7 = (**(code **)(psVar14 + 6))();
            *(undefined4 *)(psVar14 + 0x10) = uVar7;
            iVar5 = *(int *)(psVar14 + 0x10);
            if (iVar5 == 0) {
              return (undefined2 *)0x0;
            }
            if (*(int *)(iVar5 + 0x24) == 0) {
              *(undefined4 *)(iVar5 + 0x24) = 0xffffffff;
            }
            if (*(int *)(*(int *)(psVar14 + 0x10) + 0x28) == 0) {
              *(undefined4 *)(*(int *)(psVar14 + 0x10) + 0x28) = 0xffffffff;
            }
            if (*(int *)(*(int *)(psVar14 + 0x10) + 0x38) == 0) {
              *(undefined4 *)(*(int *)(psVar14 + 0x10) + 0x38) = uRam020d37f0;
            }
            if (*(int *)(*(int *)(psVar14 + 0x10) + 0x3c) == 0) {
              *(undefined4 *)(*(int *)(psVar14 + 0x10) + 0x3c) = uRam020d37f4;
            }
            if ((*(int *)(*piRam020d37f8 + 0xc) == 2) &&
               (*(int *)(*(int *)(psVar14 + 0x10) + 0x38) < iRam020d37fc)) {
              *(int *)(*(int *)(psVar14 + 0x10) + 0x38) = iRam020d37fc;
            }
          }
          puVar9 = (ushort *)*puRam020d3800;
          iVar5 = local_24;
          do {
            if ((*puVar16 & 0xffff) == (uint)*puVar9) {
              puVar13 = (ushort *)*puRam020d3800 + iVar5 * 8;
              break;
            }
            puVar9 = puVar9 + 8;
            iVar5 = iVar5 + 1;
            puVar13 = local_20;
          } while (iVar5 < iRam020d3804);
          if (puVar13[1] != 0) {
            *(uint *)(*(int *)(psVar14 + 0x10) + 0x34) = (uint)(1 < puVar13[1]);
            if (puVar13[2] == 0) {
              uVar7 = FUN_02132440(0);
              func_021329f8(uVar7,uRam020d3808);
            }
            else {
              uVar7 = FUN_02132440((uint)puVar13[2] << 0xc);
              func_02131234(uRam020d3808,uVar7);
            }
            uVar7 = func_021322c8();
            *(undefined4 *)(*(int *)(psVar14 + 0x10) + 0x2c) = uVar7;
            if (puVar13[3] == 0) {
              uVar7 = FUN_02132440(0);
              func_021329f8(uVar7,uRam020d3808);
            }
            else {
              uVar7 = FUN_02132440((uint)puVar13[3] << 0xc);
              func_02131234(uRam020d3808,uVar7);
            }
            uVar7 = func_021322c8();
            *(undefined4 *)(*(int *)(psVar14 + 0x10) + 0x30) = uVar7;
          }
          if (puVar13[4] != 0) {
            *(uint *)(*(int *)(psVar14 + 0x10) + 8) = (uint)puVar13[4];
            if (puVar13[5] == 0) {
              uVar7 = FUN_02132440(0);
              func_021329f8(uVar7,uRam020d3808);
            }
            else {
              uVar7 = FUN_02132440((uint)puVar13[5] << 0xc);
              func_02131234(uRam020d3808,uVar7);
            }
            uVar7 = func_021322c8();
            *(undefined4 *)(*(int *)(psVar14 + 0x10) + 0xc) = uVar7;
            if (puVar13[6] == 0) {
              uVar7 = FUN_02132440(0);
              func_021329f8(uVar7,uRam020d3808);
            }
            else {
              uVar7 = FUN_02132440((uint)puVar13[6] << 0xc);
              func_02131234(uRam020d3808,uVar7);
            }
            uVar7 = func_021322c8();
            *(undefined4 *)(*(int *)(psVar14 + 0x10) + 0x10) = uVar7;
            if (puVar13[7] == 0) {
              uVar7 = FUN_02132440(0);
              func_021329f8(uVar7,uRam020d3808);
            }
            else {
              uVar7 = FUN_02132440((uint)puVar13[7] << 0xc);
              func_02131234(uRam020d3808,uVar7);
            }
            uVar7 = func_021322c8();
            *(undefined4 *)(*(int *)(psVar14 + 0x10) + 0x14) = uVar7;
          }
          if ((*(int *)(psVar14 + 0x12) == 0) && (*(code **)(psVar14 + 8) != (code *)0x0)) {
            uVar7 = (**(code **)(psVar14 + 8))();
            *(undefined4 *)(psVar14 + 0x12) = uVar7;
          }
          if ((*(int *)(psVar14 + 0x14) == 0) && (*(code **)(psVar14 + 10) != (code *)0x0)) {
            uVar7 = (**(code **)(psVar14 + 10))();
            *(undefined4 *)(psVar14 + 0x14) = uVar7;
          }
          if ((*(int *)(psVar14 + 0x16) == 0) && (*(code **)(psVar14 + 0xc) != (code *)0x0)) {
            uVar7 = (**(code **)(psVar14 + 0xc))();
            *(undefined4 *)(psVar14 + 0x16) = uVar7;
          }
          if ((*(int *)(psVar14 + 0x18) == 0) && (*(code **)(psVar14 + 0xe) != (code *)0x0)) {
            uVar7 = (**(code **)(psVar14 + 0xe))();
            *(undefined4 *)(psVar14 + 0x18) = uVar7;
          }
        }
        if (psVar14 != (short *)0x0) {
          iVar5 = *(int *)(psVar14 + 0x10);
          GetActiveExecutionContext();
          uVar7 = ExecutionContext_GetHeapHandle();
          puVar8 = (undefined2 *)Mem_AllocateHeap(uVar7,*(undefined4 *)(psVar14 + 2));
          *psVar14 = *psVar14 + 1;
          if (param_2 == (undefined4 *)0x0) {
            if (param_3 != 0) {
              *(undefined4 *)(puVar8 + 0x4e) = *(undefined4 *)(param_3 + 0x9c);
            }
          }
          else {
            *(undefined4 **)(puVar8 + 0x4e) = param_2;
          }
          *puVar8 = (short)param_1;
          puVar8[1] = 0;
          if (*piRam020d380c != 0) {
            puVar8[1] = puVar8[1] | *puRam020d3810;
          }
          puVar8[0x32] = 0xffff;
          if (param_2 == (undefined4 *)0x0) {
            if (param_3 != 0) {
              *(undefined4 *)(puVar8 + 2) = *(undefined4 *)(param_3 + 4);
              *(undefined4 *)(puVar8 + 4) = *(undefined4 *)(param_3 + 8);
              *(undefined4 *)(puVar8 + 6) = *(undefined4 *)(param_3 + 0xc);
            }
          }
          else {
            *(undefined4 *)(puVar8 + 2) = *param_2;
            *(undefined4 *)(puVar8 + 4) = param_2[1];
            *(undefined4 *)(puVar8 + 6) = param_2[2];
          }
          uVar7 = uRam020d3aa4;
          if ((*(int *)(iVar5 + 0x20) == 0) || (*(int *)(iVar5 + 0x20) == 2)) {
            *(undefined4 *)(puVar8 + 8) = 0;
            *(undefined4 *)(puVar8 + 10) = 0;
            *(undefined4 *)(puVar8 + 0xc) = 0;
          }
          else {
            *(undefined4 *)(puVar8 + 8) = uRam020d3aa4;
            *(undefined4 *)(puVar8 + 10) = uVar7;
            *(undefined4 *)(puVar8 + 0xc) = uVar7;
          }
          if (param_2 == (undefined4 *)0x0) {
            if (param_3 != 0) {
              puVar8[0x3f] = *(undefined2 *)(param_3 + 0x7e);
              puVar12 = (undefined4 *)(param_3 + 0x28);
              puVar11 = (undefined4 *)(puVar8 + 0x14);
              iVar17 = 6;
              do {
                uVar7 = *puVar12;
                uVar10 = puVar12[1];
                puVar12 = puVar12 + 2;
                *puVar11 = uVar7;
                puVar11[1] = uVar10;
                puVar11 = puVar11 + 2;
                iVar17 = iVar17 + -1;
              } while (iVar17 != 0);
            }
          }
          else {
            Multiply64(param_2[4],(int)param_2[4] >> 0x1f,uRam020d3aa8,0xb6);
            puVar8[0x3f] = (short)(extraout_r1 + iRam020d3aac >> 0xc);
            func_020d6df0(param_2 + 3,puVar8 + 0x14);
          }
          *(int *)(puVar8 + 0x4c) = iVar5;
          if (param_2 == (undefined4 *)0x0) {
            func_020d29cc(puVar8,param_3 + 0x1c);
          }
          else {
            func_020d29cc(puVar8,param_2 + 6);
          }
          func_020d24d8(puVar8,*(undefined4 *)(iVar5 + 0x30));
          puVar8[0x3e] = (short)*(undefined4 *)(iVar5 + 0x34);
          if (*(int *)(iVar5 + 8) == 0) {
            puVar8[1] = puVar8[1] | *puRam020d3ab0;
          }
          else {
            puVar8[1] = puVar8[1] & 0xfffe;
          }
          if (*(int *)(iVar5 + 0x1c) == 0) {
            puVar8[1] = puVar8[1] | *puRam020d3ab4;
          }
          else {
            puVar8[1] = puVar8[1] & 0xffbf;
          }
          if ((((*(int *)(psVar14 + 0x12) == 0) || (*(int *)(*(int *)(psVar14 + 0x12) + 0x10) == 0))
              && ((*(int *)(psVar14 + 0x14) == 0 || (*(int *)(*(int *)(psVar14 + 0x14) + 0x10) == 0)
                  ))) &&
             ((*(int *)(psVar14 + 0x16) == 0 || (*(int *)(*(int *)(psVar14 + 0x16) + 0x10) == 0))))
          {
            puVar8[1] = puVar8[1] | *puRam020d3ab8;
            puVar8[1] = puVar8[1] | *puRam020d3abc;
          }
          else {
            puVar8[1] = puVar8[1] & 0xfffd;
            puVar8[1] = puVar8[1] & 0xfff7;
            puVar8[0x33] = 0x1f;
          }
          if (param_3 == 0) {
            if ((param_2 != (undefined4 *)0x0) && (*(short *)((int)param_2 + 0x36) != 0)) {
              func_020d3ae0((int)*(short *)((int)param_2 + 0x36),puVar8);
            }
          }
          else {
            *(undefined4 *)(puVar8 + 0x3a) = *(undefined4 *)(param_3 + 0x74);
            puVar8[1] = puVar8[1] | *(ushort *)(param_3 + 2) & 0x80;
          }
          if ((*(int *)(psVar14 + 0x18) == 0) || (*(int *)(*(int *)(psVar14 + 0x18) + 0x10) == 0)) {
            puVar8[1] = puVar8[1] | *puRam020d3ac0;
          }
          else {
            puVar8[1] = puVar8[1] & 0xfffb;
          }
          *(undefined4 *)(puVar8 + 0x38) = *(undefined4 *)(iRam020d3ac4 + 0x68);
          if (param_2 == (undefined4 *)0x0) {
            if ((param_3 != 0) && (*(code **)(psVar14 + 4) != (code *)0x0)) {
              (**(code **)(psVar14 + 4))(puVar8,0,param_3);
            }
          }
          else if (*(code **)(psVar14 + 4) != (code *)0x0) {
            (**(code **)(psVar14 + 4))
                      (puVar8,param_2,*(undefined4 *)(iRam020d3ac8 + local_34 * 0xc));
          }
          if (*(int *)(iVar5 + 8) != 0) {
            uVar15 = uRam020d3acc;
            if (*(int *)(iVar5 + 0x20) == 0) {
              uVar15 = uRam020d3acc | *puRam020d3ad0;
            }
            iVar5 = func_020dff70(*puVar8);
            if ((((iVar5 != 0) || (iVar5 = func_020e4320(*puVar8), iVar5 != 0)) ||
                (iVar5 = func_020e3af0(*puVar8), iVar5 != 0)) ||
               (iVar5 = func_020ffabc(*puVar8), iVar5 != 0)) {
              uVar15 = uVar15 | *puRam020d3ad4;
            }
            uVar7 = func_020d252c(puVar8);
            uVar4 = FindComputeSomeCollisionEntryId(puVar8 + 2,uVar7,uVar15,puVar8);
            puVar8[0x32] = uVar4;
          }
          piVar2 = piRam020d3ad8;
          uVar1 = *(ushort *)(*piRam020d3ad8 + 4);
          *(ushort *)(*piRam020d3ad8 + 4) = uVar1 + 1;
          *(undefined2 **)(*(int *)*piVar2 + (uint)uVar1 * 4) = puVar8;
          iVar5 = *piVar2;
          if (uRam020d3adc <= *(ushort *)(iVar5 + 4)) {
            *(undefined2 *)(iVar5 + 4) = 0xff;
          }
          return puVar8;
        }
      }
      puVar16 = puVar16 + 3;
      local_34 = local_34 + 1;
      iVar5 = *piVar2;
    } while (local_34 < iVar5);
  }
  return (undefined2 *)0x0;
}

