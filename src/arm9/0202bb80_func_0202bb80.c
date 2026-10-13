/* Decompiled C draft; module arm9; ROM address 0202bb80. No matching claim. */
#include "types.h"
#include "deps/0202bb80_func_0202bb80.h"

void func_0202bb80(void)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint local_6c;
  uint local_68;
  int local_64;
  int local_50;
  int local_4c;
  uint local_44;
  
  iVar8 = *piRam0202bee4;
  iVar3 = Bright_IsBothScreensFadedIn();
  piVar1 = piRam0202bee4;
  if (iVar3 != 0) {
    iVar3 = *piRam0202bee4;
    if (*(int *)(iVar3 + iRam0202bee8) != 0) {
      if (*(int *)(iVar3 + 0x40) == 0) {
        iVar3 = 0;
      }
      else {
        *(int *)(iVar3 + 0x40) = *(int *)(iVar3 + 0x40) + -1;
        iVar9 = *(int *)(*piVar1 + 0x40);
        iVar11 = iVar9 + 0x3c;
        iVar3 = _s32_div_f(iVar11,0x3c);
        if (iVar9 == 0) {
          NNSi_MaybeSndPlayerStartSeq(uRam0202beec,0,0x51);
        }
        else {
          _s32_div_f(iVar11,0x3c);
          if ((extraout_r1 == 0) && (iVar3 < 5)) {
            NNSi_MaybeSndPlayerStartSeq(uRam0202beec,0,0x50);
          }
        }
      }
      iVar9 = func_0202cc8c();
      *(uint *)(*(int *)(iVar8 + 0x18) + iVar9 * 0x40) = (uint)(9 < iVar3);
      uVar4 = func_0202cc8c();
      uVar5 = _s32_div_f(iVar3,10);
      _s32_div_f(uVar5,10);
      func_02025c48(uVar4,*(undefined2 *)(*piRam0202bef0 + extraout_r1_00 * 2),
                    *(undefined4 *)(iVar8 + 0xc));
      uVar4 = func_0202cc78();
      _s32_div_f(iVar3,10);
      func_02025c48(uVar4,*(undefined2 *)(*piRam0202bef0 + extraout_r1_01 * 2),
                    *(undefined4 *)(iVar8 + 0xc));
    }
    iVar3 = *piRam0202bee4;
    if (*(int *)(iVar3 + iRam0202bef4) != 2) {
      iVar9 = *(int *)(iVar3 + iRam0202bef8);
      if (iVar9 == 0) {
        iVar3 = 0;
        local_64 = 0;
        iVar9 = 0;
        do {
          iVar11 = GetGlobalCA_from_thumb();
          iVar11 = *(int *)(iVar11 + iVar3);
          uVar10 = (uint)(iVar11 != -1);
          iVar7 = GetGlobalCA_from_thumb();
          uVar4 = *(undefined4 *)(iVar7 + iVar3 + 0x14);
          if (uVar10 != 0) {
            func_02025c48(*(undefined2 *)(*piRam0202befc + iVar9 + 2),
                          *(undefined2 *)(*piRam0202bf00 + iVar11 * 2),*(undefined4 *)(iVar8 + 0xc))
            ;
          }
          *(uint *)(*(int *)(iVar8 + 0x18) + (uint)*(ushort *)(*piRam0202befc + iVar9 + 2) * 0x40) =
               uVar10;
          *(undefined4 *)
           (*(int *)(iVar8 + 0x18) + (uint)*(ushort *)(*piRam0202befc + iVar9 + 4) * 0x40) = uVar4;
          iVar3 = iVar3 + 0x18;
          iVar9 = iVar9 + 6;
          local_64 = local_64 + 1;
        } while (local_64 < 8);
      }
      else if (iVar9 == 1) {
        local_4c = 0;
        if (0 < *(int *)(iVar3 + 0x48)) {
          iVar9 = 0;
          iVar3 = 0;
          local_50 = 0;
          local_44 = 0;
          do {
            iVar11 = *piRam0202bf04;
            uVar10 = local_44;
            if ((*(int *)(iVar11 + 4) == 8) &&
               (uVar6 = (uint)*(ushort *)(iVar11 + ((uint)(local_4c << 0x10) >> 0xf) + iRam0202bf08)
               , ((uint)*(byte *)(iVar11 + iRam0202bf0c) & 1 << (uVar6 & 0xff)) != 0)) {
              uVar10 = (uint)*(byte *)(*(int *)(iVar11 + iRam0202bf10) + uVar6 * 8 + 5);
            }
            if (uVar10 == 0xff) {
              *(undefined4 *)
               (*(int *)(iVar8 + 0x18) + (uint)*(ushort *)(*piRam0202befc + iVar9 + 4) * 0x40) = 0;
              *(undefined4 *)
               (*(int *)(iVar8 + 0x18) + (uint)*(ushort *)(*piRam0202befc + iVar9 + 2) * 0x40) =
                   *(undefined4 *)
                    (*(int *)(iVar8 + 0x18) + (uint)*(ushort *)(*piRam0202befc + iVar9 + 4) * 0x40);
              iVar11 = GetGlobalCA_from_thumb();
              *(undefined4 *)(iVar11 + iVar3) = 0xffffffff;
              iVar11 = GetGlobalCA_from_thumb();
              *(undefined4 *)(iVar11 + iVar3 + 4) = 0xffffffff;
              iVar11 = GetGlobalCA_from_thumb();
              *(undefined4 *)(iVar11 + iVar3 + 0x14) = 0;
              *(undefined4 *)(*piRam0202bee4 + local_50 + iRam0202bf14) = 0;
              *(undefined4 *)(*piRam0202bee4 + local_50 + iRam0202bf18) =
                   *(undefined4 *)(*piRam0202bee4 + local_50 + iRam0202bf14);
            }
            else if ((uVar10 & 0x40) == 0) {
              if ((uVar10 & 0x80) != 0) {
                *(undefined4 *)
                 (*(int *)(iVar8 + 0x18) + (uint)*(ushort *)(*piRam0202befc + iVar9 + 4) * 0x40) = 1
                ;
                iVar11 = GetGlobalCA_from_thumb();
                *(uint *)(iVar11 + iVar3 + 4) = uVar10 & 0x3f;
                iVar11 = GetGlobalCA_from_thumb();
                *(undefined4 *)(iVar11 + iVar3 + 0x14) = 1;
                if ((*(int *)(*piRam0202bee4 + 0x44) != local_4c) &&
                   (*(int *)(*piRam0202bee4 + local_50 + iRam0202bf14) == 0)) {
                  iVar11 = GetGlobalCA_from_thumb();
                  func_0202cca4(*(undefined4 *)(iVar11 + iVar3),1);
                  *(undefined4 *)(*piRam0202bee4 + local_50 + iRam0202bf14) = 1;
                }
              }
            }
            else {
              uVar6 = uVar10 & 0x3f;
              if (uVar6 == 0xc) {
                func_02025c48(*(undefined2 *)(*piRam0202befc + iVar9 + 2),
                              (uint)*(ushort *)(*piRam0202bf00 + 0x18) +
                              *(int *)(*piRam0202bf1c + local_50 + iRam0202bf20),
                              *(undefined4 *)(iVar8 + 0xc));
              }
              else {
                func_02025c48(*(undefined2 *)(*piRam0202befc + iVar9 + 2),
                              *(undefined2 *)(*piRam0202bf00 + uVar6 * 2),
                              *(undefined4 *)(iVar8 + 0xc));
              }
              *(undefined4 *)
               (*(int *)(iVar8 + 0x18) + (uint)*(ushort *)(*piRam0202befc + iVar9 + 2) * 0x40) = 1;
              iVar11 = GetGlobalCA_from_thumb();
              *(uint *)(iVar11 + iVar3) = uVar6;
              if ((*(int *)(*piRam0202bee4 + 0x44) != local_4c) &&
                 (*(int *)(*piRam0202bee4 + local_50 + iRam0202bf18) == 0)) {
                func_0202cca4(uVar6,0);
                *(undefined4 *)(*piRam0202bee4 + local_50 + iRam0202bf18) = 1;
              }
              if ((uVar10 & 0x80) != 0) {
                uVar4 = func_02025e60(uVar6);
                *(undefined4 *)
                 (*(int *)(iVar8 + 0x18) + (uint)*(ushort *)(*piRam0202befc + iVar9 + 4) * 0x40) = 1
                ;
                iVar11 = GetGlobalCA_from_thumb();
                *(undefined4 *)(iVar11 + iVar3 + 4) = uVar4;
                iVar11 = GetGlobalCA_from_thumb();
                *(undefined4 *)(iVar11 + iVar3 + 0x14) = 1;
              }
            }
            iVar9 = iVar9 + 6;
            iVar3 = iVar3 + 0x18;
            local_50 = local_50 + 4;
            local_4c = local_4c + 1;
          } while (local_4c < *(int *)(*piRam0202bee4 + 0x48));
        }
      }
      else if ((iVar9 == 2) && (uVar10 = 0, 0 < *(int *)(iVar3 + 0x48))) {
        iVar3 = 0;
        iVar9 = 0;
        do {
          iVar11 = func_02122794(uVar10 & 0xff);
          if (iVar11 == 0) {
            func_02025c48(*(undefined2 *)(*piRam0202c0b8 + iVar3 + 2),0x2e,
                          *(undefined4 *)(iVar8 + 0xc));
            *(undefined4 *)
             (*(int *)(iVar8 + 0x18) + (uint)*(ushort *)(*piRam0202c0b8 + iVar3 + 2) * 0x40) = 1;
            *(undefined4 *)
             (*(int *)(iVar8 + 0x18) + (uint)*(ushort *)(*piRam0202c0b8 + iVar3 + 4) * 0x40) = 0;
            if (*(int *)(*piRam0202c0bc + iVar9 + iRam0202c0c0) == 0) {
              *(undefined4 *)(*piRam0202c0bc + iVar9 + iRam0202c0c0) = 1;
              NNSi_MaybeSndPlayerStartSeq(uRam0202c0c4,0,0x52);
            }
          }
          else {
            uVar2 = func_02122734(uVar10 & 0xff);
            iVar11 = func_02121e64(uVar2);
            uVar2 = func_02122734(uVar10 & 0xff);
            iVar7 = func_02121e44(uVar2);
            local_68 = (uint)(iVar11 != -1);
            local_6c = (uint)(iVar7 != -1);
            if (local_68 != 0) {
              func_02025c48(*(undefined2 *)(*piRam0202c0b8 + iVar3 + 2),
                            *(undefined2 *)(*piRam0202c0c8 + iVar11 * 2),
                            *(undefined4 *)(iVar8 + 0xc));
            }
            *(uint *)(*(int *)(iVar8 + 0x18) + (uint)*(ushort *)(*piRam0202c0b8 + iVar3 + 2) * 0x40)
                 = local_68;
            *(uint *)(*(int *)(iVar8 + 0x18) + (uint)*(ushort *)(*piRam0202c0b8 + iVar3 + 4) * 0x40)
                 = local_6c;
            if (*(uint *)(*piRam0202c0bc + 0x44) != uVar10) {
              iVar7 = *piRam0202c0bc + iVar9;
              if ((*(int *)(iVar7 + iRam0202c0cc) == 0) && (local_68 != 0)) {
                func_0202cca4(iVar11,0);
                if (local_6c != 0) {
                  *(undefined4 *)(*piRam0202c0bc + iVar9 + iRam0202c0d0) = 1;
                }
              }
              else if ((*(int *)(iVar7 + iRam0202c0d0) == 0) && (local_6c != 0)) {
                func_0202cca4(iVar11,1);
              }
              *(uint *)(*piRam0202c0bc + iVar9 + iRam0202c0cc) = local_68;
              *(uint *)(*piRam0202c0bc + iVar9 + iRam0202c0d0) = local_6c;
            }
          }
          iVar3 = iVar3 + 6;
          iVar9 = iVar9 + 4;
          uVar10 = uVar10 + 1;
        } while ((int)uVar10 < *(int *)(*piRam0202c0bc + 0x48));
      }
    }
    func_0202c960();
    func_02124c30(*(undefined4 *)(iVar8 + 0xc),*(undefined4 *)(iVar8 + 8),
                  *(undefined4 *)(iVar8 + 0x14),*(undefined4 *)(*piRam0202c0bc + 0x38),
                  *(undefined4 *)(iVar8 + 0x18));
  }
  return;
}

