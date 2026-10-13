/* Decompiled C draft; module arm9; ROM address 02041dc8. No matching claim. */
#include "types.h"
#include "deps/02041dc8_func_02041dc8.h"

void func_02041dc8(int *param_1,uint *param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_cc;
  int local_c8;
  int local_c4;
  undefined1 auStack_b4 [48];
  undefined1 auStack_84 [48];
  undefined1 auStack_54 [48];
  
  uVar10 = *(uint *)(uRam0204203c & 0xfffffffc) >> (uRam0204203c & 3) * 8 |
           *(uint *)(uRam0204203c & 0xfffffffc) << (uRam0204203c & 3) * -8 + 0x20;
  uVar8 = uVar10 + 0x18 & 3;
  uVar6 = *(uint *)(uVar10 + 0x18 & 0xfffffffc);
  if (*(char *)((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 4) != '\0') {
    param_4 = 0x1000 - param_4;
  }
  if (*(ushort *)(uVar10 + 0x20) < 2) {
    uVar8 = uVar10 + 0x1c & 3;
    uVar6 = *(uint *)(uVar10 + 0x1c & 0xfffffffc);
    uVar8 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
  }
  else {
    iVar11 = 0;
    uVar8 = 0;
    if (*(ushort *)(uVar10 + 0x20) != 0) {
      uVar10 = *(uint *)(uRam0204203c & 0xfffffffc) >> (uRam0204203c & 3) * 8 |
               *(uint *)(uRam0204203c & 0xfffffffc) << (uRam0204203c & 3) * -8 + 0x20;
      uVar8 = uVar10 + 0x1c;
      uVar6 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar6 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
      do {
        uVar8 = uVar6;
        if (param_3 == *(short *)(uVar6 + 0x1a)) break;
        iVar11 = iVar11 + 1;
        uVar6 = uVar6 + 0x1c;
        uVar8 = 0;
      } while (iVar11 < (int)(uint)*(ushort *)(uVar10 + 0x20));
    }
  }
  uVar6 = uVar8 + 0xc & 3;
  uVar7 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
  uVar10 = uVar8 + 0x10 & 3;
  uVar12 = *(uint *)(uVar8 + 0x10 & 0xfffffffc);
  uVar1 = uVar8 + 0x14 & 3;
  uVar9 = *(uint *)(uVar8 + 0x14 & 0xfffffffc);
  iVar11 = (int)((uint)(((int)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) >> 0xc) * 0xb60000)
                >> 0x10) >> 4;
  MTX_RotX43__from_thumb
            (auStack_b4,(int)*(short *)(iRam02042040 + iVar11 * 4),
             (int)*(short *)(iRam02042040 + (iVar11 * 2 + 1) * 2));
  iVar11 = (int)((uint)(((int)(uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) >> 0xc) *
                       0xb60000) >> 0x10) >> 4;
  MTX_RotY43__from_thumb
            (auStack_84,(int)*(short *)(iRam02042040 + iVar11 * 4),
             (int)*(short *)(iRam02042040 + (iVar11 * 2 + 1) * 2));
  iVar11 = (int)((uint)(((int)(uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) >> 0xc) * 0xb60000)
                >> 0x10) >> 4;
  MTX_RotZ43__from_thumb
            (auStack_54,(int)*(short *)(iRam02042040 + iVar11 * 4),
             (int)*(short *)(iRam02042040 + (iVar11 * 2 + 1) * 2));
  MTX_Concat43(auStack_b4,auStack_54,&local_e4);
  MTX_Concat43(auStack_84,&local_e4,&local_e4);
  lVar3 = (longlong)-local_e4 * (longlong)param_4 + 0x800;
  lVar4 = (longlong)-local_cc * (longlong)param_5 + 0x800;
  lVar2 = (longlong)-local_e0 * (longlong)param_4 + 0x800;
  *param_1 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
             *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) +
             ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
             ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000);
  lVar3 = (longlong)-local_c8 * (longlong)param_5 + 0x800;
  lVar4 = (longlong)-local_dc * (longlong)param_4 + 0x800;
  lVar5 = (longlong)-local_c4 * (longlong)param_5 + 0x800;
  uVar6 = uVar8 + 4 & 3;
  uVar10 = *(uint *)(uVar8 + 4 & 0xfffffffc);
  param_1[1] = (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) +
               ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) +
               ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000);
  uVar6 = uVar8 + 8 & 3;
  uVar10 = *(uint *)(uVar8 + 8 & 0xfffffffc);
  param_1[2] = (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) +
               ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000) +
               ((uint)lVar5 >> 0xc | (int)((ulonglong)lVar5 >> 0x20) * 0x100000);
  uVar6 = uVar8 + 0xc & 3;
  uVar10 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
  *param_2 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
  uVar6 = uVar8 + 0x10 & 3;
  uVar10 = *(uint *)(uVar8 + 0x10 & 0xfffffffc);
  param_2[1] = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
  uVar6 = uVar8 + 0x14 & 3;
  uVar8 = *(uint *)(uVar8 + 0x14 & 0xfffffffc);
  param_2[2] = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
  return;
}

