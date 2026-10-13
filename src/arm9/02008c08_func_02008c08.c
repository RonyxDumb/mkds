/* Decompiled C draft; module arm9; ROM address 02008c08. No matching claim. */
#include "types.h"
#include "deps/02008c08_func_02008c08.h"

void func_02008c08(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *piRam02008c98 + 0x10 + iRam02008c9c * param_1;
  iVar2 = *piRam02008ca4;
  if ((*(char *)(iVar4 + iRam02008ca8) != *(char *)(iVar2 + 5)) ||
     ((*(uint *)(iVar4 + iRam02008cac) & 1 << *(sbyte *)(iVar2 + 10)) == 0)) {
    iVar3 = iVar4;
    if ((*(byte *)(iVar2 + 4) & 3) != 0) {
      iVar3 = iVar4 + iRam02008cb0;
    }
    if (iVar3 + (uint)*(byte *)(*piRam02008ca4 + 10) * 0x62 + (uint)*(byte *)(*piRam02008ca4 + 0xc)
        <= (uint)(iVar4 + iRam02008ca0)) {
      CopyMemory16(iVar2 + 0xe);
      piVar1 = piRam02008ca4;
      *(byte *)(iVar4 + iRam02008cb4) = *(byte *)(*piRam02008ca4 + 4) & 3;
      *(uint *)(iVar4 + iRam02008cac) =
           *(uint *)(iVar4 + iRam02008cac) | 1 << *(sbyte *)(*piVar1 + 10);
      *(int *)(iVar4 + iRam02008cb8) = (1 << *(sbyte *)(*piVar1 + 0xb)) + -1;
    }
  }
  return;
}

