/* Decompiled C draft; module arm9; ROM address 02029aa0. No matching claim. */
#include "types.h"
#include "deps/02029aa0_HandleEarnedSecrets_from_thumb.h"

void HandleEarnedSecrets_from_thumb(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 local_1c;
  
  iVar2 = GetDirectInputUnitIndex();
  iVar8 = 0;
  local_1c = 0;
  iVar7 = 0;
  iVar9 = 0;
  do {
    iVar6 = *piRam02029d94 + iVar7;
    func_02124c30(*(undefined4 *)(iVar6 + 0xc),*(undefined4 *)(iVar6 + 8),
                  *(undefined4 *)(iVar6 + 0x14),*(undefined4 *)(*piRam02029d94 + iVar9 + 0x38),
                  *(undefined4 *)(iVar6 + 0x18));
    iVar7 = iVar7 + 0x1c;
    iVar9 = iVar9 + 4;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 2);
  if (*(int *)(*piRam02029d94 + 0x48) < 3) {
    func_020a2558();
    func_020a23cc();
  }
  iVar7 = *(int *)(*piRam02029d94 + 0x54);
  if (iVar7 == 0) {
    iVar7 = func_0210f71c(*(undefined4 *)(*piRam02029d94 + 0x48));
    iVar8 = *(int *)(*piRam02029d94 + 0x5c);
    *(int *)(*piRam02029d94 + 0x5c) = iVar8 + 1;
    if (iVar7 <= iVar8) {
      iVar2 = iVar2 * 0x5c;
      if ((*(ushort *)(iRam02029d98 + iVar2) & 1) == 0) {
        bVar5 = false;
        bVar1 = false;
        if ((*(short *)(iRam02029d9c + iVar2) == 0) && (*(ushort *)(iRam02029da0 + iVar2) < 5)) {
          bVar1 = true;
        }
        if (((!bVar1) && (*(short *)(iRam02029da4 + iVar2) == 0)) &&
           (*(short *)(iRam02029d9c + iVar2) != 0)) {
          bVar5 = true;
        }
        if (!bVar5) goto LAB_02029d88;
      }
      uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02029d94 + 0x4c),4);
      iVar2 = *piRam02029d94;
      uVar4 = *(uint *)(iVar2 + 0x58);
      if (uVar4 == 0) {
        iVar2 = func_020909cc();
        if (iVar2 == 0) {
          if (param_1 != 0) {
            *(undefined2 *)(param_1 + 4) = 0;
          }
        }
        else if (iVar2 == 1) {
          func_02045a2c(0);
          if (param_1 != 0) {
            *(undefined2 *)(param_1 + 4) = 2;
          }
        }
        else if ((iVar2 == 2) && (func_02045a2c(1), param_1 != 0)) {
          *(undefined2 *)(param_1 + 4) = 2;
        }
        NNSi_MaybeSndPlayerStartSeq(uRam02029dc8,0,5);
        *(undefined4 *)(*piRam02029d94 + 0x54) = 2;
      }
      else {
        if ((uVar4 & 1) == 0) {
          if ((uVar4 & 2) == 0) {
            if ((uVar4 & 4) == 0) {
              if ((uVar4 & 8) == 0) {
                if ((uVar4 & 0x10) == 0) {
                  if ((uVar4 & 0x20) == 0) {
                    if ((uVar4 & 0x40) == 0) {
                      if ((uVar4 & 0x80) == 0) {
                        if ((uVar4 & uRam02029da8) == 0) {
                          if ((uVar4 & uRam02029db0) == 0) {
                            if ((uVar4 & uRam02029db8) == 0) {
                              if ((uVar4 & uRam02029dc0) != 0) {
                                local_1c = Bmg_GetRawStringPointer_from_thumb
                                                     (*(undefined4 *)(iVar2 + 0x50),0xb);
                                *(uint *)(*piRam02029d94 + 0x58) =
                                     *(uint *)(*piRam02029d94 + 0x58) & uRam02029dc4;
                              }
                            }
                            else {
                              local_1c = Bmg_GetRawStringPointer_from_thumb
                                                   (*(undefined4 *)(iVar2 + 0x50),10);
                              *(uint *)(*piRam02029d94 + 0x58) =
                                   *(uint *)(*piRam02029d94 + 0x58) & uRam02029dbc;
                            }
                          }
                          else {
                            local_1c = Bmg_GetRawStringPointer_from_thumb
                                                 (*(undefined4 *)(iVar2 + 0x50),9);
                            *(uint *)(*piRam02029d94 + 0x58) =
                                 *(uint *)(*piRam02029d94 + 0x58) & uRam02029db4;
                          }
                        }
                        else {
                          local_1c = Bmg_GetRawStringPointer_from_thumb
                                               (*(undefined4 *)(iVar2 + 0x50),8);
                          *(uint *)(*piRam02029d94 + 0x58) =
                               *(uint *)(*piRam02029d94 + 0x58) & uRam02029dac;
                        }
                      }
                      else {
                        local_1c = Bmg_GetRawStringPointer_from_thumb
                                             (*(undefined4 *)(iVar2 + 0x50),7);
                        *(uint *)(*piRam02029d94 + 0x58) =
                             *(uint *)(*piRam02029d94 + 0x58) & 0xffffff7f;
                      }
                    }
                    else {
                      local_1c = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar2 + 0x50),6)
                      ;
                      *(uint *)(*piRam02029d94 + 0x58) =
                           *(uint *)(*piRam02029d94 + 0x58) & 0xffffffbf;
                    }
                  }
                  else {
                    local_1c = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar2 + 0x50),5);
                    *(uint *)(*piRam02029d94 + 0x58) = *(uint *)(*piRam02029d94 + 0x58) & 0xffffffdf
                    ;
                  }
                }
                else {
                  local_1c = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar2 + 0x50));
                  *(uint *)(*piRam02029d94 + 0x58) = *(uint *)(*piRam02029d94 + 0x58) & 0xffffffef;
                }
              }
              else {
                local_1c = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar2 + 0x50),3);
                *(uint *)(*piRam02029d94 + 0x58) = *(uint *)(*piRam02029d94 + 0x58) & 0xfffffff7;
              }
            }
            else {
              local_1c = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar2 + 0x50),2);
              *(uint *)(*piRam02029d94 + 0x58) = *(uint *)(*piRam02029d94 + 0x58) & 0xfffffffb;
            }
          }
          else {
            local_1c = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar2 + 0x50));
            *(uint *)(*piRam02029d94 + 0x58) = *(uint *)(*piRam02029d94 + 0x58) & 0xfffffffd;
          }
        }
        else {
          local_1c = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar2 + 0x50),0);
          *(uint *)(*piRam02029d94 + 0x58) = *(uint *)(*piRam02029d94 + 0x58) & 0xfffffffe;
        }
        TextSystem_SetFadeInSseqId_from_thumb(0x53);
        TextSystem_DisplaySingleButtonDialog_from_thumb(local_1c,uVar3,0,1,1,0);
        *(undefined4 *)(*piRam02029d94 + 0x54) = 1;
      }
    }
  }
  else if ((iVar7 == 1) && (iVar2 = TextSystem_WasAnyDialogButtonPressed_from_thumb(), iVar2 != 0))
  {
    TextSystem_CloseDialog_from_thumb();
    *(undefined4 *)(*piRam02029d94 + 0x54) = 0;
  }
LAB_02029d88:
  NavigationContext_OnSceneUpdate_from_thumb();
  return;
}

