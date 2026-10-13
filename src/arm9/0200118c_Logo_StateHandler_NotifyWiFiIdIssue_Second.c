/* Decompiled C draft; module arm9; ROM address 0200118c. No matching claim. */
#include "types.h"
#include "deps/0200118c_Logo_StateHandler_NotifyWiFiIdIssue_Second.h"

void Logo_StateHandler_NotifyWiFiIdIssue_Second(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
  if (iVar1 != 0) {
    TextSystem_CloseDialog_from_thumb();
    return;
  }
  iVar1 = TextSystem_IsDialogFinished_from_thumb();
  if (iVar1 != 0) {
    uVar2 = *(uint *)(uRam020011ec & 0xfffffffc) >> (uRam020011ec & 3) * 8 |
            *(uint *)(uRam020011ec & 0xfffffffc) << (uRam020011ec & 3) * -8 + 0x20;
    *(undefined2 *)(uVar2 + 0x28) = 10;
    *(undefined2 *)(uVar2 + 0x2a) = 1;
    return;
  }
  return;
}

