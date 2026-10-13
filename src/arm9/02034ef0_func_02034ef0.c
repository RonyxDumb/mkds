/* Decompiled C draft; module arm9; ROM address 02034ef0. No matching claim. */
#include "types.h"
#include "deps/02034ef0_func_02034ef0.h"

void func_02034ef0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = piRam02034f58;
  iVar2 = *piRam02034f58;
  iVar3 = 0;
  do {
    if (iVar3 == *(int *)(*piVar1 + 0x80)) {
      uVar4 = 0xe;
    }
    else {
      uVar4 = 0xf;
    }
    func_02124100(iVar3 + 4,uVar4,*(undefined4 *)(iVar2 + 0x5c),*(undefined4 *)(iVar2 + 0x60),
                  *(undefined4 *)(iVar2 + 0x54));
    func_02124100(iVar3,uVar4,*(undefined4 *)(iVar2 + 0x5c),*(undefined4 *)(iVar2 + 0x60),
                  *(undefined4 *)(iVar2 + 0x54));
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  if (-1 < *(int *)(*piRam02034f58 + 0x80)) {
    func_02025c6c(4,(int)*(short *)(iRam02034f5c + *(int *)(*piRam02034f58 + 0x80) * 8),
                  *(undefined4 *)(iVar2 + 0x54));
  }
  return;
}

