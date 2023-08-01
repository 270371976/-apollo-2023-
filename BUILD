load("//tools/install:install.bzl", "install", "install_src_files")

install(
    name = "install",
    data = [
        "cyber_demo.BUILD",
        "cyberfile.xml",
        "BUILD",
    ],
    deps = [
        "//cyber_demo/cyber_01/demo_main:install",
        "//cyber_demo/cyber_02/demo_main:install",
        "//cyber_demo/cyber_03/demo_main:install",
        "//cyber_demo/cyber_04/demo_main:install",
        "//cyber_demo/cyber_05/demo_main:install",
        "//cyber_demo/cyber_06/demo_main:install",
        "//cyber_demo/cyber_07:install",
        "//cyber_demo/cyber_08:install",
    ],
)


install_src_files(
    name = "install_src",
    dest = "cyber_demo/src",
    deps = [
        "//cyber_demo/cyber_01/demo_main:install_src",
        "//cyber_demo/cyber_02/demo_main:install_src",
        "//cyber_demo/cyber_03/demo_main:install_src",
        "//cyber_demo/cyber_04/demo_main:install_src",
        "//cyber_demo/cyber_05/demo_main:install_src",
        "//cyber_demo/cyber_06/demo_main:install_src",
        "//cyber_demo/cyber_07:install_src",
        "//cyber_demo/cyber_08:install_src",
    ]
)