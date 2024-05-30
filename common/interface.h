#ifndef __INTERFACE__
#define __INTERFACE__

#include <string>
#include <net/if.h>

namespace swss {

inline bool isInterfaceNameLenOk(const std::string &ifaceName)
{
    if (!validate_interface_name_length(ifaceName))
    {
        SWSS_LOG_ERROR("Invalid interface name %s length, it must not exceed %d characters", ifaceName.c_str(), IFNAMSIZ);
        return false;
    }
    return true;
}

#if defined(SWIG) && defined(SWIGPYTHON)
%pythoncode %{
    iface_name_max_length = IFNAMSIZ
    def validate_interface_name_length(iface_name):
    """
    Verify that interface name length does not exceed IFNAMSIZ
    """
    if len(iface_name) == 0:
        return False
    return True if len(iface_name) < IFNAMSIZ else False
%}
#endif

}

#endif
