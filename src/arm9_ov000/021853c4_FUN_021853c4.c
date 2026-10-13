/* Decompiled C draft; module arm9_ov000; ROM address 021853c4. No matching claim. */
#include "types.h"
#include "deps/021853c4_FUN_021853c4.h"

void FUN_021853c4(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  
  piVar1 = DAT_02185414;
  *(int *)(*DAT_02185414 + 8) = *(int *)(*DAT_02185414 + 8) + 1;
  uVar2 = func_0x020ae4c0(1,0,0x50,*(undefined4 *)(*piVar1 + 8),0xf);
  piVar1 = DAT_02185414;
  *(undefined2 *)(*DAT_02185414 + 0xc) = uVar2;
  if (((0xe < *(int *)(*piVar1 + 8)) && (iVar3 = func_0x02125f88(), iVar3 != 0)) &&
     (iVar3 = func_0x02128294(), iVar3 != 0)) {
    func_ov000_021806e0(*(undefined4 *)(*DAT_02185414 + 0x28));
  }
  return;
}

