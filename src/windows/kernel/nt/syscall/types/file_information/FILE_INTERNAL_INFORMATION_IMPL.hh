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
#include <introvirt/windows/kernel/nt/syscall/types/file_information/FILE_INTERNAL_INFORMATION.hh>

namespace introvirt {
namespace windows {
namespace nt {

namespace structs {

struct _FILE_INTERNAL_INFORMATION {
    uint64_t IndexNumber;
};

} // namespace structs

class FILE_INTERNAL_INFORMATION_IMPL final : public FILE_INTERNAL_INFORMATION {
  public:
    uint64_t IndexNumber() const override { return data_->IndexNumber; }
    void IndexNumber(uint64_t value) override { data_->IndexNumber = value; }

    FILE_INFORMATION_CLASS FileInformationClass() const override {
        return FILE_INFORMATION_CLASS::FileInternalInformation;
    }

    GuestVirtualAddress address() const override { return gva_; }

    uint32_t buffer_size() const override { return buffer_size_; }

    void write(std::ostream& os, const std::string& linePrefix = "") const override;

    Json::Value json() const override;

    FILE_INTERNAL_INFORMATION_IMPL(const GuestVirtualAddress& gva, uint32_t buffer_size);

  private:
    const GuestVirtualAddress gva_;
    const uint32_t buffer_size_;
    guest_ptr<structs::_FILE_INTERNAL_INFORMATION> data_;
};

} // namespace nt
} // namespace windows
} // namespace introvirt