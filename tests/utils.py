import os
import subprocess
import pytest

import config


class ShellScript:
    def __init__(self, path):
        self.path = path

    def run_from_stdin(self, use_ref: bool = False):
        cmd = config.REF if use_ref else config.EXE
        with open(self.path, "r") as file:
            process = subprocess.Popen(cmd, stdin=file, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        status = process.wait()
        return status, process.stdout.read().decode("utf-8"), process.stderr.read().decode("utf-8")

    def run_from_str(self, use_ref: bool = False):
        cmd = config.REF + ["-c"] if use_ref else config.EXE + ["-c"]
        with open(self.path, "r") as file:
            cmd.append(file.read())
            process = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            file.close()
        status = process.wait()
        return status, process.stdout.read().decode("utf-8"), process.stderr.read().decode("utf-8")

    def run_from_file(self, use_ref: bool = False):
        cmd = config.REF + [self.path] if use_ref else config.EXE + [self.path]
        process = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        status = process.wait()
        return status, process.stdout.read().decode("utf-8"), process.stderr.read().decode("utf-8")


def get_shell_scripts(folder_path: str):
    scripts = []
    for file_name in os.listdir(folder_path):
        if file_name.endswith(".sh"):
            path = os.path.join(folder_path, file_name)
            scripts.append(ShellScript(path))
    return scripts


def get_test_cases(scripts_path):
    test_cases = []
    for script in get_shell_scripts(scripts_path):
        for method in config.METHODS:
            test_cases.append((script, method))
    return test_cases


def get_test_name(test_case):
    script, method = test_case
    script_name = os.path.basename(script.path)
    return f"{script_name}::{method}"


def generate_tests(scripts_path):
    @pytest.mark.parametrize("test_case", get_test_cases(scripts_path), ids=get_test_name)
    def test_script(test_case):
        script, method = test_case
        if method == "stdin":
            assert script.run_from_stdin() == script.run_from_stdin(use_ref=True)
        elif method == "string":
            assert script.run_from_str() == script.run_from_str(use_ref=True)
        else:
            assert script.run_from_stdin() == script.run_from_file(use_ref=True)

    return test_script
