load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("//tools/install:install.bzl", "install", "install_src_files")
package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "main03",
    srcs = ["main.cc"],
    deps = ["//cyber_demo/cyber_03/demo_proto:car_msg_cc_proto"], 
)

install(
    name = "install",
    runtime_dest = "cyber_demo/bin",
    targets = [
        ":main03"
    ],
)

install_src_files(
    name = "install_src",
    src_dir = ["."],
    dest = "cyber_demo/src/cyber_03",
    filter = "*",
)