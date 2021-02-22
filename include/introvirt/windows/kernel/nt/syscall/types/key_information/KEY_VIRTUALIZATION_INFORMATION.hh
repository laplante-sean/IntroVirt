/*
 * Copyright 2021 Assured Information Security, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include "../../../fwd.hh"

#include "KEY_INFORMATION.hh"

namespace introvirt {
namespace windows {
namespace nt {

class KEY_VIRTUALIZATION_INFORMATION : public KEY_INFORMATION {
    virtual bool VirtualizationCandidate() const = 0;
    virtual void VirtualizationCandidate(bool value) = 0;

    virtual bool VirtualizationEnabled() const = 0;
    virtual void VirtualizationEnabled(bool value) = 0;

    virtual bool VirtualTarget() const = 0;
    virtual void VirtualTarget(bool value) = 0;

    virtual bool VirtualStore() const = 0;
    virtual void VirtualStore(bool value) = 0;

    virtual bool VirtualSource() const = 0;
    virtual void VirtualSource(bool value) = 0;
};

} // namespace nt
} // namespace windows
} // namespace introvirt
