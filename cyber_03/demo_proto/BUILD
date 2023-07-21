load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_cc//cc:defs.bzl", "cc_proto_library")
package(default_visibility = ["//visibility:public"])

proto_library(
    name = "car_msg_proto",
    srcs = ["car_msg.proto"],
)

cc_proto_library(
    name = "car_msg_cc_proto",
    deps = [":car_msg_proto"],
)