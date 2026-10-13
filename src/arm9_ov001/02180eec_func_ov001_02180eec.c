/* Decompiled C draft; module arm9_ov001; ROM address 02180eec. No matching claim. */
#include "types.h"
#include "deps/02180eec_func_ov001_02180eec.h"

undefined4 func_ov001_02180eec(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  
  local_20 = 0;
  iVar1 = param_3 >> 0xc;
  if (param_1 >> 0xc < iVar1) {
    iVar4 = param_3 - param_1;
  }
  else if (iVar1 < param_1 >> 0xc) {
    iVar4 = param_1 - param_3;
  }
  else {
    iVar4 = 0;
  }
  iVar3 = param_4 >> 0xc;
  if (param_2 >> 0xc < iVar3) {
    local_2c = param_4 - param_2;
  }
  else if (iVar3 < param_2 >> 0xc) {
    local_2c = param_2 - param_4;
  }
  else {
    local_2c = 0;
  }
  if (iVar4 == 0) {
    local_24 = 0;
  }
  else if (iVar4 < local_2c) {
    local_24 = func_0x02147f34(param_3 - param_1,local_2c);
  }
  else if (param_1 < param_3) {
    local_24 = iRam02180ffc;
  }
  else {
    local_24 = iRam02181000;
  }
  if (local_2c == 0) {
    local_28 = 0;
  }
  else if (local_2c < iVar4) {
    local_28 = func_0x02147f34(param_4 - param_2,iVar4);
  }
  else if (param_2 < param_4) {
    local_28 = iRam02180ffc;
  }
  else {
    local_28 = iRam02181000;
  }
  if (local_2c < iVar4) {
    local_2c = iVar4;
  }
  local_2c = local_2c >> 0xc;
  iVar4 = 0;
  if (-1 < local_2c) {
    do {
      pbVar2 = (byte *)func_ov001_02181200(param_1 >> 0xc,param_2 >> 0xc);
      if ((pbVar2 != (byte *)0x0) && (*pbVar2 != param_5)) {
        local_20 = 1;
        func_ov001_021811c8();
        *pbVar2 = (byte)param_5;
      }
      iVar4 = iVar4 + 1;
      param_1 = param_1 + local_24;
      param_2 = param_2 + local_28;
    } while (iVar4 <= local_2c);
  }
  pbVar2 = (byte *)func_ov001_02181200(iVar1,iVar3);
  if ((pbVar2 != (byte *)0x0) && (*pbVar2 != param_5)) {
    local_20 = 1;
    func_ov001_021811c8();
    *pbVar2 = (byte)param_5;
  }
  return local_20;
}

