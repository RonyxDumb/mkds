/* Decompiled C draft; module arm9; ROM address 020ea618. No matching claim. */
#include "types.h"
#include "deps/020ea618_func_020ea618.h"

void func_020ea618(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  uVar1 = *(ushort *)(param_1 + 0x6e);
  if (param_2 < (int)(uint)uVar1) {
    uVar2 = *(undefined2 *)(param_1 + 0x6c);
    uVar3 = func_020d3c44();
    *(undefined2 *)(param_1 + 0x6c) = uVar3;
    *(short *)(param_1 + 0x6e) = (short)param_2;
    func_0207ad88(param_1);
    *(undefined2 *)(param_1 + 0x6c) = uVar2;
    *(ushort *)(param_1 + 0x6e) = uVar1;
    return;
  }
  func_0207ad88();
  return;
}

