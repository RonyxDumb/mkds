/* Decompiled C draft; module arm9; ROM address 020487fc. No matching claim. */
#include "types.h"
#include "deps/020487fc_OnSceneLoop.h"

void OnSceneLoop(int param_1,undefined4 *param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  code *pcVar8;
  undefined4 uVar9;
  bool bVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  bool bVar14;
  bool bVar15;
  undefined4 local_28;
  
  uVar7 = uRam020497bc;
  iVar13 = 0;
  *(undefined4 *)
   ((*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
    *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) + 0xe4) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0xe8) = 0;
  uVar12 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
           *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  uVar6 = param_2[1];
  uVar9 = param_2[2];
  uVar11 = param_2[3];
  *(undefined4 *)(uVar12 + 0xec) = *param_2;
  *(undefined4 *)(uVar12 + 0xf0) = uVar6;
  *(undefined4 *)(uVar12 + 0xf4) = uVar9;
  *(undefined4 *)(uVar12 + 0xf8) = uVar11;
  uVar6 = param_2[5];
  uVar9 = param_2[6];
  uVar11 = param_2[7];
  *(undefined4 *)(uVar12 + 0xfc) = param_2[4];
  *(undefined4 *)(uVar12 + 0x100) = uVar6;
  *(undefined4 *)(uVar12 + 0x104) = uVar9;
  *(undefined4 *)(uVar12 + 0x108) = uVar11;
  *(undefined4 *)(uVar12 + 0x10c) = 6;
  *(undefined1 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x120) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x118) = 0xffffffff;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x11c) = 0;
  uVar6 = Os_DisableIrq();
  iVar3 = PM_GetLCDPower();
  if (iVar3 == 1) {
    *(undefined4 *)
     ((*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
      *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) + 0x110) = 0;
  }
  else {
    *(undefined4 *)
     ((*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
      *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) + 0x110) = 1;
  }
  Os_RestoreIrq(uVar6);
  *(undefined4 *)
   ((*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
    *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) + 0x10c) = 0;
  SetActiveExecutionContextHeapGroupId_from_thumb();
  MountArchivesForScene_from_thumb((int)*(short *)(param_1 + 2));
  SetActiveExecutionContextHeapGroupId_from_thumb(9);
  GetActiveExecutionContext();
  ExecutionContext_GetHeapHandle();
  GetActiveExecutionContext();
  uVar6 = ExecutionContext_GetHeapHandle();
  uVar6 = Mem_AllocateHeap(uVar6,0x800);
  InitializeGlobalTEQ(uVar6,0x80);
  iVar3 = TryGetSceneSpecialBgmSseqId((int)*(short *)(param_1 + 2),&local_28);
  if (iVar3 != 0) {
    SetSomeSceneSseqId(local_28);
  }
  MaybeChangeAudioForMenu(0);
  func_02043410();
  bVar14 = false;
  uVar7 = *(uint *)(uRam020497c0 & 0xfffffffc) >> (uRam020497c0 & 3) * 8 |
          *(uint *)(uRam020497c0 & 0xfffffffc) << (uRam020497c0 & 3) * -8 + 0x20;
  if (uVar7 == 0) {
    uVar12 = 0;
  }
  else {
    uVar12 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
             *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  }
  if ((uVar12 != 0) &&
     (uVar12 = uVar7 + 4 & 3, uVar4 = *(uint *)(uVar7 + 4 & 0xfffffffc),
     (uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20) != 0xd)) {
    bVar14 = true;
  }
  if (bVar14) {
    *(ushort *)(uVar7 + 0x454) = *(ushort *)(uVar7 + 0x454) | 4;
  }
  LoadMA2ContentIfMounted_from_thumb();
  func_02043b48();
  Card_SetUserCardPulledOutCallback(uRam020497c4);
  *(undefined4 *)
   ((*(uint *)(uRam020497c8 & 0xfffffffc) >> (uRam020497c8 & 3) * 8 |
    *(uint *)(uRam020497c8 & 0xfffffffc) << (uRam020497c8 & 3) * -8 + 0x20) + 0x78) = 0;
  pcVar8 = (code *)(*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
                   *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20);
  if (pcVar8 != (code *)0x0) {
    (*pcVar8)(param_1);
  }
  SomeMaskMountDataFlags_from_thumb();
  *(undefined4 *)
   ((*(uint *)(uRam020497cc & 0xfffffffc) >> (uRam020497cc & 3) * 8 |
    *(uint *)(uRam020497cc & 0xfffffffc) << (uRam020497cc & 3) * -8 + 0x20) + 0xb8) = uRam020497d0;
  func_0204ac60();
  PlayBgEffectsAndMore();
  EnableGreenSwap();
  uVar7 = uRam020497bc;
  *(undefined4 *)
   ((*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
    *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) + 0x10c) = 1;
  do {
    LoopFn_Some3D();
    iVar3 = Card_IsPulledOut();
    if (iVar3 != 0) {
      iVar3 = Pad_DetectFolding();
      if (iVar3 == 1) {
        func_0214fb54();
      }
      NotifyError(3);
    }
    func_02043a34();
    iVar3 = func_02049b6c();
    if (iVar3 == 0) {
      func_02043648();
    }
    iVar3 = Pad_DetectFolding();
    if (iVar3 == 1) {
      iVar3 = func_02049aa4();
      if (iVar3 == 0) {
        iVar3 = PM_GetLCDPower();
        if (iVar3 == 1) {
          uVar6 = Os_DisableIrq();
          *(undefined4 *)
           ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x110) = 1;
          PMi_SetLCDPower(0);
          Os_RestoreIrq(uVar6);
        }
      }
      else {
        func_0214f83c(0xc,0,0);
      }
    }
    else {
      iVar3 = PM_GetLCDPower();
      if (iVar3 == 0) {
        uVar6 = Os_DisableIrq();
        PMi_SetLCDPower(1);
        iVar3 = Bright_IsBothScreensFadedIn();
        if (iVar3 != 0) {
          SetTopBrightness(0);
          SetBottomBrightness(0);
        }
        *(undefined4 *)
         ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x110) = 0;
        Os_RestoreIrq(uVar6);
      }
    }
    LoopFn_Sound();
    iVar3 = MaybeIfExpectsReturnToTitleScene();
    if (iVar3 == 0) {
      func_020435c4();
    }
    iVar3 = GetCurrentSceneId();
    if ((iVar3 == 1) || (iVar3 == 10)) {
      uVar12 = *(uint *)(uRam020497c0 & 0xfffffffc) >> (uRam020497c0 & 3) * 8 |
               *(uint *)(uRam020497c0 & 0xfffffffc) << (uRam020497c0 & 3) * -8 + 0x20;
      if (uVar12 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20;
      }
      bVar14 = uVar4 != 0;
      if (bVar14) {
        uVar4 = uVar12 + 4 & 3;
        uVar5 = *(uint *)(uVar12 + 4 & 0xfffffffc);
        if ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) == 0xd) {
          bVar14 = false;
        }
        else {
          bVar14 = true;
        }
      }
      bVar14 = !bVar14;
      if (!bVar14) {
        bVar14 = false;
        uVar4 = (*(uint *)(uRam020497d4 & 0xfffffffc) >> (uRam020497d4 & 3) * 8 |
                *(uint *)(uRam020497d4 & 0xfffffffc) << (uRam020497d4 & 3) * -8 + 0x20) + 8;
        uVar5 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        if ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) == 5) {
          uVar4 = *(uint *)(uRam020497d8 & 0xfffffffc) >> (uRam020497d8 & 3) * 8 |
                  *(uint *)(uRam020497d8 & 0xfffffffc) << (uRam020497d8 & 3) * -8 + 0x20;
          bVar15 = false;
          if ((uVar4 != 0) && ((*(ushort *)(uVar4 + 0x75c) & 0x10) != 0)) {
            bVar15 = true;
          }
          if (bVar15) {
            bVar14 = true;
          }
        }
        if (uVar12 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                  *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20;
        }
        bVar10 = false;
        bVar15 = false;
        bVar1 = false;
        if ((uVar4 != 0) &&
           (uVar4 = uVar12 + 4 & 3, uVar5 = *(uint *)(uVar12 + 4 & 0xfffffffc),
           (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) != 0xd)) {
          bVar1 = true;
        }
        if ((bVar1) && ((*(ushort *)(uVar12 + 0x454) & 0x80) == 0)) {
          bVar15 = true;
        }
        if ((bVar15) && ((*(ushort *)(uVar12 + 0x454) & 0x10) != 0)) {
          bVar10 = true;
        }
        if (bVar10) {
          bVar14 = true;
        }
        if (bVar14) {
          bVar14 = false;
        }
        else {
          bVar14 = true;
        }
      }
      UpdateBrightnessContextsAndMore(bVar14);
    }
    else {
      uVar12 = (uint)(param_2 + 7) & 3;
      uVar4 = *(uint *)((uint)(param_2 + 7) & 0xfffffffc);
      func_02037658(uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20);
    }
    uVar12 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
             *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x10c;
    uVar4 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    iVar3 = func_0204984c(param_1,(uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) != 4);
    HandleAllGlobalTEQSubs();
    if (iVar3 != 0) {
      *(short *)(param_1 + 4) =
           (short)*(char *)((*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
                            *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20)
                           + 0x120);
      goto LAB_02049418;
    }
    func_0212034c();
    uVar5 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
    uVar12 = uVar5 + 0xe8;
    uVar4 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    *(uint *)(uVar5 + 0xe8) = (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) + 1;
    LoopFn_DisplayConfig();
    iVar3 = func_02054754();
  } while (iVar3 != 1);
  func_02043b04();
  BrightCtx_SomeFnTopBottom((int)*(short *)(param_2 + 6));
  uVar7 = uRam020497bc;
  *(undefined4 *)
   ((*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
    *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) + 0x10c) = 2;
  while( true ) {
    LoopFn_Some3D();
    iVar3 = Card_IsPulledOut();
    if (iVar3 != 0) {
      iVar3 = Pad_DetectFolding();
      if (iVar3 == 1) {
        func_0214fb54();
      }
      NotifyError(3);
    }
    func_02043a34();
    iVar3 = func_02049b6c();
    if (iVar3 == 0) {
      func_02043648();
    }
    iVar3 = Pad_DetectFolding();
    if (iVar3 == 1) {
      iVar3 = func_02049aa4();
      if (iVar3 == 0) {
        iVar3 = PM_GetLCDPower();
        if (iVar3 == 1) {
          uVar6 = Os_DisableIrq();
          *(undefined4 *)
           ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x110) = 1;
          PMi_SetLCDPower(0);
          Os_RestoreIrq(uVar6);
        }
      }
      else {
        func_0214f83c(0xc,0,0);
      }
    }
    else {
      iVar3 = PM_GetLCDPower();
      if (iVar3 == 0) {
        uVar6 = Os_DisableIrq();
        PMi_SetLCDPower(1);
        iVar3 = Bright_IsBothScreensFadedIn();
        if (iVar3 != 0) {
          SetTopBrightness(0);
          SetBottomBrightness(0);
        }
        *(undefined4 *)
         ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x110) = 0;
        Os_RestoreIrq(uVar6);
      }
    }
    uVar12 = (uint)(param_2 + 1) & 3;
    uVar4 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
    pcVar8 = (code *)(uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20);
    if (pcVar8 != (code *)0x0) {
      uVar12 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
               *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0xe4;
      uVar4 = uVar12 & 3;
      uVar12 = *(uint *)(uVar12 & 0xfffffffc);
      (*pcVar8)(param_1,uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20);
    }
    LoopFn_Sound();
    iVar3 = MaybeIfExpectsReturnToTitleScene();
    if (iVar3 == 0) {
      iVar13 = func_020435c4();
    }
    else {
      iVar13 = 0;
    }
    iVar3 = GetCurrentSceneId();
    if ((iVar3 == 1) || (iVar3 == 10)) {
      uVar12 = *(uint *)(uRam020497c0 & 0xfffffffc) >> (uRam020497c0 & 3) * 8 |
               *(uint *)(uRam020497c0 & 0xfffffffc) << (uRam020497c0 & 3) * -8 + 0x20;
      if (uVar12 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20;
      }
      bVar14 = uVar4 != 0;
      if (bVar14) {
        uVar4 = uVar12 + 4 & 3;
        uVar5 = *(uint *)(uVar12 + 4 & 0xfffffffc);
        if ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) == 0xd) {
          bVar14 = false;
        }
        else {
          bVar14 = true;
        }
      }
      bVar14 = !bVar14;
      if (!bVar14) {
        bVar14 = false;
        uVar4 = (*(uint *)(uRam020497d4 & 0xfffffffc) >> (uRam020497d4 & 3) * 8 |
                *(uint *)(uRam020497d4 & 0xfffffffc) << (uRam020497d4 & 3) * -8 + 0x20) + 8;
        uVar5 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        if ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) == 5) {
          uVar4 = *(uint *)(uRam020497d8 & 0xfffffffc) >> (uRam020497d8 & 3) * 8 |
                  *(uint *)(uRam020497d8 & 0xfffffffc) << (uRam020497d8 & 3) * -8 + 0x20;
          bVar15 = false;
          if ((uVar4 != 0) && ((*(ushort *)(uVar4 + 0x75c) & 0x10) != 0)) {
            bVar15 = true;
          }
          if (bVar15) {
            bVar14 = true;
          }
        }
        if (uVar12 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                  *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20;
        }
        bVar10 = false;
        bVar15 = false;
        bVar1 = false;
        if ((uVar4 != 0) &&
           (uVar4 = uVar12 + 4 & 3, uVar5 = *(uint *)(uVar12 + 4 & 0xfffffffc),
           (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) != 0xd)) {
          bVar1 = true;
        }
        if ((bVar1) && ((*(ushort *)(uVar12 + 0x454) & 0x80) == 0)) {
          bVar15 = true;
        }
        if ((bVar15) && ((*(ushort *)(uVar12 + 0x454) & 0x10) != 0)) {
          bVar10 = true;
        }
        if (bVar10) {
          bVar14 = true;
        }
        if (bVar14) {
          bVar14 = false;
        }
        else {
          bVar14 = true;
        }
      }
      UpdateBrightnessContextsAndMore(bVar14);
    }
    else {
      uVar12 = (uint)(param_2 + 7) & 3;
      uVar4 = *(uint *)((uint)(param_2 + 7) & 0xfffffffc);
      func_02037658(uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20);
    }
    uVar12 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
             *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x10c;
    uVar4 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    iVar3 = func_0204984c(param_1,(uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) != 4);
    HandleAllGlobalTEQSubs();
    if (iVar3 != 0) break;
    uVar12 = (uint)(param_2 + 3) & 3;
    uVar4 = *(uint *)((uint)(param_2 + 3) & 0xfffffffc);
    pcVar8 = (code *)(uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20);
    if (pcVar8 != (code *)0x0) {
      uVar12 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
               *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0xe4;
      uVar4 = uVar12 & 3;
      uVar12 = *(uint *)(uVar12 & 0xfffffffc);
      (*pcVar8)(param_1,uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20);
    }
    func_0212034c();
    bVar14 = false;
    uVar12 = (*(uint *)(uRam020497d4 & 0xfffffffc) >> (uRam020497d4 & 3) * 8 |
             *(uint *)(uRam020497d4 & 0xfffffffc) << (uRam020497d4 & 3) * -8 + 0x20) + 8;
    uVar4 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    if ((uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) == 5) {
      bVar15 = false;
      uVar12 = *(uint *)(uRam020497d8 & 0xfffffffc) >> (uRam020497d8 & 3) * 8 |
               *(uint *)(uRam020497d8 & 0xfffffffc) << (uRam020497d8 & 3) * -8 + 0x20;
      if ((uVar12 != 0) && ((*(ushort *)(uVar12 + 0x75c) & 0x10) != 0)) {
        bVar15 = true;
      }
      if (bVar15) {
        bVar14 = true;
      }
    }
    bVar10 = false;
    uVar12 = *(uint *)(uRam020497c0 & 0xfffffffc) >> (uRam020497c0 & 3) * 8 |
             *(uint *)(uRam020497c0 & 0xfffffffc) << (uRam020497c0 & 3) * -8 + 0x20;
    bVar15 = false;
    if (uVar12 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
              *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20;
    }
    bVar1 = false;
    if ((uVar4 != 0) &&
       (uVar4 = uVar12 + 4 & 3, uVar5 = *(uint *)(uVar12 + 4 & 0xfffffffc),
       (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) != 0xd)) {
      bVar1 = true;
    }
    if ((bVar1) && ((*(ushort *)(uVar12 + 0x454) & 0x80) == 0)) {
      bVar15 = true;
    }
    if ((bVar15) && ((*(ushort *)(uVar12 + 0x454) & 0x10) != 0)) {
      bVar10 = true;
    }
    if (bVar10) {
      bVar14 = true;
    }
    if (!bVar14) {
      uVar5 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
              *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
      uVar12 = uVar5 + 0xe4;
      uVar4 = uVar12 & 3;
      uVar12 = *(uint *)(uVar12 & 0xfffffffc);
      *(uint *)(uVar5 + 0xe4) = (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) + 1;
    }
    uVar5 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
    uVar12 = uVar5 + 0xe8;
    uVar4 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    *(uint *)(uVar5 + 0xe8) = (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) + 1;
    LoopFn_DisplayConfig();
    if ((*(short *)(param_1 + 4) != -1) || (iVar13 != 0)) {
      *(undefined4 *)
       ((*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
        *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) + 0x10c) = 3;
      func_02105fcc();
      uVar7 = (*(uint *)(uRam020497c8 & 0xfffffffc) >> (uRam020497c8 & 3) * 8 |
              *(uint *)(uRam020497c8 & 0xfffffffc) << (uRam020497c8 & 3) * -8 + 0x20) + 0x1c;
      uVar12 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      if (((int)((uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) << 0x1f) < 0) &&
         ((param_1 == 0 ||
          (iVar3 = ShouldPauseBgmInSceneChange
                             ((int)*(short *)(param_1 + 2),(int)*(short *)(param_1 + 4)), iVar3 != 0
          )))) {
        func_0204ac10();
      }
      if (((iVar13 != 0) || (iVar3 = GetNextSceneId(), iVar3 == 0)) && (*psRam020497dc == 2)) {
        NotifyError(0);
      }
      uVar7 = (*(uint *)(uRam020497c8 & 0xfffffffc) >> (uRam020497c8 & 3) * 8 |
              *(uint *)(uRam020497c8 & 0xfffffffc) << (uRam020497c8 & 3) * -8 + 0x20) + 0x20;
      uVar12 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      if ((uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) == 4) {
        Bright_FadeOutWhite((int)*(short *)((int)param_2 + 0x1a));
      }
      else {
        Bright_FadeOutBlack((int)*(short *)((int)param_2 + 0x1a));
      }
      do {
        LoopFn_Some3D();
        iVar3 = Card_IsPulledOut();
        if (iVar3 != 0) {
          iVar3 = Pad_DetectFolding();
          if (iVar3 == 1) {
            func_0214fb54();
          }
          NotifyError(3);
        }
        func_02043a34();
        iVar3 = func_02049b6c();
        if (iVar3 == 0) {
          func_02043648();
        }
        iVar3 = Pad_DetectFolding();
        if (iVar3 == 1) {
          iVar3 = func_02049aa4();
          if (iVar3 == 0) {
            iVar3 = PM_GetLCDPower();
            if (iVar3 == 1) {
              uVar6 = Os_DisableIrq();
              *(undefined4 *)
               ((*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
                *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) + 0x110) = 1
              ;
              PMi_SetLCDPower(0);
              Os_RestoreIrq(uVar6);
            }
          }
          else {
            func_0214f83c(0xc,0,0);
          }
        }
        else {
          iVar3 = PM_GetLCDPower();
          if (iVar3 == 0) {
            uVar6 = Os_DisableIrq();
            PMi_SetLCDPower(1);
            iVar3 = Bright_IsBothScreensFadedIn();
            if (iVar3 != 0) {
              SetTopBrightness(0);
              SetBottomBrightness(0);
            }
            *(undefined4 *)
             ((*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
              *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) + 0x110) = 0;
            Os_RestoreIrq(uVar6);
          }
        }
        uVar7 = (uint)(param_2 + 1) & 3;
        uVar12 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
        pcVar8 = (code *)(uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20);
        if (pcVar8 != (code *)0x0) {
          uVar7 = (*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
                  *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) + 0xe4;
          uVar12 = uVar7 & 3;
          uVar7 = *(uint *)(uVar7 & 0xfffffffc);
          (*pcVar8)(0,uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20);
        }
        LoopFn_Sound();
        iVar3 = MaybeIfExpectsReturnToTitleScene();
        if (iVar3 == 0) {
          func_020435c4();
        }
        iVar3 = GetCurrentSceneId();
        if ((iVar3 == 1) || (iVar3 == 10)) {
          uVar7 = *(uint *)(uRam020497c0 & 0xfffffffc) >> (uRam020497c0 & 3) * 8 |
                  *(uint *)(uRam020497c0 & 0xfffffffc) << (uRam020497c0 & 3) * -8 + 0x20;
          if (uVar7 == 0) {
            uVar12 = 0;
          }
          else {
            uVar12 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                     *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
          }
          bVar14 = uVar12 != 0;
          if (bVar14) {
            uVar12 = uVar7 + 4 & 3;
            uVar4 = *(uint *)(uVar7 + 4 & 0xfffffffc);
            if ((uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20) == 0xd) {
              bVar14 = false;
            }
            else {
              bVar14 = true;
            }
          }
          bVar14 = !bVar14;
          if (!bVar14) {
            bVar14 = false;
            uVar12 = (*(uint *)(uRam020497d4 & 0xfffffffc) >> (uRam020497d4 & 3) * 8 |
                     *(uint *)(uRam020497d4 & 0xfffffffc) << (uRam020497d4 & 3) * -8 + 0x20) + 8;
            uVar4 = uVar12 & 3;
            uVar12 = *(uint *)(uVar12 & 0xfffffffc);
            if ((uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) == 5) {
              bVar15 = false;
              uVar12 = *(uint *)(uRam020497d8 & 0xfffffffc) >> (uRam020497d8 & 3) * 8 |
                       *(uint *)(uRam020497d8 & 0xfffffffc) << (uRam020497d8 & 3) * -8 + 0x20;
              if ((uVar12 != 0) && ((*(ushort *)(uVar12 + 0x75c) & 0x10) != 0)) {
                bVar15 = true;
              }
              if (bVar15) {
                bVar14 = true;
              }
            }
            bVar15 = false;
            if (uVar7 == 0) {
              uVar12 = 0;
            }
            else {
              uVar12 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                       *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
            }
            bVar1 = false;
            bVar10 = false;
            if ((uVar12 != 0) &&
               (uVar12 = uVar7 + 4 & 3, uVar4 = *(uint *)(uVar7 + 4 & 0xfffffffc),
               (uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20) != 0xd)) {
              bVar10 = true;
            }
            if ((bVar10) && ((*(ushort *)(uVar7 + 0x454) & 0x80) == 0)) {
              bVar1 = true;
            }
            if ((bVar1) && ((*(ushort *)(uVar7 + 0x454) & 0x10) != 0)) {
              bVar15 = true;
            }
            if (bVar15) {
              bVar14 = true;
            }
            if (bVar14) {
              bVar14 = false;
            }
            else {
              bVar14 = true;
            }
          }
          UpdateBrightnessContextsAndMore(bVar14);
        }
        else {
          uVar7 = (uint)(param_2 + 7) & 3;
          uVar12 = *(uint *)((uint)(param_2 + 7) & 0xfffffffc);
          func_02037658(uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20);
        }
        uVar7 = (*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
                *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) + 0x10c;
        uVar12 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        func_0204984c(param_1,(uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) != 4);
        HandleAllGlobalTEQSubs();
        uVar7 = (uint)(param_2 + 3) & 3;
        uVar12 = *(uint *)((uint)(param_2 + 3) & 0xfffffffc);
        pcVar8 = (code *)(uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20);
        if (pcVar8 != (code *)0x0) {
          uVar7 = (*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
                  *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) + 0xe4;
          uVar12 = uVar7 & 3;
          uVar7 = *(uint *)(uVar7 & 0xfffffffc);
          (*pcVar8)(0,uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20);
        }
        func_0212034c();
        bVar14 = false;
        uVar7 = (*(uint *)(uRam020497d4 & 0xfffffffc) >> (uRam020497d4 & 3) * 8 |
                *(uint *)(uRam020497d4 & 0xfffffffc) << (uRam020497d4 & 3) * -8 + 0x20) + 8;
        uVar12 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        if ((uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) == 5) {
          bVar15 = false;
          uVar7 = *(uint *)(uRam020497d8 & 0xfffffffc) >> (uRam020497d8 & 3) * 8 |
                  *(uint *)(uRam020497d8 & 0xfffffffc) << (uRam020497d8 & 3) * -8 + 0x20;
          if ((uVar7 != 0) && ((*(ushort *)(uVar7 + 0x75c) & 0x10) != 0)) {
            bVar15 = true;
          }
          if (bVar15) {
            bVar14 = true;
          }
        }
        bVar10 = false;
        uVar7 = *(uint *)(uRam020497c0 & 0xfffffffc) >> (uRam020497c0 & 3) * 8 |
                *(uint *)(uRam020497c0 & 0xfffffffc) << (uRam020497c0 & 3) * -8 + 0x20;
        bVar15 = false;
        if (uVar7 == 0) {
          uVar12 = 0;
        }
        else {
          uVar12 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                   *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
        }
        bVar1 = false;
        if ((uVar12 != 0) &&
           (uVar12 = uVar7 + 4 & 3, uVar4 = *(uint *)(uVar7 + 4 & 0xfffffffc),
           (uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20) != 0xd)) {
          bVar1 = true;
        }
        if ((bVar1) && ((*(ushort *)(uVar7 + 0x454) & 0x80) == 0)) {
          bVar15 = true;
        }
        if ((bVar15) && ((*(ushort *)(uVar7 + 0x454) & 0x10) != 0)) {
          bVar10 = true;
        }
        if (bVar10) {
          bVar14 = true;
        }
        if (!bVar14) {
          uVar4 = *(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
                  *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20;
          uVar7 = uVar4 + 0xe4;
          uVar12 = uVar7 & 3;
          uVar7 = *(uint *)(uVar7 & 0xfffffffc);
          *(uint *)(uVar4 + 0xe4) = (uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) + 1;
        }
        uVar4 = *(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
                *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20;
        uVar7 = uVar4 + 0xe8;
        uVar12 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        *(uint *)(uVar4 + 0xe8) = (uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) + 1;
        LoopFn_DisplayConfig();
        iVar3 = Bright_IsBothScreensFadedOut();
      } while (iVar3 == 0);
LAB_02049418:
      func_02043ae0();
      bVar14 = false;
      uVar7 = *(uint *)(uRam020497e0 & 0xfffffffc) >> (uRam020497e0 & 3) * 8 |
              *(uint *)(uRam020497e0 & 0xfffffffc) << (uRam020497e0 & 3) * -8 + 0x20;
      if ((uVar7 != 0) &&
         (uVar12 = uVar7 + 0x1f30 & 3, uVar4 = *(uint *)(uVar7 + 0x1f30 & 0xfffffffc),
         uVar4 >> uVar12 * 8 != 0 || uVar4 << uVar12 * -8 + 0x20 != 0)) {
        bVar14 = true;
      }
      if (bVar14) {
        bVar14 = *(short *)(uVar7 + 0x16) == 0;
      }
      else {
        bVar14 = true;
      }
      if ((bVar14) && ((iVar13 != 0 || (iVar3 = GetNextSceneId(), iVar3 == 0)))) {
        uVar12 = uRam020497c8;
        *(undefined4 *)
         ((*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
          *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) + 0x10c) = 4;
        uVar7 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        bVar14 = false;
        *(undefined4 *)((uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) + 0x20) = 0;
        func_0204f7f4();
        uVar7 = uRam020497c0;
        do {
          LoopFn_Some3D();
          LoopFn_Sound();
          iVar3 = MaybeIfExpectsReturnToTitleScene();
          if (iVar3 == 0) {
            func_020435c4();
          }
          iVar3 = GetCurrentSceneId();
          if ((iVar3 == 1) || (iVar3 == 10)) {
            uVar12 = uVar7 & 3;
            uVar4 = *(uint *)(uVar7 & 0xfffffffc);
            uVar12 = uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20;
            if (uVar12 == 0) {
              uVar4 = 0;
            }
            else {
              uVar4 = *(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                      *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20;
            }
            bVar15 = uVar4 != 0;
            if (bVar15) {
              uVar4 = uVar12 + 4 & 3;
              uVar5 = *(uint *)(uVar12 + 4 & 0xfffffffc);
              if ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) == 0xd) {
                bVar15 = false;
              }
              else {
                bVar15 = true;
              }
            }
            bVar15 = !bVar15;
            if (!bVar15) {
              bVar15 = false;
              uVar4 = (*(uint *)(uRam020497d4 & 0xfffffffc) >> (uRam020497d4 & 3) * 8 |
                      *(uint *)(uRam020497d4 & 0xfffffffc) << (uRam020497d4 & 3) * -8 + 0x20) + 8;
              uVar5 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              if ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) == 5) {
                bVar10 = false;
                uVar4 = *(uint *)(uRam020497d8 & 0xfffffffc) >> (uRam020497d8 & 3) * 8 |
                        *(uint *)(uRam020497d8 & 0xfffffffc) << (uRam020497d8 & 3) * -8 + 0x20;
                if ((uVar4 != 0) && ((*(ushort *)(uVar4 + 0x75c) & 0x10) != 0)) {
                  bVar10 = true;
                }
                if (bVar10) {
                  bVar15 = true;
                }
              }
              if (uVar12 == 0) {
                uVar4 = 0;
              }
              else {
                uVar4 = *(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                        *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20;
              }
              bVar1 = false;
              bVar10 = false;
              bVar2 = false;
              if ((uVar4 != 0) &&
                 (uVar4 = uVar12 + 4 & 3, uVar5 = *(uint *)(uVar12 + 4 & 0xfffffffc),
                 (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) != 0xd)) {
                bVar2 = true;
              }
              if ((bVar2) && ((*(ushort *)(uVar12 + 0x454) & 0x80) == 0)) {
                bVar10 = true;
              }
              if ((bVar10) && ((*(ushort *)(uVar12 + 0x454) & 0x10) != 0)) {
                bVar1 = true;
              }
              if (bVar1) {
                bVar15 = true;
              }
              if (bVar15) {
                bVar15 = false;
              }
              else {
                bVar15 = true;
              }
            }
            UpdateBrightnessContextsAndMore(bVar15);
          }
          else {
            uVar12 = (uint)(param_2 + 7) & 3;
            uVar4 = *(uint *)((uint)(param_2 + 7) & 0xfffffffc);
            func_02037658(uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20);
          }
          iVar3 = func_02054f58();
          if (iVar3 == 1) {
            if (*(char *)((*(uint *)(uRam020497e4 & 0xfffffffc) >> (uRam020497e4 & 3) * 8 |
                          *(uint *)(uRam020497e4 & 0xfffffffc) << (uRam020497e4 & 3) * -8 + 0x20) +
                         0x28) == '\0') {
              uVar4 = *(uint *)(uRam020497e8 & 0xfffffffc) >> (uRam020497e8 & 3) * 8 |
                      *(uint *)(uRam020497e8 & 0xfffffffc) << (uRam020497e8 & 3) * -8 + 0x20;
              uVar12 = uVar4 + 0xc;
              uVar5 = uVar12 & 3;
              uVar12 = *(uint *)(uVar12 & 0xfffffffc);
              if (uVar12 >> uVar5 * 8 == 0 && uVar12 << uVar5 * -8 + 0x20 == 0) {
                uVar12 = 0;
              }
              else {
                uVar4 = uVar4 + 0x10;
                uVar12 = uVar4 & 3;
                uVar4 = *(uint *)(uVar4 & 0xfffffffc);
                uVar12 = uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20;
              }
            }
            else {
              uVar12 = 1;
            }
            if (uVar12 == 0) {
              bVar14 = true;
            }
          }
          uVar12 = (*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
                   *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) + 0x10c;
          uVar4 = uVar12 & 3;
          uVar12 = *(uint *)(uVar12 & 0xfffffffc);
          func_0204984c(param_1,(uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) != 4);
          HandleAllGlobalTEQSubs();
          func_0212034c();
          LoopFn_DisplayConfig();
        } while (!bVar14);
      }
      uVar4 = uRam020497cc;
      *(undefined4 *)
       ((*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
        *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) + 0x10c) = 5;
      uVar12 = uRam020497c0;
      uVar7 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      bVar14 = false;
      *(undefined4 *)((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 0xb8) = 0;
      uVar7 = uVar12 & 3;
      uVar12 = *(uint *)(uVar12 & 0xfffffffc);
      uVar7 = uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20;
      if (uVar7 == 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                 *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
      }
      if ((uVar12 != 0) &&
         (uVar12 = uVar7 + 4 & 3, uVar4 = *(uint *)(uVar7 + 4 & 0xfffffffc),
         (uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20) != 0xd)) {
        bVar14 = true;
      }
      if (bVar14) {
        *(ushort *)(uVar7 + 0x454) = *(ushort *)(uVar7 + 0x454) & 0xfffb;
      }
      func_020546d8();
      func_02055340();
      uVar7 = (uint)(param_2 + 2) & 3;
      uVar12 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
      pcVar8 = (code *)(uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20);
      if (pcVar8 != (code *)0x0) {
        (*pcVar8)(param_1);
      }
      Card_SetUserCardPulledOutCallback(uRam020497ec);
      if (*(uint *)(uRam020497cc & 0xfffffffc) >> (uRam020497cc & 3) * 8 != 0 ||
          *(uint *)(uRam020497cc & 0xfffffffc) << (uRam020497cc & 3) * -8 + 0x20 != 0) {
        ResetDisplayConfig();
      }
      func_02043b3c();
      CleanupPlayerGfxDataFontsEtc_from_thumb();
      SomeVramConfig();
      func_02105ec0();
      uVar7 = (*(uint *)(uRam020497c8 & 0xfffffffc) >> (uRam020497c8 & 3) * 8 |
              *(uint *)(uRam020497c8 & 0xfffffffc) << (uRam020497c8 & 3) * -8 + 0x20) + 0x1c;
      uVar12 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      if (((int)((uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) << 0x1e) < 0) &&
         (iVar3 = ShouldPauseBgmInSceneChange
                            ((int)*(short *)(param_1 + 2),(int)*(short *)(param_1 + 4)), iVar3 != 0)
         ) {
        func_0204aba8();
      }
      Arc_DisposeAllArchives_from_thumb();
      if (iVar13 == 0) {
        uVar4 = *(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
                *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20;
        uVar7 = uVar4 + 0x118;
        uVar12 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        uVar7 = uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20;
        if (uVar7 != 0xffffffff) {
          if (((uVar7 == 4) || (uVar7 == 5)) || (uVar7 == 6)) {
            *(short *)(param_1 + 4) = (short)*(char *)(uVar4 + 0x120);
          }
          else {
            *(undefined2 *)(param_1 + 4) = 0;
          }
        }
      }
      else {
        *(undefined2 *)(param_1 + 4) = 0;
      }
      ResetDTCMFrameHeap();
      uVar12 = uRam020497bc;
      *(undefined4 *)
       ((*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
        *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) + 0xe4) = 0;
      uVar7 = uVar12 & 3;
      uVar12 = *(uint *)(uVar12 & 0xfffffffc);
      *(undefined4 *)((uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) + 0x10c) = 6;
      return;
    }
  }
  *(short *)(param_1 + 4) =
       (short)*(char *)((*(uint *)(uRam020497bc & 0xfffffffc) >> (uRam020497bc & 3) * 8 |
                        *(uint *)(uRam020497bc & 0xfffffffc) << (uRam020497bc & 3) * -8 + 0x20) +
                       0x120);
  goto LAB_02049418;
}

