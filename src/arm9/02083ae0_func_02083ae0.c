/* Decompiled C draft; module arm9; ROM address 02083ae0. No matching claim. */
#include "types.h"
#include "deps/02083ae0_func_02083ae0.h"

int func_02083ae0(short *param_1,undefined1 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  short **ppsVar12;
  short *local_30 [3];
  
  uVar3 = uRam02083c10;
  uVar2 = uRam02083c0c;
  uVar11 = 0;
  ppsVar12 = local_30;
  if (*param_1 == 0) {
    ppsVar12 = (short **)&stack0xffffffdc;
  }
  iVar4 = 0;
  if (*param_1 != 0) {
    ((int *)ppsVar12)[1] = 0;
    ((int *)ppsVar12)[2] = 1;
    local_30[0] = param_1;
    do {
      iVar5 = (uint)*(ushort *)(param_3 + 0x74) * 0x58 +
              (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20);
      uVar10 = ((int *)ppsVar12)[1];
      uVar6 = (int)*ppsVar12 + uVar11 * 4 + 4;
      uVar7 = uVar6 & 3;
      uVar8 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = iVar5 + uVar11 * 4 + 4;
      uVar1 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      if ((uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) !=
          (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20)) {
        iVar4 = iVar5 + uVar11 * 8;
        uVar6 = iVar4 + 0x10U & 3;
        uVar7 = *(uint *)(iVar4 + 0x10U & 0xfffffffc);
        uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
        iVar9 = iVar5 + uVar11 * 4;
        if (uVar6 != 0) {
          iVar4 = ((int *)ppsVar12)[2];
        }
        if (uVar6 != 0) {
          *(char *)(uVar6 + 0x99) = (char)iVar4;
        }
        uVar6 = iVar5 + uVar11 * 8 + 0x14;
        uVar7 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
        if (uVar6 != 0) {
          *(char *)(uVar6 + 0x99) = (char)((int *)ppsVar12)[2];
        }
        uVar6 = (int)*ppsVar12 + uVar11 * 4 + 4;
        uVar7 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        *(uint *)(iVar9 + 4) = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
        do {
          uVar6 = iVar9 + 4;
          uVar7 = uVar6 & 3;
          uVar6 = *(uint *)(uVar6 & 0xfffffffc);
          iVar4 = func_0208b7bc(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20,uRam02083c14);
          *(int *)((uint)*(ushort *)(param_3 + 0x74) * 0x58 +
                   uVar11 * 8 +
                   (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + uVar10 * 4 + 0x10) =
               iVar4;
          *(int *)(iVar4 + 0x94) = param_3;
          *(char *)(iVar4 + 0x9b) = (char)uVar10;
          uVar10 = uVar10 + 1 & 0xffff;
          *(undefined1 *)(iVar4 + 0x98) = param_2;
          *(undefined4 *)(iVar4 + 0x90) = uVar3;
        } while (uVar10 < 2);
        iVar4 = ((int *)ppsVar12)[2];
      }
      uVar11 = uVar11 + 1 & 0xffff;
    } while (uVar11 < (ushort)**ppsVar12);
    return iVar4;
  }
  return iVar4;
}

