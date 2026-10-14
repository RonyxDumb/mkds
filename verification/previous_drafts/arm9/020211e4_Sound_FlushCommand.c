/* Decompiled C draft; module arm9; ROM address 020211e4. No matching claim. */
#include "types.h"
#include "deps/020211e4_Sound_FlushCommand.h"

undefined4 Sound_FlushCommand(uint param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  
  uVar5 = Os_DisableIrq();
  if (*(uint *)((uint)puRam02021388 & 0xfffffffc) >> ((uint)puRam02021388 & 3) * 8 == 0 &&
      *(uint *)((uint)puRam02021388 & 0xfffffffc) << ((uint)puRam02021388 & 3) * -8 + 0x20 == 0) {
    Os_RestoreIrq();
    return 1;
  }
  if (7 < (int)(*(uint *)((uint)piRam0202138c & 0xfffffffc) >> ((uint)piRam0202138c & 3) * 8 |
               *(uint *)((uint)piRam0202138c & 0xfffffffc) << ((uint)piRam0202138c & 3) * -8 + 0x20)
     ) {
    if ((param_1 & 1) == 0) {
      Os_RestoreIrq();
      return 0;
    }
    do {
      Sound_CommandReceiveAndReply(1);
    } while (7 < (int)(*(uint *)((uint)piRam0202138c & 0xfffffffc) >> ((uint)piRam0202138c & 3) * 8
                      | *(uint *)((uint)piRam0202138c & 0xfffffffc) <<
                        ((uint)piRam0202138c & 3) * -8 + 0x20));
  }
  Arm_FlushRange(uRam02021390,0x1800);
  iVar6 = Fifo_SendWord(7,*(uint *)((uint)puRam02021388 & 0xfffffffc) >>
                          ((uint)puRam02021388 & 3) * 8 |
                          *(uint *)((uint)puRam02021388 & 0xfffffffc) <<
                          ((uint)puRam02021388 & 3) * -8 + 0x20,0);
  if (iVar6 < 0) {
    if ((param_1 & 1) == 0) {
      Os_RestoreIrq(uVar5);
      return 0;
    }
    iVar6 = Fifo_SendWord(7,*(uint *)((uint)puRam02021388 & 0xfffffffc) >>
                            ((uint)puRam02021388 & 3) * 8 |
                            *(uint *)((uint)puRam02021388 & 0xfffffffc) <<
                            ((uint)puRam02021388 & 3) * -8 + 0x20,0);
    puVar2 = puRam02021388;
    while (iVar6 < 0) {
      Os_RestoreIrq(uVar5);
      Os_SpinWait(100);
      uVar5 = Os_DisableIrq();
      uVar1 = (uint)puVar2 & 3;
      uVar7 = *(uint *)((uint)puVar2 & 0xfffffffc);
      iVar6 = Fifo_SendWord(7,uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20,0);
    }
  }
  if ((param_1 & 2) != 0) {
    SoundInternal_RequestCommandProc();
  }
  iVar6 = iRam02021398;
  piVar4 = piRam02021394;
  uVar7 = *(uint *)((uint)piRam02021394 & 0xfffffffc) >> ((uint)piRam02021394 & 3) * 8 |
          *(uint *)((uint)piRam02021394 & 0xfffffffc) << ((uint)piRam02021394 & 3) * -8 + 0x20;
  uVar1 = (uint)puRam02021388 & 3;
  uVar9 = *(uint *)((uint)puRam02021388 & 0xfffffffc);
  iVar8 = uVar7 + 1;
  *piRam02021394 = iVar8;
  *(uint *)(iVar6 + uVar7 * 4) = uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20;
  piVar3 = piRam0202138c;
  bVar11 = SBORROW4(iVar8,8);
  bVar10 = iVar8 != 8;
  if (8 < iVar8) {
    iVar8 = 0;
  }
  if (bVar10 && (int)(uVar7 - 7) < 0 == bVar11) {
    *piVar4 = iVar8;
  }
  puVar2 = puRam020213a0;
  piVar4 = piRam0202139c;
  uVar9 = *(uint *)((uint)piVar3 & 0xfffffffc);
  uVar1 = (uint)piRam0202139c & 3;
  uVar7 = *(uint *)((uint)piRam0202139c & 0xfffffffc);
  *puRam02021388 = 0;
  *puVar2 = 0;
  *piVar3 = (uVar9 >> ((uint)piVar3 & 3) * 8 | uVar9 << ((uint)piVar3 & 3) * -8 + 0x20) + 1;
  *piVar4 = (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) + 1;
  Os_RestoreIrq(uVar5);
  return 1;
}

