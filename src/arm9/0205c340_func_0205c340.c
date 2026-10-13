/* Decompiled C draft; module arm9; ROM address 0205c340. No matching claim. */
#include "types.h"
#include "deps/0205c340_func_0205c340.h"

int func_0205c340(uint param_1,uint param_2,int param_3)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  
  uVar1 = *(ushort *)
           ((*(uint *)(uRam0205c468 & 0xfffffffc) >> (uRam0205c468 & 3) * 8 |
            *(uint *)(uRam0205c468 & 0xfffffffc) << (uRam0205c468 & 3) * -8 + 0x20) + 0x75c);
  iVar5 = 1;
  if ((uVar1 & 4) == 0) {
    uVar3 = func_0x0219bb50(uVar1 & 4);
    if (param_1 != uVar3) {
      uVar4 = *(uint *)(uRam0205c468 & 0xfffffffc) >> (uRam0205c468 & 3) * 8 |
              *(uint *)(uRam0205c468 & 0xfffffffc) << (uRam0205c468 & 3) * -8 + 0x20;
      uVar3 = uVar4 + 0x754 & 3;
      uVar6 = *(uint *)(uVar4 + 0x754 & 0xfffffffc);
      pbVar7 = (byte *)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
      *(ushort *)(uVar4 + 0x75c) = *(ushort *)(uVar4 + 0x75c) | 4;
      bVar2 = func_0x0219bb50();
      *pbVar7 = *pbVar7 & 0xfc | bVar2 & 3;
      *pbVar7 = *pbVar7 & 0xf3 | (byte)((param_1 & 3) << 2);
      uVar6 = uRam0205c468;
      *pbVar7 = *pbVar7 & 0xf | (byte)((param_2 & 0xf) << 4);
      uVar3 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
              *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x758;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      pbVar7[1] = (byte)(uVar3 >> uVar4 * 8) | (byte)(uVar3 << uVar4 * -8 + 0x20);
      pbVar7[2] = pbVar7[2] & 0xf0 |
                  *(byte *)((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x748) & 0xf
      ;
      DC_SomeClean((uint)(uintptr_t)(pbVar7),param_3 + 4);
      iVar5 = func_02120340(param_1,pbVar7,param_3 + 4,uRam0205c46c);
      if (iVar5 == 0) {
        uVar3 = *(uint *)(uRam0205c468 & 0xfffffffc) >> (uRam0205c468 & 3) * 8 |
                *(uint *)(uRam0205c468 & 0xfffffffc) << (uRam0205c468 & 3) * -8 + 0x20;
        *(ushort *)(uVar3 + 0x75c) = *(ushort *)(uVar3 + 0x75c) & 0xfffb;
      }
    }
    return iVar5;
  }
  return 0;
}

