/* Decompiled C draft; module arm9; ROM address 0206f914. No matching claim. */
#include "types.h"
#include "deps/0206f914_func_0206f914.h"

void func_0206f914(int param_1)

{
  longlong lVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  undefined1 auStack_150 [12];
  undefined1 auStack_144 [12];
  uint local_138 [37];
  uint local_a4 [38];
  
  uVar7 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 2) == 0) {
    uVar7 = param_1 + 0x4d4U & 3;
    uVar2 = *(uint *)(param_1 + 0x4d4U & 0xfffffffc);
    uVar7 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
    lVar1 = (ulonglong)uRam0206fdd8 * (ulonglong)uVar7;
    *(uint *)(param_1 + 0x4d4) =
         (uint)lVar1 >> 0xc |
         (((int)uVar7 >> 0x1f) * uRam0206fdd8 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  }
  else {
    uVar7 = param_1 + 0x4d4U & 3;
    uVar2 = *(uint *)(param_1 + 0x4d4U & 0xfffffffc);
    uVar7 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
    if ((int)uVar7 < 0) {
      iVar4 = 0x52;
    }
    else if ((int)uVar7 < 0x1001) {
      iVar4 = FX_Div(0x4a,0x1000);
      iVar4 = 0x52 - ((uint)((longlong)iVar4 * (longlong)(int)uVar7) >> 0xc |
                     (int)((ulonglong)((longlong)iVar4 * (longlong)(int)uVar7) >> 0x20) << 0x14);
    }
    else {
      iVar4 = 8;
    }
    uVar7 = param_1 + 0x4d4U & 3;
    uVar2 = *(uint *)(param_1 + 0x4d4U & 0xfffffffc);
    *(uint *)(param_1 + 0x4d4) = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + iVar4;
    uVar7 = param_1 + 0x4d4U & 3;
    uVar2 = *(uint *)(param_1 + 0x4d4U & 0xfffffffc);
    if (0x1000 < (int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20)) {
      *(undefined4 *)(param_1 + 0x4d4) = 0x1000;
    }
  }
  uVar7 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if ((((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x20000000) == 0) &&
     (iVar4 = GetRaceStartCountdown(), 0 < iVar4 + -0xaf)) {
    uVar7 = param_1 + 0x44U & 3;
    uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20 | 0x1000000;
  }
  iVar4 = GetRaceStartCountdown();
  if (iVar4 == 0xaf) {
    uVar7 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 2) == 0) {
      uVar7 = param_1 + 0x48U & 3;
      uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 2) != 0) {
        uVar7 = param_1 + 0x4d4U & 3;
        uVar2 = *(uint *)(param_1 + 0x4d4U & 0xfffffffc);
        uVar7 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
        if (iRam0206fdec < (int)uVar7) {
          uVar7 = param_1 + 0x4cU & 3;
          uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
          if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x20000000) == 0) {
            uVar7 = param_1 + 0x4cU & 3;
            uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
            *(uint *)(param_1 + 0x4c) = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20 | 0x20000000
            ;
            *(undefined2 *)(param_1 + 0x3be) = 0x78;
            DriverContext_UpdateCharacterAnimation(param_1,1,1);
            puVar9 = local_a4;
            iVar4 = 9;
            puVar8 = puRam0206fddc;
            do {
              uVar7 = *puVar8;
              uVar2 = puVar8[1];
              uVar5 = puVar8[2];
              uVar6 = puVar8[3];
              puVar8 = puVar8 + 4;
              *puVar9 = uVar7;
              puVar9[1] = uVar2;
              puVar9[2] = uVar5;
              puVar9[3] = uVar6;
              puVar9 = puVar9 + 4;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
            *puVar9 = *(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                      *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20;
            uVar7 = param_1 + 0x7cU & 3;
            uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
            uVar7 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
            if ((((uVar7 & 0x10) != 0) &&
                (uVar2 = param_1 + 0x590U & 3, uVar5 = *(uint *)(param_1 + 0x590U & 0xfffffffc),
                uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20, uVar2 = uVar5 + 0x58,
                uVar6 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
                uVar2 >> uVar6 * 8 == 0 && uVar2 << uVar6 * -8 + 0x20 == 0)) &&
               (((uVar7 & 1) != 0 || ((uVar7 & uRam0206fde0) == 0)))) {
              uVar5 = uVar5 + 4;
              uVar7 = uVar5 & 3;
              uVar2 = *(uint *)(uVar5 & 0xfffffffc);
              VecFx32_AddScale1(local_a4[uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20] << 4,
                                param_1 + 0x138,param_1 + 0x80,auStack_144);
              func_0208b748(0x72,auStack_144,param_1,uRam0206fde4);
              func_0208b748(0x73,auStack_144,param_1,uRam0206fde4);
            }
            uVar7 = param_1 + 0x48U & 3;
            uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
            if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x840) == 0) {
              uVar7 = param_1 + 0x3ccU & 3;
              uVar2 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
              StructMQRacerEntry_SomeFn_5(param_1,uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20,3)
              ;
            }
            DriverContext_SomeFn(param_1,1);
            *(undefined2 *)(param_1 + 0x3fc) = 1;
          }
        }
        else if (iRam0206fdf0 < (int)uVar7) {
          iVar4 = 5;
          if ((int)uVar7 < iRam0206fdf4) {
            iVar4 = 1;
          }
          else if ((int)uVar7 < iRam0206fdf8) {
            iVar4 = 2;
          }
          else if ((int)uVar7 < iRam0206fdfc) {
            iVar4 = 3;
          }
          else if ((int)uVar7 < iRam0206fe00) {
            iVar4 = 4;
          }
          *(undefined2 *)(param_1 + 0x3be) = *(undefined2 *)(iRam0206fde8 + (iVar4 + -1) * 2);
          uVar7 = param_1 + 0x44U & 3;
          uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
          *(uint *)(param_1 + 0x44) = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20 | 0x1800000;
          DriverContext_MaybeApplyBoost(param_1,2,(int)*(short *)(param_1 + 0x3be));
          uVar7 = param_1 + 0x48U & 3;
          uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
          if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x840) == 0) {
            uVar7 = param_1 + 0x3ccU & 3;
            uVar2 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
            StructMQRacerEntry_SomeFn_5(param_1,uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20,5);
          }
          uVar7 = param_1 + 0x48U & 3;
          uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
          *(uint *)(param_1 + 0x48) = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20 | 0x8000;
          uVar7 = param_1 + 0x7cU & 3;
          uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
          if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 1) == 0) {
            DriverContext_MaybeQueuePlaySfx(param_1,0xa1,0x7f,0);
          }
          else {
            puVar3 = (undefined4 *)GetGlobalRK();
            *puVar3 = 1;
          }
        }
      }
    }
    else {
      uVar7 = param_1 + 0x310U & 3;
      uVar2 = *(uint *)(param_1 + 0x310U & 0xfffffffc);
      iVar4 = func_0208c180(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
      if (iVar4 == 0) {
        uVar7 = param_1 + 0x310U & 3;
        uVar2 = *(uint *)(param_1 + 0x310U & 0xfffffffc);
        iVar4 = func_0208c178(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
        if (iVar4 != 0) {
          uVar7 = param_1 + 0x310U & 3;
          uVar2 = *(uint *)(param_1 + 0x310U & 0xfffffffc);
          iVar4 = func_0208c16c(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
          *(undefined2 *)(param_1 + 0x3be) = *(undefined2 *)(iRam0206fde8 + (iVar4 + -1) * 2);
          uVar7 = param_1 + 0x44U & 3;
          uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
          *(uint *)(param_1 + 0x44) = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20 | 0x1800000;
          DriverContext_MaybeApplyBoost(param_1,2,(int)*(short *)(param_1 + 0x3be));
          uVar7 = param_1 + 0x48U & 3;
          uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
          if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x840) == 0) {
            uVar7 = param_1 + 0x3ccU & 3;
            uVar2 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
            StructMQRacerEntry_SomeFn_5(param_1,uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20,5);
          }
          uVar7 = param_1 + 0x48U & 3;
          uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
          *(uint *)(param_1 + 0x48) = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20 | 0x8000;
          uVar7 = param_1 + 0x7cU & 3;
          uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
          if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 1) == 0) {
            DriverContext_MaybeQueuePlaySfx(param_1,0xa1,0x7f,0);
          }
          else {
            puVar3 = (undefined4 *)GetGlobalRK();
            *puVar3 = 1;
          }
        }
      }
      else {
        uVar7 = param_1 + 0x4cU & 3;
        uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
        if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x20000000) == 0) {
          uVar7 = param_1 + 0x4cU & 3;
          uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
          *(uint *)(param_1 + 0x4c) = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20 | 0x20000000;
          *(undefined2 *)(param_1 + 0x3be) = 0x78;
          DriverContext_UpdateCharacterAnimation(param_1,1,1);
          puVar9 = local_138;
          iVar4 = 9;
          puVar8 = puRam0206fddc;
          do {
            uVar7 = *puVar8;
            uVar2 = puVar8[1];
            uVar5 = puVar8[2];
            uVar6 = puVar8[3];
            puVar8 = puVar8 + 4;
            *puVar9 = uVar7;
            puVar9[1] = uVar2;
            puVar9[2] = uVar5;
            puVar9[3] = uVar6;
            puVar9 = puVar9 + 4;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
          *puVar9 = *(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                    *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20;
          uVar7 = param_1 + 0x7cU & 3;
          uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
          uVar7 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
          if ((((uVar7 & 0x10) != 0) &&
              (uVar2 = param_1 + 0x590U & 3, uVar5 = *(uint *)(param_1 + 0x590U & 0xfffffffc),
              uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20, uVar2 = uVar5 + 0x58,
              uVar6 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
              uVar2 >> uVar6 * 8 == 0 && uVar2 << uVar6 * -8 + 0x20 == 0)) &&
             (((uVar7 & 1) != 0 || ((uVar7 & uRam0206fde0) == 0)))) {
            uVar5 = uVar5 + 4;
            uVar7 = uVar5 & 3;
            uVar2 = *(uint *)(uVar5 & 0xfffffffc);
            VecFx32_AddScale1(local_138[uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20] << 4,
                              param_1 + 0x138,param_1 + 0x80,auStack_150);
            func_0208b748(0x72,auStack_150,param_1,uRam0206fde4);
            func_0208b748(0x73,auStack_150,param_1,uRam0206fde4);
          }
          uVar7 = param_1 + 0x48U & 3;
          uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
          if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x840) == 0) {
            uVar7 = param_1 + 0x3ccU & 3;
            uVar2 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
            StructMQRacerEntry_SomeFn_5(param_1,uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20,3);
          }
          DriverContext_SomeFn(param_1,1);
          *(undefined2 *)(param_1 + 0x3fc) = 1;
        }
      }
    }
    *(undefined4 *)(param_1 + 0x230) = uRam0206fe04;
    uVar7 = param_1 + 0x4cU & 3;
    uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x20000000) == 0) {
      uVar7 = param_1 + 0x44U & 3;
      uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      *(uint *)(param_1 + 0x44) = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20 | 0x1000000;
    }
  }
  uVar7 = param_1 + 0x4d4U & 3;
  uVar2 = *(uint *)(param_1 + 0x4d4U & 0xfffffffc);
  *(uint *)(param_1 + 0x4e8) = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + 0x1000;
  return;
}

