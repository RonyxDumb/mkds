/* Decompiled C draft; module arm9; ROM address 0200fd1c. No matching claim. */
#include "types.h"
#include "deps/0200fd1c_Os_Terminate.h"

void Os_Terminate(void)

{
  do {
    Os_DisableIrq();
    Os_Halt();
  } while( true );
}

