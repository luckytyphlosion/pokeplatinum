#include <nitro.h>
#include <string.h>

#include "struct_decls/struct_0200B144_decl.h"
#include "struct_decls/struct_0200B358_decl.h"
#include "struct_decls/struct_02023790_decl.h"

#include "unk_0200AC5C.h"
#include "unk_0200B29C.h"
#include "unk_0200B358.h"
#include "strbuf.h"

Strbuf* sub_0200B29C (UnkStruct_0200B358 * param0, UnkStruct_0200B144 * param1, u32 param2, u32 param3)
{
    Strbuf* v0 = NULL;
    Strbuf* v1;

    v1 = Strbuf_Init(1024, 0);

    if (v1) {
        Strbuf* v2 = sub_0200B1EC(param1, param2);

        if (v2) {
            sub_0200C388(param0, v1, v2);
            v0 = Strbuf_Clone(v1, param3);
            Strbuf_Free(v2);
        }

        Strbuf_Free(v1);
    }

    return v0;
}

Strbuf* sub_0200B2EC (u32 param0, u32 param1)
{
    UnkStruct_0200B144 * v0 = sub_0200B144(1, 26, 647, param1);

    if (v0) {
        Strbuf* v1 = Strbuf_Init(16, param1);

        if (v1) {
            sub_0200B1B8(v0, param0, v1);
        }

        sub_0200B190(v0);
        return v1;
    }

    return NULL;
}

Strbuf* sub_0200B32C (u32 param0, u32 param1)
{
    UnkStruct_0200B144 * v0 = sub_0200B144(1, 26, 412, param1);

    if (v0) {
        Strbuf* v1 = sub_0200B1EC(v0, param0);

        sub_0200B190(v0);
        return v1;
    }

    return NULL;
}
