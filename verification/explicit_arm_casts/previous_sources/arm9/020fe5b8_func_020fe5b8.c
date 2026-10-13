/* Decompiled C draft; module arm9; ROM address 020fe5b8. No matching claim. */
#include "types.h"
#include "deps/020fe5b8_func_020fe5b8.h"

void func_020fe5b8(int param_1,int param_2,byte *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = GetSomeTimeOrDuration();
  iVar1 = (int)(((uVar2 & 0xff) - (uint)*param_3) * 0x1000000) >> 0x18;
  if (iVar1 < 0) {
    func_020fe9d0(param_1,param_2,iVar1,param_3,0);
  }
  else {
    func_020f0758(param_1 * 0x44 +
                  (*(uint *)(uRam020fe68c & 0xfffffffc) >> (uRam020fe68c & 3) * 8 |
                  *(uint *)(uRam020fe68c & 0xfffffffc) << (uRam020fe68c & 3) * -8 + 0x20),param_2,
                  iVar1,param_3,0);
  }
  if (param_1 != 0xb) {
    return;
  }
  if (param_2 != 0) {
    return;
  }
  if (param_3[1] != 0xff) {
    func_020f81b8((param_4 & 0xffff) * 0x210 +
                  (*(uint *)(uRam020fe690 & 0xfffffffc) >> (uRam020fe690 & 3) * 8 |
                  *(uint *)(uRam020fe690 & 0xfffffffc) << (uRam020fe690 & 3) * -8 + 0x20),0x10);
    return;
  }
  return;
}

