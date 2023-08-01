load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("//tools/install:install.bzl", "install", "install_src_files")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "talker",
    srcs = ["talker.cc"],
    deps = [
        "//cyber",
        "//cyber_demo/cyber_04/demo_proto:car_cc_proto",
    ],
    linkstatic = True,
)

cc_binary(
    name = "listener",
    srcs = ["listener.cc"],
    deps = [
        "//cyber",
        "//cyber_demo/cyber_04/demo_proto:car_cc_proto",
    ],
    linkstatic = True,
)

install(
    name = "install",
    runtime_dest = "cyber_demo/bin",
    targets = [
        ":talker",
        ":listener"
    ],
)

install_src_files(
    name = "install_src",
    src_dir = ["."],
    dest = "cyber_demo/src/cyber_04",
    filter = "*",
)