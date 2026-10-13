/* Decompiled C draft; module arm9; ROM address 0214d830. No matching claim. */
#include "types.h"
#include "deps/0214d830_Fifo_Initialize.h"

void Fifo_Initialize(void)

{
  ushort uVar1;
  ushort *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar3 = Os_DisableIrq();
  iVar5 = iRam0214d924;
  if (*psRam0214d920 == 0) {
    *psRam0214d920 = 1;
    iVar4 = 0;
    *(undefined4 *)(iVar5 + 0x388) = 0;
    iVar5 = iRam0214d928;
    do {
      *(undefined4 *)(iVar5 + iVar4 * 4) = 0;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x20);
    *puRam0214d930 = (short)uRam0214d92c;
    SetIF(0x40000);
    Os_SetIrqHandler(0x40000,uRam0214d934);
    Os_EnableIrqHandler(0x40000);
    puVar2 = puRam0214d938;
    iVar5 = 0;
    while( true ) {
      uVar1 = *puVar2;
      uVar6 = uVar1 & 0xf;
      *puVar2 = (ushort)(uVar6 << 8);
      if (((uVar1 & 0xf) == 0) && (4 < iVar5)) break;
      iVar4 = 1000;
      uVar1 = *puVar2;
      while ((uVar1 & 0xf) == uVar6) {
        if (iVar4 < 1) {
          iVar5 = 0;
          break;
        }
        iVar4 = iVar4 + -1;
        uVar1 = *puVar2;
      }
      iVar5 = iVar5 + 1;
    }
  }
  Os_RestoreIrq(uVar3);
  return;
}

