/* Decompiled C draft; module arm9; ROM address 02083484. No matching claim. */
#include "types.h"
#include "deps/02083484_func_02083484.h"

void func_02083484(int param_1,int param_2)

{
  char cVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  uint uVar10;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  uint uStack_28;
  uint uStack_24;
  uint uStack_20;
  uint uVar11;
  
  if (param_2 == 0) {
    uVar8 = param_1 + 0x94U & 3;
    uVar10 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
    uVar11 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
    uVar7 = 0;
    iStack_34 = *(int *)(uVar11 + 0x3b0);
    iStack_30 = *(int *)(uVar11 + 0x3b4);
    iStack_2c = *(int *)(uVar11 + 0x3b8);
    uVar8 = iRam02083678 + (uint)*(byte *)(param_1 + 0x98) * 4;
    uVar10 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar8 = uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20;
    cVar9 = *(char *)(param_1 + 0x9a);
    cVar1 = *(char *)(param_1 + 0x99);
    bVar3 = true;
    iVar4 = StructMQRacerEntry_SomeFn_51(uVar11);
    if ((iVar4 == 0) &&
       (uVar10 = uVar11 + 0x2a4 & 3, uVar6 = *(uint *)(uVar11 + 0x2a4 & 0xfffffffc),
       iRam0208367c <= (int)(uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20))) {
      bVar3 = false;
    }
    if (bVar3) {
      uVar7 = 1;
    }
    uVar10 = param_1 + 0x24U & 3;
    uVar6 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    if (!bVar3) {
      uVar7 = 0;
    }
    *(uint *)(param_1 + 0x24) =
         (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) & 0xfffffffd | (uVar7 & 1) << 1;
    uVar10 = uVar11 + 0x138 & 3;
    uVar7 = *(uint *)(uVar11 + 0x138 & 0xfffffffc);
    uVar10 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
    lVar2 = (ulonglong)uVar10 * 0xffffb000;
    uStack_28 = (uint)lVar2 >> 0xc | ((int)((ulonglong)lVar2 >> 0x20) - uVar10) * 0x100000;
    uVar10 = uVar11 + 0x13c & 3;
    uVar7 = *(uint *)(uVar11 + 0x13c & 0xfffffffc);
    uVar10 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
    lVar2 = (ulonglong)uVar10 * 0xffffb000;
    uStack_24 = (uint)lVar2 >> 0xc | ((int)((ulonglong)lVar2 >> 0x20) - uVar10) * 0x100000;
    uVar10 = uVar11 + 0x140 & 3;
    uVar7 = *(uint *)(uVar11 + 0x140 & 0xfffffffc);
    uVar10 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
    puVar5 = (uint *)(param_1 + 0x24);
    lVar2 = (ulonglong)uVar10 * 0xffffb000;
    uStack_20 = (uint)lVar2 >> 0xc | ((int)((ulonglong)lVar2 >> 0x20) - uVar10) * 0x100000;
    if ((cVar1 != '\0') && (cVar9 = cVar9 + '\x01', cVar9 == '\n')) {
      *puVar5 = (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) & 0xfffffffe
                | 1;
    }
    *(char *)(param_1 + 0x9a) = cVar9;
    uVar10 = uVar11 + 0x508 & 3;
    uVar7 = *(uint *)(uVar11 + 0x508 & 0xfffffffc);
    VecFx32_Add(uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20,&uStack_28,&iStack_40);
    uVar10 = param_1 + 0x20U & 3;
    uVar7 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar7 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
    uVar10 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar10 = (uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) + 4;
    uVar7 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    *(uint *)(param_1 + 0x28) =
         (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + (iStack_40 >> 4);
    uVar10 = param_1 + 0x20U & 3;
    uVar7 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar7 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
    uVar10 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar10 = (uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) + 8;
    uVar7 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    *(uint *)(param_1 + 0x2c) =
         (iStack_3c >> 4) + (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20);
    uVar10 = param_1 + 0x20U & 3;
    uVar7 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar7 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
    uVar10 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar10 = (uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) + 0xc;
    uVar7 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    *(uint *)(param_1 + 0x30) =
         (iStack_38 >> 4) + (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20);
    *(uint *)(param_1 + 0x40) =
         (uint)((longlong)iStack_34 * (longlong)(int)uVar8) >> 0xc |
         (int)((ulonglong)((longlong)iStack_34 * (longlong)(int)uVar8) >> 0x20) << 0x14;
    *(uint *)(param_1 + 0x44) =
         (uint)((longlong)iStack_30 * (longlong)(int)uVar8) >> 0xc |
         (int)((ulonglong)((longlong)iStack_30 * (longlong)(int)uVar8) >> 0x20) << 0x14;
    *(uint *)(param_1 + 0x48) =
         (uint)((longlong)iStack_2c * (longlong)(int)uVar8) >> 0xc |
         (int)((ulonglong)((longlong)iStack_2c * (longlong)(int)uVar8) >> 0x20) << 0x14;
    return;
  }
  return;
}

