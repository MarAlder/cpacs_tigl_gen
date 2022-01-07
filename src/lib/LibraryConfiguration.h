#pragma once

#include <unordered_map>
#include <iostream>

namespace tigl {
    
    class LibraryConfiguration{
        
        public:
            LibraryConfiguration(const std::string& key);

            std::string exportVariable();
            std::string libNamespace();
            std::string libInternal();
            std::string errorClass();
            std::string uIDObject();
            std::string reqUIDObject();
            std::string optUIDObject();

        private:

            std::string m_exportVariable;
            std::string m_libNamespace;
            std::string m_libInternal;
            std::string m_errorClass;
            std::string m_uIDObject;
            std::string m_reqUIDObject;
            std::string m_optUIDObject;

    };
    
}
    
