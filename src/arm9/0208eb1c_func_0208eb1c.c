/* Decompiled C draft; module arm9; ROM address 0208eb1c. No matching claim. */
#include "types.h"
#include "deps/0208eb1c_func_0208eb1c.h"

int func_0208eb1c(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  uVar2 = (*(uint *)(uRam0208ec50 & 0xfffffffc) >> (uRam0208ec50 & 3) * 8 |
          *(uint *)(uRam0208ec50 & 0xfffffffc) << (uRam0208ec50 & 3) * -8 + 0x20) + 0xc;
  uVar11 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar11 * 8 | uVar2 << uVar11 * -8 + 0x20) == 5) {
    iVar3 = IntrusiveListWrapper_GetAtIndex
                      ((*(uint *)(uRam0208ec54 & 0xfffffffc) >> (uRam0208ec54 & 3) * 8 |
                       *(uint *)(uRam0208ec54 & 0xfffffffc) << (uRam0208ec54 & 3) * -8 + 0x20) + 0xc
                       ,0);
    if (iVar3 != 0) {
      iVar4 = GetDriverEntry(param_1);
      uVar2 = iVar4 + 0x590U & 3;
      uVar11 = *(uint *)(iVar4 + 0x590U & 0xfffffffc);
      uVar12 = uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20;
      uVar2 = uVar12 + 0x20 & 3;
      uVar11 = *(uint *)(uVar12 + 0x20 & 0xfffffffc);
      iVar5 = (*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
              *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) * 0xc +
              (uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20);
      iVar6 = *(int *)(iVar5 + 0x44);
      iVar8 = *(int *)(iVar5 + 0x48);
      iVar10 = *(int *)(iVar5 + 0x4c);
      *(int *)(iVar3 + 0x14) = iVar4 + 0x80;
      *(undefined4 *)(iVar3 + 0x18) = 0;
      *(undefined4 *)(iVar3 + 0x1c) = 0x400;
      *(undefined4 *)(iVar3 + 0x20) = param_1;
      iVar5 = iRam0208ec5c;
      uVar11 = uVar12 + 4 & 3;
      uVar7 = *(uint *)(uVar12 + 4 & 0xfffffffc);
      uVar2 = iRam0208ec58 +
              (*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
              *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) * 8;
      uVar1 = uVar2 & 3;
      uVar9 = *(uint *)(uVar2 & 0xfffffffc);
      uVar2 = iRam0208ec5c + (uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20) * 4;
      uVar11 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      iVar4 = (int)((iVar8 + ((int)(uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) >> 4)) -
                   (uVar2 >> uVar11 * 8 | uVar2 << uVar11 * -8 + 0x20)) / 2;
      *(int *)(iVar3 + 0x1c) = iVar4;
      iVar8 = iRam0208ec60;
      *(int *)(iVar3 + 0x24) = iVar6 << 4;
      uVar1 = uRam0208ec54;
      uVar2 = uVar12 + 4 & 3;
      uVar11 = *(uint *)(uVar12 + 4 & 0xfffffffc);
      uVar2 = iVar5 + (uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) * 4;
      uVar11 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(iVar3 + 0x28) = ((uVar2 >> uVar11 * 8 | uVar2 << uVar11 * -8 + 0x20) + iVar4) * 0x10
      ;
      uVar2 = iVar8 + (*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                      *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) * 8;
      uVar11 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(iVar3 + 0x2c) = (uVar2 >> uVar11 * 8 | uVar2 << uVar11 * -8 + 0x20) + iVar10 * 0x10;
      uVar2 = uVar1 & 3;
      uVar11 = *(uint *)(uVar1 & 0xfffffffc);
      IntrusiveListWrapper_RemoveItem
                ((uint *)(uintptr_t)((uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) + 0xc),iVar3);
      IntrusiveListWrapper_InsertLast
                (*(uint *)(uRam0208ec54 & 0xfffffffc) >> (uRam0208ec54 & 3) * 8 |
                 *(uint *)(uRam0208ec54 & 0xfffffffc) << (uRam0208ec54 & 3) * -8 + 0x20,iVar3);
    }
    return iVar3;
  }
  return 0;
}

