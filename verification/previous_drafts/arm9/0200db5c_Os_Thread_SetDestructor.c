/* Decompiled C draft; module arm9; ROM address 0200db5c. No matching claim. */
#include "types.h"
#include "deps/0200db5c_Os_Thread_SetDestructor.h"

void Os_Thread_SetDestructor(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xb4) = param_2;
  return;
}

