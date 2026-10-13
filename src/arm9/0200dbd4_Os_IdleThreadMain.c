/* Decompiled C draft; module arm9; ROM address 0200dbd4. No matching claim. */
#include "types.h"
#include "deps/0200dbd4_Os_IdleThreadMain.h"

void Os_IdleThreadMain(void)

{
  Os_EnableIrq();
  do {
    Os_Halt();
  } while( true );
}

