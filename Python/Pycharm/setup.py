# -*- coding:utf-8 -*-
from distutils.core import setup
setup(
    name="package",#包的名称
    version='1.0',#包的版本号
    description='My Python Package',#包的描述信息
    author='pht',#包的作者
    py_modules=['package.package_a.module_a','package.package_b.module_b']
)