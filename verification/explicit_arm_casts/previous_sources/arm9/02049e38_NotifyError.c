/* Decompiled C draft; module arm9; ROM address 02049e38. No matching claim. */
#include "types.h"
#include "deps/02049e38_NotifyError.h"

/* WARNING: Removing unreachable block (ram,0x02049ee0) */

void NotifyError(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = DAT_02049f54;
  uVar6 = 0;
  uVar1 = DAT_02049f4c & 3;
  uVar5 = *(uint *)(DAT_02049f4c & 0xfffffffc);
  switch(param_1) {
  case 0:
    uVar6 = (uint)(*DAT_02049f50 != 2);
    break;
  case 1:
    goto LAB_02049e90;
  case 2:
LAB_02049e90:
    uVar6 = 0;
    break;
  case 3:
    uVar6 = 0;
    break;
  case 4:
    goto LAB_02049e98;
  case 5:
    goto LAB_02049e98;
  case 6:
LAB_02049e98:
    uVar6 = 1;
  }
  *(undefined4 *)
   ((*(uint *)(DAT_02049f54 & 0xfffffffc) >> (DAT_02049f54 & 3) * 8 |
    *(uint *)(DAT_02049f54 & 0xfffffffc) << (DAT_02049f54 & 3) * -8 + 0x20) + 0x118) = param_1;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x11c) = uVar6;
  func_02049f60();
  func_02105fcc();
  uVar3 = (*(uint *)(DAT_02049f58 & 0xfffffffc) >> (DAT_02049f58 & 3) * 8 |
          *(uint *)(DAT_02049f58 & 0xfffffffc) << (DAT_02049f58 & 3) * -8 + 0x20) + 0x1c;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((int)((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) << 0x1f) < 0) {
    func_0204ac10();
  }
  if (uVar5 >> uVar1 * 8 == 0 && uVar5 << uVar1 * -8 + 0x20 == 0) {
    SetBrightness(DAT_02049f5c,0x10);
    return;
  }
  Bright_ResetBlackBothScreens();
  Bright_FadeOutBlack(10);
  do {
    LoopFn_Some3D();
    LoopFn_Sound();
    LoopFn_Brightness();
    LoopFn_DisplayConfig();
    iVar4 = Bright_IsBothScreensFadedOut();
  } while (iVar4 == 0);
  return;
}

