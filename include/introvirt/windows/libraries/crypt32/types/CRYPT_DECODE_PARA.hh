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

#include <introvirt/core/memory/GuestVirtualAddress.hh>
#include <introvirt/windows/libraries/crypt32/types/HCERTSTORE.hh>

#include <cstdint>

namespace introvirt {
namespace windows {
namespace crypt32 {

/**
 * @brief
 *
 * @see https://docs.microsoft.com/en-us/windows/win32/api/wincrypt/ns-wincrypt-crypt_decode_para
 */
class CRYPT_DECODE_PARA {
  public:
    virtual uint32_t cbSize() const = 0;
    virtual void cbSize(uint32_t cbSize) = 0;

    virtual GuestVirtualAddress pfnAlloc() const = 0;
    virtual void pfnAlloc(const GuestVirtualAddress& gva) = 0;

    virtual GuestVirtualAddress pfnFree() const = 0;
    virtual void pfnFree(const GuestVirtualAddress& gva) = 0;

    /**
     * @brief Create a CRYPT_DECODE_PARA
     */
    static std::unique_ptr<CRYPT_DECODE_PARA> make_unique(const GuestVirtualAddress& gva, bool x64);

    /**
     * @brief Get the size of the structure
     * @param x64 If true, return the size of the 64-bit version, otherwise 32-bit
     */
    static size_t size(bool x64);

    /**
     * @brief Get the size of the structure
     * @param vcpu The VCPU to use as context
     *
     * This version will use the current processor state
     * to determine if the structure would be 32-bit or 64-bit.
     */
    static size_t size(const Vcpu& vcpu);

    virtual ~CRYPT_DECODE_PARA() = default;
};

} // namespace crypt32
} // namespace windows
} // namespace introvirt