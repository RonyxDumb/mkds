/* Decompiled C draft; module arm9; ROM address 0200399c. No matching claim. */
#include "types.h"
#include "deps/0200399c_Fs_File_DefaultOperation_SeekDirectory.h"

undefined4 Fs_File_DefaultOperation_SeekDirectory(int param_1)

{
  uint uVar1;
  uint uVar2;
  int local_20;
  undefined2 local_1c;
  ushort local_1a;
  uint local_18;
  int local_14;
  uint uVar3;
  
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = uVar3 + 0x34 & 3;
  uVar2 = *(uint *)(uVar3 + 0x34 & 0xfffffffc);
  local_14 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) +
             (uint)*(ushort *)(param_1 + 0x34) * 8;
  local_18 = uVar3;
  Fs_SyncReader_Read((uint)(uintptr_t)(&local_18),(undefined4)(uintptr_t)(&local_20),8);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x38);
  if ((*(short *)(param_1 + 0x36) == 0) &&
     (uVar1 = param_1 + 0x38U & 3, uVar2 = *(uint *)(param_1 + 0x38U & 0xfffffffc),
     uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0)) {
    *(undefined2 *)(param_1 + 0x26) = local_1c;
    uVar1 = uVar3 + 0x34 & 3;
    uVar2 = *(uint *)(uVar3 + 0x34 & 0xfffffffc);
    *(uint *)(param_1 + 0x28) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + local_20;
  }
  *(uint *)(param_1 + 0x2c) = uRam02003a30 & local_1a;
  return 0;
}

