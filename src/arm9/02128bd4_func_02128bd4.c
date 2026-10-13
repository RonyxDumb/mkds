/* Decompiled C draft; module arm9; ROM address 02128bd4. No matching claim. */
#include "types.h"
#include "deps/02128bd4_func_02128bd4.h"

void func_02128bd4(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = iRam02128c3c;
  iVar2 = iRam02128c38;
  piVar1 = piRam02128c34;
  iVar3 = 0;
  iVar4 = *(int *)(*piRam02128c34 + 4);
  if (*(char *)(iRam02128c38 + iVar4) != '\0') {
    do {
      *(undefined4 *)
       (*(int *)(*piVar1 + iVar4 * 8 + 0x78) + (uint)*(byte *)(iVar3 + iVar5 + iVar4 * 0xc) * 0x40)
           = 0;
      iVar3 = iVar3 + 1;
      iVar4 = *(int *)(*piVar1 + 4);
    } while (iVar3 < (int)(uint)*(byte *)(iVar2 + iVar4));
  }
  iVar5 = *piRam02128c34;
  iVar2 = func_020ab748();
  *(undefined4 *)
   (*(int *)(iVar5 + iVar4 * 8 + 0x78) + (uint)*(byte *)(iVar2 + iRam02128c3c + iVar4 * 0xc) * 0x40)
       = 1;
  return;
}

