/* Decompiled C draft; module arm9; ROM address 02108e38. No matching claim. */
#include "types.h"
#include "deps/02108e38_func_02108e38.h"

void func_02108e38(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = iRam02108e68;
  iVar2 = 7;
  do {
    func_0212c6f0(iVar1 + iVar2 * 4,0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xc);
  return;
}

