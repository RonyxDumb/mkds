/* Decompiled C draft; module arm9; ROM address 02047178. No matching claim. */
#include "types.h"
#include "deps/02047178_Input_MaybeInitializeTouch.h"

void Input_MaybeInitializeTouch(void)

{
  int iVar1;
  undefined1 auStack_10 [16];
  
  Os_InitializeTouchPanelFifo();
  iVar1 = ComputeSomeScreenCalibrationStuff((undefined2 *)(void *)(auStack_10));
  if (iVar1 != 0) {
    UseSomeCalibrationStuff((short *)(void *)(auStack_10));
    return;
  }
  return;
}

