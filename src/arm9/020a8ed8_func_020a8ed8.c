/* Decompiled C draft; module arm9; ROM address 020a8ed8. No matching claim. */
#include "types.h"
#include "deps/020a8ed8_func_020a8ed8.h"

void func_020a8ed8(int param_1,uint param_2)

{
  longlong lVar1;
  short *psVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  iVar3 = GetGlobalHD4();
  uVar7 = *(uint *)(uRam020a91a4 & 0xfffffffc) >> (uRam020a91a4 & 3) * 8 |
          *(uint *)(uRam020a91a4 & 0xfffffffc) << (uRam020a91a4 & 3) * -8 + 0x20;
  uVar4 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  if (uVar4 != 0x14) {
    if (uVar4 != 0x19) {
      return;
    }
    iVar6 = UpdatePlayerLapCountIfNot123((short)*(char *)(uVar7 + 0x62));
    if ((iVar6 == 0) && (iVar6 = IsNotStaffRoll(), iVar6 == 0)) {
      iVar6 = 0x320000;
    }
    else {
      iVar6 = 0x384000;
    }
    uVar9 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
            *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
    uVar4 = iVar3 + 0x24U & 3;
    uVar7 = *(uint *)(iVar3 + 0x24U & 0xfffffffc);
    uVar7 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
    uVar4 = uVar9 - iVar6;
    if (((int)uVar4 <= (int)uVar7) && (uVar4 = uVar9 + iVar6, (int)uVar7 <= (int)uVar4)) {
      uVar4 = uVar7;
    }
    *(uint *)(param_1 + 0x10) = uVar4;
    uVar4 = param_2 + 4 & 3;
    uVar7 = *(uint *)(param_2 + 4 & 0xfffffffc);
    *(uint *)(param_1 + 0x14) = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
    uVar4 = param_2 + 8 & 3;
    uVar7 = *(uint *)(param_2 + 8 & 0xfffffffc);
    *(uint *)(param_1 + 0x18) = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
    uVar4 = iVar3 + 0x24U & 3;
    uVar7 = *(uint *)(iVar3 + 0x24U & 0xfffffffc);
    if ((int)(uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) <
        (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
             *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20)) {
      *(undefined4 *)(param_1 + 0x20) = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x20) = 0;
    }
    return;
  }
  iVar5 = UpdatePlayerLapCountIfNot123((short)*(char *)(uVar7 + 0x62));
  iVar6 = iRam020a91a8;
  if ((iVar5 == 0) && (iVar5 = IsNotStaffRoll(), iVar6 = iRam020a91a8, iVar5 == 0)) {
    iVar6 = iRam020a91ac;
  }
  uVar4 = iVar3 + 0x24U & 3;
  uVar11 = *(uint *)(iVar3 + 0x24U & 0xfffffffc);
  uVar7 = iVar3 + 0x2cU & 3;
  uVar10 = *(uint *)(iVar3 + 0x2cU & 0xfffffffc);
  uVar9 = param_2 + 8 & 3;
  uVar8 = *(uint *)(param_2 + 8 & 0xfffffffc);
  uVar7 = FX_Atan2((uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) -
                   (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                   *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20),
                   (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) -
                   (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20));
  iVar5 = iRam020a91bc;
  uVar4 = uRam020a91b8;
  psVar2 = psRam020a91b4;
  if ((-1 < (int)uVar7) && ((int)uVar7 <= iRam020a91b0)) {
    iVar3 = (int)(uVar7 & 0xffff) >> 4;
    lVar1 = (ulonglong)uRam020a91b8 * (ulonglong)(uint)(int)psRam020a91b4[iVar3 * 2];
    *(uint *)(param_1 + 0x10) =
         (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
         *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) +
         ((uint)lVar1 >> 0xc |
         (((int)psRam020a91b4[iVar3 * 2] >> 0x1f) * uRam020a91b8 + (int)((ulonglong)lVar1 >> 0x20))
         * 0x100000);
    uVar7 = param_2 + 4 & 3;
    uVar9 = *(uint *)(param_2 + 4 & 0xfffffffc);
    *(uint *)(param_1 + 0x14) = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
    uVar9 = (uint)psVar2[iVar3 * 2 + 1];
    uVar7 = param_2 + 8 & 3;
    uVar8 = *(uint *)(param_2 + 8 & 0xfffffffc);
    lVar1 = (ulonglong)uVar4 * (ulonglong)uVar9;
    *(uint *)(param_1 + 0x18) =
         (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) +
         ((uint)lVar1 >> 0xc |
         (((int)uVar9 >> 0x1f) * uVar4 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
    *(undefined4 *)(param_1 + 0x20) = 0;
    return;
  }
  uVar7 = iVar3 + 0x2cU & 3;
  uVar10 = *(uint *)(iVar3 + 0x2cU & 0xfffffffc);
  uVar9 = param_2 + 8 & 3;
  uVar8 = *(uint *)(param_2 + 8 & 0xfffffffc);
  if (((int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) <
       (int)(uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20)) &&
     (uVar7 = param_2 + 4 & 3, uVar8 = *(uint *)(param_2 + 4 & 0xfffffffc),
     uVar9 = iVar3 + 0x28U & 3, uVar10 = *(uint *)(iVar3 + 0x28U & 0xfffffffc),
     (int)(uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20) <
     (int)((uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) - 0x32000))) {
    lVar1 = (ulonglong)uRam020a91b8 * (ulonglong)(uint)(int)*psRam020a91b4;
    *(uint *)(param_1 + 0x10) =
         (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
         *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) +
         ((uint)lVar1 >> 0xc |
         (((int)*psRam020a91b4 >> 0x1f) * uRam020a91b8 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000
         );
    uVar7 = param_2 + 4 & 3;
    uVar9 = *(uint *)(param_2 + 4 & 0xfffffffc);
    *(uint *)(param_1 + 0x14) = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
    uVar9 = (uint)psVar2[1];
    uVar7 = param_2 + 8 & 3;
    uVar8 = *(uint *)(param_2 + 8 & 0xfffffffc);
    lVar1 = (ulonglong)uVar4 * (ulonglong)uVar9;
    *(uint *)(param_1 + 0x18) =
         (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) +
         ((uint)lVar1 >> 0xc |
         (((int)uVar9 >> 0x1f) * uVar4 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
    uVar4 = param_1 + 0x10U & 3;
    uVar9 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    uVar7 = iVar3 + 0x24U & 3;
    uVar8 = *(uint *)(iVar3 + 0x24U & 0xfffffffc);
    uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    uVar4 = (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) - iVar6;
    if ((int)uVar7 <= (int)uVar4) {
      uVar7 = uVar4;
    }
    *(uint *)(param_1 + 0x10) = uVar7;
    *(undefined4 *)(param_1 + 0x20) = 1;
    return;
  }
  lVar1 = (ulonglong)uRam020a91b8 * (ulonglong)(uint)(int)*(short *)(iRam020a91bc + 0xa8);
  *(uint *)(param_1 + 0x10) =
       (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
       *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) +
       ((uint)lVar1 >> 0xc |
       (((int)*(short *)(iRam020a91bc + 0xa8) >> 0x1f) * uRam020a91b8 +
       (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  uVar7 = param_2 + 4 & 3;
  uVar9 = *(uint *)(param_2 + 4 & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
  uVar7 = param_2 + 8 & 3;
  uVar9 = *(uint *)(param_2 + 8 & 0xfffffffc);
  lVar1 = (ulonglong)uVar4 * (ulonglong)(uint)(int)*(short *)(iVar5 + 0xaa);
  *(uint *)(param_1 + 0x18) =
       (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) +
       ((uint)lVar1 >> 0xc |
       (((int)*(short *)(iVar5 + 0xaa) >> 0x1f) * uVar4 + (int)((ulonglong)lVar1 >> 0x20)) *
       0x100000);
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}

