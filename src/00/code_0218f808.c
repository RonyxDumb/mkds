#include "00/code_0218f808.h"
#include "00/GameSpy/hashtable.h"
#include "00/GameSpy/gpiConnect.h"

void func_ov000_0218f808(GpConnection *a) {
    GpiConnection *v1;
    v1 = a->mGpiConnection;
    GpiCloseConnection(a, 1);
    func_ov000_021a3668(v1->field460);
    v1->field460 = NULL;
    HashtableDelete(v1->mProfileList.mTable);
    func_ov000_021a3668(v1);
    a->mGpiConnection = NULL;
}
