load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_cc//cc:defs.bzl", "cc_proto_library")
package(default_visibility = ["//visibility:public"])

proto_library(
    name = "car_proto",
    srcs = ["car.proto"],
)

cc_proto_library(
    name = "car_cc_proto",
    deps = [":car_proto"],
)