/* Decompiled C draft; module arm9; ROM address 020e82dc. No matching claim. */
#include "types.h"
#include "deps/020e82dc_E7Fn2_6.h"

void E7Fn2_6(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar5 = uRam020e8354;
  uVar4 = uRam020e8350;
  uVar3 = uRam020e834c;
  uVar2 = uRam020e8348;
  puVar1 = puRam020e8344;
  *puRam020e8344 = uRam020e8340;
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  puVar1[3] = uVar4;
  func_020d7d18(uVar5,0,puVar1,0x1ec);
  uVar4 = uRam020e8364;
  uVar3 = uRam020e8360;
  uVar2 = uRam020e835c;
  *puRam020e8358 = 0;
  func_020ea1d4(uVar2,uVar3,uVar4);
  return;
}

