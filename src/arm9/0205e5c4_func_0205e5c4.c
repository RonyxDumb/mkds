/* Decompiled C draft; module arm9; ROM address 0205e5c4. No matching claim. */
#include "types.h"
#include "deps/0205e5c4_func_0205e5c4.h"

void func_0205e5c4(int param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    bVar3 = false;
    uVar1 = *(uint *)(uRam0205e670 & 0xfffffffc) >> (uRam0205e670 & 3) * 8 |
            *(uint *)(uRam0205e670 & 0xfffffffc) << (uRam0205e670 & 3) * -8 + 0x20;
    if ((uVar1 != 0) &&
       (uVar1 = uVar1 + 0x1f30, uVar2 = uVar1 & 3, uVar1 = *(uint *)(uVar1 & 0xfffffffc),
       uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0)) {
      bVar3 = true;
    }
    uVar4 = uRam0205e674;
    if (!bVar3) {
      return;
    }
  }
  else {
    bVar3 = false;
    uVar1 = *(uint *)(uRam0205e668 & 0xfffffffc) >> (uRam0205e668 & 3) * 8 |
            *(uint *)(uRam0205e668 & 0xfffffffc) << (uRam0205e668 & 3) * -8 + 0x20;
    if (uVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    }
    if ((uVar2 != 0) &&
       (uVar2 = uVar1 + 4 & 3, uVar1 = *(uint *)(uVar1 + 4 & 0xfffffffc),
       (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) != 0xd)) {
      bVar3 = true;
    }
    uVar4 = uRam0205e66c;
    if (!bVar3) {
      return;
    }
  }
  EnableMKDSSVSomeFlag_from_thumb();
  WorkerInsertTask(uVar4);
  *(undefined4 *)
   ((*(uint *)(uRam0205e678 & 0xfffffffc) >> (uRam0205e678 & 3) * 8 |
    *(uint *)(uRam0205e678 & 0xfffffffc) << (uRam0205e678 & 3) * -8 + 0x20) + 0xf8) = 1;
  return;
}

