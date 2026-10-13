/* Decompiled C draft; module arm9; ROM address 02007624. No matching claim. */
#include "types.h"
#include "deps/02007624_func_02007624.h"

void func_02007624(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  ushort *puVar7;
  uint uVar8;
  
  iVar3 = iRam0200768c;
  iVar2 = iRam02007688;
  piVar1 = piRam02007684;
  uVar8 = 0;
  do {
    iVar6 = *piVar1 + iVar2 * uVar8;
    if (*(char *)(iVar6 + iVar3) != '\0') {
      *(undefined2 *)(iVar6 + iRam02007690) = 0;
    }
    uVar4 = uRam02007694;
    uVar8 = uVar8 + 1 & 0xffff;
  } while (uVar8 < 0x10);
  uVar5 = 1;
  do {
    puVar7 = (ushort *)func_021432ac(param_1,uVar5);
    if (((puVar7 != (ushort *)0x0) && (*puVar7 != uVar4)) && (*puVar7 != 0)) {
      func_02007698((int)(uintptr_t)(puVar7),uVar5);
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x10);
  return;
}

