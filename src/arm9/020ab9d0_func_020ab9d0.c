/* Decompiled C draft; module arm9; ROM address 020ab9d0. No matching claim. */
#include "types.h"
#include "deps/020ab9d0_func_020ab9d0.h"

void func_020ab9d0(int param_1)

{
  int iVar1;
  
  switch(param_1) {
  case 0:
    iVar1 = *DAT_020aba8c + param_1 * 4;
    func_020a9f40(*(undefined4 *)(iVar1 + 0x28),*(undefined4 *)(iVar1 + 0x10),
                  *(undefined2 *)(DAT_020aba90 + param_1 * 2));
    break;
  case 1:
    iVar1 = *DAT_020aba8c + param_1 * 4;
    func_020a9ff4(*(undefined4 *)(iVar1 + 0x28),*(undefined4 *)(iVar1 + 0x10),
                  *(undefined2 *)(DAT_020aba90 + param_1 * 2));
    break;
  case 2:
    iVar1 = *DAT_020aba8c + param_1 * 4;
    func_020a9fc4(*(undefined4 *)(iVar1 + 0x28),*(undefined4 *)(iVar1 + 0x10),
                  *(undefined2 *)(DAT_020aba90 + param_1 * 2));
    break;
  case 3:
    iVar1 = *DAT_020aba8c + param_1 * 4;
    func_020a9f98(*(undefined4 *)(iVar1 + 0x28),*(undefined4 *)(iVar1 + 0x10),
                  *(undefined2 *)(DAT_020aba90 + param_1 * 2));
    break;
  case 4:
    iVar1 = *DAT_020aba8c + param_1 * 4;
    func_020a9f6c(*(undefined4 *)(iVar1 + 0x28),*(undefined4 *)(iVar1 + 0x10),
                  *(undefined2 *)(DAT_020aba90 + param_1 * 2));
    break;
  case 5:
    iVar1 = *DAT_020aba8c + param_1 * 4;
    func_020a9f40(*(undefined4 *)(iVar1 + 0x28),*(undefined4 *)(iVar1 + 0x10),
                  *(undefined2 *)(DAT_020aba90 + param_1 * 2));
  }
  *(int *)(*DAT_020aba8c + 0x4c) = param_1;
  return;
}

