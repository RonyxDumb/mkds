/* Decompiled C draft; module arm9; ROM address 020acb08. No matching claim. */
#include "types.h"
#include "deps/020acb08_func_020acb08.h"

void func_020acb08(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = *(int *)(*piRam020acbbc + 0x68);
  iVar2 = func_020acbe8(*(undefined4 *)(*piRam020acbbc + 0x6c));
  iVar3 = func_020adaf8();
  if (iVar3 < 10) {
    iVar3 = 0;
    do {
      uVar4 = func_020adaf8();
      uVar1 = ComputeValueInterpolation_from_thumb(1,0,0xf8,uVar4,10);
      *(undefined2 *)(iVar5 + iVar3 * 0x40 + 4) = uVar1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xf);
    iVar3 = 0;
    do {
      uVar4 = func_020adaf8();
      uVar1 = ComputeValueInterpolation_from_thumb(1,0,0xf8,uVar4,10);
      *(undefined2 *)(iVar5 + (iVar3 + iVar2) * 0x40 + 4) = uVar1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
  }
  else {
    iVar3 = 0;
    do {
      *(undefined2 *)(iVar5 + iVar3 * 0x40 + 4) = 0xf8;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xf);
    iVar3 = 0;
    do {
      *(undefined2 *)(iVar5 + (iVar3 + iVar2) * 0x40 + 4) = 0xf8;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
    iVar2 = func_020acbc0();
    if (iVar2 == 0) {
      func_020adad0(6,8);
    }
    else {
      func_020adad0(*(undefined4 *)(*piRam020acbbc + 0x10),8);
    }
  }
  func_020acff4();
  return;
}

