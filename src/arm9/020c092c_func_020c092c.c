/* Decompiled C draft; module arm9; ROM address 020c092c. No matching claim. */
#include "types.h"
#include "deps/020c092c_func_020c092c.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020c092c(int param_1,int param_2,int param_3)

{
  uint uVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int local_54;
  short local_4c;
  int *piStack_44;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  
  uVar2 = *(ushort *)
           (*(uint *)(uRam020c0b7c & 0xfffffffc) >> (uRam020c0b7c & 3) * 8 |
           *(uint *)(uRam020c0b7c & 0xfffffffc) << (uRam020c0b7c & 3) * -8 + 0x20);
  if (param_3 != 0) {
    local_4c = func_020b6368();
  }
  uVar13 = param_2 + 4U & 3;
  uVar5 = *(uint *)(param_2 + 4U & 0xfffffffc);
  local_54 = 0;
  if (0 < (int)(uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20)) {
    iVar14 = 0;
    piStack_44 = (int *)0x0;
    do {
      uVar13 = param_2 + 0x10U & 3;
      uVar5 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
      iVar6 = (uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20) + iVar14;
      uVar13 = (uint)*(ushort *)(iVar6 + 0xc);
      if (uVar2 <= uVar13) {
        sVar3 = *(short *)(iVar6 + 0xe);
        if (param_3 != 0) {
          if (*(char *)((*(uint *)(uRam020c0b80 & 0xfffffffc) >> (uRam020c0b80 & 3) * 8 |
                        *(uint *)(uRam020c0b80 & 0xfffffffc) << (uRam020c0b80 & 3) * -8 + 0x20) +
                       0x57) == '\0') {
            MaybeCreateRotationMatrix(&iStack_38,local_4c + (-0x8000 - *(short *)(iVar6 + 0x10)));
          }
          else {
            MaybeCreateRotationMatrix(&iStack_38,(*(short *)(iVar6 + 0x10) + -0x8000) - local_4c);
          }
          iVar6 = func_020ae5c4(param_1);
          iVar6 = param_1 + iVar6 * 0x20;
          *(short *)(iVar6 + 6) = (short)(iStack_38 >> 4);
          *(short *)(iVar6 + 0xe) = (short)(iStack_34 >> 4);
          *(short *)(iVar6 + 0x16) = (short)(iStack_30 >> 4);
          *(short *)(iVar6 + 0x1e) = (short)(iStack_2c >> 4);
        }
        uVar5 = param_2 + 0x10U & 3;
        uVar8 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
        uVar12 = (uint)*(ushort *)(param_1 + 0x400);
        iVar6 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + iVar14;
        uVar5 = iVar6 + 8;
        uVar8 = uVar5 & 3;
        uVar9 = *(uint *)(uVar5 & 0xfffffffc);
        uVar5 = iVar6 + 4;
        uVar1 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        piVar10 = (int *)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
        if (param_3 != 0) {
          piVar10 = &iStack_38;
        }
        puVar11 = (uint *)(param_1 + uVar12 * 8);
        if (param_3 == 0) {
          piVar10 = piStack_44;
        }
        sVar4 = MaybeMakeOamSlot(puVar11,0x80 - uVar12 & 0xffff,
                                 uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20,piVar10);
        puVar7 = (ushort *)(param_1 + 0x400);
        *puVar7 = *puVar7 + sVar4;
        if (uVar12 < *puVar7) {
          do {
            if (sVar3 == 0) {
              iVar6 = -1;
            }
            else {
              iVar6 = 1;
            }
            uVar5 = 0xffffffff;
            if (iVar6 != -1) {
              if (sVar3 != 0) {
                uVar5 = 1;
              }
              if (sVar3 == 0) {
                uVar5 = 0xffffffff;
              }
              *puVar11 = (*(uint *)((uint)puVar11 & 0xfffffffc) >> ((uint)puVar11 & 3) * 8 |
                         *(uint *)((uint)puVar11 & 0xfffffffc) << ((uint)puVar11 & 3) * -8 + 0x20) &
                         0xfffff3ff | (uVar5 & 3) << 10;
            }
            if (uVar13 != 0xffffffff) {
              uVar5 = (uint)(puVar11 + 1) & 3;
              uVar8 = *(uint *)((uint)(puVar11 + 1) & 0xfffffffc);
              puVar11[1] = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 0xfffff3ff |
                           (uVar13 & 3) << 10;
            }
            uVar12 = uVar12 + 1;
            puVar11 = puVar11 + 2;
          } while ((int)uVar12 < (int)(uint)*(ushort *)(param_1 + 0x400));
        }
      }
      iVar14 = iVar14 + 0x14;
      local_54 = local_54 + 1;
      uVar13 = param_2 + 4U & 3;
      uVar5 = *(uint *)(param_2 + 4U & 0xfffffffc);
    } while (local_54 < (int)(uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20));
    return;
  }
  return;
}

