/* Decompiled C draft; module arm9_ov001; ROM address 02185d74. No matching claim. */
#include "types.h"
#include "deps/02185d74_FUN_02185d74.h"

undefined1 FUN_02185d74(int param_1,int param_2,char *param_3,undefined1 *param_4)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  
  cVar1 = *param_3;
  uVar2 = *param_4;
  if ((*(uint *)(param_2 + 0x48) & DAT_02185dc4) == 0) {
    if (*(int *)(*DAT_02185dc8 + 8) == 4) {
      iVar3 = func_0x020a1084(*(undefined2 *)(param_2 + 0x74));
    }
    else {
      iVar3 = 0;
    }
    if (iVar3 == 0) {
      if (cVar1 == '\x01') {
        *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_02185dcc;
        *(undefined4 *)(param_1 + 0xac) = 2;
      }
      return uVar2;
    }
  }
  return 0;
}

