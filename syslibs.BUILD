load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake", "configure_make")

package(default_visibility = ["//visibility:public"])

cmake(
    name = "ares",
    cache_entries = {
        "CARES_BUILD_TOOLS": "no",
        "CARES_SHARED": "no",
        "CARES_STATIC": "on",
        "CMAKE_CXX_COMPILER_FORCED": "on",
        "CMAKE_INSTALL_LIBDIR": "lib",
    },
    defines = ["CARES_STATICLIB"],
    lib_source = "@ares//:all",
    out_static_libs =  ["libcares.a"],
)

configure_make(
    name = "openssl",
    configure_command = "config",
    configure_in_place = True,
    configure_options = [
        "no-comp",
        "no-idea",
        "no-weak-ssl-ciphers",
        "no-shared",
    ],
    lib_name = "openssl",
    lib_source = "@openssl//:all",
    out_binaries = ["openssl"],
    out_static_libs =  [
        "libssl.a",
        "libcrypto.a",
    ],
    targets = [
        "build_programs",
        "install_sw",
    ],
)

cmake(
    name = "curl",
    cache_entries = {
        "BUILD_CURL_EXE": "off",
        "BUILD_SHARED_LIBS": "off",
        "CURL_USE_LIBSSH2": "off",
        "CURL_USE_LIBPSL": "off",
        "CURL_BROTLI": "off",
        "CURL_USE_GSSAPI": "off",
        "CMAKE_BUILD_TYPE": "RELEASE",
        "CMAKE_PREFIX_PATH": "$$EXT_BUILD_DEPS$$/openssl",
        "CURL_USE_OPENSSL": "on",
        # TODO: ldap should likely be enabled
        "CURL_DISABLE_LDAP": "on",
        "OPENSSL_ROOT_DIR": "$$EXT_BUILD_DEPS$$/openssl",
        "CMAKE_C_FLAGS": "-fPIC",
        "ENABLE_ARES": "on",
        # Avoid libidn2
        "USE_LIBIDN2": "off",
        # NGHTTP2.
        "USE_NGHTTP2": "on",
        "NGHTTP2_LIBRARY": "$EXT_BUILD_DEPS/nghttp2",
        "NGHTTP2_INCLUDE_DIR": "$EXT_BUILD_DEPS/nghttp2/include",
    },


    generate_crosstool_file = False,
    lib_source = "@curl//:all",
    linkopts = [
            "-lpthread",
        ],
    out_static_libs = ["libcurl.a"],
    visibility = ["//visibility:public"],
    deps = [
        ":ares",
        ":nghttp2",
        ":openssl",
        ":zlib",
    ],
)


cmake(
    name = "nghttp2",
    cache_entries = {
        "ENABLE_LIB_ONLY": "on",
        "ENABLE_SHARED_LIB": "off",
        "ENABLE_STATIC_LIB": "on",
        "CMAKE_INSTALL_LIBDIR": "lib",
        "CMAKE_CXX_COMPILER_FORCED": "on",
    },
    defines = ["NGHTTP2_STATICLIB"],
    lib_source = "@nghttp2//:all",
    out_static_libs = ["libnghttp2.a"],
)

cmake(
    name = "zlib",
    cache_entries = {
        "CMAKE_CXX_COMPILER_FORCED": "on",
        "CMAKE_C_COMPILER_FORCED": "on",
        "SKIP_BUILD_EXAMPLES": "on",
        "BUILD_SHARED_LIBS": "off",

        # The following entries are for zlib-ng. Since zlib and zlib-ng are compatible source
        # codes and CMake ignores unknown cache entries, it is fine to combine it into one
        # dictionary.
        #
        # Reference: https://github.com/zlib-ng/zlib-ng#build-options.
        "ZLIB_COMPAT": "on",
        "ZLIB_ENABLE_TESTS": "off",

        # Warning: Turning WITH_OPTIM to "on" doesn't pass ZlibCompressorImplTest.CallingChecksum.
        "WITH_OPTIM": "on",
        # However turning off SSE4 fixes it.
        "WITH_SSE4": "off",

        # Warning: Turning WITH_NEW_STRATEGIES to "on" doesn't pass gzip compressor fuzz test.
        # Turning this off means falling into NO_QUICK_STRATEGY route.
        "WITH_NEW_STRATEGIES": "off",

        # Only allow aligned address.
        # Reference: https://github.com/zlib-ng/zlib-ng#advanced-build-options.
        "UNALIGNED_OK": "off",
    },
    lib_source =  "@zlib//:all",
    out_static_libs =  ["libz.a"],
)

configure_make(
    name = "apr",
    configure_in_place = True,
    configure_options = [
        "--disable-shared",
    ],
    lib_name = "apr",
    lib_source = "@apr//:all",
    out_static_libs = ["libapr-1.a"],
    out_include_dir = "include/apr-1",
    visibility = ["//visibility:public"],
)

configure_make(
    name = "apr_util",
    configure_in_place = True,
    configure_options = [
        "--with-apr=$EXT_BUILD_DEPS/apr",
        "--with-expat=$EXT_BUILD_DEPS/expat",
    ],
    lib_source = "@apr_util//:all",
    out_static_libs = ["libaprutil-1.a"],
    out_include_dir = "include/apr-1",
    visibility = ["//visibility:public"],
    deps = [
        ":apr",
        ":expat",
    ],
)

configure_make(
    name = "expat",
    configure_options = [
        "--disable-shared",
        "--without-docbook",
        "--without-examples",
        "--without-tests",
    ],
    lib_name = "expat",
    lib_source = "@expat//:all",
    out_static_libs = ["libexpat.a"],
)

configure_make(
    name = "jansson",
    configure_in_place = True,
    configure_options = [
        "--enable-static",
        "--disable-shared",
    ],
    lib_source = "@jansson//:all",
    out_static_libs = ["libjansson.a"],
    visibility = ["//visibility:public"],
)
