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
#include <introvirt/windows/libraries/WindowsFunctionCall.hh>
#include <introvirt/windows/libraries/ws2_32/types/SOCKADDR.hh>
#include <introvirt/windows/libraries/ws2_32/types/SOCKET.hh>

#include <memory>

namespace introvirt {
namespace windows {
namespace ws2_32 {

/**
 * @brief Handler for ws2_32!WSASendTo
 *
 * @see https://docs.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-WSASendTo
 */
class WSASendTo : public WindowsFunctionCall {
  public:
    /* Input arguments */
    SOCKET s() const;
    void s(SOCKET s);

    GuestVirtualAddress lpBuffers() const;
    void lpBuffers(const GuestVirtualAddress& gva);

    uint32_t dwBufferCount() const;
    void dwBufferCount(uint32_t dwBufferCount);

    GuestVirtualAddress lpNumberOfBytesSent() const;
    void lpNumberOfBytesSent(const GuestVirtualAddress& gva);

    uint32_t dwFlags() const;
    void dwFlags(uint32_t dwFlags);

    GuestVirtualAddress lpTo() const;
    void lpTo(const GuestVirtualAddress& gva);

    int32_t iTolen() const;
    void iTolen(int32_t iTolen);

    GuestVirtualAddress lpOverlapped() const;
    void lpOverlapped(const GuestVirtualAddress& gva);

    GuestVirtualAddress lpCompletionRoutine() const;
    void lpCompletionRoutine(const GuestVirtualAddress& gva);

    /* Helpers */
    uint32_t NumberOfBytesSent() const;
    void NumberOfBytesSent(uint32_t NumberOfBytesSent);

    const SOCKADDR* To() const;
    SOCKADDR* To();

    int32_t result() const;

    const std::string& function_name() const override;
    const std::string& library_name() const override;
    void write(std::ostream& os = std::cout) const override;

    WSASendTo(Event& event);
    ~WSASendTo() override;

    static constexpr int ArgumentCount = 9;
    inline static const std::string LibraryName = "ws2_32";
    inline static const std::string FunctionName = "WSASendTo";

  private:
    SOCKET s_;
    GuestVirtualAddress lpBuffers_;
    uint32_t dwBufferCount_;
    GuestVirtualAddress lpNumberOfBytesSent_;
    uint32_t dwFlags_;
    GuestVirtualAddress lpTo_;
    int32_t iTolen_;
    GuestVirtualAddress lpOverlapped_;
    GuestVirtualAddress lpCompletionRoutine_;

    mutable std::unique_ptr<SOCKADDR> to_;
};

} // namespace ws2_32
} // namespace windows
} // namespace introvirt