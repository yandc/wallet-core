// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Base64.h"

#include <boost/algorithm/string.hpp>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/beast/core/detail/base64.hpp>

namespace TW::Base64 {

using namespace TW;
using namespace std;

Data decode(const string& val) {
    string output;
    size_t len = val.size();
    output.resize(boost::beast::detail::base64::decoded_size(len));
    auto result = boost::beast::detail::base64::decode(output.data(), val.data(), len);
    output.resize(result.first);
    return TW::data(output);
}

string encode(const Data& val) {
    using namespace boost::archive::iterators;
    using It = base64_from_binary<transform_width<Data::const_iterator, 6, 8>>;
    auto encoded = string(It(begin(val)), It(end(val)));
    return encoded.append((3 - val.size() % 3) % 3, '=');
}

/// Convert from Base64Url format to regular
void convertFromBase64Url(string& b) {
    // '-' and '_' (Base64URL format) are changed to '+' and '/'
    // in-place replace
    size_t n = b.length();
    char* start = b.data();
    char* end = start + n;
    for (auto* p = start; p < end; ++p) {
        if (*p == '-') {
            *p = '+';
        } else if (*p == '_') {
            *p = '/';
        }
    }
}

/// Convert from regular format to Base64Url
void convertToBase64Url(string& b) {
    // '+' and '/' are changed to '-' and '_' (Base64URL format)
    // in-place replace
    size_t n = b.length();
    char* start = b.data();
    char* end = start + n;
    for (auto* p = start; p < end; ++p) {
        if (*p == '+') {
            *p = '-';
        } else if (*p == '/') {
            *p = '_';
        }
    }
}

Data decodeBase64Url(const string& val) {
    Data bytes;
    // 2nd try: Base64URL format (replaced by '-' and '_' by '+' and '/' )
    string base64Url = val;
    convertFromBase64Url(base64Url);
    return decode(base64Url);
}

string encodeBase64Url(const Data& val) {
    using namespace boost::archive::iterators;
    using It = base64_from_binary<transform_width<Data::const_iterator, 6, 8>>;
    auto encoded = string(It(begin(val)), It(end(val)));
    encoded.append((3 - val.size() % 3) % 3, '=');
    convertToBase64Url(encoded);
    return encoded;
}

} // namespace TW::Base64
