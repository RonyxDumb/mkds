/* Decompiled C draft; module arm9; ROM address 020e1e98. No matching claim. */
#include "types.h"
#include "deps/020e1e98_func_020e1e98.h"

void func_020e1e98(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_r1;
  undefined4 *puVar4;
  
  func_020d90a8(param_1 + 0xd8,*(undefined2 *)(param_1 + 0xfc),1);
  func_020d8b18(param_1 + 0xd8,param_1 + 4,param_1 + 0x10);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(param_1 + 0x14) = 0;
  puVar1 = puRam020e1f34;
  uVar3 = puRam020e1f34[1];
  puVar4 = puRam020e1f34 + 2;
  *(undefined4 *)(param_1 + 0xb4) = *puRam020e1f34;
  *(undefined4 *)(param_1 + 0xb8) = uVar3;
  uVar3 = puVar1[3];
  *(undefined4 *)(param_1 + 0xbc) = *puVar4;
  *(undefined4 *)(param_1 + 0xc0) = uVar3;
  iVar2 = func_02148538(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x18),
                        param_1 + 0xc4,puVar1 + 4);
  Multiply64(iVar2,iVar2 >> 0x1f,uRam020e1f38,uRam020e1f3c);
  func_020d79b0(param_1 + 0xb4,(uint)((extraout_r1 + iRam020e1f40) * 0x10) >> 0x10,param_1 + 0xa4);
  func_01ffccd0(param_1 + 0x28,param_1 + 0xa4);
  *(undefined2 *)(param_1 + 0xfe) = 0;
  *(undefined2 *)(param_1 + iRam020e1f48) = *(undefined2 *)(param_1 + iRam020e1f44);
  *(undefined2 *)(param_1 + iRam020e1f4c) = 0;
  LightInfo_SomeFn(param_1 + iRam020e1f50,1);
  return;
}

