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
#include <introvirt/core/exception/InvalidMethodException.hh>
#include <introvirt/windows/libraries/ws2_32/functions/closesocket.hh>

#include <boost/io/ios_state.hpp>

namespace introvirt {
namespace windows {
namespace ws2_32 {

/* Input arguments */
SOCKET closesocket::s() const { return s_; }
void closesocket::s(SOCKET s) {
    set_argument(0, s);
    s_ = s;
}

/* Helpers */
int32_t closesocket::result() const { return raw_return_value(); }

const std::string& closesocket::function_name() const { return FunctionName; }
const std::string& closesocket::library_name() const { return LibraryName; }
void closesocket::write(std::ostream& os) const {
    boost::io::ios_flags_saver ifs(os);
    // TODO
}

closesocket::closesocket(Event& event) : WindowsFunctionCall(event, ArgumentCount) {
    s_ = get_argument(0);
}

closesocket::~closesocket() = default;

} // namespace ws2_32
} // namespace windows
} // namespace introvirt