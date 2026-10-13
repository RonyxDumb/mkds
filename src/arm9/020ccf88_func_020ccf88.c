/* Decompiled C draft; module arm9; ROM address 020ccf88. No matching claim. */
#include "types.h"
#include "deps/020ccf88_func_020ccf88.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020ccf88(int param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  
  iVar3 = func_020c0dc4();
  sVar1 = func_020b6368();
  iVar10 = 0;
  uVar6 = *(uint *)(uRam020cd1b8 & 0xfffffffc) >> (uRam020cd1b8 & 3) * 8 |
          *(uint *)(uRam020cd1b8 & 0xfffffffc) << (uRam020cd1b8 & 3) * -8 + 0x20;
  uVar9 = uVar6 + 4 & 3;
  uVar4 = *(uint *)(uVar6 + 4 & 0xfffffffc);
  if (0 < (int)(uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20)) {
    iVar11 = iVar10;
    do {
      uVar9 = uVar6 + 0x10 & 3;
      uVar4 = *(uint *)(uVar6 + 0x10 & 0xfffffffc);
      iVar5 = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + iVar10;
      uVar9 = (uint)*(ushort *)(iVar5 + 0xc);
      if (iVar3 <= (int)uVar9) {
        if (*(short *)(iVar5 + 0xe) == 0) {
          if (*(char *)((*(uint *)(uRam020cd1bc & 0xfffffffc) >> (uRam020cd1bc & 3) * 8 |
                        *(uint *)(uRam020cd1bc & 0xfffffffc) << (uRam020cd1bc & 3) * -8 + 0x20) +
                       0x57) == '\0') {
            MaybeCreateRotationMatrix(&iStack_34,sVar1 + (0x4000 - *(short *)(iVar5 + 0x10)));
          }
          else {
            MaybeCreateRotationMatrix(&iStack_34,(*(short *)(iVar5 + 0x10) + 0x4000) - sVar1);
          }
        }
        else if (*(char *)((*(uint *)(uRam020cd1bc & 0xfffffffc) >> (uRam020cd1bc & 3) * 8 |
                           *(uint *)(uRam020cd1bc & 0xfffffffc) << (uRam020cd1bc & 3) * -8 + 0x20) +
                          0x57) == '\0') {
          func_020b4c74(&iStack_34,(0x4000 - *(short *)(iVar5 + 0x10)) - sVar1);
        }
        else {
          func_020b4c74(&iStack_34,sVar1 + *(short *)(iVar5 + 0x10) + 0x4000);
        }
        iVar5 = func_020ae5c4(param_1);
        iVar5 = param_1 + iVar5 * 0x20;
        *(short *)(iVar5 + 6) = (short)(iStack_34 >> 4);
        *(short *)(iVar5 + 0xe) = (short)(iStack_30 >> 4);
        *(short *)(iVar5 + 0x16) = (short)(iStack_2c >> 4);
        *(short *)(iVar5 + 0x1e) = (short)(iStack_28 >> 4);
        uVar8 = (uint)*(ushort *)(param_1 + 0x400);
        uVar4 = (*(uint *)(uRam020cd1b8 & 0xfffffffc) >> (uRam020cd1b8 & 3) * 8 |
                *(uint *)(uRam020cd1b8 & 0xfffffffc) << (uRam020cd1b8 & 3) * -8 + 0x20) + 0x10;
        uVar6 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        iVar5 = param_1 + uVar8 * 8;
        uVar4 = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + iVar10 + 8;
        uVar6 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        sVar2 = MaybeMakeOamSlot(iVar5,0x80 - uVar8 & 0xffff,
                                 uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20,&iStack_34);
        puVar7 = (ushort *)(param_1 + 0x400);
        *puVar7 = *puVar7 + sVar2;
        if (uVar8 < *puVar7) {
          do {
            uVar4 = 0xffffffff;
            if (uVar9 != 0xffffffff) {
              uVar4 = iVar5 + 4U & 3;
              uVar6 = *(uint *)(iVar5 + 4U & 0xfffffffc);
              uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
            }
            uVar8 = uVar8 + 1;
            if (uVar9 != 0xffffffff) {
              *(uint *)(iVar5 + 4) = uVar4 & 0xfffff3ff | (uVar9 & 3) << 10;
            }
            iVar5 = iVar5 + 8;
          } while ((int)uVar8 < (int)(uint)*(ushort *)(param_1 + 0x400));
        }
      }
      iVar11 = iVar11 + 1;
      uVar6 = *(uint *)(uRam020cd1b8 & 0xfffffffc) >> (uRam020cd1b8 & 3) * 8 |
              *(uint *)(uRam020cd1b8 & 0xfffffffc) << (uRam020cd1b8 & 3) * -8 + 0x20;
      iVar10 = iVar10 + 0x14;
      uVar9 = uVar6 + 4 & 3;
      uVar4 = *(uint *)(uVar6 + 4 & 0xfffffffc);
    } while (iVar11 < (int)(uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20));
    return;
  }
  return;
}

