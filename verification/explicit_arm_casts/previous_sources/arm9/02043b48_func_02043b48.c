/* Decompiled C draft; module arm9; ROM address 02043b48. No matching claim. */
#include "types.h"
#include "deps/02043b48_func_02043b48.h"

void func_02043b48(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = uRam02043c0c;
  iVar5 = 0;
  iVar4 = iRam02043c08;
  do {
    StructCY_SomeFn(iVar4);
    *(undefined2 *)(iVar4 + 0x40) = 0;
    StructCY_SomeFn_0(iVar4,uVar2,0x1e,10);
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 0x5c;
  } while (iVar5 < 10);
  func_02047054();
  func_02043648();
  uVar2 = uRam02043c0c;
  iVar5 = 0;
  iVar4 = iRam02043c08;
  do {
    *(undefined2 *)(iVar4 + 0x12) = 0;
    *(undefined2 *)(iVar4 + 0x14) = 0;
    StructCY_SomeFn_0(iVar4,uVar2,0x1e,10);
    uVar3 = uRam02043c10;
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 0x5c;
  } while (iVar5 < 10);
  *(undefined2 *)
   ((*(uint *)(uRam02043c10 & 0xfffffffc) >> (uRam02043c10 & 3) * 8 |
    *(uint *)(uRam02043c10 & 0xfffffffc) << (uRam02043c10 & 3) * -8 + 0x20) + 2) = 0;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(undefined2 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 4) = 0;
  return;
}

