/* Decompiled C draft; module arm9; ROM address 0211f77c. No matching claim. */
#include "types.h"
#include "deps/0211f77c_func_0211f77c.h"

void func_0211f77c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  if (param_1 == 0) {
    bVar7 = param_2 != 0;
    uVar3 = 0;
    if (bVar7) {
      param_2 = 1;
      uVar3 = *(uint *)(uRam0211f858 & 0xfffffffc) >> (uRam0211f858 & 3) * 8 |
              *(uint *)(uRam0211f858 & 0xfffffffc) << (uRam0211f858 & 3) * -8 + 0x20;
    }
    uVar6 = 0;
    if (bVar7) {
      *(int *)(uVar3 + 0x1cfc) = param_2;
    }
    iVar4 = func_0x0219d9b0((*(uint *)(uRam0211f858 & 0xfffffffc) >> (uRam0211f858 & 3) * 8 |
                            *(uint *)(uRam0211f858 & 0xfffffffc) << (uRam0211f858 & 3) * -8 + 0x20)
                            + iRam0211f85c,0x3c);
    iVar2 = iRam0211f860;
    iVar1 = iRam0211f85c;
    uVar3 = uRam0211f858;
    if (0 < iVar4) {
      do {
        uVar5 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
        PlayerProfileInfo_SomeFn_3_from_thumb(uVar5 + iVar2,uVar6 * 0xc + uVar5 + iVar1);
        uVar6 = uVar6 + 1 & 0xff;
        iVar4 = func_0x0219d9b0((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + iVar1,
                                0x3c);
      } while ((int)uVar6 < iVar4);
    }
    *(undefined4 *)
     ((*(uint *)(uRam0211f858 & 0xfffffffc) >> (uRam0211f858 & 3) * 8 |
      *(uint *)(uRam0211f858 & 0xfffffffc) << (uRam0211f858 & 3) * -8 + 0x20) + 0x1f2c) = 5;
    return;
  }
  func_0x0219c0f4();
  func_0x021a37dc();
  *(undefined4 *)
   ((*(uint *)(uRam0211f858 & 0xfffffffc) >> (uRam0211f858 & 3) * 8 |
    *(uint *)(uRam0211f858 & 0xfffffffc) << (uRam0211f858 & 3) * -8 + 0x20) + 0x1f2c) = 7;
  return;
}

