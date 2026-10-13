/* Decompiled C draft; module arm9; ROM address 0200388c. No matching claim. */
#include "types.h"
#include "deps/0200388c_Fs_File_DefaultOperation_ReadDirectory.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 Fs_File_DefaultOperation_ReadDirectory(int param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte local_18 [2];
  ushort uStack_16;
  uint local_14;
  uint local_10;
  uint *puVar5;
  
  uVar3 = param_1 + 0x30U & 3;
  uVar4 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
  puVar5 = (uint *)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
  uVar3 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  local_14 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 0x28U & 3;
  uVar4 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  local_10 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  Fs_SyncReader_Read((uint)(uintptr_t)(&local_14),(undefined4)(uintptr_t)(local_18),1);
  puVar5[4] = local_18[0] & 0x7f;
  puVar5[3] = (int)(uint)local_18[0] >> 7;
  uVar3 = (uint)(puVar5 + 4) & 3;
  uVar4 = *(uint *)((uint)(puVar5 + 4) & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    uVar4 = param_1 + 0x34U & 3;
    uVar2 = *(uint *)(param_1 + 0x34U & 0xfffffffc);
    if (uVar2 >> uVar4 * 8 == 0 && uVar2 << uVar4 * -8 + 0x20 == 0) {
      Fs_SyncReader_Read(&local_14,puVar5 + 5);
      uVar3 = (uint)(puVar5 + 4) & 3;
      uVar4 = *(uint *)((uint)(puVar5 + 4) & 0xfffffffc);
      *(undefined1 *)((int)puVar5 + (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x14) = 0;
    }
    else {
      local_10 = local_10 + uVar3;
    }
    uVar3 = (uint)(puVar5 + 3) & 3;
    uVar4 = *(uint *)((uint)(puVar5 + 3) & 0xfffffffc);
    if (uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0) {
      uVar3 = param_1 + 8U & 3;
      uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
      *puVar5 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
      puVar5[1] = (uint)*(ushort *)(param_1 + 0x26);
      *(short *)(param_1 + 0x26) = *(short *)(param_1 + 0x26) + 1;
    }
    else {
      Fs_SyncReader_Read((uint)(uintptr_t)(&local_14),(undefined4)(uintptr_t)(&uStack_16),2);
      uVar3 = param_1 + 8U & 3;
      uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
      uVar1 = (ushort)uRam02003998;
      *puVar5 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
      *(ushort *)(puVar5 + 1) = uStack_16 & uVar1;
      *(undefined2 *)((int)puVar5 + 6) = 0;
      puVar5[2] = 0;
    }
    *(uint *)(param_1 + 0x28) = local_10;
    return 0;
  }
  return 1;
}

