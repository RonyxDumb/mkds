/* Decompiled C draft; module arm9; ROM address 020e516c. No matching claim. */
#include "types.h"
#include "deps/020e516c_func_020e516c.h"

bool func_020e516c(uint *param_1,int *param_2,undefined4 param_3,undefined2 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 auStack_3c [16];
  undefined1 auStack_2c [12];
  int local_20;
  int local_1c;
  int local_18;
  
  local_20 = *param_2;
  local_18 = param_2[2];
  local_1c = param_2[1] + iRam020e52b4;
  iVar1 = func_01ffdee4(&local_20,0,0,uRam020e52b8,8,0xfffffffe,0,auStack_2c,0,0,0,0,0,0);
  if (iVar1 == 0) {
    MTX_Identity33_(param_1);
  }
  else {
    func_020d7b88(auStack_2c,auStack_3c);
    func_01ffccd0(param_1,auStack_3c);
    iVar2 = _s32_div_f(param_3,10);
    iVar3 = iVar2 >> 0x1f;
    uVar4 = Multiply64(*param_1,(int)*param_1 >> 0x1f,iVar2,iVar3);
    *param_1 = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
    uVar4 = Multiply64(param_1[1],(int)param_1[1] >> 0x1f,iVar2,iVar3);
    param_1[1] = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
    uVar4 = Multiply64(param_1[2],(int)param_1[2] >> 0x1f,iVar2,iVar3);
    param_1[2] = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
    uVar4 = Multiply64(param_1[3],(int)param_1[3] >> 0x1f,iVar2,iVar3);
    param_1[3] = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
    uVar4 = Multiply64(param_1[4],(int)param_1[4] >> 0x1f,iVar2,iVar3);
    param_1[4] = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
    uVar4 = Multiply64(param_1[5],(int)param_1[5] >> 0x1f,iVar2,iVar3);
    param_1[5] = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
    uVar4 = Multiply64(param_1[6],(int)param_1[6] >> 0x1f,iVar2,iVar3);
    param_1[6] = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
    uVar4 = Multiply64(param_1[7],(int)param_1[7] >> 0x1f,iVar2,iVar3);
    param_1[7] = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
    uVar4 = Multiply64(param_1[8],(int)param_1[8] >> 0x1f,iVar2,iVar3);
    param_1[8] = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
  }
  param_1[9] = local_20 >> 4;
  param_1[10] = local_1c >> 4;
  param_1[0xb] = local_18 >> 4;
  *(undefined2 *)(param_1 + 0xc) = param_4;
  return iVar1 != 0;
}

