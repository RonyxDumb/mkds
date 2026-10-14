/* Decompiled C draft; module arm9; ROM address 02004090. No matching claim. */
#include "types.h"
#include "deps/02004090_Fs_UnregisterArchive.h"

void Fs_UnregisterArchive(undefined4 *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 != 0 ||
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 != 0) {
    Os_DisableIrq();
    uVar4 = (uint)(param_1 + 1) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if (uVar4 != 0) {
      uVar3 = (uint)(param_1 + 2) & 3;
      uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      *(uint *)(uVar4 + 8) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    }
    uVar4 = (uint)(param_1 + 2) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if (uVar4 != 0) {
      uVar3 = (uint)(param_1 + 1) & 3;
      uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
      *(uint *)(uVar4 + 4) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    }
    *param_1 = 0;
    param_1[2] = 0;
    puVar1 = puRam02004120;
    uVar4 = (uint)(param_1 + 2) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    param_1[1] = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar4 = (uint)(param_1 + 7) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
    param_1[7] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xfffffffe;
    uVar4 = uRam02004124;
    if ((undefined4 *)
        (*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
        *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) == param_1) {
      puVar1[2] = 0;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      *(undefined2 *)((int)puVar1 + 6) = 0;
      *puVar1 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
      *(undefined2 *)(puVar1 + 1) = 0;
    }
    Os_RestoreIrq();
    return;
  }
  return;
}

