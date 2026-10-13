/* Decompiled C draft; module arm9_ov001; ROM address 021850b4. No matching claim. */
#include "types.h"
#include "deps/021850b4_FUN_021850b4.h"

int FUN_021850b4(ushort *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 < 1) {
    uVar1 = func_0x02132440(param_3 << 0xc);
    func_0x021329f8(uVar1,DAT_0218515c);
  }
  else {
    uVar1 = func_0x02132440(param_3 << 0xc);
    func_0x02131234(DAT_0218515c,uVar1);
  }
  iVar2 = func_0x021322c8();
  if (param_4 < 1) {
    uVar1 = func_0x02132440(param_4 << 0xc);
    func_0x021329f8(uVar1,DAT_0218515c);
  }
  else {
    uVar1 = func_0x02132440(param_4 << 0xc);
    func_0x02131234(DAT_0218515c,uVar1);
  }
  iVar3 = func_0x021322c8();
  if (param_2 < (int)(uint)*param_1) {
    iVar4 = *(int *)(param_1 + 2) + param_2 * 0x88;
    do {
      if ((((*(int *)(iVar4 + 4) + *(int *)(iVar4 + 0x1c) < iVar2) &&
           (iVar2 < *(int *)(iVar4 + 4) + *(int *)(iVar4 + 0x20))) &&
          (*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0x24) < iVar3)) &&
         (iVar3 < *(int *)(iVar4 + 8) + *(int *)(iVar4 + 0x28))) {
        return param_2;
      }
      iVar4 = iVar4 + 0x88;
      param_2 = param_2 + 1;
    } while (param_2 < (int)(uint)*param_1);
  }
  return -1;
}

