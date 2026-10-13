/* Decompiled C draft; module arm9; ROM address 020812d0. No matching claim. */
#include "types.h"
#include "deps/020812d0_func_020812d0.h"

void func_020812d0(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  ushort uVar8;
  
  iVar4 = GetDriverEntry();
  uVar3 = uRam02081334;
  uVar2 = uRam02081330;
  uVar1 = iVar4 + 0x4cU & 3;
  uVar5 = *(uint *)(iVar4 + 0x4cU & 0xfffffffc);
  if (((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0x8000) != 0) {
    uVar8 = 0;
    do {
      iVar6 = func_0208b7bc(0x58,uVar2);
      uVar7 = uVar8 + 1;
      *(int *)(iVar6 + 0x94) = iVar4;
      *(char *)(iVar6 + 0x9b) = (char)uVar8;
      *(undefined4 *)(iVar6 + 0x90) = uVar3;
      uVar8 = uVar7;
    } while (uVar7 < 2);
    return;
  }
  return;
}

