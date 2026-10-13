/* Decompiled C draft; module arm9; ROM address 0212a604. No matching claim. */
#include "types.h"
#include "deps/0212a604_func_0212a604.h"

void func_0212a604(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  piVar1 = piRam0212a66c;
  local_28 = 0;
  local_20 = 0;
  iVar3 = iRam0212a668;
  do {
    local_24 = 0;
    local_1c = 0;
    do {
      iVar4 = 0;
      do {
        iVar2 = *(int *)(local_20 + local_1c + *piVar1 + 0x74) +
                (uint)*(byte *)(iVar3 + iVar4) * 0x40;
        *(undefined4 *)(iVar2 + 8) = 1;
        *(undefined2 *)(iVar2 + 0xc) = 0;
        *(undefined2 *)(iVar2 + 0xe) = 0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
      local_1c = local_1c + 4;
      local_24 = local_24 + 1;
    } while (local_24 < 2);
    iVar3 = iVar3 + 4;
    local_20 = local_20 + 8;
    local_28 = local_28 + 1;
  } while (local_28 < 2);
  return;
}

