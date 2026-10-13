/* Decompiled C draft; module arm9; ROM address 020082b4. No matching claim. */
#include "types.h"
#include "deps/020082b4_func_020082b4.h"

void func_020082b4(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 local_18;
  
  local_18 = uRam02008304;
  iVar1 = param_2 + iRam02008308;
  *param_1 = *(undefined4 *)(param_2 + 0x24);
  param_1[1] = *(undefined4 *)(param_2 + 0x34);
  puVar2 = param_1 + 3;
  iVar4 = 0;
  iVar3 = iRam0200830c;
  do {
    func_02008188(param_2,iVar3,puVar2,&local_18);
    puVar2 = puVar2 + 4;
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  Mem_CpuCopy8(iVar1,param_1 + 0xf,0x88);
  return;
}

