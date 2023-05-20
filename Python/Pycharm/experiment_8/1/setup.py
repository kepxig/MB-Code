from distutils.core import setup

setup(
    name='package',#包的名称
    version='1.0',#包的版本号
    description='我的Python包',#包的描述信息
    author='pyton',#包的作者
    #允许操作的python模块
    py_modules=['package.package_a.module_a','package.package_b.module_b']

)
