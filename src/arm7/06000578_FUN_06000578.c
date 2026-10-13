/* Decompiled C draft; module arm7; ROM address 06000578. No matching claim. */
#include "types.h"
#include "deps/06000578_FUN_06000578.h"

void FUN_06000578(undefined4 param_1,undefined2 *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  
  if (((param_3 == 0) && (iVar2 = thunk_FUN_037f9854(DAT_060005d8,param_2,0), iVar2 == 0)) &&
     (uVar1 = DAT_060005dc + 0x54cU & 3, uVar3 = *(uint *)(DAT_060005dc + 0x54cU & 0xfffffffc),
     uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0)) {
    puVar4 = (undefined2 *)thunk_FUN_03807424();
    *puVar4 = *param_2;
    puVar4[1] = 8;
    puVar4[2] = 0;
    puVar4[3] = 0;
    thunk_FUN_038074cc();
  }
  return;
}

