/* Decompiled C draft; module arm9; ROM address 02020e64. No matching claim. */
#include "types.h"
#include "deps/02020e64_Sound_InitializeImpl.h"

void Sound_InitializeImpl(void)

{
  undefined4 uVar1;
  
  uVar1 = uRam02020eac;
  if (*(uint *)((uint)puRam02020ea8 & 0xfffffffc) >> ((uint)puRam02020ea8 & 3) * 8 == 0 &&
      *(uint *)((uint)puRam02020ea8 & 0xfffffffc) << ((uint)puRam02020ea8 & 3) * -8 + 0x20 == 0) {
    *puRam02020ea8 = 1;
    Os_Mutex_Initialize(uVar1);
    Sound_InitializeCommands();
    Sound_InitializeAlarms();
    return;
  }
  return;
}

