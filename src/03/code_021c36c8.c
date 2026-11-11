#include "03/code_021c36c8.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021c209c.h"
#include "03/code_021c36b0.h"

void UpdateJb5InfoButtonsIn(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateJb5Info);
    }
}
