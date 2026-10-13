/* Decompiled C draft; module arm9; ROM address 020ccbb8. No matching claim. */
#include "types.h"
#include "deps/020ccbb8_func_020ccbb8.h"

void func_020ccbb8(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 local_20;
  undefined4 local_1c [2];
  
  iVar1 = func_020ae3b4(7);
  iVar2 = func_020ae3b4(6);
  uVar4 = iVar2 + 1;
  if ((int)(iVar1 + 1U) <= (int)uVar4) {
    uVar4 = iVar2 + 2;
  }
  puVar3 = (undefined4 *)GetGlobalCA_from_thumb();
  iVar2 = GetGlobalCA_from_thumb();
  func_0203be6c(*(undefined4 *)(*piRam020ccc6c + iRam020ccc70),0,*puVar3,*(undefined4 *)(iVar2 + 4))
  ;
  func_0203ba70(*(undefined4 *)(*piRam020ccc6c + iRam020ccc70));
  puVar3 = (undefined4 *)GetGlobalCA_from_thumb();
  iVar2 = GetGlobalCA_from_thumb();
  uVar6 = 0xffffffff;
  uVar7 = 3;
  StructCO_ConfigureRacerDefault(0,*puVar3,*(undefined4 *)(iVar2 + 4),0,0xffffffff,3);
  uVar5 = 1;
  uVar8 = 1;
  do {
    func_0203be48(*(undefined4 *)(*piRam020ccc6c + iRam020ccc70),uVar5,&local_20,local_1c,uVar6,
                  uVar7,uVar8);
    if (uVar5 == iVar1 + 1U) {
      uVar7 = 0;
    }
    else {
      uVar7 = uVar8;
      if (uVar5 != uVar4) {
        uVar7 = 3;
      }
    }
    uVar6 = 0xffffffff;
    StructCO_ConfigureRacerDefault(uVar5,local_20,local_1c[0],1);
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 8);
  return;
}

