/* Decompiled C draft; module arm9; ROM address 020122cc. No matching claim. */
#include "types.h"
#include "deps/020122cc_func_020122cc.h"

void func_020122cc(int *param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar12;
  uint unaff_r8;
  uint uStack_f0;
  uint local_ec;
  undefined1 auStack_e8 [16];
  undefined1 auStack_d8 [4];
  int local_d4;
  int local_d0;
  undefined1 auStack_c8 [16];
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined1 auStack_a8 [64];
  undefined1 auStack_68 [68];
  uint uVar11;
  
  iVar6 = iRam020125f8;
  puVar5 = puRam020125f4;
  puVar4 = puRam020125f0;
  uVar11 = (uint)(param_1 + 2) & 3;
  uVar10 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar11 = uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20;
  iVar12 = 2;
  if ((uVar11 & 0x200) == 0) {
    if (((param_2 == 0x40) || (param_2 == 0x60)) && (iVar12 = 3, (uVar11 & 0x100) == 0)) {
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
      uStack_f0 = (uint)bVar1;
      func_01ff9048(0x14,&uStack_f0,1);
    }
    uVar11 = (uint)(param_1 + 0xb) & 3;
    uVar10 = *(uint *)((uint)(param_1 + 0xb) & 0xfffffffc);
    bVar2 = uVar10 >> uVar11 * 8 != 0;
    bVar3 = uVar10 << uVar11 * -8 + 0x20 != 0;
    if (bVar2 || bVar3) {
      unaff_r8 = (uint)*(byte *)(param_1 + 0x25);
    }
    uVar11 = (uint)(param_1 + 2) & 3;
    uVar10 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    if (!bVar2 && !bVar3) {
      unaff_r8 = 0;
    }
    if (((uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) & 0x100) == 0) {
      func_01ff9234();
      puVar7 = puRam02012600;
      *puRam02012600 = uRam020125fc;
      *puVar7 = 0;
      *puVar7 = 0;
      do {
        iVar8 = G3X_GetClipMtx(auStack_e8);
      } while (iVar8 != 0);
      uVar11 = iRam02012604 + 0xfcU & 3;
      uVar10 = *(uint *)(iRam02012604 + 0xfcU & 0xfffffffc);
      uVar11 = uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20;
      if ((uVar11 & 1) == 0) {
        if ((uVar11 & 2) != 0) {
          func_021471e4(uRam02012608,auStack_68);
          func_021479b4(auStack_e8,auStack_68,auStack_e8);
        }
      }
      else {
        uVar9 = func_02010e2c();
        func_021471e4(uVar9,auStack_a8);
        func_021479b4(auStack_e8,auStack_a8,auStack_e8);
      }
      *puVar4 = local_b8;
      puVar4[1] = local_b4;
      puVar4[2] = local_b0;
      uVar9 = VecFx32_Norm(auStack_e8);
      *puVar5 = uVar9;
      uVar9 = VecFx32_Norm(auStack_d8);
      puVar5[1] = uVar9;
      uVar9 = VecFx32_Norm(auStack_c8);
      puVar5[2] = uVar9;
      if ((local_d4 == 0) && (local_d0 == 0)) {
        VecFx32_Normalize(auStack_c8,iVar6 + 0x18);
        uVar11 = iVar6 + 0x1cU & 3;
        uVar10 = *(uint *)(iVar6 + 0x1cU & 0xfffffffc);
        *(uint *)(iVar6 + 0x14) = -(uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20);
        uVar11 = iVar6 + 0x20U & 3;
        uVar10 = *(uint *)(iVar6 + 0x20U & 0xfffffffc);
        *(uint *)(iVar6 + 0x10) = uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20;
      }
      else {
        VecFx32_Normalize(auStack_d8,iVar6 + 0xc);
        uVar11 = iVar6 + 0x14U & 3;
        uVar10 = *(uint *)(iVar6 + 0x14U & 0xfffffffc);
        *(uint *)(iVar6 + 0x1c) = -(uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20);
        uVar11 = iVar6 + 0x10U & 3;
        uVar10 = *(uint *)(iVar6 + 0x10U & 0xfffffffc);
        *(uint *)(iVar6 + 0x20) = uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20;
      }
      uVar9 = uRam02012610;
      puVar4 = puRam02012600;
      uVar11 = iRam02012604 + 0xfcU & 3;
      uVar10 = *(uint *)(iRam02012604 + 0xfcU & 0xfffffffc);
      uVar11 = uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20;
      if ((uVar11 & 1) == 0) {
        if ((uVar11 & 2) == 0) {
          MIi_CpuSend32(uRam02012618,puRam02012600,0x48);
        }
        else {
          *puRam02012600 = uRam0201260c;
          MIi_CpuSend32(uVar9,puVar4,8);
          uVar9 = func_02010ed4();
          MIi_CpuSend32(uVar9,puRam02012600,0x30);
          puVar4 = puRam02012600;
          iVar6 = iRam020125f8;
          *puRam02012600 = uRam02012614;
          MIi_CpuSend32(iVar6,puVar4,0x3c);
        }
      }
      else {
        *puRam02012600 = uRam0201260c;
        MIi_CpuSend32(uVar9,puVar4,8);
        uVar9 = func_02010de8();
        MIi_CpuSend32(uVar9,puRam02012600,0x30);
        puVar4 = puRam02012600;
        iVar6 = iRam020125f8;
        *puRam02012600 = uRam02012614;
        MIi_CpuSend32(iVar6,puVar4,0x3c);
      }
    }
    if (unaff_r8 == 3) {
      uVar11 = (uint)(param_1 + 2) & 3;
      uVar10 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      param_1[2] = (uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) & 0xffffffbf;
      uVar11 = (uint)(param_1 + 0xb) & 3;
      uVar10 = *(uint *)((uint)(param_1 + 0xb) & 0xfffffffc);
      (*(code *)(uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20))(param_1);
      uVar11 = (uint)(param_1 + 2) & 3;
      uVar10 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      uVar11 = (uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) & 0x40;
    }
    else {
      uVar11 = 0;
    }
    if (((param_2 == 0x20) || (param_2 == 0x60)) &&
       ((iVar12 = iVar12 + 1, uVar11 == 0 &&
        (uVar11 = (uint)(param_1 + 2) & 3, uVar10 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc),
        ((uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) & 0x100) == 0)))) {
      local_ec = (uint)*(byte *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                                 *(uint *)((uint)param_1 & 0xfffffffc) <<
                                 ((uint)param_1 & 3) * -8 + 0x20) + 2);
      func_01ff9048(0x13,&local_ec,1);
    }
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + iVar12;
    return;
  }
  if ((param_2 == 0x40) || (param_2 == 0x60)) {
    iVar12 = 3;
  }
  if ((param_2 == 0x20) || (param_2 == 0x60)) {
    iVar12 = iVar12 + 1;
  }
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + iVar12;
  return;
}

