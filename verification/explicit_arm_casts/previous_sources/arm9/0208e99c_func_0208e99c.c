/* Decompiled C draft; module arm9; ROM address 0208e99c. No matching claim. */
#include "types.h"
#include "deps/0208e99c_func_0208e99c.h"

void func_0208e99c(int param_1)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  
  iVar4 = IntrusiveListWrapper_NextItem(param_1 + 8,0);
  puVar3 = puRam0208eb04;
  uVar1 = uRam0208eb00;
  if (iVar4 != 0) {
    iVar10 = param_1 + 8;
    do {
      iVar5 = IntrusiveListWrapper_NextItem(iVar10,iVar4);
      *(short *)(iVar4 + 0xc) = *(short *)(iVar4 + 0xc) + 1;
      if (*puVar3 < *(ushort *)(iVar4 + 0xc)) {
        IntrusiveListWrapper_RemoveItem(iVar10,iVar4);
        IntrusiveListWrapper_InsertLast
                  ((*(uint *)(uRam0208eb08 & 0xfffffffc) >> (uRam0208eb08 & 3) * 8 |
                   *(uint *)(uRam0208eb08 & 0xfffffffc) << (uRam0208eb08 & 3) * -8 + 0x20) + 0x18,
                   iVar4);
        if (iVar5 == 0) break;
      }
      else {
        uVar7 = iVar4 + 8U & 3;
        uVar9 = *(uint *)(iVar4 + 8U & 0xfffffffc);
        uVar2 = uVar1 & 3;
        uVar6 = *(uint *)(uVar1 & 0xfffffffc);
        *(uint *)(iVar4 + 8) =
             (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) -
             (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
        iVar5 = iVar4;
      }
      iVar4 = IntrusiveListWrapper_NextItem(iVar10,iVar5);
    } while (iVar4 != 0);
  }
  uVar1 = param_1 + 0x18U & 3;
  uVar7 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  if (uVar7 >> uVar1 * 8 == 0 && uVar7 << uVar1 * -8 + 0x20 == 0) {
    uVar8 = IntrusiveListWrapper_GetAtIndex
                      ((*(uint *)(uRam0208eb08 & 0xfffffffc) >> (uRam0208eb08 & 3) * 8 |
                       *(uint *)(uRam0208eb08 & 0xfffffffc) << (uRam0208eb08 & 3) * -8 + 0x20) +
                       0x18,0);
    IntrusiveListWrapper_RemoveItem
              ((*(uint *)(uRam0208eb08 & 0xfffffffc) >> (uRam0208eb08 & 3) * 8 |
               *(uint *)(uRam0208eb08 & 0xfffffffc) << (uRam0208eb08 & 3) * -8 + 0x20) + 0x18,uVar8)
    ;
    IntrusiveListWrapper_InsertLast(param_1 + 8,uVar8);
    (*(code *)(*(uint *)(uRam0208eb0c & 0xfffffffc) >> (uRam0208eb0c & 3) * 8 |
              *(uint *)(uRam0208eb0c & 0xfffffffc) << (uRam0208eb0c & 3) * -8 + 0x20))
              (uVar8,param_1);
    return;
  }
  if (*(short *)(param_1 + 0x10) == 0) {
    IntrusiveListWrapper_RemoveItem
              (*(uint *)(uRam0208eb08 & 0xfffffffc) >> (uRam0208eb08 & 3) * 8 |
               *(uint *)(uRam0208eb08 & 0xfffffffc) << (uRam0208eb08 & 3) * -8 + 0x20,param_1);
    IntrusiveListWrapper_InsertLast
              ((*(uint *)(uRam0208eb08 & 0xfffffffc) >> (uRam0208eb08 & 3) * 8 |
               *(uint *)(uRam0208eb08 & 0xfffffffc) << (uRam0208eb08 & 3) * -8 + 0x20) + 0xc,param_1
              );
    return;
  }
  return;
}

