/* Decompiled C draft; module arm9; ROM address 021060dc. No matching claim. */
#include "types.h"
#include "deps/021060dc_func_021060dc.h"

void func_021060dc(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = DAT_02106288;
  puVar1 = DAT_02106280;
  uVar5 = (uint)(DAT_02106280 + 2) & 3;
  uVar7 = *(uint *)((uint)(DAT_02106280 + 2) & 0xfffffffc);
  if (uVar7 >> uVar5 * 8 == 0 && uVar7 << uVar5 * -8 + 0x20 == 0) {
    *DAT_02106280 =
         *(uint *)(DAT_02106284 & 0xfffffffc) >> (DAT_02106284 & 3) * 8 |
         *(uint *)(DAT_02106284 & 0xfffffffc) << (DAT_02106284 & 3) * -8 + 0x20;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    iVar2 = func_02110640(puVar1,uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    if (iVar2 != -1) {
      uVar5 = DAT_0210628c & 3;
      uVar6 = *(uint *)(DAT_0210628c & 0xfffffffc);
      iVar3 = Sound_IsGlobalSdatUsed();
      if (iVar3 != 0) {
        uVar4 = Sound_GetActiveSdat();
        Sound_MaybeSetActiveSdat(DAT_02106290);
        uVar7 = 1;
        do {
          iVar3 = Sound_GetPlayerInfoEntry(uVar7);
          if ((iVar3 != 0) &&
             (((int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) >> (uVar7 & 0xff) & 1U) != 0))
          {
            MaybeSetPlayerVolume(uVar7,iVar2);
          }
          uVar7 = uVar7 + 1;
        } while ((int)uVar7 < 8);
        Sound_MaybeSetActiveSdat(uVar4);
      }
    }
  }
  iVar2 = GetCurrentSceneId();
  if (iVar2 != 2) {
    iVar2 = GetCurrentSceneId();
    if (iVar2 == 9) {
      uVar5 = DAT_02106298 + 4U & 3;
      uVar6 = *(uint *)(DAT_02106298 + 4U & 0xfffffffc);
      if ((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) == 0x5d) {
        func_0212c6f0(DAT_0210629c,0x1b);
      }
    }
    else {
      iVar2 = GetCurrentSceneId();
      if ((iVar2 == 1) || (iVar2 = GetCurrentSceneId(), iVar2 == 0xc)) {
        if (*DAT_021062a0 != 2) {
          func_02110754();
        }
      }
      else {
        iVar2 = GetCurrentSceneId();
        if (iVar2 == 3) {
          func_02110874();
        }
      }
    }
    goto switchD_0210619c_default;
  }
  uVar5 = (*(uint *)(DAT_02106294 & 0xfffffffc) >> (DAT_02106294 & 3) * 8 |
          *(uint *)(DAT_02106294 & 0xfffffffc) << (DAT_02106294 & 3) * -8 + 0x20) + 0xc;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  switch(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    goto switchD_0210619c_default;
  case 2:
    break;
  case 3:
    goto LAB_021061c0;
  case 4:
LAB_021061c0:
    func_021062a8();
  default:
    goto switchD_0210619c_default;
  }
  func_02106580();
switchD_0210619c_default:
  uVar5 = *(uint *)(DAT_021062a4 & 0xfffffffc) >> (DAT_021062a4 & 3) * 8 |
          *(uint *)(DAT_021062a4 & 0xfffffffc) << (DAT_021062a4 & 3) * -8 + 0x20;
  if (((uVar5 != 0) &&
      (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 == 0 &&
       *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20 == 0)) &&
     (uVar6 = uVar5 + 0xc & 3, uVar7 = *(uint *)(uVar5 + 0xc & 0xfffffffc),
     uVar7 >> uVar6 * 8 != 0 || uVar7 << uVar6 * -8 + 0x20 != 0)) {
    func_0210f780(uVar5 + 0xc);
  }
  uVar5 = DAT_02106298 + 4U & 3;
  uVar6 = *(uint *)(DAT_02106298 + 4U & 0xfffffffc);
  *(uint *)(DAT_02106298 + 4) = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 1;
  return;
}

