/* Decompiled C draft; module arm9; ROM address 02050650. No matching claim. */
#include "types.h"
#include "deps/02050650_func_02050650.h"

bool func_02050650(int param_1,ushort param_2,undefined4 param_3,int param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(uRam0205075c & 0xfffffffc) >> (uRam0205075c & 3) * 8 |
          *(uint *)(uRam0205075c & 0xfffffffc) << (uRam0205075c & 3) * -8 + 0x20;
  if (uVar3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  }
  if (uVar1 == 1) {
    if (*(char *)(uVar3 + 0x87) == '\0') {
      return false;
    }
  }
  else if ((uVar1 == 2) && (*(ushort *)(uVar3 + 0x432) == uRam02050760)) {
    return false;
  }
  if (*(ushort *)(param_5 + 4) < param_2) {
    param_2 = *(ushort *)(param_5 + 4);
  }
  Arm_FlushRange(param_1,param_2);
  if (param_4 != 0) {
    Mem_CpuCopy8(param_1,param_4,param_2);
    Arm_FlushRange(param_4,param_2);
    param_1 = param_4;
  }
  iVar2 = func_02144048(*(uint *)(param_5 & 0xfffffffc) >> (param_5 & 3) * 8 |
                        *(uint *)(param_5 & 0xfffffffc) << (param_5 & 3) * -8 + 0x20,0,param_1,
                        param_2);
  return iVar2 == 2;
}

