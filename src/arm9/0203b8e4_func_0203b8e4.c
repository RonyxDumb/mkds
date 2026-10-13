/* Decompiled C draft; module arm9; ROM address 0203b8e4. No matching claim. */
#include "types.h"
#include "deps/0203b8e4_func_0203b8e4.h"

byte func_0203b8e4(longlong *param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint extraout_r1;
  uint uVar5;
  longlong lVar6;
  
  cVar1 = '\0';
  uVar5 = 0;
  bVar2 = 0;
  do {
    iVar3 = func_0203b96c(bVar2);
    if (iVar3 != 0) {
      cVar1 = cVar1 + '\x01';
    }
    bVar2 = bVar2 + 1;
  } while (bVar2 < 8);
  if (cVar1 == '\0') {
    uVar4 = 0;
  }
  else {
    lVar6 = Multiply64((int)param_1[1],*(undefined4 *)((int)param_1 + 0xc),(int)*param_1,
                       *(undefined4 *)((int)param_1 + 4));
    *param_1 = lVar6 + param_1[2];
    if (cVar1 == '\0') {
      uVar4 = *(uint *)((int)param_1 + 4);
    }
    else {
      Multiply64(*(undefined4 *)((int)param_1 + 4),0,cVar1,0);
      uVar4 = extraout_r1;
    }
  }
  bVar2 = 0;
  while ((iVar3 = func_0203b96c(bVar2), iVar3 == 0 ||
         (uVar5 = uVar5 + 1 & 0xffff, uVar5 <= (uVar4 & 0xffff)))) {
    bVar2 = bVar2 + 1;
    if (7 < bVar2) {
      return bVar2;
    }
  }
  return bVar2;
}

