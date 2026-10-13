/* Decompiled C draft; module arm9_ov001; ROM address 0218175c. No matching claim. */
#include "types.h"
#include "deps/0218175c_func_ov001_0218175c.h"

void func_ov001_0218175c(uint param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *piRam021817d4;
  cVar1 = *(char *)(iVar2 + 0x2f);
  if (((cVar1 == '\x03') || (cVar1 == '\a')) || (cVar1 == '\0')) {
    if ((((*(ushort *)(iVar2 + 0x3c) == 0) && (*(short *)(iVar2 + 0x3e) == 0)) &&
        ((*(short *)(iVar2 + 0x40) == 0 &&
         ((*(short *)(iVar2 + 0x42) == 0 && (iRam021817d8 < (int)param_1)))))) &&
       ((int)param_1 < iRam021817dc)) {
      FUN_02181aa0();
      return;
    }
    if ((((param_1 == *(ushort *)(iVar2 + 0x3c)) || (param_1 == *(ushort *)(iVar2 + 0x3e))) ||
        (param_1 == *(ushort *)(iVar2 + 0x40))) || (param_1 == *(ushort *)(iVar2 + 0x42))) {
      FUN_02181aa0();
    }
  }
  return;
}

