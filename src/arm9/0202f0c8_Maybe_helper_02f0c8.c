/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define Maybe_helper_0287ec Maybe_helper_02f028
#define Maybe_check_0287c8 Maybe_check_02f0fc
#define Maybe_helper_028794 Maybe_helper_02f0c8
#pragma optimize_for_size on
extern int Maybe_helper_0287ec(void *a0);
extern int Maybe_check_0287c8(void *a0);

int Maybe_helper_028794(void *a0) {
    int r = 0;
    if (Maybe_helper_0287ec(a0) == 0 && Maybe_check_0287c8(a0) != 0)
        r = 1;
    return r;
}
