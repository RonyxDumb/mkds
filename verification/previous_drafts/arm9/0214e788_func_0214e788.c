/* Decompiled C draft; module arm9; ROM address 0214e788. No matching claim. */
#include "types.h"
#include "deps/0214e788_func_0214e788.h"

void func_0214e788(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  code *pcVar7;
  uint uVar8;
  
  uVar3 = uRam0214e890;
  uVar8 = 0;
  *(undefined4 *)(uRam0214e890 + 0x10) = param_3;
  *(undefined2 *)(uVar3 + 0xc) = 0;
  *(short *)(uVar3 + 0xe) = (short)param_2;
  *(short *)(uVar3 + 0x14) = (short)param_4;
  if (param_4 != 0) {
    do {
      uVar1 = uVar3 + 0x10 & 3;
      uVar4 = *(uint *)(uVar3 + 0x10 & 0xfffffffc);
      iVar6 = uVar8 * 8;
      uVar8 = uVar8 + 1;
      *(undefined2 *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + iVar6 + 4) = 0;
    } while (uVar8 < param_4);
  }
  uVar5 = Os_DisableIrq();
  iVar6 = Fifo_SendWord(6,param_2 & 0xff | uRam0214e894,0);
  if (iVar6 < 0) {
    bVar2 = false;
  }
  else {
    iVar6 = Fifo_SendWord(6,param_1 | uRam0214e898,0);
    if (iVar6 < 0) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
  }
  uVar3 = uRam0214e890;
  if (!bVar2) {
    Os_RestoreIrq(uVar5);
    pcVar7 = (code *)(*(uint *)(uRam0214e890 & 0xfffffffc) >> (uRam0214e890 & 3) * 8 |
                     *(uint *)(uRam0214e890 & 0xfffffffc) << (uRam0214e890 & 3) * -8 + 0x20);
    *(ushort *)(uRam0214e890 + 0x34) = *(ushort *)(uRam0214e890 + 0x34) | 2;
    if (pcVar7 == (code *)0x0) {
      return;
    }
    (*pcVar7)(1,4,0);
    return;
  }
  *(ushort *)(uRam0214e890 + 0x36) = *(ushort *)(uRam0214e890 + 0x36) | 2;
  *(ushort *)(uVar3 + 0x34) = *(ushort *)(uVar3 + 0x34) & 0xfffd;
  Os_RestoreIrq(uVar5);
  return;
}

