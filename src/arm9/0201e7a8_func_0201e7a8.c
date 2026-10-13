/* Decompiled C draft; module arm9; ROM address 0201e7a8. No matching claim. */
#include "types.h"
#include "deps/0201e7a8_func_0201e7a8.h"

undefined4 func_0201e7a8(int param_1,int param_2,undefined4 param_3)

{
  short sVar1;
  short *psVar2;
  int *piVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  
  func_0214d5b8();
  iVar7 = Fifo_IsHandlerReady(0xf,1);
  psVar2 = psRam0201ea10;
  if (iVar7 == 0) {
    return 2;
  }
  sVar1 = *psRam0201ea10;
  while (sVar1 == 0) {
    iVar7 = Os_AllocateLockId();
    if (iVar7 == -3) {
      return 7;
    }
    *psVar2 = (short)iVar7;
    sVar1 = *psVar2;
  }
  uVar8 = Os_DisableIrq();
  if (*(uint *)((uint)piRam0201ea14 & 0xfffffffc) >> ((uint)piRam0201ea14 & 3) * 8 != 0 ||
      *(uint *)((uint)piRam0201ea14 & 0xfffffffc) << ((uint)piRam0201ea14 & 3) * -8 + 0x20 != 0) {
    Os_RestoreIrq();
    return 5;
  }
  if (*psRam0201ea18 != 0) {
    Os_RestoreIrq();
    return 5;
  }
  if (param_1 == 4) {
    iVar7 = func_0200ff04(4,*psRam0201ea10);
    puVar4 = puRam0201ea1c;
    if (iVar7 == 0) {
      Os_RestoreIrq(uVar8);
      return 6;
    }
    *psRam0201ea18 = 4;
    *puVar4 = 0x82;
  }
  else if (param_1 == 8) {
    iVar7 = func_0200ff04(8,*psRam0201ea10);
    puVar4 = puRam0201ea20;
    if (iVar7 == 0) {
      Os_RestoreIrq(uVar8);
      return 6;
    }
    *psRam0201ea18 = 8;
    *puVar4 = 0x82;
  }
  else {
    if (param_1 != 0xc) {
      Os_RestoreIrq();
      return 3;
    }
    iVar7 = func_0200ff04(0xc,*psRam0201ea10);
    puVar4 = puRam0201ea1c;
    if (iVar7 == 0) {
      Os_RestoreIrq(uVar8);
      return 6;
    }
    *psRam0201ea18 = 0xc;
    puVar5 = puRam0201ea20;
    *puVar4 = 0x82;
    *puVar5 = 0x8a;
  }
  iVar7 = Fifo_IsHandlerReady(0xf,0);
  if (iVar7 == 0) {
    Fifo_RegisterHandler(0xf,uRam0201ea24);
  }
  puVar6 = puRam0201ea2c;
  if (param_2 == 0) {
    *piRam0201ea14 = iRam0201ea28;
  }
  else {
    *piRam0201ea14 = param_2;
  }
  *puVar6 = param_3;
  iVar7 = Fifo_SendWord(0xf,0x10000,0);
  if (iVar7 < 0) {
    Os_UnlockVram(*psRam0201ea18,*psRam0201ea10);
    piVar3 = piRam0201ea14;
    *psRam0201ea18 = 0;
    *piVar3 = 0;
    Os_RestoreIrq(uVar8);
    return 4;
  }
  Os_RestoreIrq(uVar8);
  return 1;
}

