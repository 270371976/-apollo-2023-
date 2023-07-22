
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("//tools/install:install.bzl", "install", "install_src_files")
package(default_visibility = ["//visibility:public"])

cc_library(
    name = "common_component_example_lib",
    srcs = ["CommonComponentSample.cc"],
    hdrs = ["CommonComponentSample.h"],
    visibility = ["//visibility:private"],
    deps = [
        "//cyber",
        "//cyber_demo/cyber_07/proto:examples_cc_proto",
    ],
    alwayslink = True,
)

cc_binary(
    name = "libcommon_component_example.so",
    linkshared = True,
    linkstatic = True,
    deps = [":common_component_example_lib"],
)

install(
    name = "install",
    library_dest = "cyber_demo/lib",
    targets = [
        ":libcommon_component_example.so",
        ":runtime_data"
    ],
)

install_src_files(
    name = "install_src",
    src_dir = ["."],
    dest = "cyber_demo/src/cyber_07",
    filter = "*",
)

filegroup(
    name = "runtime_data",
    srcs = glob([
        "dag/*.dag",
        "launch/*.launch",
    ]),
)
