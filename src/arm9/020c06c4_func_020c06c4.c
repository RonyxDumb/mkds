/* Decompiled C draft; module arm9; ROM address 020c06c4. No matching claim. */
#include "types.h"
#include "deps/020c06c4_func_020c06c4.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020c06c4(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  int local_50;
  short local_48;
  int iStack_44;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  
  uVar1 = *(ushort *)
           (*(uint *)(uRam020c0924 & 0xfffffffc) >> (uRam020c0924 & 3) * 8 |
           *(uint *)(uRam020c0924 & 0xfffffffc) << (uRam020c0924 & 3) * -8 + 0x20);
  if (param_3 != 0) {
    local_48 = func_020b6368();
  }
  uVar10 = param_2 + 4U & 3;
  uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
  local_50 = 0;
  if (0 < (int)(uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20)) {
    iStack_44 = 0;
    do {
      uVar10 = param_2 + 0x10U & 3;
      uVar4 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
      iVar5 = (uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) + iStack_44;
      uVar10 = (uint)*(ushort *)(iVar5 + 0xc);
      if (uVar1 <= uVar10) {
        sVar2 = *(short *)(iVar5 + 0xe);
        if (param_3 == 0) {
          uVar4 = param_2 + 0xcU & 3;
          uVar7 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
          uVar4 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + local_50 * 8;
          uVar7 = uVar4 & 3;
          uVar4 = *(uint *)(uVar4 & 0xfffffffc);
          func_020b4cec(&iStack_38,uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20);
        }
        else if (*(char *)((*(uint *)(uRam020c0928 & 0xfffffffc) >> (uRam020c0928 & 3) * 8 |
                           *(uint *)(uRam020c0928 & 0xfffffffc) << (uRam020c0928 & 3) * -8 + 0x20) +
                          0x57) == '\0') {
          uVar4 = param_2 + 0xcU & 3;
          uVar7 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
          uVar4 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + local_50 * 8;
          uVar7 = uVar4 & 3;
          uVar4 = *(uint *)(uVar4 & 0xfffffffc);
          func_020b4bf8(&iStack_38,uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20,
                        local_48 - *(short *)(iVar5 + 0x10));
        }
        else {
          uVar4 = param_2 + 0xcU & 3;
          uVar7 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
          uVar4 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + local_50 * 8;
          uVar7 = uVar4 & 3;
          uVar4 = *(uint *)(uVar4 & 0xfffffffc);
          func_020b4bf8(&iStack_38,uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20,
                        *(short *)(iVar5 + 0x10) - local_48);
        }
        iVar5 = func_020ae5c4(param_1);
        iVar5 = param_1 + iVar5 * 0x20;
        *(short *)(iVar5 + 6) = (short)(iStack_38 >> 4);
        *(short *)(iVar5 + 0xe) = (short)(iStack_34 >> 4);
        *(short *)(iVar5 + 0x16) = (short)(iStack_30 >> 4);
        *(short *)(iVar5 + 0x1e) = (short)(iStack_2c >> 4);
        uVar9 = (uint)*(ushort *)(param_1 + 0x400);
        uVar4 = param_2 + 0x10U & 3;
        uVar7 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
        uVar4 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + iStack_44 + 8;
        uVar7 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        puVar8 = (uint *)(param_1 + uVar9 * 8);
        sVar3 = MaybeMakeOamSlot(puVar8,0x80 - uVar9 & 0xffff,
                                 uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20,&iStack_38);
        puVar6 = (ushort *)(param_1 + 0x400);
        *puVar6 = *puVar6 + sVar3;
        if (uVar9 < *puVar6) {
          do {
            if (sVar2 == 0) {
              iVar5 = -1;
            }
            else {
              iVar5 = 1;
            }
            uVar4 = 0xffffffff;
            if (iVar5 != -1) {
              if (sVar2 != 0) {
                uVar4 = 1;
              }
              if (sVar2 == 0) {
                uVar4 = 0xffffffff;
              }
              *puVar8 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                        *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                        0xfffff3ff | (uVar4 & 3) << 10;
            }
            if (uVar10 != 0xffffffff) {
              uVar4 = (uint)(puVar8 + 1) & 3;
              uVar7 = *(uint *)((uint)(puVar8 + 1) & 0xfffffffc);
              puVar8[1] = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) & 0xfffff3ff |
                          (uVar10 & 3) << 10;
            }
            uVar9 = uVar9 + 1;
            puVar8 = puVar8 + 2;
          } while ((int)uVar9 < (int)(uint)*(ushort *)(param_1 + 0x400));
        }
      }
      uVar10 = param_2 + 4U & 3;
      uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
      local_50 = local_50 + 1;
      iStack_44 = iStack_44 + 0x14;
    } while (local_50 < (int)(uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20));
    return;
  }
  return;
}

