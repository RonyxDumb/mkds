/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define SaveDataIoManagerIsBusy SaveDataIoManager_IsBusy
#define data_021759d4 SDK_data_021759d4
#define SaveDataIoManagerIsBusy12 func_020360a0
// PURPOSE: Checks whether save data input or output is still busy.
// Takes no arguments.
// Returns zero when the manager is idle.
// The pointed-to state probably belongs to the save-data I/O manager.

extern int SaveDataIoManagerIsBusy(void);
extern unsigned char *data_021759d4;

int SaveDataIoManagerIsBusy12(void) {
    if (SaveDataIoManagerIsBusy()) {
        return *(int *)(data_021759d4 + 0x10);
    }
    return 0;
}
