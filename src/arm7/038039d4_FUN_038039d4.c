/* Decompiled C draft; module arm7; ROM address 038039d4. No matching claim. */
#include "types.h"
#include "deps/038039d4_FUN_038039d4.h"

void FUN_038039d4(undefined4 param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = DAT_03803a40;
  while( true ) {
    uVar2 = FUN_037faf70();
    param_2[1] = uVar2;
    uVar2 = FUN_037f8af4(uVar1);
    *param_2 = uVar2 & 0x80;
    if ((*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 != 0 ||
         *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20 != 0) ||
       (iVar3 = FUN_037f8b04(param_1), iVar3 == 0)) break;
    uVar2 = (uint)(param_2 + 1) & 3;
    uVar4 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
    FUN_037faf84(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
    thunk_FUN_038011a4(1);
  }
  return;
}

