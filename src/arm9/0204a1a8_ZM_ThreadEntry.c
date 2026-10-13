/* Decompiled C draft; module arm9; ROM address 0204a1a8. No matching claim. */
#include "types.h"
#include "deps/0204a1a8_ZM_ThreadEntry.h"

void ZM_ThreadEntry(void)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  short *psVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  bool bVar11;
  
  psVar6 = DAT_0204a334;
  uVar5 = DAT_0204a330;
  do {
    Os_Thread_Sleep((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                    *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0xc4);
    *(undefined1 *)
     ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
      *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x120) = 0;
    ResetMultiplayErrors_from_thumb();
    bVar3 = *(uint *)(DAT_0204a338 & 0xfffffffc) >> (DAT_0204a338 & 3) * 8 != 0;
    bVar4 = *(uint *)(DAT_0204a338 & 0xfffffffc) << (DAT_0204a338 & 3) * -8 + 0x20 != 0;
    InitializeGlobalG_2();
    UpdateInput();
    VBlankIntrWait();
    bVar2 = false;
    uVar7 = *(uint *)(DAT_0204a33c & 0xfffffffc) >> (DAT_0204a33c & 3) * 8 |
            *(uint *)(DAT_0204a33c & 0xfffffffc) << (DAT_0204a33c & 3) * -8 + 0x20;
    if ((uVar7 != 0) &&
       (uVar7 = uVar7 + 0x1f30, uVar10 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
       uVar7 >> uVar10 * 8 != 0 || uVar7 << uVar10 * -8 + 0x20 != 0)) {
      bVar2 = true;
    }
    uVar10 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
             *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
    uVar7 = uVar10 + 0x118;
    uVar1 = uVar7 & 3;
    uVar8 = *(uint *)(uVar7 & 0xfffffffc);
    uVar10 = uVar10 + 0x11c;
    uVar7 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    DisplayMultiplayError_from_thumb
              (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20,
               uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20);
    Maybe_helper_105b48();
    if (*psVar6 == 2) {
      func_02108d00();
    }
    else {
      func_02108c80();
    }
    if (!bVar2) goto switchD_0204a26c_default;
    uVar7 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x118;
    uVar10 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    switch(uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) {
    case 0:
      goto switchD_0204a26c_default;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    default:
      goto switchD_0204a26c_default;
    }
    OnSomeMultiplayError();
switchD_0204a26c_default:
    do {
      if (bVar3 || bVar4) {
        LoopFn_Some3D();
      }
      if (bVar2) {
        bVar11 = true;
      }
      else {
        iVar9 = func_02054f58();
        bVar11 = iVar9 == 1;
      }
      LoopFn_Sound();
      VBlankIntrWait();
      if (bVar3 || bVar4) {
        LoopFn_DisplayConfig();
      }
    } while (!bVar11);
    do {
      if (bVar3 || bVar4) {
        LoopFn_Some3D();
      }
      UpdateInput();
      iVar9 = func_0212b0b8();
      LoopFn_Sound();
      VBlankIntrWait();
      if (bVar3 || bVar4) {
        LoopFn_DisplayConfig();
      }
    } while (iVar9 == -1);
    if (iVar9 == 1) {
      *(undefined1 *)
       ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
        *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x120) = 0xc;
    }
    else {
      *(undefined1 *)
       ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
        *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x120) = 0;
    }
  } while( true );
}

