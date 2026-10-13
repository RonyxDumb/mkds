/* Decompiled C draft; module arm9; ROM address 020a7148. No matching claim. */
#include "types.h"
#include "deps/020a7148_func_020a7148.h"

void func_020a7148(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = func_020d3bf8(0x6a);
  if (iVar1 == 0) {
    func_020ac588(0x6a,0x14,param_1);
    func_020ac588(0x70,*(undefined1 *)
                        ((*(uint *)(uRam020a71b8 & 0xfffffffc) >> (uRam020a71b8 & 3) * 8 |
                         *(uint *)(uRam020a71b8 & 0xfffffffc) << (uRam020a71b8 & 3) * -8 + 0x20) +
                        0x3d0),param_1);
    func_020a233c(uRam020a71bc);
    func_020a2328(uRam020a71c0);
    func_020a2314(uRam020a71c4);
    return;
  }
  func_020d2398(param_1);
  return;
}

