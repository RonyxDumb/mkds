/* Decompiled C draft; module arm9; ROM address 0202b4bc. No matching claim. */
#include "types.h"
#include "deps/0202b4bc_func_0202b4bc.h"

void func_0202b4bc(int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *piRam0202b54c;
  if (param_1 == 1) {
    if (param_3 == 0) {
      uVar1 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar2 + 0x8c),0x1a);
    }
    else {
      uVar1 = func_02025d5c(*(undefined4 *)(iRam0202b550 + (param_3 + -1) * 4));
      uVar1 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0202b54c + 0x8c),uVar1);
    }
    func_0212426c(1,param_2,*(undefined4 *)(iVar2 + 0x78),uVar1,*(undefined4 *)(iVar2 + 0x70),
                  *(undefined4 *)(iVar2 + 0x7c));
    return;
  }
  if (param_1 == 0) {
    iVar3 = 0;
    do {
      if (iVar3 == param_4) {
        uVar1 = 0xe;
      }
      else {
        uVar1 = 0xf;
      }
      func_02124100(iVar3,uVar1,*(undefined4 *)(iVar2 + 0x78),*(undefined4 *)(iVar2 + 0x7c),
                    *(undefined4 *)(iVar2 + 0x70));
      iVar3 = iVar3 + 1;
    } while (iVar3 < 7);
  }
  return;
}

