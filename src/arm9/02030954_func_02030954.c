/* Decompiled C draft; module arm9; ROM address 02030954. No matching claim. */
#include "types.h"
#include "deps/02030954_func_02030954.h"

void func_02030954(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_24;
  uint local_1c [2];
  
  iVar3 = *piRam020309cc;
  local_1c[0] = *puRam020309d0;
  local_1c[1] = puRam020309d0[1];
  iVar4 = 0;
  local_24 = 0;
  do {
    iVar2 = local_24;
    if ((*(int *)(*piRam020309cc + 0x28) == iVar4) && (param_1 != 0)) {
      iVar2 = 1;
    }
    iVar1 = iRam020309d4 + iVar4 * 6;
    *(int *)(*(int *)(iVar3 + 0x18) + (uint)*(ushort *)(iRam020309d4 + iVar4 * 6) * 0x40) = iVar2;
    *(uint *)(*(int *)(iVar3 + 0x18) + (uint)*(ushort *)(iVar1 + 2) * 0x40) = (uint)(iVar2 == 0);
    func_02124100(*(undefined2 *)(iVar1 + 4),local_1c[iVar2] & 0xff,*(undefined4 *)(iVar3 + 0x14),
                  *(undefined4 *)(iVar3 + 0x18),*(undefined4 *)(iVar3 + 0xc));
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  return;
}

