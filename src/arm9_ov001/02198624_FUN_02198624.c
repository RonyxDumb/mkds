/* Decompiled C draft; module arm9_ov001; ROM address 02198624. No matching claim. */
#include "types.h"
#include "deps/02198624_FUN_02198624.h"

void FUN_02198624(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  iVar3 = func_0x02125f54();
  if (iVar3 != 0) {
    func_0x02125fc0();
    return;
  }
  iVar3 = func_0x02125f88();
  if (iVar3 != 0) {
    iVar3 = func_0x02125f60();
    puVar1 = DAT_021986e0;
    if (iVar3 == 0) {
      iVar3 = *DAT_021986dc;
      *(byte *)(*(int *)*DAT_021986e0 + 0x31) = *(byte *)(*(int *)*DAT_021986e0 + 0x31) & 0xfe | 1;
      func_0x0214d168((uint *)(uintptr_t)(*(int *)*puVar1 + 0xc),0,0x14);
      func_0x0214d1fc((ushort *)(uintptr_t)(iVar3 + 0x2a),(uint *)(uintptr_t)(*(int *)*DAT_021986e0 + 0xc),0x14);
      func_0x02056d40();
      piVar2 = DAT_021986e4;
      *(undefined4 *)(*DAT_021986e4 + 4) = 3;
      uVar4 = func_0x020b3f7c(*(undefined4 *)(*piVar2 + 0x14),0x13);
      uVar5 = func_0x020b3f7c(*(undefined4 *)(*DAT_021986e4 + 0x14),0);
      uVar6 = func_0x020b3f7c(*(undefined4 *)(*DAT_021986e4 + 0x14),1);
      func_0x0212611c(uVar4,uVar5,uVar6,1);
      return;
    }
    *(undefined2 *)(*DAT_021986e4 + 0xe) = 0xe;
  }
  return;
}

