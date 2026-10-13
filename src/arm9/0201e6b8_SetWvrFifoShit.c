/* Decompiled C draft; module arm9; ROM address 0201e6b8. No matching claim. */
#include "types.h"
#include "deps/0201e6b8_SetWvrFifoShit.h"

undefined4 SetWvrFifoShit(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  func_0214d5b8();
  iVar2 = Fifo_IsHandlerReady(0xf,1);
  if (iVar2 == 0) {
    return 2;
  }
  uVar3 = Os_DisableIrq(iVar2);
  if (*(uint *)((uint)piRam0201e798 & 0xfffffffc) >> ((uint)piRam0201e798 & 3) * 8 != 0 ||
      *(uint *)((uint)piRam0201e798 & 0xfffffffc) << ((uint)piRam0201e798 & 3) * -8 + 0x20 != 0) {
    Os_RestoreIrq();
    return 5;
  }
  iVar2 = Fifo_IsHandlerReady(0xf,0);
  if (iVar2 == 0) {
    Fifo_RegisterHandler(0xf,uRam0201e79c);
  }
  puVar1 = puRam0201e7a4;
  if (param_1 == 0) {
    *piRam0201e798 = iRam0201e7a0;
  }
  else {
    *piRam0201e798 = param_1;
  }
  *puVar1 = param_2;
  iVar2 = Fifo_SendWord(0xf,0x20000,0);
  if (iVar2 < 0) {
    *piRam0201e798 = 0;
    Os_RestoreIrq(uVar3);
    return 4;
  }
  Os_RestoreIrq(uVar3);
  return 1;
}

