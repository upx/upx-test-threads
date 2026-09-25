#pragma once

#if defined(__cplusplus)
#    define TESTING_ACX 1
#    undef CTA_INTERNAL_PREFIX
#    define CTA_INTERNAL_PREFIX tt_acx_
namespace tt_acx {
#    include "cxx_type_traits_test.h"
}
#    undef TESTING_ACX
#    undef CTA_INTERNAL_PREFIX

#    if __cplusplus >= 201103L && !defined(FREESTANDING) && 1
#        include <type_traits>
#        define acx ::std
#        undef CTA_INTERNAL_PREFIX
#        define CTA_INTERNAL_PREFIX tt_std_
namespace tt_std {
#        include "cxx_type_traits_test.h"
}
#        undef acx
ct_assert((std::is_same<std::nullptr_t, acx::nullptr_t>::value));
ct_assert((acx::is_same<std::nullptr_t, acx::nullptr_t>::value));
#        undef CTA_INTERNAL_PREFIX
#    endif
#endif
