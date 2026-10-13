/* Decompiled C draft; module arm9; ROM address 02145f80. No matching claim. */
#include "types.h"
#include "deps/02145f80_Card_BackupCommandTask.h"

void Card_BackupCommandTask(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  code *pcVar9;
  uint uVar10;
  uint uVar12;
  uint uVar8;
  uint uVar11;
  
  uVar1 = param_1 + 0x2c & 3;
  uVar12 = *(uint *)(param_1 + 0x2c & 0xfffffffc);
  uVar3 = param_1 + 0x34 & 3;
  uVar10 = *(uint *)(param_1 + 0x34 & 0xfffffffc);
  uVar11 = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 0x30 & 3;
  uVar10 = *(uint *)(param_1 + 0x30 & 0xfffffffc);
  Os_ReferSymbol(uRam02146138);
  iVar6 = param_1 + 0x120;
  do {
    uVar8 = param_1 + 0x24 & 3;
    uVar7 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    if (0x100 < uVar8) {
      uVar8 = 0x100;
    }
    *(uint *)((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
              *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x14) = uVar8;
    uVar7 = param_1 + 0x114 & 3;
    uVar2 = *(uint *)(param_1 + 0x114 & 0xfffffffc);
    if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x40) != 0) {
      uVar1 = param_1 + 0x114 & 3;
      uVar3 = *(uint *)(param_1 + 0x114 & 0xfffffffc);
      *(uint *)(param_1 + 0x114) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xffffffbf;
      *(undefined4 *)
       (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) = 7;
      break;
    }
    if (uVar11 == 0) {
      DC_InvalidateRangeNoClean(param_1 + 0x120,uVar8);
      uVar7 = param_1 + 0x1c & 3;
      uVar2 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
      *(uint *)((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0xc) =
           uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
      *(int *)((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x10) = iVar6;
    }
    else {
      uVar7 = param_1 + 0x1c & 3;
      uVar2 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
      Mem_CpuCopy8(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20,iVar6,uVar8);
      Arm_FlushRange(param_1 + 0x120,uVar8);
      Mem_DcDrainWriteBuffer();
      *(int *)((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0xc) = iVar6;
      uVar7 = param_1 + 0x20 & 3;
      uVar2 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
      *(uint *)((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x10) =
           uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
    }
    iVar4 = Card_Request(param_1,uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20,
                         uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20);
    if (iVar4 == 0) break;
    if (uVar11 == 2) {
      iVar4 = Card_Request(param_1,9,1);
      if (iVar4 == 0) break;
    }
    else if (uVar11 == 0) {
      uVar7 = param_1 + 0x20 & 3;
      uVar2 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
      Mem_CpuCopy8(param_1 + 0x120,uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20,uVar8);
    }
    uVar7 = param_1 + 0x1c & 3;
    uVar2 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
    *(uint *)(param_1 + 0x1c) = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + uVar8;
    uVar7 = param_1 + 0x20 & 3;
    uVar2 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
    *(uint *)(param_1 + 0x20) = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + uVar8;
    uVar7 = param_1 + 0x24 & 3;
    uVar2 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
    *(uint *)(param_1 + 0x24) = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) - uVar8;
    uVar8 = param_1 + 0x24 & 3;
    uVar7 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
  } while (uVar7 >> uVar8 * 8 != 0 || uVar7 << uVar8 * -8 + 0x20 != 0);
  uVar1 = param_1 + 0x38 & 3;
  uVar3 = *(uint *)(param_1 + 0x38 & 0xfffffffc);
  pcVar9 = (code *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  uVar1 = param_1 + 0x3c & 3;
  uVar11 = *(uint *)(param_1 + 0x3c & 0xfffffffc);
  uVar5 = Os_DisableIrq();
  uVar3 = param_1 + 0x114 & 3;
  uVar10 = *(uint *)(param_1 + 0x114 & 0xfffffffc);
  *(uint *)(param_1 + 0x114) = (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) & 0xffffffb3;
  Os_Thread_WakeUp(param_1 + 0x10c);
  uVar3 = param_1 + 0x114 & 3;
  uVar10 = *(uint *)(param_1 + 0x114 & 0xfffffffc);
  if (((uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) & 0x10) != 0) {
    Os_Thread_WakeUpDirect(param_1 + 0x44);
  }
  Os_RestoreIrq(uVar5);
  if (pcVar9 == (code *)0x0) {
    return;
  }
  (*pcVar9)(uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20);
  return;
}

