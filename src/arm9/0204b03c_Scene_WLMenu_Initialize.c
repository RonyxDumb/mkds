/* Decompiled C draft; module arm9; ROM address 0204b03c. No matching claim. */
#include "types.h"
#include "deps/0204b03c_Scene_WLMenu_Initialize.h"

void Scene_WLMenu_Initialize(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0204b080 & 0xfffffffc) >> (uRam0204b080 & 3) * 8 |
          *(uint *)(uRam0204b080 & 0xfffffffc) << (uRam0204b080 & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 3) {
    DisposeLoadedOverlay();
    UpdateOverlayStatusWithKind(0);
    WaitOverlayLoadedStarted();
  }
  GetActiveExecutionContext();
  ExecutionContext_GetHeapHandle();
  func_0202f2b4();
  return;
}

