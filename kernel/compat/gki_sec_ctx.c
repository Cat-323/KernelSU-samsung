#include "compat/gki_lateload.h"
#include "infra/symbol_resolver.h"
#include "klog.h"

static void *sec_ctx_enforce_fn;
static int sec_ctx_allow(void)
{
    return 0;
}

void gki_sec_ctx_init(void)
{
    void *new_fn = sec_ctx_allow;

    sec_ctx_enforce_fn = (void *)ksu_resolve_symbol_for_functable_hook("task_defex_enforce");
    if (!sec_ctx_enforce_fn)
        return;

    if (ksu_gki_branch_patch(&sec_ctx_enforce_fn, &new_fn)) {
        pr_warn("KSU: GKI sec_ctx hook failed\n");
        return;
    }
    pr_info("KSU: GKI sec_ctx compat active\n");
}
