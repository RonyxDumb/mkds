/* Decompiled C draft; module arm9; ROM address 0203b96c. No matching claim. */
#include "types.h"
#include "deps/0203b96c_func_0203b96c.h"

undefined4 func_0203b96c(int param_1)

{
  int iVar1;
  
  if (param_1 == 9) {
    return 0;
  }
  switch(param_1) {
  case 0:
  case 1:
  case 4:
  case 5:
    return 1;
  case 2:
    iVar1 = CheckSavedSecretFlag_from_thumb(0);
    if ((((iVar1 != 0) || (iVar1 = CheckSavedSecretFlag_from_thumb(1), iVar1 != 0)) ||
        (iVar1 = CheckSavedSecretFlag_from_thumb(2), iVar1 != 0)) ||
       (iVar1 = CheckSavedSecretFlag_from_thumb(3), iVar1 != 0)) {
      return 1;
    }
    break;
  case 3:
    iVar1 = CheckSavedSecretFlag_from_thumb(4);
    if (((iVar1 != 0) || (iVar1 = CheckSavedSecretFlag_from_thumb(5), iVar1 != 0)) ||
       ((iVar1 = CheckSavedSecretFlag_from_thumb(6), iVar1 != 0 ||
        (iVar1 = CheckSavedSecretFlag_from_thumb(7), iVar1 != 0)))) {
      return 1;
    }
    break;
  case 6:
    iVar1 = CheckSavedSecretFlag_from_thumb(8);
    if (((iVar1 != 0) || (iVar1 = CheckSavedSecretFlag_from_thumb(9), iVar1 != 0)) ||
       ((iVar1 = CheckSavedSecretFlag_from_thumb(10), iVar1 != 0 ||
        (iVar1 = CheckSavedSecretFlag_from_thumb(0xb), iVar1 != 0)))) {
      return 1;
    }
    break;
  case 7:
    iVar1 = CheckSavedSecretFlag_from_thumb(0xc);
    if ((((iVar1 != 0) || (iVar1 = CheckSavedSecretFlag_from_thumb(0xd), iVar1 != 0)) ||
        (iVar1 = CheckSavedSecretFlag_from_thumb(0xe), iVar1 != 0)) ||
       (iVar1 = CheckSavedSecretFlag_from_thumb(0xf), iVar1 != 0)) {
      return 1;
    }
  }
  return 0;
}

