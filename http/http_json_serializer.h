// Copyright 2018 The Ufo Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#include "nlohmann/json_fwd.hpp"
#include "utility/io/buffer.h"

namespace ufo {

class HttpMsgCreator;

// appends json msg to out by http packer
bool serialize_json_msg(io::SerializedMsg& out, HttpMsgCreator& packer, const nlohmann::json& o);

} //namespace
