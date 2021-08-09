#include "intel-ipsec-mb.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    MB_MGR *p_mgr = NULL;
    uint64_t flags = 0;

    p_mgr = alloc_mb_mgr(flags);
    if (p_mgr == NULL) {
        printf("alloc_mb_mgr failed!\n");
        return EXIT_SUCCESS;  /* Ignore failure */
    }

    init_mb_mgr_sse(p_mgr);
    init_mb_mgr_avx(p_mgr);
    init_mb_mgr_avx2(p_mgr);
    init_mb_mgr_avx512(p_mgr);
    free_mb_mgr(p_mgr);

    return EXIT_SUCCESS;
}
