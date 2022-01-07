#pragma once

#include <string>
#include "LibraryConfiguration.h"

namespace tigl {
    struct TypeSystem;
    class Tables;
    class Filesystem;

    void genCode(const std::string& outputLocation, TypeSystem typeSystem, const std::string& ns, const Tables& tables, Filesystem& fs);
}
