/* Decompiled C draft; module arm7; ROM address 06007980. No matching claim. */
#include "types.h"
#include "deps/06007980_FUN_06007980.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_06007980(uint param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  ushort local_228 [2];
  uint uStack_224;
  undefined4 local_220;
  undefined1 auStack_21c [516];
  
  iVar2 = FUN_06000680();
  uVar4 = iVar2 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  thunk_FUN_037faf70();
  uVar5 = *(ushort *)(uVar3 + 0x17e);
  uVar1 = *(undefined2 *)(uVar3 + 0x86);
  thunk_FUN_037faf84();
  uVar4 = DAT_06007b20;
  local_228[0] = 0;
  if (*(short *)(uVar3 + 0x88) == 1) {
    *(undefined2 *)(uVar3 + 0x88) = 0;
    param_1 = uVar4;
  }
  if (*(short *)(uVar3 + 0x9a) == 0) {
    iVar2 = FUN_06007394(param_1,(uint)uVar5,uVar1,local_228);
    if (iVar2 == 1) {
      return;
    }
    uVar4 = *(ushort *)(uVar3 + 400) + 2;
    if (*(short *)(uVar3 + 0x92) == 1) {
      param_1 = uStack_224;
    }
    param_1 = param_1 & uVar5;
    uVar5 = (ushort)param_1;
    if ((*(short *)(uVar3 + 0x36) == 1) || (*(short *)(uVar3 + 0x38) == 1)) {
      FUN_06006a10(local_220,uVar4,param_1);
      local_228[0] = local_228[0] | 0x8000;
    }
  }
  else {
    uVar4 = 0;
    *(undefined2 *)(uVar3 + 0x9a) = 0;
    local_220 = 0;
    local_228[0] = 0;
    thunk_FUN_037faf70();
    *(short *)(uVar3 + 0x36) = *(short *)(uVar3 + 0x36) + 1;
    *(short *)(uVar3 + 0x38) = *(short *)(uVar3 + 0x38) + 1;
    thunk_FUN_037faf84();
  }
  FUN_06002658(auStack_21c,0,0,uVar4 & 0xffff);
  *(ushort *)(uVar3 + 0x3c) = uVar5;
  *(ushort *)(uVar3 + 0x3e) = local_228[0];
  *(short *)(uVar3 + 0x40) = (short)uVar4;
  *(short *)(uVar3 + 0x42) = (short)local_220;
  return;
}

