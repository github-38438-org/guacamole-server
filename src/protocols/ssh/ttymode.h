/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef GUAC_SSH_TTYMODE_H
#define GUAC_SSH_TTYMODE_H

#include "config.h"

#include <stdint.h>

/**
 * The size of a TTY mode encoding opcode and
 * value pair.  As defined in the SSH RFC, this
 * is 5 bytes - a single byte for the opcode, and
 * 4 bytes for the value.
 */
#define GUAC_SSH_TTY_OPCODE_SIZE 5

/**
 * The SSH TTY mode encoding opcode that terminates
 * the list of TTY modes.
 */
#define GUAC_SSH_TTY_OP_END 0

/**
 * The SSH TTY mode encoding opcode that configures
 * the TTY erase code to configure the server
 * backspace key.
 */
#define GUAC_SSH_TTY_OP_VERASE 3

/**
 * Simple structure that defines a opcode and
 * value pair.
 */
typedef struct guac_ssh_ttymode {
    char opcode;
    uint32_t value;
} guac_ssh_ttymode;

/**
 * Initialize an array with the specified opcode/value
 * pairs, and return the size, in bytes, of the array.
 *
 * @param opcode_array
 *     Pointer to the opcode array.
 *
 * @param array_size
 *     Size, in bytes, of the array.
 *
 * @param num_opcodes
 *     Number of opcodes to expect.
 *
 * @params ...
 *     A variable number of guac_ssh_ttymodes
 *     to place in the array.
 *
 * @return
 *     The size, in bytes, of the array.
 */
int guac_ssh_ttymodes_init(char opcode_array[], const int array_size,
        const int num_opcodes, ...);

#endif
