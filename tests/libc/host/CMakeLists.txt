# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.

add_executable(libc_host host.cpp)

target_link_libraries(libc_host oehostapp)
