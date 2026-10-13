/* Decompiled C draft; module arm9; ROM address 0210f1d4. No matching claim. */
#include "types.h"
#include "deps/0210f1d4_InitializeBalloonHardware.h"

void InitializeBalloonHardware(void)

{
  RegisterFifoMicrophone();
  PM_Initialize();
  func_0214fb3c(1);
  *puRam0210f204 = 1;
  return;
}

