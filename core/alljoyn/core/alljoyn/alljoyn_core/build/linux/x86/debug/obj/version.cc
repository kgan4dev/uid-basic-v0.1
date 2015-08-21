/* This file is auto-generated.  Do not modify. */
/**
 * @file
 * This file provides access to Alljoyn library version and build information.
 */

/******************************************************************************
 * Copyright (c) 2010-2014, AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/

#include "alljoyn/version.h"

static const unsigned int year = 14;
static const unsigned int month = 6;
static const unsigned int feature = 0; /* feature is always 0 for core. */
static const unsigned int bugfix = 'a';

static const char version[] = "v14.06.00a";
static const char build[] = "AllJoyn Library v14.06.00a (Built Fri Aug 21 06:08:43 UTC 2015 by vedams - Git: uid-basic-v0.1.git branch: 'master' tag: '<none>' commit ref: 45a85eb02994d0c02b9bd34c6760840aae005f9f)";

const char* ajn::GetVersion()
{
    return version;
}

const char* ajn::GetBuildInfo()
{
    return build;
}

uint32_t ajn::GetNumericVersion()
{
    return GenerateNumericVersionValue(year, month, feature, bugfix);
}
