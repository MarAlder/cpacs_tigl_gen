// Copyright (c) 2020 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDObject;

namespace generated
{
    // This class is used in:
    // generated from /xsd:schema/xsd:complexType[1]
    class CPACSRoot
    {
    public:
        TIGL_EXPORT CPACSRoot();
        TIGL_EXPORT virtual ~CPACSRoot();

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT bool ValidateChoices() const;

        TIGL_EXPORT virtual const boost::optional<int>& GetA_choice1() const;
        TIGL_EXPORT virtual void SetA_choice1(const boost::optional<int>& value);

        TIGL_EXPORT virtual const boost::optional<int>& GetB_choice2() const;
        TIGL_EXPORT virtual void SetB_choice2(const boost::optional<int>& value);

    protected:
        boost::optional<int> m_a_choice1;
        boost::optional<int> m_b_choice2;

    private:
        CPACSRoot(const CPACSRoot&) = delete;
        CPACSRoot& operator=(const CPACSRoot&) = delete;

        CPACSRoot(CPACSRoot&&) = delete;
        CPACSRoot& operator=(CPACSRoot&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSRoot = generated::CPACSRoot;
} // namespace tigl
// Copyright (c) 2020 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "CPACSRoot.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSRoot::CPACSRoot()
    {
    }

    CPACSRoot::~CPACSRoot()
    {
    }

    const CTiglUIDObject* CPACSRoot::GetNextUIDParent() const
    {
        return nullptr;
    }

    CTiglUIDObject* CPACSRoot::GetNextUIDParent()
    {
        return nullptr;
    }

    void CPACSRoot::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element a
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/a")) {
            m_a_choice1 = tixi::TixiGetElement<int>(tixiHandle, xpath + "/a");
        }

        // read element b
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/b")) {
            m_b_choice2 = tixi::TixiGetElement<int>(tixiHandle, xpath + "/b");
        }

        if (!ValidateChoices()) {
            LOG(ERROR) << "Invalid choice configuration at xpath " << xpath;
        }
    }

    void CPACSRoot::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element a
        if (m_a_choice1) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/a");
            tixi::TixiSaveElement(tixiHandle, xpath + "/a", *m_a_choice1);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/a")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/a");
            }
        }

        // write element b
        if (m_b_choice2) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/b");
            tixi::TixiSaveElement(tixiHandle, xpath + "/b", *m_b_choice2);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/b")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/b");
            }
        }

    }

    bool CPACSRoot::ValidateChoices() const
    {
        return
        (
            (
                (
                    // mandatory elements of this choice must be there
                    m_a_choice1.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_b_choice2.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_b_choice2.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_a_choice1.is_initialized()
                    )
                )
                == 1
            )
        )
        ;
    }

    const boost::optional<int>& CPACSRoot::GetA_choice1() const
    {
        return m_a_choice1;
    }

    void CPACSRoot::SetA_choice1(const boost::optional<int>& value)
    {
        m_a_choice1 = value;
    }

    const boost::optional<int>& CPACSRoot::GetB_choice2() const
    {
        return m_b_choice2;
    }

    void CPACSRoot::SetB_choice2(const boost::optional<int>& value)
    {
        m_b_choice2 = value;
    }

} // namespace generated
} // namespace tigl
