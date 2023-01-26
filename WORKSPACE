workspace(name="tst")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_foreign_cc",
    sha256 = "2a4d07cd64b0719b39a7c12218a3e507672b82a97b98c6a89d38565894cf7c51",
    strip_prefix = "rules_foreign_cc-0.9.0",
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/refs/tags/0.9.0.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

# This sets up some common toolchains for building targets. For more details, please see
# https://bazelbuild.github.io/rules_foreign_cc/0.9.0/flatten.html#rules_foreign_cc_dependencies
rules_foreign_cc_dependencies()


all_content = """filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])"""

http_archive(
    name = "openssl",
    build_file_content = all_content,
    sha256 = "c5ac01e760ee6ff0dab61d6b2bbd30146724d063eb322180c6f18a6f74e4b6aa",
    strip_prefix = "openssl-1.1.1s",
    urls = ["https://www.openssl.org/source/openssl-1.1.1s.tar.gz"],
)

http_archive(
    name = "ares",
    build_file_content = all_content,
    sha256 = "1a7d52a8a84a9fbffb1be9133c0f6e17217d91ea5a6fa61f6b4729cda78ebbcf",
    strip_prefix = "c-ares-1.18.1",
    urls = ["https://github.com/c-ares/c-ares/releases/download/cares-1_18_1/c-ares-1.18.1.tar.gz"],
)

http_archive(
    name = "nghttp2",
    build_file_content = all_content,
    sha256 = "2a0bef286f65b35c24250432e7ec042441a8157a5b93519412d9055169d9ce54",
    strip_prefix = "nghttp2-1.51.0",
    urls = ["https://github.com/nghttp2/nghttp2/releases/download/v1.51.0/nghttp2-1.51.0.tar.gz"],
)

http_archive (
    name = "zlib",
    build_file_content = all_content,
    sha256 = "1525952a0a567581792613a9723333d7f8cc20b87a81f920fb8bc7e3f2251428",
    strip_prefix = "zlib-1.2.13",
    urls = ["https://github.com/madler/zlib/archive/v1.2.13.tar.gz"],
)

http_archive(
    name = "curl",
    build_file_content = all_content,
    sha256 = "8a063d664d1c23d35526b87a2bf15514962ffdd8ef7fd40519191b3c23e39548",
    strip_prefix = "curl-7.87.0",
    urls = ["https://github.com/curl/curl/releases/download/curl-7_87_0/curl-7.87.0.tar.gz"],
)

http_archive(
    name = "apr",
    sha256 = "48e9dbf45ae3fdc7b491259ffb6ccf7d63049ffacbc1c0977cced095e4c2d5a2",
    build_file_content = all_content,
    strip_prefix = "apr-1.7.0",
    urls = [
        "https://mirror.bazel.build/www-eu.apache.org/dist/apr/apr-1.7.0.tar.gz",
        "https://www-eu.apache.org/dist/apr/apr-1.7.0.tar.gz",
    ],
)

http_archive(
    name = "apr_util",
    sha256 = "b65e40713da57d004123b6319828be7f1273fbc6490e145874ee1177e112c459",
    build_file_content = all_content,
    strip_prefix = "apr-util-1.6.1",
    urls = [
        "https://mirror.bazel.build/www-us.apache.org/dist//apr/apr-util-1.6.1.tar.gz",
        "https://www-us.apache.org/dist//apr/apr-util-1.6.1.tar.gz",
    ],
)

http_archive(
    name = "expat",
    sha256 = "a00ae8a6b96b63a3910ddc1100b1a7ef50dc26dceb65ced18ded31ab392f132b",
    build_file_content = all_content,
    strip_prefix = "expat-2.4.1",
    urls = [
        "https://mirror.bazel.build/github.com/libexpat/libexpat/releases/download/R_2_4_1/expat-2.4.1.tar.gz",
        "https://github.com/libexpat/libexpat/releases/download/R_2_4_1/expat-2.4.1.tar.gz",
    ],
)

http_archive(
    name = "jansson",
    sha256 = "5798d010e41cf8d76b66236cfb2f2543c8d082181d16bc3085ab49538d4b9929",
    build_file_content = all_content,
    strip_prefix = "jansson-2.14",
    urls = [
        "https://github.com/akheron/jansson/releases/download/v2.14/jansson-2.14.tar.gz",
    ],
)

new_local_repository(
    name = "syslibs",
    path = "./",
    build_file = "syslibs.BUILD"
)
