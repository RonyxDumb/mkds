/* Decompiled C draft; module arm9; ROM address 02142e78. No matching claim. */
#include "types.h"
#include "deps/02142e78_Wm_Initialize.h"

void Wm_Initialize(void)

{
  int iVar1;
  
  iVar1 = Wm_InitializeImpl();
  if (iVar1 == 0) {
    *(undefined2 *)
     ((*(uint *)(uRam02142ea8 & 0xfffffffc) >> (uRam02142ea8 & 3) * 8 |
      *(uint *)(uRam02142ea8 & 0xfffffffc) << (uRam02142ea8 & 3) * -8 + 0x20) + 0x16) = 0;
  }
  return;
}

