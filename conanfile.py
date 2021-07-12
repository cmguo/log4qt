import os

from QtToolsFish import conans_tools
from QtToolsFish.Conans import QtConanFile


class ConanConfig(QtConanFile):
    name = "log4qt"
    version = "master"

    git_url = "git@github.com:cmguo/log4qt.git"

    enable_debug_and_release_one_package = True

    def package_include(self):
        conans_tools.copy_includes(conan_file=self, include_dir=f"./{self.name}/src/")
        conans_tools.copy_includes(conan_file=self, include_dir=f"./{self.name}/")


if __name__ == '__main__':
    conans_tools.create(build_type_list=["None"])
    conans_tools.upload("log4qt/master")
