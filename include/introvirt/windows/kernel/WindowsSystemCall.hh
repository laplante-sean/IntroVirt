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

#include <introvirt/core/memory/guest_ptr.hh>
#include <introvirt/core/syscall/SystemCall.hh>
#include <introvirt/windows/kernel/SystemCallIndex.hh>

#include <introvirt/fwd.hh>

namespace introvirt {
namespace windows {

/**
 * @brief Base class for Windows system calls
 */
class WindowsSystemCall : public SystemCall {
  public:
    /**
     * @brief Get the system call number
     *
     * @return const SystemCallIndex
     */
    virtual SystemCallIndex index() const = 0;
};

} // namespace windows
} // namespace introvirt