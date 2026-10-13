/* Decompiled C draft; module arm9; ROM address 02009e70. No matching claim. */
#include "types.h"
#include "deps/02009e70_func_02009e70.h"

undefined4 func_02009e70(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = piRam02009f0c;
  *(undefined2 *)(*piRam02009f0c + iRam02009f10) = 0;
  *(undefined2 *)(*piVar1 + iRam02009f14) = 0;
  *(undefined2 *)(*piVar1 + iRam02009f18) = 0;
  *(undefined2 *)(*piVar1 + iRam02009f1c) = 0;
  func_02009adc(10);
  iVar4 = iRam02009f30;
  puVar3 = puRam02009f2c;
  puVar2 = puRam02009f28;
  piVar1 = piRam02009f0c;
  if (*(int *)(*piRam02009f20 + iRam02009f24) != 0) {
    func_021435e8(*(undefined4 *)(*piRam02009f0c + iRam02009f30));
    *(undefined1 *)(*piRam02009f0c + iRam02009f34) = 1;
    func_0200ad00();
    return 0;
  }
  do {
    iVar5 = StructWM_SomeFn(*puVar2,*(undefined4 *)(*piVar1 + iVar4),*puVar3);
  } while (iVar5 == 4);
  if (iVar5 == 2) {
    func_021435e8(*(undefined4 *)(*piRam02009f0c + iRam02009f30));
    *(undefined1 *)(*piRam02009f0c + iRam02009f34) = 1;
    return 0;
  }
  return 8;
}

