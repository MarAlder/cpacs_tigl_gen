#include "LibraryConfiguration.h"

namespace tigl {

    LibraryConfiguration::LibraryConfiguration(const std::string& key){

        if(key=="tigl"){
            m_exportVariable = "TIGL_EXPORT";
            m_libNamespace = "tigl";
            m_libInternal = "tigl_internal.h";
            m_errorClass = "CTiglError.h";
            m_uIDObject = "CTiglUIDObject";
            m_reqUIDObject = "CTiglReqUIDObject";
            m_optUIDObject = "CTiglOptUIDObject";

        }
        else if(key=="cpacsLibrary"){
            m_exportVariable = "CPLIB_EXPORT";
            m_libNamespace = "cpacsLib";
            m_libInternal = "cpacsLib_internal.h";
            m_errorClass = "cpacsLibError.h";
            m_uIDObject = "uIDObject";
            m_reqUIDObject = "reqUIDObject";
            m_optUIDObject = "optUIDObject";
        }
        else{
            throw "Unknown library. Use one of (tigl|cpacsLibrary).";
        }
    }

    std::string LibraryConfiguration::exportVariable(){
        return m_exportVariable;
    }

    std::string LibraryConfiguration::libNamespace(){
        return m_libNamespace;
    }

    std::string LibraryConfiguration::libInternal(){
        return m_libInternal;
    }

    std::string LibraryConfiguration::errorClass(){
        return m_errorClass;
    }

    std::string LibraryConfiguration::uIDObject(){
       return m_uIDObject;
    }

    std::string LibraryConfiguration::reqUIDObject(){
       return m_reqUIDObject;
    }

    std::string LibraryConfiguration::optUIDObject(){
       return m_optUIDObject;
    }


}
