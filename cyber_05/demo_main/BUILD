load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("//tools/install:install.bzl", "install", "install_src_files")
package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "server",
    srcs = ["server.cc"],
    deps = [
        "//cyber",
        "//cyber_demo/cyber_05/demo_proto:car_cc_proto",
    ],
    linkstatic = True,
)

cc_binary(
    name = "client",
    srcs = ["client.cc"],
    deps = [
        "//cyber",
        "//cyber_demo/cyber_05/demo_proto:car_cc_proto",
    ],
    linkstatic = True,
)

install(
    name = "install",
    runtime_dest = "cyber_demo/bin",
    targets = [
        ":server",
        ":client"
    ],
)

install_src_files(
    name = "install_src",
    src_dir = ["."],
    dest = "cyber_demo/src/cyber_05",
    filter = "*",
)