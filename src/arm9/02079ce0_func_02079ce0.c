/* Decompiled C draft; module arm9; ROM address 02079ce0. No matching claim. */
#include "types.h"
#include "deps/02079ce0_func_02079ce0.h"

bool func_02079ce0(int param_1,short param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  short *psVar11;
  
  psVar11 = (short *)(param_1 + 0x6a);
  if (*(short *)(param_1 + 0x94) < 0x1000) {
    *(short *)(param_1 + 0x94) = *(short *)(param_1 + 0x94) + param_2;
    sVar1 = *(short *)(param_1 + 0x94);
    if (0xfff < sVar1) {
      *(undefined2 *)(param_1 + 0x94) = 0x1000;
    }
    iVar9 = (int)*(short *)(param_1 + 0x94);
    bVar10 = 0xfff < sVar1;
    *psVar11 = (short)(((int)*(short *)(param_1 + 0x70) +
                       (*(short *)(param_1 + 0x76) * iVar9 + 0x800U >> 0xc)) * 0x10000 >> 0x10) +
               (short)((int)(((int)*(short *)(param_1 + 0x72) +
                             (*(short *)(param_1 + 0x78) * iVar9 + 0x800U >> 0xc)) * 0x10000) >> 0xb
                      ) +
               (short)((int)(((int)*(short *)(param_1 + 0x74) +
                             (*(short *)(param_1 + 0x7a) * iVar9 + 0x800U >> 0xc)) * 0x10000) >> 6);
    uVar8 = param_1 + 0x10U & 3;
    uVar7 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    uVar8 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    ModelBlock_SomeMatFn_0(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20,*psVar11);
    uVar8 = param_1 + 0x14U & 3;
    uVar7 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    uVar8 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    ModelBlock_SomeMatFn_0(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20,*psVar11);
    uVar8 = param_1 + 0x18U & 3;
    uVar7 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    if (uVar8 != 0) {
      uVar8 = uVar8 + 4;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      ModelBlock_SomeMatFn_0(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20,*psVar11);
    }
    iVar9 = (int)*(short *)(param_1 + 0x94);
    *(short *)(param_1 + 0x6c) =
         (short)(((int)*(short *)(param_1 + 0x7c) +
                 (*(short *)(param_1 + 0x82) * iVar9 + 0x800U >> 0xc)) * 0x10000 >> 0x10) +
         (short)((int)(((int)*(short *)(param_1 + 0x7e) +
                       (*(short *)(param_1 + 0x84) * iVar9 + 0x800U >> 0xc)) * 0x10000) >> 0xb) +
         (short)((int)(((int)*(short *)(param_1 + 0x80) +
                       (*(short *)(param_1 + 0x86) * iVar9 + 0x800U >> 0xc)) * 0x10000) >> 6);
    uVar8 = param_1 + 0x10U & 3;
    uVar7 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    uVar8 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    ModelBlock_SetEmi(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20,
                      *(undefined2 *)(param_1 + 0x6c));
    uVar8 = param_1 + 0x14U & 3;
    uVar7 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    uVar8 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    ModelBlock_SetEmi(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20,
                      *(undefined2 *)(param_1 + 0x6c));
    uVar8 = param_1 + 0x18U & 3;
    uVar7 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    if (uVar8 != 0) {
      uVar8 = uVar8 + 4;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      ModelBlock_SetEmi(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20,
                        *(undefined2 *)(param_1 + 0x6c));
    }
    iVar9 = (int)*(short *)(param_1 + 0x94);
    sVar1 = *(short *)(param_1 + 0x8e);
    sVar2 = *(short *)(param_1 + 0x90);
    sVar3 = *(short *)(param_1 + 0x92);
    uVar8 = param_1 + 0x10U & 3;
    uVar7 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    sVar4 = *(short *)(param_1 + 0x88);
    sVar5 = *(short *)(param_1 + 0x8a);
    sVar6 = *(short *)(param_1 + 0x8c);
    uVar8 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    ModelBlock_SomeMatFn_1
              (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20,*(undefined2 *)(param_1 + 0x6e));
    uVar8 = param_1 + 0x14U & 3;
    uVar7 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    uVar8 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    ModelBlock_SomeMatFn_1
              (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20,*(undefined2 *)(param_1 + 0x6e));
    uVar8 = param_1 + 0x18U & 3;
    uVar7 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    if (uVar8 != 0) {
      uVar8 = uVar8 + 4;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      ModelBlock_SomeMatFn_1
                (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20,*(undefined2 *)(param_1 + 0x6e));
    }
    *(short *)(param_1 + 0x6e) =
         (short)(((int)sVar4 + (sVar1 * iVar9 + 0x800U >> 0xc)) * 0x10000 >> 0x10) +
         (short)(((int)sVar5 + (sVar2 * iVar9 + 0x800U >> 0xc)) * 0x10000 >> 0x10) * 0x20 +
         (short)(((int)sVar6 + (sVar3 * iVar9 + 0x800U >> 0xc)) * 0x10000 >> 0x10) * 0x400;
  }
  else {
    bVar10 = true;
  }
  return bVar10;
}

