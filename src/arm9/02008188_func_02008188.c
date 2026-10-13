/* Decompiled C draft; module arm9; ROM address 02008188. No matching claim. */
#include "types.h"
#include "deps/02008188_func_02008188.h"

void func_02008188(int param_1,int *param_2,int *param_3,int *param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  iVar3 = *param_2;
  if (iVar3 == 0) {
    uVar2 = *(uint *)(param_1 + 0x28);
    if ((uRam02008290 <= uVar2) && (uVar2 < uRam02008294)) {
      if (uVar2 + *(int *)(param_1 + 0x2c) <= uRam02008294) {
        param_3[2] = *(int *)(param_1 + 0x2c);
        param_3[1] = *(int *)(param_1 + 0x28);
        *param_3 = param_3[1];
        param_3[3] = param_3[3] & 0xfffffffe;
        return;
      }
    }
    Os_Terminate();
    return;
  }
  if (iVar3 != 1) {
    if (iVar3 != 2) {
      return;
    }
    param_3[2] = iRam020082ac;
    param_3[1] = iRam020082b0;
    *param_3 = param_3[1];
    param_3[3] = param_3[3] & 0xfffffffe;
    return;
  }
  bVar5 = false;
  bVar1 = false;
  uVar2 = *(uint *)(param_1 + 0x38);
  uVar4 = uVar2 + *(uint *)(param_1 + 0x3c);
  if ((uVar2 < uRam02008290) || (uRam02008298 <= uVar2)) {
    if ((uVar2 < uRam020082a4) || (uRam020082a8 <= uVar2)) {
      bVar5 = true;
    }
    else if (uRam020082a8 < uVar4) {
      bVar5 = true;
    }
    else {
      bVar1 = true;
    }
  }
  else if (uRam0200829c < uVar4) {
    if ((uVar4 < uRam02008298) && (*(uint *)(param_1 + 0x3c) <= uRam020082a0)) {
      bVar1 = true;
    }
    else {
      bVar5 = true;
    }
  }
  if (bVar5) {
    Os_Terminate();
  }
  param_3[2] = *(int *)(param_1 + 0x3c);
  param_3[1] = *(int *)(param_1 + 0x38);
  if (bVar1) {
    *param_3 = *param_4;
    *param_4 = *param_4 + param_3[2];
  }
  else {
    *param_3 = param_3[1];
  }
  param_3[3] = param_3[3] & 0xfffffffeU | 1;
  return;
}

