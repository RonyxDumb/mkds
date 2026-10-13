/* Decompiled C draft; module arm9; ROM address 0207fa74. No matching claim. */
#include "types.h"
#include "deps/0207fa74_func_0207fa74.h"

void func_0207fa74(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar10;
  
  *param_1 = param_2;
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(param_2 + 0x74);
  *(ushort *)((int)param_1 + 6) = *(ushort *)(param_1 + 1) & 3;
  if (param_3 == 0) {
    iVar3 = func_020853f0((short)param_1[1]);
  }
  else {
    iVar3 = 0;
  }
  uVar5 = uRam0207fb9c;
  uVar1 = uRam0207fb98;
  uVar11 = (*(uint *)(uRam0207fb94 & 0xfffffffc) >> (uRam0207fb94 & 3) * 8 |
           *(uint *)(uRam0207fb94 & 0xfffffffc) << (uRam0207fb94 & 3) * -8 + 0x20) + iVar3 * 4;
  uVar12 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  param_1[0x22] = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
  uVar11 = uVar1 & 3;
  uVar12 = *(uint *)(uVar1 & 0xfffffffc);
  uVar11 = (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) + iVar3 * 4;
  uVar12 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  param_1[0x23] = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
  uVar11 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x2cc;
  uVar12 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  uVar11 = (uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20) + 0x10;
  uVar12 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  uVar12 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
  lVar2 = (ulonglong)uVar5 * (ulonglong)uVar12;
  uVar11 = (uint)lVar2;
  param_1[0x27] =
       uVar11 + 0x800 >> 0xc |
       (((int)uVar12 >> 0x1f) * uVar5 + (int)((ulonglong)lVar2 >> 0x20) +
       (uint)(0xfffff7ff < uVar11)) * 0x100000;
  func_02080d34(param_1 + 2,(short)param_1[1]);
  func_0207f9cc(param_1,0);
  piVar4 = (int *)func_0208537c();
  uVar11 = (uint)(piVar4 + 2) & 3;
  uVar12 = *(uint *)((uint)(piVar4 + 2) & 0xfffffffc);
  uVar8 = uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20;
  uVar7 = *(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
          *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20;
  uVar11 = (uint)(piVar4 + 1) & 3;
  uVar5 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
  lVar2 = (ulonglong)uVar7 * (ulonglong)uVar8;
  uVar13 = (uint)lVar2;
  uVar12 = (uint)(piVar4 + 3) & 3;
  uVar6 = *(uint *)((uint)(piVar4 + 3) & 0xfffffffc);
  uVar1 = (uint)(piVar4 + 4) & 3;
  uVar9 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar10 = uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20;
  uVar1 = (uint)(piVar4 + 5) & 3;
  uVar9 = *(uint *)((uint)(piVar4 + 5) & 0xfffffffc);
  *piVar4 = uVar10 + uVar13;
  piVar4[1] = (uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) +
              (uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) * uVar7 +
              uVar8 * (uVar5 >> uVar11 * 8 | uVar5 << uVar11 * -8 + 0x20) +
              (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar10,uVar13);
  uVar11 = (uint)(piVar4 + 1) & 3;
  uVar12 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
  if ((ushort)((ushort)((uVar12 >> uVar11 * 8) >> 0x10) |
              (ushort)((uVar12 << uVar11 * -8 + 0x20) >> 0x10)) >> 4 < 0x801) {
    iVar3 = -1;
  }
  else {
    iVar3 = 1;
  }
  param_1[0x33] = iVar3;
  return;
}

