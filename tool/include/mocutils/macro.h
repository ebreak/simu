#ifndef __MOC_MACRO_H
#define __MOC_MACRO_H

#define make(type, args...) moc::make_##type<args>()
#define makeptr(type, args...) moc::makeptr_##type<args>()

#endif