/* Decompiled C draft; module arm9; ROM address 0204ef1c. No matching claim. */
#include "types.h"
#include "deps/0204ef1c_func_0204ef1c.h"

void func_0204ef1c(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam0204ef70;
  *(undefined4 *)(*piRam0204ef70 + 0xc) = 0xb;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
  iVar2 = *piVar1;
  iVar2 = func_02144230(uRam0204ef78,*(undefined4 *)(iVar2 + iRam0204ef7c),
                        *(uint *)(iVar2 + iRam0204ef80) & 0xffff,
                        *(undefined4 *)(iVar2 + iRam0204ef84),
                        *(uint *)(iVar2 + iRam0204ef74) & 0xffff,1,0,0,0,0,0);
  if (iVar2 != 2) {
    func_02050e60(2);
  }
  return;
}

