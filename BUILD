
cc_binary(
    name = "testit",
    srcs = ["testit.cc"],
    linkstatic = 1,
    linkopts=['-static'],
    deps = [
        "@syslibs//:openssl",
        "@syslibs//:curl",
        "@syslibs//:apr",
        "@syslibs//:apr_util",
        "@syslibs//:jansson",
    ],
)
