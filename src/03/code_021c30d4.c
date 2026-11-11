#include "03/code_021c30d4.h"
#include "03/code_021c209c.h"
#include "03/code_021c30f0.h"
#include "03/code_021cea3c.h"

void UpdateYb5MultiMessageClose(void) {
    int messageOpen;
    messageOpen = func_ov003_021cef6c();
    if (messageOpen == 0) {
        SetUpdateFunction(StartYb5MultiClose);
    }
}
