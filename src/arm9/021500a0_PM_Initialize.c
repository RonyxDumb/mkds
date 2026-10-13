/* Decompiled C draft; module arm9; ROM address 021500a0. No matching claim. */
#include "types.h"
#include "deps/021500a0_PM_Initialize.h"

void PM_Initialize(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  puVar2 = puRam0215014c;
  if (*psRam02150148 == 0) {
    *psRam02150148 = 1;
    *puVar2 = 0;
    puVar2[1] = 0;
    func_0214d5b8();
    do {
      iVar3 = Fifo_IsHandlerReady(8,1);
    } while (iVar3 == 0);
    Fifo_RegisterHandler(8,uRam02150150);
    iVar3 = iRam02150154;
    iVar4 = 0;
    do {
      iVar1 = iVar4 * 8;
      iVar4 = iVar4 + 1;
      *(undefined2 *)(iVar3 + iVar1) = 0;
    } while (iVar4 < 4);
    Os_Mutex_Initialize((uint *)(uintptr_t)(uRam02150158));
    *puRam02150160 =
         *(uint *)(uRam0215015c & 0xfffffffc) >> (uRam0215015c & 3) * 8 |
         *(uint *)(uRam0215015c & 0xfffffffc) << (uRam0215015c & 3) * -8 + 0x20;
    return;
  }
  return;
}

