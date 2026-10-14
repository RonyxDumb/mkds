/* Decompiled C draft; module arm9; ROM address 0214e8f4. No matching claim. */
#include "types.h"
#include "deps/0214e8f4_func_0214e8f4.h"

void func_0214e8f4(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  
  uVar2 = Os_DisableIrq();
  iVar3 = Fifo_SendWord(6,0x3000000,0);
  uVar1 = uRam0214e990;
  if (-1 < iVar3) {
    *(ushort *)(uRam0214e990 + 0x36) = *(ushort *)(uRam0214e990 + 0x36) | 1;
    *(ushort *)(uVar1 + 0x34) = *(ushort *)(uVar1 + 0x34) & 0xfffe;
    Os_RestoreIrq(uVar2);
    return;
  }
  Os_RestoreIrq(uVar2);
  pcVar4 = (code *)(*(uint *)(uRam0214e990 & 0xfffffffc) >> (uRam0214e990 & 3) * 8 |
                   *(uint *)(uRam0214e990 & 0xfffffffc) << (uRam0214e990 & 3) * -8 + 0x20);
  *(ushort *)(uRam0214e990 + 0x34) = *(ushort *)(uRam0214e990 + 0x34) | 1;
  if (pcVar4 == (code *)0x0) {
    return;
  }
  (*pcVar4)(0,4,0);
  return;
}

