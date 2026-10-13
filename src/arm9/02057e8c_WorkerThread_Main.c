/* Decompiled C draft; module arm9; ROM address 02057e8c. No matching claim. */
#include "types.h"
#include "deps/02057e8c_WorkerThread_Main.h"

void WorkerThread_Main(void)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  
  uVar2 = uRam02057ed0;
  do {
    uVar4 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xf8;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    if (uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0) {
      pcVar3 = (code *)WorkerGetNextTaskFn();
      if (pcVar3 == (code *)0x0) {
        *(undefined4 *)
         ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xf8) = 0;
      }
      else {
        (*pcVar3)();
      }
    }
    Os_Sleep(2);
  } while( true );
}

