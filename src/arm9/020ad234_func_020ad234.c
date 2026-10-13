/* Decompiled C draft; module arm9; ROM address 020ad234. No matching claim. */
#include "types.h"
#include "deps/020ad234_func_020ad234.h"

void func_020ad234(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(*piRam020ad260 + 0x50) == 0) {
    iVar2 = 0x6b;
  }
  iVar1 = func_020adaf8();
  if (iVar2 <= iVar1) {
    func_020adad0(1,8);
  }
  Title_SomeBldalphaConfig_from_thumb();
  return;
}

