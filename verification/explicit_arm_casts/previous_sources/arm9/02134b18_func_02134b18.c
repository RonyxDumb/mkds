/* Decompiled C draft; module arm9; ROM address 02134b18. No matching claim. */
#include "types.h"
#include "deps/02134b18_func_02134b18.h"

uint func_02134b18(int param_1,short *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  undefined1 auStack_20 [4];
  
  uVar5 = 0;
  if ((param_1 != 0) && (param_2 != (short *)0x0)) {
    while( true ) {
      if (*param_2 == 0) {
        puVar4 = (uint *)(param_1 + uVar5);
        uVar2 = (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xffffff00
        ;
        uVar1 = (4 - ((uint)puVar4 & 3)) * 8 & 0x1f;
        *puVar4 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
        return uVar5;
      }
      param_2 = param_2 + 1;
      iVar3 = func_02134c6c(auStack_20);
      if (param_3 < uVar5 + iVar3) break;
      SomeStrncpy_0(param_1 + uVar5,auStack_20,iVar3);
      uVar5 = uVar5 + iVar3;
      if (param_3 < uVar5) {
        return uVar5;
      }
    }
    return uVar5;
  }
  return 0;
}

