/* Decompiled C draft; module arm9; ROM address 0212b9f8. No matching claim. */
#include "types.h"
#include "deps/0212b9f8_func_0212b9f8.h"

void func_0212b9f8(void)

{
  undefined4 uVar1;
  
  func_0212cb78();
  SND_StopTimer(0,0,0,0);
  uVar1 = func_02021114();
  Sound_FlushCommand(1);
  func_02021154(uVar1);
  return;
}

