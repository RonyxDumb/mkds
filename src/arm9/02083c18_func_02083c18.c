/* Decompiled C draft; module arm9; ROM address 02083c18. No matching claim. */
#include "types.h"
#include "deps/02083c18_func_02083c18.h"

int func_02083c18(short *param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  short **ppsVar13;
  short *local_30 [3];
  
  uVar4 = uRam02083d48;
  uVar3 = uRam02083d44;
  uVar2 = uRam02083d40;
  uVar12 = 0;
  ppsVar13 = local_30;
  if (*param_1 == 0) {
    ppsVar13 = (short **)&stack0xffffffdc;
  }
  iVar5 = 0;
  if (*param_1 != 0) {
    ((int *)ppsVar13)[1] = 0;
    ((int *)ppsVar13)[2] = 1;
    local_30[0] = param_1;
    do {
      iVar6 = (uint)*(ushort *)(param_3 + 0x74) * 0x58 +
              (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20);
      uVar11 = ((int *)ppsVar13)[1];
      uVar7 = (int)*ppsVar13 + uVar12 * 4 + 4;
      uVar8 = uVar7 & 3;
      uVar9 = *(uint *)(uVar7 & 0xfffffffc);
      uVar7 = iVar6 + uVar12 * 4 + 4;
      uVar1 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      if ((uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) !=
          (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20)) {
        iVar5 = iVar6 + uVar12 * 8;
        uVar7 = iVar5 + 0x10U & 3;
        uVar8 = *(uint *)(iVar5 + 0x10U & 0xfffffffc);
        uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        iVar10 = iVar6 + uVar12 * 4;
        if (uVar7 != 0) {
          iVar5 = ((int *)ppsVar13)[2];
        }
        if (uVar7 != 0) {
          *(char *)(uVar7 + 0x99) = (char)iVar5;
        }
        uVar7 = iVar6 + uVar12 * 8 + 0x14;
        uVar8 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        uVar7 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
        if (uVar7 != 0) {
          *(char *)(uVar7 + 0x99) = (char)((int *)ppsVar13)[2];
        }
        uVar7 = (int)*ppsVar13 + uVar12 * 4 + 4;
        uVar8 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        *(uint *)(iVar10 + 4) = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
        do {
          uVar7 = iVar10 + 4;
          uVar8 = uVar7 & 3;
          uVar7 = *(uint *)(uVar7 & 0xfffffffc);
          iVar5 = func_0208b7bc(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20,uVar2);
          *(int *)((uint)*(ushort *)(param_3 + 0x74) * 0x58 +
                   uVar12 * 8 +
                   (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                   *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + uVar11 * 4 + 0x10) =
               iVar5;
          *(int *)(iVar5 + 0x94) = param_3;
          *(char *)(iVar5 + 0x9b) = (char)uVar11;
          uVar11 = uVar11 + 1 & 0xffff;
          *(undefined4 *)(iVar5 + 0x90) = uVar4;
        } while (uVar11 < 2);
        iVar5 = ((int *)ppsVar13)[2];
      }
      uVar12 = uVar12 + 1 & 0xffff;
    } while (uVar12 < (ushort)**ppsVar13);
    return iVar5;
  }
  return iVar5;
}

