/* Decompiled C draft; module arm9; ROM address 0214cc04. No matching claim. */
#include "types.h"
#include "deps/0214cc04_Mem_DmaFill32.h"

void Mem_DmaFill32(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_4 != 0) {
    uVar3 = iRam0214cc8c + (param_1 * 3 + 2) * 4;
    do {
    } while (((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & 0x80000000) != 0);
    uVar1 = Os_DisableIrq();
    iVar2 = iRam0214cc90 + param_1 * 4;
    *(undefined4 *)(param_1 * 4 + 0x40000e0) = param_3;
    func_01fffe2c(param_1,iVar2,param_2,param_4 >> 2 | 0x85000000);
    Os_RestoreIrq(uVar1);
    do {
    } while (((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & 0x80000000) != 0);
    return;
  }
  return;
}

