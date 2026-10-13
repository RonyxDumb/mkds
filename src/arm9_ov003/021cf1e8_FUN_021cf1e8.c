/* Decompiled C draft; module arm9_ov003; ROM address 021cf1e8. No matching claim. */
#include "types.h"
#include "deps/021cf1e8_FUN_021cf1e8.h"

undefined2 FUN_021cf1e8(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 1;
  iVar3 = *DAT_021cf25c;
  do {
    if (((uint)*(ushort *)(iVar3 + 2) & 1 << (uVar4 & 0xff)) != 0) {
      iVar2 = (uVar4 - 1) * 0x1e;
      iVar1 = iVar3 + 0x24 + iVar2;
      if ((((*param_1 == *(char *)(iVar3 + 0x24 + iVar2)) && (param_1[1] == *(char *)(iVar1 + 1)))
          && (param_1[2] == *(char *)(iVar1 + 2))) &&
         (((param_1[3] == *(char *)(iVar1 + 3) && (param_1[4] == *(char *)(iVar1 + 4))) &&
          (param_1[5] == *(char *)(iVar1 + 5))))) {
        return *(undefined2 *)(iVar3 + iVar2 + 0x2a);
      }
    }
    uVar4 = uVar4 + 1 & 0xffff;
    if (1 < uVar4) {
      return 0;
    }
  } while( true );
}

