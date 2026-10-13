/* Decompiled C draft; module arm9; ROM address 02049f60. No matching claim. */
#include "types.h"
#include "deps/02049f60_func_02049f60.h"

void func_02049f60(void)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  uint uVar9;
  bool bVar10;
  
  *(undefined1 *)
   ((*(uint *)(DAT_0204a194 & 0xfffffffc) >> (DAT_0204a194 & 3) * 8 |
    *(uint *)(DAT_0204a194 & 0xfffffffc) << (DAT_0204a194 & 3) * -8 + 0x20) + 0x120) = 0;
  ResetMultiplayErrors_from_thumb();
  bVar2 = *(uint *)(DAT_0204a198 & 0xfffffffc) >> (DAT_0204a198 & 3) * 8 != 0;
  bVar3 = *(uint *)(DAT_0204a198 & 0xfffffffc) << (DAT_0204a198 & 3) * -8 + 0x20 != 0;
  if (*DAT_0204a19c == 2) {
    uVar9 = *(uint *)(DAT_0204a194 & 0xfffffffc) >> (DAT_0204a194 & 3) * 8 |
            *(uint *)(DAT_0204a194 & 0xfffffffc) << (DAT_0204a194 & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0x118;
    uVar1 = uVar6 & 3;
    uVar5 = *(uint *)(uVar6 & 0xfffffffc);
    uVar9 = uVar9 + 0x11c;
    uVar6 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    DisplayMultiplayError_from_thumb
              (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,
               uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20);
  }
  InitializeGlobalG_2();
  UpdateInput();
  VBlankIntrWait();
  bVar8 = false;
  uVar6 = *(uint *)(DAT_0204a1a0 & 0xfffffffc) >> (DAT_0204a1a0 & 3) * 8 |
          *(uint *)(DAT_0204a1a0 & 0xfffffffc) << (DAT_0204a1a0 & 3) * -8 + 0x20;
  if ((uVar6 != 0) &&
     (uVar6 = uVar6 + 0x1f30, uVar9 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
     uVar6 >> uVar9 * 8 != 0 || uVar6 << uVar9 * -8 + 0x20 != 0)) {
    bVar8 = true;
  }
  if (*DAT_0204a19c != 2) {
    uVar9 = *(uint *)(DAT_0204a194 & 0xfffffffc) >> (DAT_0204a194 & 3) * 8 |
            *(uint *)(DAT_0204a194 & 0xfffffffc) << (DAT_0204a194 & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0x118;
    uVar1 = uVar6 & 3;
    uVar5 = *(uint *)(uVar6 & 0xfffffffc);
    uVar9 = uVar9 + 0x11c;
    uVar6 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    DisplayMultiplayError_from_thumb
              (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,
               uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20);
  }
  Maybe_helper_105b48();
  if (*DAT_0204a19c == 2) {
    func_02108d00();
  }
  else {
    func_02108c80();
  }
  func_0214f4bc((*(uint *)(DAT_0204a194 & 0xfffffffc) >> (DAT_0204a194 & 3) * 8 |
                *(uint *)(DAT_0204a194 & 0xfffffffc) << (DAT_0204a194 & 3) * -8 + 0x20) + 0xcc);
  func_0214f4a4((*(uint *)(DAT_0204a194 & 0xfffffffc) >> (DAT_0204a194 & 3) * 8 |
                *(uint *)(DAT_0204a194 & 0xfffffffc) << (DAT_0204a194 & 3) * -8 + 0x20) + 0xd8);
  PMi_SetLCDPower(1);
  if (!bVar8) goto switchD_0204a070_default;
  uVar6 = (*(uint *)(DAT_0204a194 & 0xfffffffc) >> (DAT_0204a194 & 3) * 8 |
          *(uint *)(DAT_0204a194 & 0xfffffffc) << (DAT_0204a194 & 3) * -8 + 0x20) + 0x118;
  uVar9 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  switch(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) {
  case 0:
    goto switchD_0204a070_default;
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
    goto switchD_0204a070_default;
  }
  OnSomeMultiplayError();
switchD_0204a070_default:
  do {
    UpdateInput();
    if (bVar2 || bVar3) {
      LoopFn_Some3D();
    }
    if (bVar8) {
      bVar4 = true;
      if (*(short *)((*(uint *)(DAT_0204a1a0 & 0xfffffffc) >> (DAT_0204a1a0 & 3) * 8 |
                     *(uint *)(DAT_0204a1a0 & 0xfffffffc) << (DAT_0204a1a0 & 3) * -8 + 0x20) + 0x16)
          == 0) {
        bVar10 = true;
      }
      else {
        bVar10 = false;
      }
    }
    else {
      iVar7 = func_02054f58();
      bVar10 = iVar7 == 1;
      bVar4 = bVar10;
    }
    if ((bVar10) && ((int)(*DAT_0204a1a4 & 0x8000) >> 0xf != 0)) {
      func_0214f83c(0xc,0,0);
    }
    iVar7 = func_0212b0b8();
    LoopFn_Sound();
    VBlankIntrWait();
    if (bVar2 || bVar3) {
      LoopFn_DisplayConfig();
    }
  } while ((!bVar4) || (iVar7 == -1));
  if (iVar7 == 1) {
    *(undefined1 *)
     ((*(uint *)(DAT_0204a194 & 0xfffffffc) >> (DAT_0204a194 & 3) * 8 |
      *(uint *)(DAT_0204a194 & 0xfffffffc) << (DAT_0204a194 & 3) * -8 + 0x20) + 0x120) = 0xc;
    return;
  }
  *(undefined1 *)
   ((*(uint *)(DAT_0204a194 & 0xfffffffc) >> (DAT_0204a194 & 3) * 8 |
    *(uint *)(DAT_0204a194 & 0xfffffffc) << (DAT_0204a194 & 3) * -8 + 0x20) + 0x120) = 0;
  return;
}

