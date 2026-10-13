/* Decompiled C draft; module arm9; ROM address 0201261c. No matching claim. */
#include "types.h"
#include "deps/0201261c_func_0201261c.h"

void func_0201261c(int *param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar11;
  uint unaff_r7;
  uint uStack_e8;
  uint local_e4;
  undefined1 auStack_e0 [16];
  undefined1 auStack_d0 [16];
  undefined1 auStack_c0 [16];
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined1 auStack_a0 [64];
  undefined1 auStack_60 [64];
  uint uVar10;
  
  puVar5 = puRam020128e4;
  puVar4 = puRam020128e0;
  uVar10 = (uint)(param_1 + 2) & 3;
  uVar9 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
  iVar11 = 2;
  if ((uVar10 & 0x200) == 0) {
    if (((param_2 == 0x40) || (param_2 == 0x60)) && (iVar11 = 3, (uVar10 & 0x100) == 0)) {
      if (param_2 == 0x40) {
        bVar1 = *(byte *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20)
                         + 2);
      }
      else {
        bVar1 = *(byte *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20)
                         + 3);
      }
      uStack_e8 = (uint)bVar1;
      func_01ff9048(0x14,&uStack_e8,1);
    }
    uVar10 = (uint)(param_1 + 10) & 3;
    uVar9 = *(uint *)((uint)(param_1 + 10) & 0xfffffffc);
    bVar2 = uVar9 >> uVar10 * 8 != 0;
    bVar3 = uVar9 << uVar10 * -8 + 0x20 != 0;
    if (bVar2 || bVar3) {
      unaff_r7 = (uint)*(byte *)((int)param_1 + 0x93);
    }
    uVar10 = (uint)(param_1 + 2) & 3;
    uVar9 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    if (!bVar2 && !bVar3) {
      unaff_r7 = 0;
    }
    if (((uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) & 0x100) == 0) {
      func_01ff9234();
      puVar6 = puRam020128ec;
      *puRam020128ec = uRam020128e8;
      *puVar6 = 0;
      *puVar6 = 0;
      do {
        iVar7 = G3X_GetClipMtx(auStack_e0);
      } while (iVar7 != 0);
      uVar10 = iRam020128f0 + 0xfcU & 3;
      uVar9 = *(uint *)(iRam020128f0 + 0xfcU & 0xfffffffc);
      uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
      if ((uVar10 & 1) == 0) {
        if ((uVar10 & 2) != 0) {
          func_021471e4(uRam020128f4,auStack_60);
          func_021479b4(auStack_e0,auStack_60,auStack_e0);
        }
      }
      else {
        uVar8 = func_02010e2c();
        func_021471e4(uVar8,auStack_a0);
        func_021479b4(auStack_e0,auStack_a0,auStack_e0);
      }
      *puVar4 = local_b0;
      puVar4[1] = local_ac;
      puVar4[2] = local_a8;
      uVar8 = VecFx32_Norm(auStack_e0);
      *puVar5 = uVar8;
      uVar8 = VecFx32_Norm(auStack_d0);
      puVar5[1] = uVar8;
      uVar8 = VecFx32_Norm(auStack_c0);
      iVar7 = iRam020128f0;
      puVar5[2] = uVar8;
      uVar8 = uRam020128fc;
      puVar4 = puRam020128ec;
      uVar10 = iVar7 + 0xfcU & 3;
      uVar9 = *(uint *)(iVar7 + 0xfcU & 0xfffffffc);
      uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
      if ((uVar10 & 1) == 0) {
        if ((uVar10 & 2) == 0) {
          MIi_CpuSend32(uRam02012908,puRam020128ec,0x48);
        }
        else {
          *puRam020128ec = uRam020128f8;
          MIi_CpuSend32(uVar8,puVar4,8);
          uVar8 = func_02010ed4();
          MIi_CpuSend32(uVar8,puRam020128ec,0x30);
          uVar8 = uRam02012904;
          puVar4 = puRam020128ec;
          *puRam020128ec = uRam02012900;
          MIi_CpuSend32(uVar8,puVar4,0x3c);
        }
      }
      else {
        *puRam020128ec = uRam020128f8;
        MIi_CpuSend32(uVar8,puVar4,8);
        uVar8 = func_02010de8();
        MIi_CpuSend32(uVar8,puRam020128ec,0x30);
        uVar8 = uRam02012904;
        puVar4 = puRam020128ec;
        *puRam020128ec = uRam02012900;
        MIi_CpuSend32(uVar8,puVar4,0x3c);
      }
    }
    if (unaff_r7 == 3) {
      uVar10 = (uint)(param_1 + 2) & 3;
      uVar9 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      param_1[2] = (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) & 0xffffffbf;
      uVar10 = (uint)(param_1 + 10) & 3;
      uVar9 = *(uint *)((uint)(param_1 + 10) & 0xfffffffc);
      (*(code *)(uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20))(param_1);
      uVar10 = (uint)(param_1 + 2) & 3;
      uVar9 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      uVar10 = (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) & 0x40;
    }
    else {
      uVar10 = 0;
    }
    if (((param_2 == 0x20) || (param_2 == 0x60)) &&
       ((iVar11 = iVar11 + 1, uVar10 == 0 &&
        (uVar10 = (uint)(param_1 + 2) & 3, uVar9 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc),
        ((uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) & 0x100) == 0)))) {
      local_e4 = (uint)*(byte *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                                 *(uint *)((uint)param_1 & 0xfffffffc) <<
                                 ((uint)param_1 & 3) * -8 + 0x20) + 2);
      func_01ff9048(0x13,&local_e4,1);
    }
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + iVar11;
    return;
  }
  if ((param_2 == 0x40) || (param_2 == 0x60)) {
    iVar11 = 3;
  }
  if ((param_2 == 0x20) || (param_2 == 0x60)) {
    iVar11 = iVar11 + 1;
  }
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + iVar11;
  return;
}

