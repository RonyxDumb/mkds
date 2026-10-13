/* Decompiled C draft; module arm9_ov001; ROM address 0218cdb8. No matching claim. */
#include "types.h"
#include "deps/0218cdb8_FUN_0218cdb8.h"

void FUN_0218cdb8(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = func_0x020d34d4(param_1,DAT_0218ce28);
  iVar2 = func_0x020d34d4(param_1,DAT_0218ce28);
  iVar3 = func_0x020d34d4(param_1,DAT_0218ce28);
  iVar4 = func_0x020d34d4(param_1,DAT_0218ce28);
  *(int *)(iVar1 + 0xa4) = param_1;
  *(int *)(iVar2 + 0xa4) = iVar1;
  *(int *)(iVar3 + 0xa4) = iVar2;
  *(int *)(iVar4 + 0xa4) = iVar3;
  func_0x020364e8();
  uVar5 = func_0x020364e0();
  uVar5 = func_0x02036bec(uVar5,0x44);
  *(undefined4 *)(param_1 + 0x94) = uVar5;
  func_0x02109110(*(undefined4 *)(param_1 + 0x94),0xd,param_1 + 4);
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(DAT_0218ce2c + 0x74);
  return;
}

