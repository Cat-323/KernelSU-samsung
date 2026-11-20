#include <linux/jump_label.h>

#include "compat/gki_lateload.h"

void gki_cred_sync_init(void);
void gki_cred_sync_exit(void);
void gki_mem_sync_init(void);
void gki_mem_sync_exit(void);
void gki_sec_ctx_init(void);

int init_gki_lateload(void)
{
    gki_cred_sync_init();
    gki_mem_sync_init();
    gki_sec_ctx_init();
    return 0;
}

void exit_gki_lateload(void)
{
    gki_cred_sync_exit();
    gki_mem_sync_exit();
}
