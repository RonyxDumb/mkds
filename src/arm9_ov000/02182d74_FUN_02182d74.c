/* Decompiled C draft; module arm9_ov000; ROM address 02182d74. No matching claim. */
#include "types.h"
#include "deps/02182d74_FUN_02182d74.h"

void FUN_02182d74(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = func_0x02036d08();
  if (iVar2 != 0) {
    func_0x02037288(10);
  }
  iVar2 = func_0x02036c5c();
  if (iVar2 != 0) {
    iVar2 = func_0x02122ae4();
    piVar1 = DAT_02182de0;
    if (iVar2 != 0) {
      *(undefined4 *)(*DAT_02182de0 + 4) = 1;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + DAT_02182de4),0x1b);
      func_0x02126638(uVar3,0,0,1,0,0,0);
      func_0x02122ab0();
      func_0x0211fe44();
      return;
    }
    *(undefined4 *)(*DAT_02182de0 + 4) = 2;
    FUN_02182de8();
    func_0x0211fe44();
  }
  return;
}

