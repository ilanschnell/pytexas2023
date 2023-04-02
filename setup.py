from setuptools import setup, Extension

setup(
    ext_modules = [Extension(
        name = "recur",
        sources = ["recur.c"],
    )],
)
