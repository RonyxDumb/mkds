/* Decompiled C draft; module arm9; ROM address 02044060. No matching claim. */
#include "types.h"
#include "deps/02044060_LoadStaffGhost.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LoadStaffGhost(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar6;
  undefined1 auStack_90 [132];
  uint uVar5;
  
  uVar3 = uRam02044194;
  iVar6 = 0;
  uVar4 = (*(uint *)(uRam02044194 & 0xfffffffc) >> (uRam02044194 & 3) * 8 |
          *(uint *)(uRam02044194 & 0xfffffffc) << (uRam02044194 & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar4 = uVar5 + 8;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(uVar5 + 8) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xfffffffe;
  uVar4 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x1c;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar4 = uVar5 + 8;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(uVar5 + 8) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xfffffffe;
  uVar4 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x14;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar4 = uVar5 + 8;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(uVar5 + 8) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xfffffffe;
  uVar4 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar4 = uVar5 + 8;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(uVar5 + 8) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xfffffffe;
  uVar4 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x1c;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar4 = uVar5 + 8;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(uVar5 + 8) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xfffffffe;
  uVar4 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x14;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar3 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar4 = uVar3 + 8;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(uVar3 + 8) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xfffffffe;
  func_02056700();
  WaitForWorkerTask();
  uVar4 = (*(uint *)(uRam02044198 & 0xfffffffc) >> (uRam02044198 & 3) * 8 |
          *(uint *)(uRam02044198 & 0xfffffffc) << (uRam02044198 & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0) {
    func_02145d38();
  }
  uVar4 = (*(uint *)(uRam02044198 & 0xfffffffc) >> (uRam02044198 & 3) * 8 |
          *(uint *)(uRam02044198 & 0xfffffffc) << (uRam02044198 & 3) * -8 + 0x20) + 4;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0) {
    uVar4 = (*(uint *)(uRam02044194 & 0xfffffffc) >> (uRam02044194 & 3) * 8 |
            *(uint *)(uRam02044194 & 0xfffffffc) << (uRam02044194 & 3) * -8 + 0x20) + 0x14;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar3 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    uVar4 = uVar3 + 8;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(uVar3 + 8) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xfffffffe;
  }
  iVar2 = FindFormatGhostBinPath(param_1,(undefined4)(uintptr_t)(auStack_90),0x80);
  if (iVar2 != 0) {
    iVar6 = GetReadStaffGhost_from_thumb((undefined4)(uintptr_t)(auStack_90));
  }
  if (iVar6 == 0) {
    Mem_CpuFill8(0,0,0x1000);
    _SupervisorCall = _SupervisorCall & 0xfffffffe;
    return;
  }
  return;
}

