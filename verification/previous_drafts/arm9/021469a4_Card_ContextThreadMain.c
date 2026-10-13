/* Decompiled C draft; module arm9; ROM address 021469a4. No matching claim. */
#include "types.h"
#include "deps/021469a4_Card_ContextThreadMain.h"

void Card_ContextThreadMain(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar5;
  uint uVar4;
  
  iVar1 = iRam021469fc;
  iVar5 = iRam021469fc + 0x44;
  do {
    uVar2 = Os_DisableIrq();
    uVar4 = iVar1 + 0x114U & 3;
    uVar3 = *(uint *)(iVar1 + 0x114U & 0xfffffffc);
    for (uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20; (uVar4 & 8) == 0;
        uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) {
      *(int *)(iVar1 + 0x104) = iVar5;
      Os_Thread_Sleep(0);
      uVar4 = iVar1 + 0x114U & 3;
      uVar3 = *(uint *)(iVar1 + 0x114U & 0xfffffffc);
    }
    Os_RestoreIrq(uVar2);
    uVar4 = iVar1 + 0x40U & 3;
    uVar3 = *(uint *)(iVar1 + 0x40U & 0xfffffffc);
    (*(code *)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20))(iVar1);
  } while( true );
}

