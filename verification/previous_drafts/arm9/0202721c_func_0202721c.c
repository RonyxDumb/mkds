/* Decompiled C draft; module arm9; ROM address 0202721c. No matching claim. */
#include "types.h"
#include "deps/0202721c_func_0202721c.h"

void func_0202721c(void)

{
  int iVar1;
  
  iVar1 = *piRam02027284;
  if (*(int *)(iVar1 + iRam02027288) == 0) {
    func_02124748((int)*(short *)(iVar1 + *(int *)(iVar1 + 0x60) * 8 + 0x94),
                  *(undefined4 *)(iVar1 + 0x40),*(undefined4 *)(iVar1 + 0x38),
                  *(undefined4 *)(iVar1 + 0x44),0,2,*(undefined4 *)(iVar1 + 8),
                  *(undefined4 *)(iVar1 + 0xc));
    func_02124748((int)*(short *)(*piRam02027284 + *(int *)(*piRam02027284 + 0x60) * 8 + 0x94),
                  *(undefined4 *)(iVar1 + 0x40),*(undefined4 *)(iVar1 + 0x38),
                  *(undefined4 *)(iVar1 + 0x44),0,1,*(undefined4 *)(iVar1 + 8),
                  *(undefined4 *)(iVar1 + 0xc));
  }
  return;
}

