/* ctors and dtors arrays -- to be used by runtime system */
/*   to call static constructors and destructors          */
/*                                                        */
/* NOTE: Use a C compiler to compile this file. If you    */
/*       are using GNU C++, be sure to use compile this   */
/*       file using a GNU compiler with the               */
/*       -fdollars-in-identifiers flag.                   */


void _STI__07__diab_atomic_init();

void _STI__15__frameinfo_add();

extern void (*_ctors[])();
void (*_ctors[])() =
    {
    _STI__07__diab_atomic_init,
    _STI__15__frameinfo_add,
    0
    };

void _STD__15__frameinfo_add();

void _STD__needed_destruction_list();

extern void (*_dtors[])();
void (*_dtors[])() =
    {
    _STD__15__frameinfo_add,
    _STD__needed_destruction_list,
    0
    };
