/* Decompiled C draft; module arm9; ROM address 02128dbc. No matching claim. */
#include "types.h"
#include "deps/02128dbc_Keyboard_SwitchFn13_from_thumb.h"

void Keyboard_SwitchFn13_from_thumb(void)

{
  int iVar1;
  
  iVar1 = TextSystem_IsDialogFinished_from_thumb();
  if (iVar1 == 0) {
    iVar1 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
    if (iVar1 != 0) {
      TextSystem_CloseDialog_from_thumb();
    }
    return;
  }
  iVar1 = TextSystem_IsButton2Focused_from_thumb();
  if (iVar1 == 0) {
    *(undefined2 *)(*piRam02128e04 + 0x72) = 3;
    return;
  }
  *(undefined2 *)(*piRam02128e04 + 0x72) = 0;
  return;
}

