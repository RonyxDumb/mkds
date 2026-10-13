/* Decompiled C draft; module arm9; ROM address 020f14a0. No matching claim. */
#include "types.h"
#include "deps/020f14a0_func_020f14a0.h"

undefined4 func_020f14a0(int param_1,int param_2,int param_3,int param_4)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  undefined4 uVar10;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  iVar9 = param_1 + 0x50;
  puVar8 = (uint *)(param_1 + 0x5c);
  uVar10 = 0;
  uVar3 = func_02061f7c();
  uVar7 = param_1 + 0x48U & 3;
  uVar6 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if ((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 1) == uVar3) &&
     (uVar7 = param_1 + 0x228U & 3, uVar6 = *(uint *)(param_1 + 0x228U & 0xfffffffc),
     uVar3 = param_1 + 0x74U & 3, uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc),
     uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0x1fc, uVar6 = uVar7 & 3,
     uVar7 = *(uint *)(uVar7 & 0xfffffffc), uVar7 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,
     ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 0x20000) == 0)) {
    iVar5 = StructMQRacerEntry_SomeFn_86(uVar7);
    if (iVar5 != 0) {
      param_2 = param_2 >> 1;
    }
    VecFx32_Subtract(uVar7 + 0x98,iVar9,&local_4c);
    iVar5 = VecFx32_CrossProduct_0(param_1 + 0xf0,&local_4c);
    iVar5 = (iVar5 >> 0xc) * (iVar5 >> 0xc);
    if ((iVar5 - iRam020f1a04 != 0 && iRam020f1a04 <= iVar5) &&
       (lVar1 = (longlong)(int)local_4c * (longlong)(int)local_4c +
                (longlong)(int)local_44 * (longlong)(int)local_44,
       (int)((ulonglong)lVar1 >> 0x20) < (int)(uint)((uint)lVar1 < 0xe1000000))) {
      uVar10 = 1;
    }
    iVar5 = 0;
    lVar1 = (longlong)(int)local_44 * (longlong)(int)local_44 +
            (longlong)(int)local_4c * (longlong)(int)local_4c;
    local_48 = 0;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      iVar5 = Vector3_MaybeNormalize(&local_4c,&local_4c);
    }
    local_4c = (uint)((longlong)(int)local_4c * (longlong)param_2) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_4c * (longlong)param_2) >> 0x20) << 0x14;
    local_48 = (uint)((longlong)(int)local_48 * (longlong)param_2) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_48 * (longlong)param_2) >> 0x20) << 0x14;
    local_44 = (uint)((longlong)(int)local_44 * (longlong)param_2) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_44 * (longlong)param_2) >> 0x20) << 0x14;
    uVar3 = param_1 + 0x74U & 3;
    uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if ((((uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) & 0x8000000) != 0) &&
       (uVar3 = uVar7 + 0x2cc & 3, uVar6 = *(uint *)(uVar7 + 0x2cc & 0xfffffffc),
       uVar6 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20, uVar3 = uVar7 + 0xc4 & 3,
       uVar4 = *(uint *)(uVar7 + 0xc4 & 0xfffffffc), uVar7 = uVar6 & 3,
       uVar6 = *(uint *)(uVar6 & 0xfffffffc),
       lVar1 = (longlong)(int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) *
               (longlong)(int)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x800,
       iVar5 < (int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000))) {
      uVar7 = param_1 + 0x238U & 3;
      uVar3 = *(uint *)(param_1 + 0x238U & 0xfffffffc);
      *(uint *)(param_1 + 0x238) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
      uVar7 = param_1 + 0x238U & 3;
      uVar3 = *(uint *)(param_1 + 0x238U & 0xfffffffc);
      if (0x5a < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        func_020f7070(param_1,1);
        return 0;
      }
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
    }
    VecFx32_Subtract(&local_4c,param_1 + 0x22c,&local_4c);
    uVar7 = 0x64000 - iVar5;
    if (0 < (int)uVar7) {
      param_3 = param_3 + (uVar7 * 0x10 >> 0xc | (((int)uVar7 >> 0x1f) << 4 | uVar7 >> 0x1c) << 0x14
                          );
    }
    local_44 = (uint)((longlong)(int)local_44 * (longlong)param_3) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_44 * (longlong)param_3) >> 0x20) << 0x14;
    local_4c = (uint)((longlong)(int)local_4c * (longlong)param_3) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_4c * (longlong)param_3) >> 0x20) << 0x14;
    local_48 = (uint)((longlong)(int)local_48 * (longlong)param_3) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_48 * (longlong)param_3) >> 0x20) << 0x14;
    VecFx32_Add(param_1 + 0x22c,&local_4c,param_1 + 0x22c);
    uVar7 = param_1 + 0x228U & 3;
    uVar3 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
    uVar7 = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 0x1fc;
    uVar3 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    VecFx32_Subtract((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0xa4,puVar8,&local_4c);
    local_48 = 0;
    local_4c = (uint)((longlong)(int)local_4c * (longlong)param_3) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_4c * (longlong)param_3) >> 0x20) << 0x14;
    local_44 = (uint)((longlong)(int)local_44 * (longlong)param_3) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_44 * (longlong)param_3) >> 0x20) << 0x14;
    VecFx32_Add(puVar8,&local_4c,puVar8);
  }
  uVar7 = param_1 + 0x228U & 3;
  uVar3 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
  *(undefined4 *)((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 0x208) = 1;
  VecFx32_Add(param_1 + 0x22c,iVar9,iVar9);
  VecFx32_Add(puVar8,iVar9,iVar9);
  uVar7 = param_1 + 0xdcU & 3;
  uVar3 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
  iVar5 = func_01ffdee4(iVar9,param_1 + 0xe4,0,uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,4,
                        (int)*(short *)(param_1 + 0xda),&local_4c,&local_40,&local_34,param_1 + 0xfc
                        ,0,0,0,0);
  if (iVar5 != 0) {
    VecFx32_Add(&local_4c,iVar9,iVar9);
    uVar7 = param_1 + 0xfcU & 3;
    uVar3 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    if (((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) & uRam020f1a08) != 0) {
      iVar9 = Vector3_DotProduct(&local_40,puVar8);
      *puVar8 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) -
                ((uint)((longlong)(int)local_40 * (longlong)iVar9) >> 0xc |
                (int)((ulonglong)((longlong)(int)local_40 * (longlong)iVar9) >> 0x20) << 0x14);
      uVar7 = param_1 + 0x60U & 3;
      uVar3 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
      *(uint *)(param_1 + 0x60) =
           (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) -
           ((uint)((longlong)(int)local_3c * (longlong)iVar9) >> 0xc |
           (int)((ulonglong)((longlong)(int)local_3c * (longlong)iVar9) >> 0x20) << 0x14);
      uVar7 = param_1 + 100U & 3;
      uVar3 = *(uint *)(param_1 + 100U & 0xfffffffc);
      *(uint *)(param_1 + 100) =
           (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) -
           ((uint)((longlong)(int)local_38 * (longlong)iVar9) >> 0xc |
           (int)((ulonglong)((longlong)(int)local_38 * (longlong)iVar9) >> 0x20) << 0x14);
      uVar7 = param_1 + 0xf0U & 3;
      uVar3 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
      if (((local_40 == (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) &&
          (uVar7 = param_1 + 0xf4U & 3, uVar3 = *(uint *)(param_1 + 0xf4U & 0xfffffffc),
          local_3c == (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20))) &&
         (uVar7 = param_1 + 0xf8U & 3, uVar3 = *(uint *)(param_1 + 0xf8U & 0xfffffffc),
         local_38 == (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20))) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (!bVar2) {
        *(uint *)(param_1 + 0xf0) = local_40;
        *(uint *)(param_1 + 0xf4) = local_3c;
        *(uint *)(param_1 + 0xf8) = local_38;
        uVar7 = param_1 + 0x74U & 3;
        uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
        *(uint *)(param_1 + 0x74) = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20 | 0x100;
      }
    }
    uVar7 = param_1 + 0xfcU & 3;
    uVar3 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    uVar7 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
    if ((((uVar7 & uRam020f1a0c) != 0) &&
        (uVar3 = param_1 + 0x158U & 3, uVar6 = *(uint *)(param_1 + 0x158U & 0xfffffffc),
        uVar6 >> uVar3 * 8 == 0 && uVar6 << uVar3 * -8 + 0x20 == 0)) && (param_4 != 0)) {
      iVar9 = Vector3_DotProduct(&local_34,puVar8);
      local_4c = (uint)((longlong)local_34 * (longlong)iVar9) >> 0xc |
                 (int)((ulonglong)((longlong)local_34 * (longlong)iVar9) >> 0x20) << 0x14;
      local_48 = (uint)((longlong)local_30 * (longlong)iVar9) >> 0xc |
                 (int)((ulonglong)((longlong)local_30 * (longlong)iVar9) >> 0x20) << 0x14;
      local_44 = (uint)((longlong)local_2c * (longlong)iVar9) >> 0xc |
                 (int)((ulonglong)((longlong)local_2c * (longlong)iVar9) >> 0x20) << 0x14;
      *puVar8 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) - local_4c;
      uVar7 = param_1 + 0x60U & 3;
      uVar3 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
      *(uint *)(param_1 + 0x60) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) - local_48;
      uVar7 = param_1 + 100U & 3;
      uVar3 = *(uint *)(param_1 + 100U & 0xfffffffc);
      *(uint *)(param_1 + 100) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) - local_44;
      VecFx32_Subtract(puVar8,&local_4c,puVar8);
      uVar3 = uRam020f1a10;
      uVar7 = *(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
              *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20;
      lVar1 = (ulonglong)uRam020f1a10 * (ulonglong)uVar7;
      *puVar8 = (uint)lVar1 >> 0xc |
                (((int)uVar7 >> 0x1f) * uRam020f1a10 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      uVar7 = param_1 + 0x60U & 3;
      uVar6 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
      uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      lVar1 = (ulonglong)uVar3 * (ulonglong)uVar7;
      *(uint *)(param_1 + 0x60) =
           (uint)lVar1 >> 0xc |
           (((int)uVar7 >> 0x1f) * uVar3 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      uVar7 = param_1 + 100U & 3;
      uVar6 = *(uint *)(param_1 + 100U & 0xfffffffc);
      uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      lVar1 = (ulonglong)uVar3 * (ulonglong)uVar7;
      *(uint *)(param_1 + 100) =
           (uint)lVar1 >> 0xc |
           (((int)uVar7 >> 0x1f) * uVar3 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      func_020f6fc4(param_1,1);
      return 0;
    }
    if ((uVar7 & 0x8000) != 0) {
      func_020f7070(param_1,1);
      return 0;
    }
  }
  func_020f2028(param_1);
  return uVar10;
}

