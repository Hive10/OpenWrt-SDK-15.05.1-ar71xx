/* vim: set tabstop=8 shiftwidth=4 softtabstop=4 expandtab smarttab colorcolumn=80: */
/*
 * Copyright 2016 Red Hat, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <jose/b64.h>
#include <jose/jwk.h>
#include <jose/jws.h>
#include <jose/jwe.h>

#define JOSE_VERSION 7

/**
 * Converts a JWS or JWE from compact format into JSON format.
 */
json_t *
jose_from_compact(const char *cmpct);

/**
 * Converts a JWS or JWE from JSON format into compact format.
 *
 * If more than one signature/recipient exists or if an unprotected header is
 * found, this operation will fail.
 *
 * Free with free().
 */
char *
jose_to_compact(const json_t *jose);
