/* Decompiled C draft; module arm9; ROM address 02145d44. No matching claim. */
#include "types.h"
#include "deps/02145d44_MaybeInitializeBackup.h"

bool MaybeInitializeBackup(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  
  uVar1 = uRam02145e84;
  Os_ReferSymbol(uRam02145e80);
  if (param_1 == 0) {
    Os_Terminate();
  }
  EnsureCardEnabled();
  uVar2 = Os_DisableIrq();
  uVar3 = uVar1 + 0x114 & 3;
  uVar4 = *(uint *)(uVar1 + 0x114 & 0xfffffffc);
  if (((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 4) != 0) {
    do {
      Os_Thread_Sleep(uVar1 + 0x10c);
      uVar3 = uVar1 + 0x114 & 3;
      uVar4 = *(uint *)(uVar1 + 0x114 & 0xfffffffc);
    } while (((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 4) != 0);
  }
  uVar3 = uVar1 + 0x114 & 3;
  uVar4 = *(uint *)(uVar1 + 0x114 & 0xfffffffc);
  *(uint *)(uVar1 + 0x114) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20 | 4;
  *(undefined4 *)(uVar1 + 0x38) = 0;
  *(undefined4 *)(uVar1 + 0x3c) = 0;
  Os_RestoreIrq(uVar2);
  func_02145b54(param_1);
  uVar3 = iRam02145e88 + 4U & 3;
  uVar4 = *(uint *)(iRam02145e88 + 4U & 0xfffffffc);
  *(uint *)(uRam02145e84 + 0x104) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  Card_Request(uVar1,2,1);
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xc) = 0;
  *(uint *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10) = uVar1 + 0x120;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x14) = 1;
  Card_Request(uVar1,6);
  uVar3 = uVar1 + 0x38 & 3;
  uVar4 = *(uint *)(uVar1 + 0x38 & 0xfffffffc);
  pcVar7 = (code *)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
  uVar3 = uVar1 + 0x3c & 3;
  uVar6 = *(uint *)(uVar1 + 0x3c & 0xfffffffc);
  uVar2 = Os_DisableIrq();
  uVar4 = uVar1 + 0x114 & 3;
  uVar5 = *(uint *)(uVar1 + 0x114 & 0xfffffffc);
  *(uint *)(uVar1 + 0x114) = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xffffffb3;
  Os_Thread_WakeUp((uint *)(uintptr_t)(uVar1 + 0x10c));
  uVar4 = uVar1 + 0x114 & 3;
  uVar5 = *(uint *)(uVar1 + 0x114 & 0xfffffffc);
  if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x10) != 0) {
    Os_Thread_WakeUpDirect(uVar1 + 0x44);
  }
  Os_RestoreIrq(uVar2);
  if (pcVar7 != (code *)0x0) {
    (*pcVar7)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
  }
  uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  return uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0;
}

