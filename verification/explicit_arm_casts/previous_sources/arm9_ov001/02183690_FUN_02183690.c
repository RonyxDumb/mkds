/* Decompiled C draft; module arm9_ov001; ROM address 02183690. No matching claim. */
#include "types.h"
#include "deps/02183690_FUN_02183690.h"

undefined4 FUN_02183690(ushort *param_1)

{
  int iVar1;
  
  if (*param_1 == DAT_02183750) {
    iVar1 = func_0x0209b620(*(undefined4 *)((int)param_1 + DAT_02183754));
    if (iVar1 == 2) {
      FUN_02187af4(param_1);
      FUN_021872e0(param_1,DAT_02183764,0,0,0,DAT_02183758,DAT_0218375c,DAT_02183760,0);
      FUN_021872e0(param_1,DAT_02183764,0,0,0,DAT_02183758,DAT_0218375c,DAT_02183768,0);
      FUN_021872e0(param_1,DAT_02183764,0,0,0,DAT_0218376c,DAT_0218375c,DAT_02183770,0);
      func_0x020d2774(param_1,DAT_02183774);
    }
  }
  else if ((*param_1 == DAT_02183778) &&
          ((iVar1 = func_0x0209b620(*(undefined4 *)((int)param_1 + DAT_02183754)), iVar1 == 0x2b ||
           (iVar1 = func_0x0209b620(*(undefined4 *)((int)param_1 + DAT_02183754)), iVar1 == 0x48))))
  {
    FUN_02187af4(param_1);
    FUN_02187518(param_1,0,0,0,DAT_0218377c,0);
  }
  return 0;
}

