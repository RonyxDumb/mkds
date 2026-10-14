/* Decompiled C draft; module arm9; ROM address 02003234. No matching claim. */
#include "types.h"
#include "deps/02003234_Fs_File_DefaultOperation_OpenFileById.h"

undefined4 Fs_File_DefaultOperation_OpenFileById(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  int iStack_14;
  
  uVar1 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uStack_18 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x34U & 3;
  uVar4 = *(uint *)(param_1 + 0x34U & 0xfffffffc);
  uVar5 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar4 = uStack_18 + 0x30 & 3;
  uVar2 = *(uint *)(uStack_18 + 0x30 & 0xfffffffc);
  uVar1 = uVar5 * 8;
  if (uVar1 < (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20)) {
    uVar4 = uStack_18 + 0x2c & 3;
    uVar2 = *(uint *)(uStack_18 + 0x2c & 0xfffffffc);
    iStack_14 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + uVar1;
    Fs_SyncReader_Read((uint)(uintptr_t)(&uStack_18),(undefined4)(uintptr_t)(&uStack_20),8);
    *(undefined4 *)(param_1 + 0x30) = uStack_20;
    *(undefined4 *)(param_1 + 0x34) = uStack_1c;
    *(uint *)(param_1 + 0x38) = uVar5;
    uVar3 = Fs_File_DoExecuteOperation(param_1,7);
    return uVar3;
  }
  return 1;
}

