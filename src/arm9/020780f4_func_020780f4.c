/* Decompiled C draft; module arm9; ROM address 020780f4. No matching claim. */
#include "types.h"
#include "deps/020780f4_func_020780f4.h"

void func_020780f4(void)

{
  short sVar1;
  int iVar2;
  
  iVar2 = *piRam02078148;
  sVar1 = *(short *)(iVar2 + iRam0207814c);
  if (-1 < sVar1) {
    if ((*(int *)(iVar2 + 0x24) != -1) && (*(int *)(iVar2 + 0x28) != -1)) {
      func_020787f4(*(undefined4 *)(iVar2 + 0x50),*puRam02078150);
      func_02078580((int *)(uintptr_t)(iVar2 + 0x58 + sVar1 * 0xb8),*piRam02078148 + 0x24,
                    *(undefined4 *)(*piRam02078148 + iRam02078154));
      func_01ff9234();
    }
  }
  return;
}

