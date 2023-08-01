load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("//tools/install:install.bzl", "install", "install_src_files")
package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "camera_driver",
    srcs = ["camera_driver.cc"],
    deps = ["//cyber",
            "//modules/common_msgs/sensor_msgs:sensor_image_cc_proto",
            ], 
)

install(
    name = "install",
    runtime_dest = "cyber_demo/bin",
    targets = [
    ":camera_driver"
        ],
)

install_src_files(
    name = "install_src",
    src_dir = ["."],
    dest = "cyber_demo/src/cyber_08",
    filter = "*",
)