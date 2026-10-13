/* Decompiled C draft; module arm9; ROM address 020f3c54. No matching claim. */
#include "types.h"
#include "deps/020f3c54_func_020f3c54.h"

bool func_020f3c54(uint param_1,uint *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar9;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint local_44;
  int local_40;
  int local_3c;
  uint uVar8;
  uint uVar10;
  
  uVar3 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar13 = param_3 + 4 & 3;
  uVar6 = *(uint *)(param_3 + 4 & 0xfffffffc);
  uVar7 = uVar3 + 0x18 & 3;
  uVar9 = *(uint *)(uVar3 + 0x18 & 0xfffffffc);
  uVar10 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
  uVar7 = uVar10 + 4 & 3;
  uVar9 = *(uint *)(uVar10 + 4 & 0xfffffffc);
  uVar11 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
           *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
  iVar12 = (int)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) -
                (uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20)) >> 0xc;
  uVar13 = uVar10 + 8 & 3;
  uVar6 = *(uint *)(uVar10 + 8 & 0xfffffffc);
  iVar4 = (int)((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) - uVar11) >> 0xc;
  uVar7 = param_3 + 8 & 3;
  uVar9 = *(uint *)(param_3 + 8 & 0xfffffffc);
  iVar5 = (int)((uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20) -
               (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20)) >> 0xc;
  iVar12 = iVar5 * iVar5 + iVar4 * iVar4 + iVar12 * iVar12;
  local_40 = 0;
  local_44 = uVar3;
  if (*(short *)(uVar3 + 0x24) != 0) {
    do {
      uVar13 = uVar3 + local_40 * 4;
      uVar7 = uVar13 & 3;
      uVar13 = *(uint *)(uVar13 & 0xfffffffc);
      uVar13 = uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20;
      if (uVar13 != 0) {
        uVar7 = uVar13 + 0x18 & 3;
        uVar9 = *(uint *)(uVar13 + 0x18 & 0xfffffffc);
        uVar9 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
        uVar7 = param_3 + 4 & 3;
        uVar6 = *(uint *)(param_3 + 4 & 0xfffffffc);
        uVar10 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
        uVar7 = uVar9 + 4 & 3;
        uVar6 = *(uint *)(uVar9 + 4 & 0xfffffffc);
        iVar4 = (int)((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                      *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) - uVar11) >> 0xc;
        iVar5 = (int)((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) - uVar10) >> 0xc;
        uVar7 = param_3 + 8 & 3;
        uVar6 = *(uint *)(param_3 + 8 & 0xfffffffc);
        uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
        uVar7 = uVar9 + 8 & 3;
        uVar9 = *(uint *)(uVar9 + 8 & 0xfffffffc);
        iVar1 = (int)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) - uVar6) >> 0xc;
        iVar4 = iVar1 * iVar1 + iVar4 * iVar4 + iVar5 * iVar5;
        if (iVar4 < iVar12) {
          iVar12 = iVar4;
          local_44 = uVar13;
        }
        iVar4 = 0;
        if (*(ushort *)(uVar13 + 0x24) != 0) {
          do {
            uVar7 = uVar13 + iVar4 * 4;
            uVar9 = uVar7 & 3;
            uVar7 = *(uint *)(uVar7 & 0xfffffffc);
            uVar8 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
            iVar4 = iVar4 + 1;
            uVar7 = uVar8 + 0x18;
            uVar9 = uVar7 & 3;
            uVar7 = *(uint *)(uVar7 & 0xfffffffc);
            uVar14 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
            uVar7 = uVar14 + 4 & 3;
            uVar9 = *(uint *)(uVar14 + 4 & 0xfffffffc);
            iVar5 = (int)((*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                          *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) - uVar11) >>
                    0xc;
            iVar1 = (int)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) - uVar10) >> 0xc;
            uVar7 = uVar14 + 8 & 3;
            uVar9 = *(uint *)(uVar14 + 8 & 0xfffffffc);
            iVar2 = (int)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) - uVar6) >> 0xc;
            iVar5 = iVar2 * iVar2 + iVar5 * iVar5 + iVar1 * iVar1;
            if (iVar5 < iVar12) {
              iVar12 = iVar5;
              local_44 = uVar8;
            }
          } while (iVar4 < (int)(uint)*(ushort *)(uVar13 + 0x24));
        }
        iVar4 = 0;
        if (*(ushort *)(uVar13 + 0x26) != 0) {
          do {
            uVar7 = uVar13 + iVar4 * 4 + 0xc;
            uVar9 = uVar7 & 3;
            uVar7 = *(uint *)(uVar7 & 0xfffffffc);
            uVar7 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
            if (uVar7 != uVar3) {
              uVar9 = uVar7 + 0x18 & 3;
              uVar8 = *(uint *)(uVar7 + 0x18 & 0xfffffffc);
              uVar14 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
              uVar9 = uVar14 + 4 & 3;
              uVar8 = *(uint *)(uVar14 + 4 & 0xfffffffc);
              iVar5 = (int)((*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                            *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) - uVar11) >>
                      0xc;
              iVar1 = (int)((uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) - uVar10) >> 0xc;
              uVar9 = uVar14 + 8 & 3;
              uVar8 = *(uint *)(uVar14 + 8 & 0xfffffffc);
              iVar2 = (int)((uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) - uVar6) >> 0xc;
              iVar5 = iVar2 * iVar2 + iVar5 * iVar5 + iVar1 * iVar1;
              if (iVar5 < iVar12) {
                iVar12 = iVar5;
                local_44 = uVar7;
              }
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < (int)(uint)*(ushort *)(uVar13 + 0x26));
        }
      }
      local_40 = local_40 + 1;
    } while (local_40 < (int)(uint)*(ushort *)(uVar3 + 0x24));
  }
  local_3c = 0;
  if (*(short *)(uVar3 + 0x26) != 0) {
    do {
      uVar13 = uVar3 + local_3c * 4 + 0xc;
      uVar7 = uVar13 & 3;
      uVar13 = *(uint *)(uVar13 & 0xfffffffc);
      uVar13 = uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20;
      if (uVar13 != 0) {
        uVar7 = uVar13 + 0x18 & 3;
        uVar9 = *(uint *)(uVar13 + 0x18 & 0xfffffffc);
        uVar9 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
        uVar7 = param_3 + 4 & 3;
        uVar6 = *(uint *)(param_3 + 4 & 0xfffffffc);
        uVar10 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
        uVar7 = uVar9 + 4 & 3;
        uVar6 = *(uint *)(uVar9 + 4 & 0xfffffffc);
        iVar4 = (int)((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                      *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) - uVar11) >> 0xc;
        iVar5 = (int)((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) - uVar10) >> 0xc;
        uVar7 = param_3 + 8 & 3;
        uVar6 = *(uint *)(param_3 + 8 & 0xfffffffc);
        uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
        uVar7 = uVar9 + 8 & 3;
        uVar9 = *(uint *)(uVar9 + 8 & 0xfffffffc);
        iVar1 = (int)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) - uVar6) >> 0xc;
        iVar4 = iVar1 * iVar1 + iVar4 * iVar4 + iVar5 * iVar5;
        if (iVar4 < iVar12) {
          iVar12 = iVar4;
          local_44 = uVar13;
        }
        iVar4 = 0;
        if (*(ushort *)(uVar13 + 0x26) != 0) {
          do {
            uVar7 = uVar13 + iVar4 * 4 + 0xc;
            uVar9 = uVar7 & 3;
            uVar7 = *(uint *)(uVar7 & 0xfffffffc);
            uVar14 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
            iVar4 = iVar4 + 1;
            uVar7 = uVar14 + 0x18;
            uVar9 = uVar7 & 3;
            uVar7 = *(uint *)(uVar7 & 0xfffffffc);
            uVar8 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
            uVar7 = uVar8 + 4 & 3;
            uVar9 = *(uint *)(uVar8 + 4 & 0xfffffffc);
            iVar5 = (int)((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                          *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) - uVar11) >> 0xc
            ;
            iVar1 = (int)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) - uVar10) >> 0xc;
            uVar7 = uVar8 + 8 & 3;
            uVar9 = *(uint *)(uVar8 + 8 & 0xfffffffc);
            iVar2 = (int)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) - uVar6) >> 0xc;
            iVar5 = iVar2 * iVar2 + iVar5 * iVar5 + iVar1 * iVar1;
            if (iVar5 < iVar12) {
              iVar12 = iVar5;
              local_44 = uVar14;
            }
          } while (iVar4 < (int)(uint)*(ushort *)(uVar13 + 0x26));
        }
        iVar4 = 0;
        if (*(ushort *)(uVar13 + 0x24) != 0) {
          do {
            uVar7 = uVar13 + iVar4 * 4;
            uVar9 = uVar7 & 3;
            uVar7 = *(uint *)(uVar7 & 0xfffffffc);
            uVar7 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
            if (uVar7 != uVar3) {
              uVar9 = uVar7 + 0x18 & 3;
              uVar8 = *(uint *)(uVar7 + 0x18 & 0xfffffffc);
              uVar14 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
              uVar9 = uVar14 + 4 & 3;
              uVar8 = *(uint *)(uVar14 + 4 & 0xfffffffc);
              iVar5 = (int)((*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                            *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) - uVar11) >>
                      0xc;
              iVar1 = (int)((uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) - uVar10) >> 0xc;
              uVar9 = uVar14 + 8 & 3;
              uVar8 = *(uint *)(uVar14 + 8 & 0xfffffffc);
              iVar2 = (int)((uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) - uVar6) >> 0xc;
              iVar5 = iVar2 * iVar2 + iVar5 * iVar5 + iVar1 * iVar1;
              if (iVar5 < iVar12) {
                iVar12 = iVar5;
                local_44 = uVar7;
              }
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < (int)(uint)*(ushort *)(uVar13 + 0x24));
        }
      }
      local_3c = local_3c + 1;
    } while (local_3c < (int)(uint)*(ushort *)(uVar3 + 0x26));
  }
  *param_2 = local_44;
  param_2[1] = 1;
  return local_44 != uVar3;
}

